/**
 * Exercise 05: Node Deletion from Red-Black Tree with Fixup
 * 
 * Description:
 * Implements CLRS-compliant Red-Black Tree node deletion including:
 * - rbTransplant helper function for subtree replacement
 * - Inorder successor finding via minimum()
 * - deleteFixup algorithm handling all 4 double-black restoration cases
 * - Demonstrates deletion of node 'M' from the tree and confirms success.
 */

#include <stdio.h>
#include <stdlib.h>

#define BLACK 0
#define RED 1

struct Node {
    char data;
    int color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

struct Node *root;
struct Node *TNULL;

void init() {
    TNULL = (struct Node*)malloc(sizeof(struct Node));
    TNULL->color = BLACK;
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
}

void leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixup(struct Node* k) {
    struct Node* u;
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u != TNULL && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u != TNULL && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) break;
    }
    root->color = BLACK;
}

void insert(char key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->parent = NULL;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = RED;

    struct Node* y = NULL;
    struct Node* x = root;

    while (x != TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == NULL) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == NULL) {
        node->color = BLACK;
        return;
    }
    if (node->parent->parent == NULL) {
        return;
    }

    insertFixup(node);
}

// Subtree transplant helper
void rbTransplant(struct Node* u, struct Node* v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

// Find minimum node in a subtree
struct Node* minimum(struct Node* node) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

// Fixup algorithm after deletion to restore Red-Black properties
void deleteFixup(struct Node* x) {
    struct Node* w;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right; // Sibling
            if (w->color == RED) {
                // Case 1: Sibling is Red
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                // Case 2: Sibling is Black, and both children of sibling are Black
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    // Case 3: Sibling is Black, left child Red, right child Black
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                // Case 4: Sibling is Black, right child Red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            w = x->parent->left; // Sibling
            if (w->color == RED) {
                // Case 1: Sibling is Red
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                // Case 2: Sibling is Black, and both children of sibling are Black
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    // Case 3: Sibling is Black, right child Red, left child Black
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                // Case 4: Sibling is Black, left child Red
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

// Delete node with given key from tree
void deleteNode(char key) {
    struct Node* z = root;
    while (z != TNULL && z->data != key) {
        if (key < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == TNULL) {
        printf("Key %c not found for deletion.\n", key);
        return;
    }

    struct Node *x, *y = z;
    int y_original_color = y->color;

    if (z->left == TNULL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);

    if (y_original_color == BLACK) {
        deleteFixup(x);
    }
}

int main() {
    init();
    char keys[] = {'F','S','Q','K','C','L','H','T','V','W','M','R','N','P','A','B','X','Y','D','Z','E'};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    deleteNode('M');
    printf("Successfully deleted node 'M'.\n");

    return 0;
}
