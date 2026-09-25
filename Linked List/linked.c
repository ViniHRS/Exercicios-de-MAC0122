#include <stdio.h>
#include <stdlib.h>

// Defining a Node structure
typedef struct Node {
    int data;           //Data stored
    struct Node* next;  //Pointer for the next node
} Node;

// Function prototypes
Node* create_node(int value);
void insert_in_beggining(Node** head, int value);
void insert_in_end(Node** head, int value);
void print_list(Node* head);
void free_list(Node** head);
void remove_element(Node** head, int number);

// Main function
int main() {
    Node* head = NULL;
    int menu = -1, data;

    //Menu for using the program
    while (menu != 0) {
        printf("=== Linked List Program ===\n");
        printf("Escolha uma opção:\n"
               "1) Inserir um nó no início\n"
               "2) Inserir um nó no final\n"
               "3) Imprimir lista\n"
               "4) Apagar lista\n"
               "5) Remover um elemento\n"
               "0) Sair do programa\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                free_list(&head);
                break;
            case 1:
                printf("Informe o elemento a ser inserido no início da lista: ");
                scanf("%i", &data);

                insert_in_beggining(&head, data);
                break;
            case 2:
                printf("Informe o elemento a ser inserido no final da lista: ");
                scanf("%i", &data);

                insert_in_end(&head, data);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                free_list(&head);
                break;
            case 5:
                printf("Informe o elemento a ser removido da lista: ");
                scanf("%i", &data);

                remove_element(&head, data);
                break;
        }
    }

    return 0;
}

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    //Checking if the memory allocation succeded
    if (new_node == NULL) {
        printf("Erro ao criar um novo nó.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;  //It doesn't receive the next element address yet

    return new_node;
}

//Inserting an element in the beggining (O(1) - Faster insertion)
void insert_in_beggining(Node** head, int value) {
    Node* new_node = create_node(value);

    //New node points to the previous head
    new_node->next = *head;

    //Head starts to point to the new node
    *head = new_node;
}

//Inserting an element in the end (O(n) - Lower insertion if there's no pointer for the tail)
void insert_in_end(Node** head, int value) {
    Node* new_node = create_node(value);

    //If the list is empty
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    //Searching for the last element
    Node* current_node = *head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    //Last node must point to the new node
    current_node->next = new_node;
}

void print_list(Node* head) {
    Node* current_node = head;

    printf("----[ Linked List ]----\n");
    while (current_node != NULL) {
        printf("[%i] -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("NULL\n");
}

void free_list(Node** head) {
    Node* current_node = *head;
    Node* next;

    while (current_node != NULL) {
        next = current_node->next;
        free(current_node);
        current_node = next;
    }
    *head = NULL;
}

void remove_element(Node** head, int number) {
    Node* current_node = *head;
    Node* prev_node = NULL;

    if (head == NULL || *head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    //Searching for the node that will be removed
    while (current_node != NULL && current_node->data != number) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    //If number wasn't found
    if (current_node == NULL) {
        printf("Elemento %i não encontrado.\n", number);
        return;
    }

    //Removing the element
    if (prev_node == NULL) {
        *head = current_node->next;
    }
    else {
        prev_node->next = current_node->next;
    }
    free(current_node);
}