/**
 * Exercise 01: Creation of Red-Black Tree & Sequential Key Insertion
 * 
 * Description:
 * Writes a C program to create a Red-Black Tree and inserts the following
 * keys in order into an initially empty tree:
 * F, S, Q, K, C, L, H, T, V, W, M, R, N, P, A, B, X, Y, D, Z, E.
 * Displays the result using an Inorder Traversal.
 */

#include <stdio.h>
#include <stdlib.h>

// Color definitions: 0 = Black, 1 = Red
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

// Initialize sentinel leaf node TNULL and root
void init() {
    TNULL = (struct Node*)malloc(sizeof(struct Node));
    TNULL->color = BLACK;
    TNULL->left = NULL;
    TNULL->right = NULL;
    root = TNULL;
}

// Left rotation around node x
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

// Right rotation around node x
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

// Balance restoration after standard BST insertion
void insertFixup(struct Node* k) {
    struct Node* u;
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left; // Uncle node
            if (u != TNULL && u->color == RED) {
                // Case 1: Uncle is Red -> Recolor
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                // Case 2: Uncle is Black & k is left child -> Right rotate parent
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                // Case 3: Uncle is Black & k is right child -> Left rotate grandparent
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right; // Uncle node
            if (u != TNULL && u->color == RED) {
                // Case 1: Uncle is Red -> Recolor
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                // Case 2: Uncle is Black & k is right child -> Left rotate parent
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                // Case 3: Uncle is Black & k is left child -> Right rotate grandparent
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) break;
    }
    root->color = BLACK;
}

// Insert a character key into the Red-Black Tree
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

// Inorder traversal to verify sorted order of keys
void inorder(struct Node* node) {
    if (node != TNULL) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

int main() {
    init();
    char keys[] = {'F','S','Q','K','C','L','H','T','V','W','M','R','N','P','A','B','X','Y','D','Z','E'};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
