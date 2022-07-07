// Adjacency Matrix representation in C

#include <stdio.h>
#define V 5

// Initialize the matrix to zero
void init(int arr[V][V]) {
  int i, j;
  for (i = 1; i <= V; i++)
    for (j = 1; j <= V; j++)
      arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[V][V], int i, int j) {
  arr[i][j] = 1;
 
}

// Print the matrix
void printAdjMatrix(int arr[V][V]) {
  int i, j;

  for (i = 1; i <= V; i++) {
    printf("%d: ", i);
    for (j = 1; j <= V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 1, 4);
  addEdge(adjMatrix, 2, 1);
  addEdge(adjMatrix, 2, 4);
  addEdge(adjMatrix, 3, 5);
  addEdge(adjMatrix, 4, 1);
  addEdge(adjMatrix, 4, 3);
  addEdge(adjMatrix, 4, 5);
  addEdge(adjMatrix, 5, 1);
  addEdge(adjMatrix, 5, 3);
  addEdge(adjMatrix, 5, 4);

  printAdjMatrix(adjMatrix);

  return 0;
}




	// addEdge(graph, 1, 2);
	// addEdge(graph, 1, 4);
	// addEdge(graph, 2, 1);
	// addEdge(graph, 2, 4);
	// addEdge(graph, 3, 5);
    // addEdge(graph, 4, 1);
	// addEdge(graph, 4, 3);
	// addEdge(graph, 4, 5);
	// addEdge(graph, 5, 1);
	// addEdge(graph, 5, 3);
    // addEdge(graph, 5, 4);