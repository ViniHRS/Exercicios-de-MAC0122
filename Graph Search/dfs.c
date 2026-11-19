#include <stdio.h>
#include <stdlib.h>

#define N 5

// Function prototypes
int* create_visited();
void DFS(int graph[N][N], int *visited, int current_vertex);

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
    // Creating visited vertices array
    int *visited = create_visited();

    DFS(graph, visited, 0);

    printf("\n");

    return 0;
}

// Function declarations
int* create_visited() {
    // Allocating memory for visited vertices
    int *visited = (int*)malloc(N*sizeof(int));

    // Checking if the memory allocations succeeded
    if (visited == NULL) {
        printf("Erro ao alocar memória para o vetor de vértices visitados\n");
        exit(1);
    }
    // Initializing visited array
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    return visited;
}

void DFS(int graph[N][N], int *visited, int current_vertex) {
    // Visiting the current vertex
    visited[current_vertex] = 1;
    printf("v[%i] ", current_vertex);

    // Going through each column in current_vertex
    for (int i = 0; i < N; i++) {
        /*
         *  Checking if there's a connections between vertex i
         *  and current_vertex and if the i vertex was not visited
         */
        if (graph[current_vertex][i] == 1 && visited[i] == 0) {
            // Visiting vertex i and it's neighbors
            DFS(graph, visited, i);
        }
    }
}