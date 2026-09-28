#include <stdio.h>
#include <stdlib.h>

// Struct for Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struct for Stack
typedef struct Stack {
    Node *top;
} Stack;

// Function prototypes
Node* create_node(int data);
Stack* create_stack();
int is_empty(Stack *stack);
void push(Stack *stack, int data);
void pop(Stack *stack);
void peek(Stack *stack);
void print_stack(Stack *stack);
void free_stack_data(Stack *stack);

int main() {
    int menu = -1;
    Stack *stack = create_stack();

    //Menu for controlling the program
    while (menu != 0) {
        printf("==== Stack ====\n"
               "Escolha uma opção:\n"
               "0) Sair do programa\n"
               "1) Empilhar\n"
               "2) Desempilhar\n"
               "3) Ver topo\n"
               "4) Imprimir pilha\n"
               "5) Deletar os dados da pilha\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                free_stack_data(stack);
                free(stack);
                break;
            case 1:
                int data;
                printf("Informe o elemento a ser empilhado: ");
                scanf("%i", &data);

                push(stack, data);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            case 4:
                print_stack(stack);
                break;
            case 5:
                free_stack_data(stack);
                break;
            default:
                printf("Opção inválida, tente novamente\n");
                break;
        }
    }

    return 0;
}

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    //Checking if the memory allocation succeded
    if (new_node == NULL) {
        printf("Erro ao criar um novo nó\n");
        exit(1);
    }
    //Initializing new_node
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

Stack* create_stack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    //Checking if the memory allocation succeded
    if (stack == NULL) {
        printf("Erro ao criar a pilha\n");
        exit(1);
    }
    //Initializing top node (empty stack)
    stack->top = NULL;

    return stack;
}

int is_empty(Stack *stack) {
    return (stack->top == NULL);
}

void push(Stack *stack, int data) {
    //Creating a new node
    Node *new_node = create_node(data);
    //Checking if the stack is empty
    if (is_empty(stack)) {
        //If the stack is empty, the first element becomes
        //the top and points to NULL
        stack->top = new_node;
    }
    else {
        //If the stack is not empty, the new element becomes
        //the top and points to the former top
        new_node->next = stack->top;
        stack->top = new_node;
    }
}

void pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Não foi possível desempilhar, a pilha está vazia\n");
        return;
    }
    else {
        //Creating a temporary variable to receive the former top
        //to free it later
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

void peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("A pilha está vazia\n");
    }
    else {
        printf("Elemento do topo: %i\n", stack->top->data);
    }
}

void print_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("A pilha está vazia\n");
    }
    else {
        //Creating a node to help the print
        Node *current_node = stack->top;
        printf("----[ Pilha ]----\n");
        //While loop to print the stack
        while (current_node != NULL) {
            printf("-[%i]-", current_node->data);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

void free_stack_data(Stack *stack) {
    if (is_empty(stack)) {
        printf("A pilha já está vazia\n");
    }
    else {
        //Going through all the stack and deleting each node
        Node *current_node = stack->top;
        while (current_node != NULL) {
            Node *temp = current_node;
            current_node = current_node->next;
            free(temp);
        }
        stack->top = NULL;
    }
}