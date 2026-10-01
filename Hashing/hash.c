#include <stdio.h>
#include <stdlib.h>

// Struct for a Node
typedef struct Node {
    int key, data;
    struct Node* next;
} Node;

// Function prototypes
Node* create_node(int key, int data);
Node** create_hash_table();
int hash_function(int key);
void insert(Node **table, int key, int data);
void search(Node **table, int key);
void remove_node(Node **table, int key);
void clear_hash_table(Node **table);

int main() {
    int menu = -1, key, data;
    Node **hash_table = NULL;

    //Menu for controlling the program
    while (menu != 0) {
        printf("=== Hash Table Program ===\n");
        printf("Escolha uma opção:\n"
               "0) Sair do programa\n"
               "1) Criar uma tabela Hash\n"
               "2) Inserir um elemento na tabela\n"
               "3) Procurar um elemento pela chave\n"
               "4) Remover um elemento\n"
               "5) Limpar a tabela hash\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                clear_hash_table(hash_table);
                free(hash_table);
                break;
            case 1:
                if (hash_table != NULL) {
                    clear_hash_table(hash_table);
                    free(hash_table);
                }
                hash_table = create_hash_table();
                break;
            case 2:
                printf("Informe o elemento a ser inserido: ");
                scanf("%i", &data);

                printf("Informe a chave do elemento: ");
                scanf("%i", &key);

                insert(hash_table, key, data);
                break;
            case 3:
                printf("Informe a chave do elemento: ");
                scanf("%i", &key);
                
                search(hash_table, key);
                break;
            case 4:
                printf("Informe a chave do elemento a ser removido: ");
                scanf("%i", &key);

                remove_node(hash_table, key);
                break;
            case 5:
                clear_hash_table(hash_table);
                break;
            default:
                printf("Informe uma opção válida\n");
                break;
        }
    }
    return 0;
}

// Function declarations
Node* create_node(int key, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    //Checking if the memory allocations failed
    if (new_node == NULL) {
        printf("Erro ao criar um novo nó\n");
        exit(1);
    }
    //Initializing new_node
    new_node->key = key;
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Node** create_hash_table() {
    //Creating a hash table of 10 positions
    Node **table = (Node**)malloc(10*sizeof(Node*));
    if (table == NULL) {
        printf("Falha ao criar a tabela Hash\n");
        exit(1);
    }
    //Initializing the table
    for (int i = 0; i < 10; i++) {
        table[i] = NULL;
    }
    return table;
}

int hash_function(int key) {
    int index = key % 10;   //This hash function takes the remainder as an index
    //Correcting index value if key is negative
    if (index < 0) {
        index = -1*index;
    }

    return index;
}

void insert(Node **table, int key, int data) {
    if (table == NULL) {
        printf("A tabela não existe\n");
        return;
    }
    int index = hash_function(key);
    //Creating a new node
    Node *new_node = create_node(key, data);
    //Inserting the new node in hash table
    if (table[index] == NULL) {
        table[index] = new_node;
    }
    else {
        new_node->next = table[index];
        table[index] = new_node;
    }

    printf("Elemento inserido: %i\n"
           "Chave: %i\n"
           "Index: %i\n", data, key, index);
}

void search(Node **table, int key) {
    if (table == NULL) {
        printf("A tabela não existe\n");
        return;
    }
    int index = hash_function(key);
    //Creating a node to search for the element
    Node *current_node = table[index];
    while (current_node != NULL) {
        if (current_node->key == key) {
            printf("O elemento %i foi encontrado\n", current_node->data);
            return;
        }
        current_node = current_node->next;
    }
    //If any element was found
    printf("Não há um elemento de chave %i na tabela Hash\n", key);
}

void remove_node(Node **table, int key) {
    if (table == NULL) {
        printf("A tabela não existe\n");
        return;
    }
    int index = hash_function(key);
    int found = 0;
    //Searching the element
    Node *previous_node = NULL;
    Node *current_node = table[index];
    while (current_node != NULL) {
        if (current_node->key == key) {
            found = 1;
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    //Checking if the element was found
    if (!found) {
        printf("Não há elemento com a chave informada\n");
    }
    else {
        //Removing the element
        if (previous_node == NULL) {
            table[index] = current_node->next;
        }
        else {
            previous_node->next = current_node->next;
        }
        free(current_node);
        current_node = NULL;

        printf("Elemento removido com sucesso\n");
    }
}

void clear_hash_table(Node **table) {
    if (table == NULL) {
        printf("A tabela não existe\n");
        return;
    }
    else {
        for (int i = 0; i < 10; i++) {
            if (table[i] != NULL) {
                //Going through all the list and deleting each element
                Node *current_node = table[i];
                while (current_node != NULL) {
                    Node *temp = current_node;
                    current_node = current_node->next;
                    free(temp);
                }
                table[i] = NULL;
            }
        }
    }
}