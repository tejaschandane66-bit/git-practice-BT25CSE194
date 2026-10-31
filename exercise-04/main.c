/**
 * Exercise 04: Visual 2D Representation of Red-Black Tree
 * 
 * Description:
 * Implements a visualizer function that displays the hierarchical 2D structure
 * of the Red-Black Tree along with node keys and color annotations (Red/Black),
 * rotated 90 degrees with appropriate indentation.
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

// 2D visual representation of the Red-Black Tree
void visualize(struct Node* node, int depth) {
    if (node != TNULL) {
        visualize(node->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }
        printf("%c(%s)\n", node->data, node->color == RED ? "Red" : "Black");
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

    printf("RB Tree Visual Representation:\n");
    visualize(root, 0);

    return 0;
}
