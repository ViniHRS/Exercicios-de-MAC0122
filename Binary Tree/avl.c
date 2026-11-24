#include <stdio.h>
#include <stdlib.h>

// Struct for Node
typedef struct Node {
    int data;
    int height;

    struct Node* left;
    struct Node* right;
} Node;

// Function Prototypes
Node* create_node(int data);
int height(Node *node);
int max(int a, int b);
void update_height(Node *node);
int balance_factor(Node *node);
void right_rotation(Node **parent);
void left_rotation(Node **parent);
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
        printf("\n=== AVL Tree Program ===\n");
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

// Function Declarations
Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    // Checking if the new_node was created successfully
    if (new_node == NULL) {
        printf("Erro ao criar um novo nó\n");
        exit(1);
    }
    else {
        // Initializing the new node
        new_node->left = NULL;
        new_node->right = NULL;

        new_node->data = data;
        new_node->height = 1;

        return new_node;
    }
}

int height(Node *node) {
    // Get node's height
    if (node == NULL) {
        return 0;
    }
    else {
        return node->height;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

void update_height(Node *node) {
    // Updating a node's height by adding one
    node->height = 1 + max(height(node->left), height(node->right));
}

int balance_factor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int bf = height(node->left) - height(node->right);

        return bf;
    }
}

void right_rotation(Node **parent) {
    // Verifying if it's possible to make the rotation
    if (parent == NULL || *parent == NULL || (*parent)->left == NULL) {
        return;
    }

    Node *left_child = (*parent)->left;
    Node *subtree = left_child->right;

    // Making the rotation
    left_child->right = *parent;
    (*parent)->left = subtree;

    // Updating heights
    update_height(*parent);
    update_height(left_child);

    // Making the left child the new root in the tree
    *parent = left_child;
}

void left_rotation(Node **parent) {
    // Verifying if it's possible to make the rotation
    if (parent == NULL || *parent == NULL || (*parent)->right == NULL) {
        return;
    }

    Node *right_child = (*parent)->right;
    Node *subtree = right_child->left;

    // Making the rotation
    right_child->left = *parent;
    (*parent)->right = subtree;

    // Updating height
    update_height(*parent);
    update_height(right_child);

    // Making the right child the new root in the tree
    *parent = right_child;
}

void insert(Node **root, int data) {
    // Checking if the tree is empty
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    // If the tree is not empty, it should use recursion to insert the element
    if (data < (*root)->data) {
        insert(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        insert(&(*root)->right, data);
    }
    else {
        return;
    }

    // Updating the height and balancing the tree
    update_height(*root);

    int bf = balance_factor(*root);

    // Case LL: bf > 1 and data < (*root)->left->data
    if (bf > 1 && data < (*root)->left->data) {
        right_rotation(root);
    }
    // Case RR: bf < -1 and data > (*root)->right->data
    else if (bf < -1 && data > (*root)->right->data) {
        left_rotation(root);
    }
    // Case LR: bf > 1 and data > (*root)->right->data
    else if (bf > 1 && data > (*root)->right->data) {
        left_rotation(&((*root)->left));
        right_rotation(root);
    }
    // Case RL: bf < -1 and data < (*root)->right->data
    else if (bf < -1 && data < (*root)->right->data) {
        right_rotation(&(*root)->right);
        left_rotation(root);
    }
}

void search(Node *root, int data) {
    // If the recursion gets root == nULL
    if (root == NULL) {
        printf("Elemento %i não encontrado na árvore\n", data);
        return;
    }
    // If the recursion find the element
    if (root->data == data) {
        printf("Elemento %i encontrado na árvore\n", data);
        return;
    }
    // Loop to go through the tree with recursion
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