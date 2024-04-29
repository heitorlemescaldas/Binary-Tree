#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char item;
    struct _node* left;
    struct _node* right;
}t_node;

t_node* create_node(char item){
    t_node* root = malloc(sizeof(t_node));
    root->item = item;
    root->left = NULL;
    root->right = NULL;
    return root;
}

/*
// Função que remove vírgulas de uma string, criando uma nova versão sem vírgulas
char* removeCommas(const char* str) {
    int length = 0;
    const char *p = str;
    while (*p) {
        length++;
        p++;
    }

    char *noCommas = malloc(length + 1);
    if (noCommas == NULL) return NULL;

    char *dest = noCommas;
    while (*str) {
        if (*str != ',') {
            *dest++ = *str;
        }
        str++;
    }
    *dest = '\0';
    return noCommas;
}


// Função para verificar se a entrada é válida
int isValidInput(const char *str) {
    int balance = 0;  // Balanceamento de parênteses
    int expectingSubtree = 0;  // Indica se estamos esperando uma subárvore

    while (*str) {
        if (*str == '(') {
            balance++;
            str++;
            if (!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z') && *str != ')') {
                return 0; // Após '(' deve vir uma letra ou ser um parêntese vazio ')'
            }
            expectingSubtree = 1;
        } else if (*str == ')') {
            balance--;
            if (balance < 0) {
                return 0;
            }
            str++;
            expectingSubtree = 0;
        } else if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            str++;
            if (*str != '(' && *str != ')') {
                return 0; // Após uma letra, deve vir um '(' iniciando a subárvore ou um ')' fechando
            }
        } else {
            return 0; // Caracteres inválidos
        }
    }

    return balance == 0;  // Todos os parênteses devem estar balanceados ao final
}

int countParameters(char *str){
    int balance = 1;

    while (*str != '\0'){
        if (*str == '('){
            balance++;
        } else if (*str == ')'){
            balance--;
            if (balance < 0){
                return 0;
            }
        }
    }
    return balance;
}

int confereCommas(char *str){
    int commas = 0;
    while (*str != '\0'){
        if (*str == ','){
            commas++;
        } else if (*str == '('){
            commas--;
        }
    }
    return commas;
}

int isValidInput(char *str){
    int balance = countParameters(str);
    if (balance != 1){
        return 0;
    }
    int commas = confereCommas(str);
    if (commas != -1){
        return 0;
    }
    while (*str == '\0'){

    }
}
*/

int isValidInput(const char *str) {
    int balance = 0; // Used to check the balance of parentheses
    int expectingLeftChild = 0; // Flag to check if we're expecting a left child (after a node character)
    int nodeCount = 0; // Used to count nodes and ensure there are pairs of parentheses after each node

    while (*str != '\0') {
        if (*str == '(') {
            balance++;
            expectingLeftChild = 1; // After an opening '(', we should expect a left child
            nodeCount = 0; // Reset node count inside new subtree
        } else if (*str == ')') {
            balance--;
            if (balance < 0 || nodeCount == 1) {
                return 0; // Too many closing ')' or there was only one child for a node
            }
            expectingLeftChild = 0; // Reset flag after closing a subtree
        } else if (isalpha((unsigned char)*str)) {
            if (!expectingLeftChild || nodeCount > 0) {
                return 0; // Node characters should only come after an opening '(' or a ',' between children
            }
            nodeCount++; // Increase the node count
        } else if (*str == ',') {
            if (!expectingLeftChild || nodeCount != 1) {
                return 0; // Commas should only come after a left child has been accounted for
            }
            nodeCount = 0; // Reset node count after a comma, expecting a right child
        } else if (!isspace((unsigned char)*str)) { // Ignore whitespace
            return 0; // Invalid character
        }
        str++; // Move to the next character
    }

    return balance == 0; // Check if all parentheses are closed
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
}

void preOrder(t_node *root)
{
    if (root)
    {
        printf("%c\t", root->item);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(t_node *root){
    if (root)
    {
        inOrder(root->left);
        printf("%c\t", root->item);
        inOrder(root->right);
    }
}

void postOrder(t_node *root){
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c\t", root->item);
    }
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

int main(){
    /*
    Valid:
    (A,(B,(D,(H,(),()),()),(E,(),())),(C,(F,(),()),(G,(I,(),()),(J,(),()))))
    (A,(B,(),()),(C,(F,(),()),()))
    (A,(B,(),()),())
    (B,(),())
    Invalid:
    (A,(B,()),(C,(F,(),()),()))
    */
    char *treeStr = "(A,(B,(),()),())";

    if (isValidInput(treeStr)){
        t_node *root = createBinaryTree(&treeStr);
        printf("Pre-Order: \n");
        preOrder(root);
        printf("\n");

        printf("In-Order: \n");
        inOrder(root);
        printf("\n");

        printf("Post-Order: \n");
        postOrder(root);

        freeTree(root);
    } else {
        printf("invalid");
    }
    return 0;
}

