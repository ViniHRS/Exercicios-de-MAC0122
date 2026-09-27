#include <stdio.h>
#include <stdlib.h>

// Struct for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struct for a queue
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// Function Prototypes
Queue* create_queue();
int is_empty(Queue *queue);
void enqueue(Queue *queue, int data);
void dequeue(Queue *queue);
void delete_queue(Queue *queue);
void print_queue(Queue *queue);

int main() {
    int menu = -1;
    //Creating the queue
    Queue *queue = create_queue();

    while (menu != 0) {
        printf("==== Queue ====\n"
               "Informe uma opção:\n"
               "0) Sair do programa\n"
               "1) Imprimir fila\n"
               "2) Adicionar um elemento\n"
               "3) Remover um elemento\n"
               "Opção: ");
        scanf("%i", &menu);

        switch (menu) {
            case 0:
                delete_queue(queue);
                break;
            case 1:
                print_queue(queue);
                break;
            case 2:
                int element;
                printf("Informe o elemento a ser adicionado à fila: ");
                scanf("%i", &element);

                enqueue(queue, element);
                break;
            case 3:
                dequeue(queue);
                break;
        }
    }

    return 0;
}

// Functions
Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    //Checking if the memory allocation worked
    if (queue == NULL) {
        printf("Falha ao alocar memória para a fila\n");
        exit(1);
    }
    //Setting head and tail as NULL because there isn't any element
    //in the queue yet
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

int is_empty(Queue *queue) {
    if (queue->head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(Queue *queue, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    //Checking if the memory allocation worked
    if (new_node == NULL) {
        printf("Falha ao alocar memória para um novo nó\n");
        return;
    }
    //Setting new_node datas
    new_node->data = data;
    new_node->next = NULL;

    //Checking if the queue is empty or not
    if (queue->head == NULL) {
        //If it's empty, new_node becomes the head and the tail
        queue->head = new_node;
        queue->tail = new_node;
        return;
    }
    else {
        //If it's not empty, tail->next receives the new_node address
        //and then new_node becomes the new tail
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

void dequeue(Queue *queue) {
    if (queue->head == NULL) {
        printf("Erro ao remover um elemento, a fila está vazia\n");
        return;
    }
    else {
        Node *temp = queue->head;           //Creating a temporary node to remove the old head later        
        queue->head = queue->head->next;    //Moving the head to the next node

        //Checking if the queue is empty
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        free(temp); //Removing the old head
    }
}

void delete_queue(Queue *queue) {
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void print_queue(Queue *queue) {
    if (queue == NULL) {
        printf("Não há fila criada\n");
        return;
    }
    else {
        if (queue->head == NULL) {
            printf("A fila está vazia\n");
            return;
        }
        else {
            Node *current_node = queue->head;

            printf("--- Queue ---\n");
            while (current_node != NULL) {
                printf("-[%i]-", current_node->data);
                current_node = current_node->next;
            }
            printf("\n");
        }
    }
}