#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BST {
    TreeNode* root;
} BST;

BST* createBST();
TreeNode* createNode(int value);
void insert(BST* tree, int value);
void levelOrderTraversal(BST* tree);

#endif
