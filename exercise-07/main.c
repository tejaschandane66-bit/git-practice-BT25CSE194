/**
 * Exercise 07: Binary Tree Property Checker
 * 
 * Description:
 * Implements validation algorithms to check if a given binary tree satisfies:
 * 1. AVL Tree Property:
 *    - Binary Search Tree (BST) property
 *    - Balance factor: height difference between left and right subtrees <= 1
 * 2. Red-Black Tree Properties:
 *    - BST property
 *    - Root is Black
 *    - No two consecutive Red nodes (Red property)
 *    - Every path from node to descendant leaf has the same number of Black nodes (Black-height property)
 * 3. Heap Property:
 *    - Complete binary tree property
 *    - Max Heap (parent >= children) OR Min Heap (parent <= children)
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    char color; // 'R' for Red, 'B' for Black
    struct Node *left;
    struct Node *right;
};

// Create a new binary tree node
struct Node* createNode(int data, char color) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = color;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Calculate height of tree
int height(struct Node* node) {
    if (node == NULL) return 0;
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? l : r) + 1;
}

// Check BST property
int isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL) return 1;
    if (node->data <= min || node->data >= max) return 0;
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

int isBST(struct Node* node) {
    return isBSTUtil(node, -10000, 10000);
}

// Check AVL property (BST + balance factor <= 1 at every node)
int isAVL(struct Node* node) {
    if (node == NULL) return 1;
    if (!isBST(node)) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    if (abs(lh - rh) > 1) return 0;
    return isAVL(node->left) && isAVL(node->right);
}

// Check Red-Black black-height property
int checkBlackHeight(struct Node* node, int* bh) {
    if (node == NULL) {
        *bh = 1;
        return 1;
    }
    int leftBH = 0, rightBH = 0;
    if (!checkBlackHeight(node->left, &leftBH)) return 0;
    if (!checkBlackHeight(node->right, &rightBH)) return 0;
    if (leftBH != rightBH) return 0;
    *bh = leftBH + (node->color == 'B' ? 1 : 0);
    return 1;
}

// Check Red-Black red property (no consecutive red nodes)
int checkRedProperty(struct Node* node) {
    if (node == NULL) return 1;
    if (node->color == 'R') {
        if (node->left && node->left->color == 'R') return 0;
        if (node->right && node->right->color == 'R') return 0;
    }
    return checkRedProperty(node->left) && checkRedProperty(node->right);
}

// Check if tree is a valid Red-Black Tree
int isRBTree(struct Node* root) {
    if (root == NULL) return 1;
    if (!isBST(root)) return 0;
    if (root->color == 'R') return 0; // Root must be black
    if (!checkRedProperty(root)) return 0;
    int bh = 0;
    return checkBlackHeight(root, &bh);
}

// Count total nodes in tree
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

// Check if tree is a complete binary tree
int isComplete(struct Node* root, int index, int number_nodes) {
    if (root == NULL) return 1;
    if (index >= number_nodes) return 0;
    return (isComplete(root->left, 2 * index + 1, number_nodes) &&
            isComplete(root->right, 2 * index + 2, number_nodes));
}

// Check Max-Heap order
int isMaxHeapUtil(struct Node* root) {
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->right == NULL) return root->data >= root->left->data;
    if (root->data >= root->left->data && root->data >= root->right->data)
        return isMaxHeapUtil(root->left) && isMaxHeapUtil(root->right);
    return 0;
}

// Check Min-Heap order
int isMinHeapUtil(struct Node* root) {
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->right == NULL) return root->data <= root->left->data;
    if (root->data <= root->left->data && root->data <= root->right->data)
        return isMinHeapUtil(root->left) && isMinHeapUtil(root->right);
    return 0;
}

// Check if tree satisfies Min-Heap or Max-Heap property
int isHeap(struct Node* root) {
    if (root == NULL) return 1;
    int node_count = countNodes(root);
    if (!isComplete(root, 0, node_count)) return 0;
    return isMaxHeapUtil(root) || isMinHeapUtil(root);
}

int main() {
    // Construct sample binary tree:
    //      20(B)
    //      /   \
    //   10(R)  30(R)
    struct Node* root = createNode(20, 'B');
    root->left = createNode(10, 'R');
    root->right = createNode(30, 'R');

    printf("AVL Property: %s\n", isAVL(root) ? "YES" : "NO");
    printf("Red-Black Property: %s\n", isRBTree(root) ? "YES" : "NO");
    printf("Heap Property: %s\n", isHeap(root) ? "YES" : "NO");

    return 0;
}
