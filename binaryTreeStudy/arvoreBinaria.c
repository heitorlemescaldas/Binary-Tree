#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

t_node* create_node(char item) {
    t_node* root = malloc(sizeof(t_node));
    root->item = item;
    root->left = NULL;
    root->right = NULL;
    return root;
}

t_node* createBinaryTree(char **str) {
    if (**str == '\0') return NULL;
    if (**str == '(') {
        (*str)++;
        if(**str == ',') (*str)++;
        if (**str == ')') {
            (*str)++;
            if(**str == ',') (*str)++;
            return NULL;
        }

        t_node *root = create_node(**str);
        (*str)++;
        if(**str == ',') (*str)++;
        root->left = createBinaryTree(str);
        root->right = createBinaryTree(str);
        (*str)++;
        if(**str == ',') (*str)++;
        return root;
    }
    return NULL;
}

void preOrder(t_node *root) {
    if (root) {
        printf("%c ", root->item);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(t_node *root) {
    if (root) {
        inOrder(root->left);
        printf("%c ", root->item);
        inOrder(root->right);
    }
}

void postOrder(t_node *root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->item);
    }
}

void printTreeUtils(t_node* root, int spaceBeetwinNodes) {
    if (root == NULL)
        return;
    
    spaceBeetwinNodes += 5;
    printTreeUtils(root->right, spaceBeetwinNodes);

    printf("\n");
    for (int i = 5; i < spaceBeetwinNodes; i++)
        printf(" ");
    printf("%c\n", root->item);

    printTreeUtils(root->left, spaceBeetwinNodes);
}

void printTree(t_node* root) {
    printTreeUtils(root, 0);
}

void freeTree(t_node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}