#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct AVl_Node
{
    struct AVl_Node* left;
    struct AVl_Node* right;
    int data;
    int height;
    
}AVL_TREE_NODE;

//getting  the height of the node
int height(AVL_TREE_NODE* root)
{
    if( root == NULL)
    {
        return  -1;

    }
    else return root->height;
}

//getting the max of two numbers
int max( int h1 , int h2)
{
    if( h1 >= h2)
    {
        return h1;
    }
    else
    {
        return h2;
    }
}

//function to get the balance factor of the node
AVL_TREE_NODE* single_Left_Rotation(AVL_TREE_NODE* Node)
{
    AVL_TREE_NODE* left_node = Node->left;//getting left_child of Unbalanced sub-tree
    Node->left = left_node->right;
    left_node->right = Node;

    Node->height = max(height(Node->left) , height(Node->right)) + 1;
    left_node->height = max ( height(left_node->left), height(left_node->right)) + 1;

    return left_node;

}


AVL_TREE_NODE* single_right_rotation(AVL_TREE_NODE* Node)
{
    AVL_TREE_NODE* right_node = Node->right;
    Node->right = right_node->left;
    right_node->left = Node;

    Node->height = max(height(Node->left) , height(Node->right)) + 1;
    right_node->height = max ( height(right_node->left), height(right_node->right)) + 1;

    return right_node;

}

AVL_TREE_NODE* double_left_right_rotation(AVL_TREE_NODE* Node)
{
    Node->left = single_right_rotation(Node->left);
    return single_Left_Rotation(Node);
}

AVL_TREE_NODE* double_right_left_rotation(AVL_TREE_NODE* Node)
{
    Node->right = single_Left_Rotation(Node->right);
    return single_right_rotation(Node);
}

AVL_TREE_NODE* createNode( int data)
{
    AVL_TREE_NODE* newNode = (AVL_TREE_NODE*)malloc(sizeof(AVL_TREE_NODE));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;

    return newNode;
}

AVL_TREE_NODE* insert(AVL_TREE_NODE* root , int data)
{
    if(root == NULL)
    {
        AVL_TREE_NODE* new_node = createNode(data);
        
        return new_node;
    }
    else if(data < root->data)
    {
        root->left = insert(root->left , data);
        if(height(root->left) - height(root->right) == 2)
        {
            if(data < root->left->data)
            {
                root = single_Left_Rotation(root);
            }
            else
            {
                root = double_left_right_rotation(root);
            }
        }
    }
    else if(data > root->data)
    {
        root->right = insert(root->right , data);
        if(height(root->right) - height(root->left) == 2)
        {
            if(data > root->right->data)
            {
                root = single_right_rotation(root);
            }
            else
            {
                root = double_right_left_rotation(root);
            }
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    return root;
}

void  PrintAVLTREE(AVL_TREE_NODE* root)
{
    if(root != NULL)
    {
        PrintAVLTREE(root->left);
        printf("%d ", root->data);
        PrintAVLTREE(root->right);
    }
}

int main()
{
    AVL_TREE_NODE* root = NULL;
    root = insert(root , 10);
    root = insert(root , 20);
    root = insert(root , 15);
    root = insert(root , 30);

    
  
  

    PrintAVLTREE(root);

    // printf("Root node is %d\n", root->data);
    // printf("Left child of root is %d\n", root->left->data);
    // printf("Right child of root is %d\n", root->right->data);

    return 0;
}

