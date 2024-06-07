#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    char *treeStr = "(A,(B,(),()),(C,(F,(),()),()))";
    
    t_node *root = createBinaryTree(&treeStr);

    printf("Pre-Order: \n");
    preOrder(root);
    printf("\n");

    printf("In-Order: \n");
    inOrder(root);
    printf("\n");

    printf("Post-Order: \n");
    postOrder(root);
    printf("\n");

    printf("Tree Structure: \n");
    printTree(root);
    freeTree(root);
}