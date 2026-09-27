#include <stdio.h>
#include <stdlib.h>

// Struct for Stack
typedef struct Stack {
    int *data;
    int top;
    int size;
} Stack;

// Function prototypes
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
        }
    }

    return 0;
}

Stack* create_stack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    //Checking if the stack wasn't created succesfully
    if (stack == NULL) {
        printf("Erro ao criar a pilha\n");
        exit(1);
    }
    //Initializing stack
    stack->data = NULL;
    stack->size = 0;
    stack->top = -1; //Indicates that stack is empty

    return stack;
}

int is_empty(Stack *stack) {
    return (stack->top == -1);
}

void push(Stack *stack, int data) {
    //Checking if the stack is empty
    if (is_empty(stack)) {
        //If it's empty, must allocate memory for the first element
        stack->data = (int*)malloc(sizeof(int));

        if (stack->data == NULL) {
            printf("Erro ao alocar memória para os dados da pilha\n");
            return;
        }
        else {
            //If the memory allocation succeded, algorithm changes stack top, size and data[0]
            stack->top = 0;
            stack->size = 1;
            stack->data[0] = data;
        }
    }
    else {
        //Allocating a temporary array
        int *temp = (int*)realloc(stack->data, (stack->size + 1)*sizeof(int));

        if (temp == NULL) {
            printf("Erro ao realocar memória para os dados da pilha\n");
            return;
        }
        else {
            //Pushing the new data in the stack
            stack->data = temp;
            stack->size++;
            stack->top++;
            stack->data[stack->top] = data;
        }
    }
}

void pop(Stack *stack) {
    if (stack->top == -1) {
        printf("A pilha está vazia\n");
        return;
    }
    else if (stack->top == 0) {
        //If top == 0, we must free the stack data and reduce top to -1
        free(stack->data);
        stack->data = NULL;
        stack->top--;
        stack->size--;
    }
    else {
        //Creating a temporary array
        int *temp = (int*)realloc(stack->data, (stack->size - 1)*sizeof(int));

        if (temp == NULL) {
            printf("Erro ao realocar memória dos dados da pilha\n");
            return;
        }
        else {
            //Eliminating the top element and reducing stack->data size
            stack->data = temp;
            stack->size--;
            stack->top--;
        }
    }
}

void peek(Stack *stack) {
    if (stack->top == -1) {
        printf("A pilha está vazia\n");
    }
    else {
        printf("Elemento no topo: %i\n", stack->data[stack->top]);
    }
}

void print_stack(Stack *stack) {
    if (stack->top == -1) {
        printf("A pilha está vazia\n");
    }
    else {
        printf("---[ Pilha ]---\n");
        for (int i = 0; i <= stack->top; i++) {
            printf("-[%i]-", stack->data[i]);
        }
        printf("\n");
    }
}

void free_stack_data(Stack *stack) {
    //Checking if the stack is empty
    if (stack == NULL) {
        printf("Não há uma pilha criada\n");
        return;
    }
    //Checking if stack data is empty
    else if (stack->data == NULL || stack->top == -1) {
        printf("A pilha está vazia\n");
    }
    else {
        free(stack->data);
        stack->data = NULL;
        stack->top = -1;
        stack->size = 0;
    }
}