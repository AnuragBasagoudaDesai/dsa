#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

BST* createBST() {
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(BST* tree, int value) {
    if (tree->root == NULL) {
        tree->root = createNode(value);
        return;
    }

    TreeNode* current = tree->root;
    TreeNode* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (value < parent->value)
        parent->left = createNode(value);
    else
        parent->right = createNode(value);
}

void levelOrderTraversal(BST* tree) {
    if (tree->root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, tree->root);

    while (!isEmpty(queue)) {
        TreeNode* node = dequeue(queue);
        printf("%d ", node->value);

        if (node->left) enqueue(queue, node->left);
        if (node->right) enqueue(queue, node->right);
    }

    free(queue);
    printf("\n");
}