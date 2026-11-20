#include <stdio.h>

#define N 5

// Function prototypes
int* create_visited();
void BFS(int graph[N][N], int first);

int main() {
    // Graph to be explored in the algorithm
    // This graph will have only five vertices
    int graph[N][N] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    // BFS function to search in graph
    BFS(graph, 0);

    return 0;
}

// Function declarations
void BFS(int graph[N][N], int first) {
    // Array for visited vertices
    int visited[N] = {0};

    // Creating a queue
    int queue[N] = {-1};
    int head = 0, tail = 0;

    // Enqueuing and visiting the first vertex
    visited[first] = 1;
    queue[tail] = first;
    tail++;

    // Loop for visit the other vertices
    while (head < tail) {
        // Dequeuing the head
        int current_vertex = queue[head];
        head++;
        // Printing the visited vertex
        printf("v[%i] ", current_vertex);

        // Finding the neighbors and enqueuing them
        for (int i = 0; i < N; i++) {
            // It must enqueue a neighbor if it wasn't visited yet
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;

                queue[tail] = i;
                tail++;
            }
        }
    }
    printf("\n");
}