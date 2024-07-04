#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

struct Edge {
  int src, dest, weight;
};

struct Graph {
  int num_vertices, num_edges;
  struct Edge edges[MAX_EDGES];
};

struct Subset {
  int parent, rank;
};

int find(struct Subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
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

int compare(const void* a, const void* b) {
  struct Edge* edge1 = (struct Edge*)a;
  struct Edge* edge2 = (struct Edge*)b;
  return edge1->weight - edge2->weight;
}

void kruskal(struct Graph graph) {
  int i, e = 0;
  struct Subset subsets[MAX_VERTICES];
  struct Edge result[MAX_VERTICES];

  for (i = 0; i < graph.num_vertices; i++) {
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  qsort(graph.edges, graph.num_edges, sizeof(graph.edges[0]), compare);

  i = 0;
  while (e < graph.num_vertices - 1 && i < graph.num_edges) {
    struct Edge next_edge = graph.edges[i++];

    int x = find(subsets, next_edge.src);
    int y = find(subsets, next_edge.dest);

    if (x != y) {
      result[e++] = next_edge;
      Union(subsets, x, y);
    }
  }

  printf("Edges in the MST:\n");
  for (i = 0; i < e; i++)
    printf("(%d, %d) weight=%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
  struct Graph graph = {
    6, // number of vertices
    8, // number of edges
    {
      {0, 1, 4},
      {0, 2, 3},
      {1, 2, 1},
      {1, 3, 2},
      {2, 3, 4},
      {2, 4, 5},
      {3, 4, 6},
      {3, 5, 7}
    }
  };

  kruskal(graph);

  return 0;
}
