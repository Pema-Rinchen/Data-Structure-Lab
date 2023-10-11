#include <stdio.h>

#define MAX_NODES 5

int adjMatrix[MAX_NODES][MAX_NODES];

void initializeMatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int startNode, int endNode) {
    adjMatrix[startNode][endNode] = 1;
}

void printMatrix(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes = MAX_NODES;
    int numEdges = 6; // Number of edges in the directed graph

    initializeMatrix(numNodes);

    // Adding directed edges to the graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);

    printMatrix(numNodes);

    return 0;
}
