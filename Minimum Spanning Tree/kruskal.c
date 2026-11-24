#include <stdio.h>
#include <stdlib.h>

// Struct for edge
typedef struct {
    int u, v;
    int weight;
} Edge;

// Function Prototypes
int find(int root[], int x);
int unite(int root[], int tree_size[], int u, int v);
int comparing_edges(const void *a, const void *b);
void kruskal(Edge edge[], int n_vertices, int n_edges);

int main() {
    // Declaring a vector of edges
    Edge edge[8] = {
        {0, 1, 1},
        {1, 2, 2},
        {0, 2, 3},
        {1, 3, 4},
        {2, 3, 5},
        {2, 4, 6},
        {3, 4, 7},
        {1, 4, 8}
    };

    // Kruskal function
    kruskal(edge, 5, 8);
    
    return 0;
}

// Function Declarations
int find(int root[], int x) {
    // If root[x] != x, x is not a root. Then, we must find the root from x set
    if (root[x] != x) {
        // This guarantees that all elements from the same set points to the root
        root[x] = find(root, root[x]);
    }
    // When root[x] == x, it means that the set root was found
    return root[x];
}

int unite(int root[], int tree_size[], int u, int v) {
    int root_u = find(root, u);
    int root_v = find(root, v);

    // Checking if u and v belongs to the same set
    if (root_u == root_v) {
        return 0;
    }
    // In order to guarantee an eficient find, we must
    // make the smaller tree point to the bigger tree
    if (tree_size[root_u] < tree_size[root_v]) {
        int swapp = root_u;
        root_u = root_v;
        root_v = swapp;
        // Now, tree_size[root_v] < tree_size[root_u]
    }
    // Uniting the trees
    root[root_v] = root_u;
    tree_size[root_u] += tree_size[root_v];
    // Union succeeded
    return 1;
}

int comparing_edges(const void *a, const void *b) {
    const Edge *edge_a = a;
    const Edge *edge_b = b;

    if (edge_a->weight < edge_b->weight) {
        return -1;
    }
    else if (edge_a->weight > edge_b->weight) {
        return 1;
    }
    else {
        return 0;
    }
}

void kruskal(Edge edge[], int n_vertices, int n_edges) {
    int root[n_vertices];
    int tree_size[n_vertices];

    // Initializing Union-Find
    for (int i = 0; i < n_vertices; i++) {
        root[i] = i;
        tree_size[i] = 1;
    }

    // Sorting the edges by its priority
    qsort(edge, n_edges, sizeof(Edge), comparing_edges);

    int mst_edges = 0;
    // Loop to generate the Minimum Spanning Tree
    // Going through all the edges until it's made (n_vertices - 1) connections
    for (int i =0; i < n_edges && mst_edges < n_vertices - 1; i++) {
        int u = edge[i].u;
        int v = edge[i].v;

        // Uniting and printing u and v
        if (unite(root, tree_size, u, v)) {
            printf("%i -- %i (weight %i)\n", u, v, edge[i].weight);

            mst_edges++;
        }
    }
    // Result
    if (mst_edges == n_vertices-1) {
        printf("\nMinimum Spanning Tree generated\n");
    }
    else {
        printf("\nThere is not a Minimum Spanning Tree\n");
    }
}