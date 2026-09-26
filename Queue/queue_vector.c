#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* create_queue(int *size);
void delete_queue(int **queue);
void enqueue(int **queue, int element, int *size);
void dequeue(int **queue, int *size);
void print_queue(int *queue, int *size);

int main() {
    int menu = -1, size = 0;
    int *queue;

    while (menu != 0) {
        printf("==== Queue ====\n"
               "Informe uma opção:\n"
               "0) Sair do programa\n"
               "1) Imprimir fila\n"
               "2) Adicionar um elemento\n"
               "3) Remover um elemento\n"
               "4) Deletar a lista\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                delete_queue(&queue);
                break;
            case 1:
                print_queue(queue, &size);
                break;
            case 2:
                int element;
                printf("Informe o elemento a ser adicionado à fila: ");
                scanf("%i", &element);

                enqueue(&queue, element, &size);
                break;
            case 3:
                dequeue(&queue, &size);
                break;
            case 4:
                delete_queue(&queue);
                break;
        }
    }

    return 0;
}

int* create_queue(int *size) {
    int *queue = (int*)malloc(sizeof(int));
    //Checking if the memory allocation succeded
    if (queue == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    *size = 1;

    return queue;
}

void delete_queue(int **queue) {
    free(*queue);
    *queue = NULL;
}

void enqueue(int **queue, int element, int *size) {
    //Checking if a queue was not created
    if (*queue == NULL) {
        //Creating a queue
        *queue = create_queue(size);
        //Adding the first element in the queue
        (*queue)[0] = element;
    }
    else {
        (*size)++;
        //Reallocating memory for the queue
        int *temp = (int*)realloc(*queue, (*size)*sizeof(int));

        //Checking if the temporary allocation worked
        if (temp == NULL) {
            printf("Erro ao alocar memória temporária.\n");
            return;
        }
        else {
            //Inserting the new element
            *queue = temp;
            (*queue)[*size-1] = element;
        }
    }
}

void dequeue(int **queue, int *size) {
    //Checking if the queue is not empty
    if (*size > 0 || *queue != NULL) {
        //Removing the first element in the queue
        for (int i = 1; i < *size; i++) {
            (*queue)[i-1] = (*queue)[i];
        }
        //Reducing the queue size
        (*size)--;
        //Checking if the queue is empty
        if ((*size) == 0) {
            free(*queue);
            *queue = NULL;
            return;
        }
        //If the queue is not empty, it will be reduced
        int *temp = (int*)realloc(*queue, (*size)*sizeof(int));

        if (temp != NULL) {
            *queue = temp;
        }
        else {
            return;
        }
    }
    else {
        printf("Não foi possível remover um elemento, a fila está vazia.\n");
    }
}

void print_queue(int *queue, int *size) {
    //Checking if there's a Queue
    if (queue == NULL) {
        printf("Não há uma fila criada.\n");
        return;
    }

    printf("--- Queue ---\n");
    for (int i = 0; i < *size; i++) {
        printf("-[%i]-", queue[i]);
    }
    printf("\n");

    printf("-------------\nHead: %i\nTail: %i\n", queue[0], queue[*size-1]);
}