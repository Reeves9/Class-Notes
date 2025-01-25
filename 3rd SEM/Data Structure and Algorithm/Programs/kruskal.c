#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to find the subset of an element
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function for qsort
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskal(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    struct Edge* result = (struct Edge*)malloc(V * sizeof(struct Edge));
    int numEdges = 0, i = 0;

    while (numEdges < V - 1 && i < E) {
        struct Edge currentEdge = edges[i++];
        int srcSubset = find(subsets, currentEdge.src);
        int destSubset = find(subsets, currentEdge.dest);

        if (srcSubset != destSubset) {
            result[numEdges++] = currentEdge;
            unionSets(subsets, srcSubset, destSubset);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; ++i) {
        printf("%d -- %d : %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
    free(result);
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));

    printf("Enter source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, V, E);

    free(edges);

    return 0;
}

