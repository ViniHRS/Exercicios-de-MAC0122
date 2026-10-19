#include <stdio.h>
#include <stdlib.h>

// Struct for Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* create_node(int data);
void insert(Node **root, int data);
void search(Node *root, int data);
void in_order(Node *root);
void pre_order(Node *root);
void post_order(Node *root);
void free_tree(Node *root);

int main() {
    Node *root = NULL;
    int menu = -1, data;

    //Menu for using the program
    while (menu != 0) {
        printf("\n=== Binary Tree Program ===\n");
        printf("Escolha uma opção:\n"
               "1) Inserir um elemento\n"
               "2) Procurar um elemento\n"
               "3) Varredura em ordem\n"
               "4) Varredura pré ordem\n"
               "5) Varredura pós ordem\n"
               "6) Apagar árvore\n"
               "0) Sair do programa\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                free_tree(root);
                break;
            case 1:
                printf("Informe o elemento a ser inserido na árvore: ");
                scanf("%i", &data);

                insert(&root, data);
                break;
            case 2:
                printf("Informe o elemento a ser procurado: ");
                scanf("%i", &data);

                search(root, data);
                break;
            case 3:
                in_order(root);
                break;
            case 4:
                pre_order(root);
                break;
            case 5:
                post_order(root);
                break;
            default:
                printf("Informe uma opção válida\n");
                break;
        }
    }

    return 0;
}

Node* create_node(int data) {
    //Creating a Node and checking if the memory allocation succeded
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para um novo nó\n");
        exit(1);
    }
    //Initializing new node
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(Node **root, int data) {
    //Checking if the tree is empty (root == NULL)
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    //If the tree is not empty, it should use recursion to insert the new element in the right position
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}

void search(Node *root, int data) {
    //If the recursion gets root == NULL, the element isn't in the tree
    if (root == NULL) {
        printf("Elemento %i não encontrado na árvore\n", data);
        return;
    }
    //If the recursion find the element
    if (root->data == data) {
        printf("Elemento %i foi encontrado na árvore\n", data);
        return;
    }
    //Going through the tree
    if (data < root->data) {
        search(root->left, data);
    }
    else {
        search(root->right, data);
    }
}

void in_order(Node *root) {
    //Order: left->root->right 
    if (root != NULL) {
        in_order(root->left);
        printf("-[%i]-", root->data);
        in_order(root->right);
    }
}

void pre_order(Node *root) {
    //Order: root->left->right
    if (root != NULL) {
        printf("-[%i]-", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(Node *root) {
    //Order: left->right->root
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        printf("-[%i]-", root->data);
    }
}

void free_tree(Node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}