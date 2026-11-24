#include <stdio.h>
#include <limits.h>

#define INF (LLONG_MAX / 4)

// Function Prototypes
int get_vertex(long long int dist[], int visited[], int n);
void dijkstra(int n, long long int graph[n][n], int origin);
void print_path(int v, int father[]);

int main() {
    // Declaring a graph to be tested
    long long int graph[5][5] = {
        {INF,   4,   1, INF, INF}, // v[0]
        {  4, INF,   2,   1,   8}, // v[1]
        {  1,   2, INF,   5, INF}, // v[2]
        {INF,   1,   5, INF,   3}, // v[3]
        {INF,   8, INF,   3, INF}  // v[4]
    };

    // Executing Dijkstra algorithm
    dijkstra(5, graph, 0);

    printf("\n");

    return 0;
}

// Function Declarations
int get_vertex(long long int dist[], int visited[], int n) { // This function chooses the next vertex to be visited
    // Initializing the exploration
    long long int shortest = INF;
    int index = -1;

    for (int i = 0; i < n; i++) {
        // Checking if the vertex was visited and getting its shortest distance
        if (!visited[i] && dist[i] < shortest) {
            shortest = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int n, long long int graph[n][n], int origin) {
    // Algorithm parameters
    long long int dist[n];
    int visited[n];
    int father[n];

    // Initializing the graph
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        dist[i] = INF;
        father[i] = -1;
    }
    // Distance from the first vertex to itself
    dist[origin] = 0;

    // Executing the Dijkstra algorithm
    for (int i = 0; i < n; i++) {
        int u = get_vertex(dist, visited, n);

        // Checking if there's no more vertices to visit
        if (u == -1) {
            break;
        }
        // Visiting the next vertex
        visited[u] = 1;

        // Edge relaxation
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                // Checking if the new distance is shorter than the actual one
                if ((dist[u] + graph[u][v]) < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    father[v] = u;
                }
            } 
        }
    }

    // Printing the path followed by the algorithm
    print_path(n-1, father);
}

void print_path(int v, int father[]) {
    if (father[v] != -1) {
        print_path(father[v], father);
        printf(" -> ");
    }
    
    printf("v[%i]", v);
}