#include <stdio.h>
#include "tree.h"

int main() {
    BST* bst = createBST();

    insert(bst, 10);
    insert(bst, 5);
    insert(bst, 15);
    insert(bst, 2);
    insert(bst, 7);

    printf("Level Order Traversal:\n");
    levelOrderTraversal(bst);

    return 0;
}
