#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef  struct  tree_node
{
    int data;
    struct tree_node* left_child;
    struct tree_node* right_child;
}tree_node;

//creating the Node of tree
tree_node* createNode(int data)
{
    tree_node* newNode = (tree_node*)malloc(sizeof(tree_node));

    if(newNode == NULL)
    {
        printf("memory alloaction is failed");
        return newNode;
    }

    newNode->data = data;
    newNode->left_child =  NULL;
    newNode->right_child = NULL;

    return newNode;

}

//inserting element in the tree
void insertElement(tree_node** root,int data)
{
    //creating the newNode
    tree_node* newNode = createNode(data);

    if(*root == NULL)
    {
        *root = newNode;
        return;
    }

    tree_node* current = *root;
    tree_node* parent = NULL;

    while( current != NULL )
    {
        parent = current;

        if(newNode->data < current->data)
            current = current->left_child;
        else
            current = current->right_child;
    }

    if(newNode->data < parent->data)
        parent->left_child = newNode;
    else
        parent->right_child = newNode;

}


//InorderTraversal of tree
void inorderTraversal(tree_node* root) 
{
    
    if (root == NULL) 
    {
        return;
    }

    inorderTraversal(root->left_child);
    printf("%d ", root->data);
    inorderTraversal(root->right_child);
}

void preOrderTraversal(tree_node* root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%d ",root->data);
    preOrderTraversal(root->left_child);
    preOrderTraversal(root->right_child);
}


bool findKey(tree_node* root , int key)
{
    if(root == NULL)
    {
        return false;
    }

    tree_node* current = root;

    while(current != NULL)
    {
        if(current->data == key )
        {
            return true;
        }

        if(current->data > key)
        {
            current = current->left_child;
        }
        else
        {
            current = current->right_child;
        }
    }

    return false;
}

tree_node* find_max_element(tree_node* root)
{
    if(root == NULL)
    {
        printf("\nthe tree is null");
        return 0;
    }

    while(root->right_child != NULL)
    {
        root = root->right_child;
    }

    return root;
}

int find_max(tree_node* root)
{
    int root_data , left_data , right_data , MAX = INT_MIN;

    if(root != NULL)
    {
        root_data = root->data;

        left_data = find_max(root->left_child);
        right_data = find_max(root->right_child);

        if(left_data > right_data)
        {
            MAX = left_data;
        }
        else
            MAX = right_data;
        if(root_data > MAX)
            MAX = root_data;
    }
    return MAX;
}

int find_min_element(tree_node* root)
{
    if(root == NULL)
    {
        printf("tree is NUll \n");
        return 0;
    }

    while (root->left_child != NULL)
    {
        root = root->left_child;
    }

    return root->data;
    
}

void delete_min_element(tree_node** root)
{

    if(*root == NULL)
    {
        printf(" tree is empty\n");
        return ;
    }
    tree_node* cur = *root;
    tree_node* prev = NULL;

    while (cur->left_child != NULL)
    {
        prev = cur;
        cur = (cur)->left_child;
    }

    tree_node* temp = cur;
    printf("\nthe deleted element is %d\n",cur->data);
    cur = prev;
    cur->left_child = NULL;
    free(temp);

}

tree_node* deletElement(tree_node* root , int data)
{
    tree_node* temp;
    if (root == NULL)
    {
        printf("Element is not there in tree\n");
        return NULL;
    }

    if (data < root->data)
    {
        root->left_child = deletElement(root->left_child, data);
    }
    else if (data > root->data)
    {
        root->right_child = deletElement(root->right_child, data);
    }
    else
    {
        // Node to be deleted is found
        if (root->left_child != NULL && root->right_child != NULL)
        {
            // Find the maximum element in the left subtree (predecessor)
            temp = find_max_element(root->left_child);
            root->data = temp->data;  // Replace the node's data with the predecessor
            root->left_child = deletElement(root->left_child, root->data); // Delete the predecessor
        }
        else
        {
            // Node has at most one child
            temp = root;
            if (root->left_child == NULL)
            {
                root = root->right_child;  // Only right child exists
            }
            else
            {
                root = root->left_child;  // Only left child exists
            }
            free(temp);  // Free the node
        }
    }
    return root;
}

bool isBinaryTree(tree_node* root)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->left_child != NULL && root->left_child->data > root->data )
        return false;

    if(root->right_child != NULL && root->right_child->data < root->data)
        return false;

    if((!isBinaryTree(root->right_child)) || (!isBinaryTree(root->right_child)))
        return false;

    
    return true;
}

// find height of binary tree
int findHeightOftree(tree_node* root)
{
    int leftH , rightH;
    if (root == NULL)
    {
        return 0;
    }
    leftH = findHeightOftree(root->left_child);
    rightH = findHeightOftree(root->right_child);
    
    if (leftH > rightH) return (leftH +1);

    else return (rightH+1);

}

int main()
{
    tree_node* root = NULL;

    insertElement(&root,4);
    insertElement(&root,5);
    insertElement(&root,3);
    insertElement(&root,6);
    insertElement(&root,2);
    insertElement(&root,1);
    insertElement(&root,7);

    int height = findHeightOftree(root);
    printf("height of tree is %d",height);

    // bool isBinary = isBinaryTree(root);
    // if(isBinary)
    //     printf("is Binary");

//    //int MAX = find_max_element(root);
//     printf("max element is %d\n",MAX);

//     int MIN = find_min_element(root);
//     printf("min element is %d\n",MIN);

  
    // inorderTraversal(root);

    // delete_min_element(&root);

    // inorderTraversal(root);
    
    // int Maximum = find_max(root);
    // printf("\n--Maximum element is %d",Maximum);

}