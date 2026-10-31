/**
 * Exercise 06: Demonstration of Red-Black Tree Deletion Cases
 * 
 * Description:
 * Demonstrates the 3 structural cases of node deletion in a Red-Black Tree:
 *   Case 1: Deletion of a leaf node (Node 'A')
 *   Case 2: Deletion of a node with one child (Node 'E')
 *   Case 3: Deletion of a node with two children (Node 'F')
 * Displays the 2D tree representation after each operation to verify structural
 * integrity and color balancing.
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

struct Node* minimum(struct Node* node) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

void deleteFixup(struct Node* x) {
    struct Node* w;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
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

void deleteNode(char key) {
    struct Node* z = root;
    while (z != TNULL && z->data != key) {
        if (key < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }
    if (z == TNULL) return;

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

void visualize(struct Node* node, int depth) {
    if (node != TNULL) {
        visualize(node->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%c(%s)\n", node->data, node->color == RED ? "R" : "B");
        visualize(node->left, depth + 1);
    }
}

int main() {
    init();
    char keys[] = {'F','S','Q','K','C','L','H','T','V','W','M','R','N','P','A','B','X','Y','D','Z','E'};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    // Case 1: Leaf node deletion
    printf("Case 1 (Leaf Node Deletion - 'A'):\n");
    deleteNode('A');
    visualize(root, 0);

    // Case 2: Node with one child deletion
    printf("\nCase 2 (Node with one child Deletion - 'E'):\n");
    deleteNode('E');
    visualize(root, 0);

    // Case 3: Node with two children deletion
    printf("\nCase 3 (Node with two children Deletion - 'F'):\n");
    deleteNode('F');
    visualize(root, 0);

    return 0;
}
