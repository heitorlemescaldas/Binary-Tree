#ifdef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct _node{
    char item;
    struct _node* left;
    struct _node* right;
}t_node;

t_node* create_node(char item);
t_node* createBinaryTree(char **str);
void preOrder(t_node *root);
void inOrder(t_node *root);
void postOrder(t_node *root);
void printTreeUtils(t_node* root, int spaceBeetwinNodes);
void printTree(t_node* root);
void freeTree(t_node *root);



#endif