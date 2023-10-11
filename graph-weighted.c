#include <stdio.h>

#define MAX_NODES 5
#define INF 9999 // A large value to represent infinity

int adjMatrix[MAX_NODES][MAX_NODES];

void initializeMatrix(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        adjMatrix[i][i] = 0;
    }
}

void addEdge(int startNode, int endNode, int weight) {
    adjMatrix[startNode][endNode] = weight;
    adjMatrix[endNode][startNode] = weight; // Undirected graph
}

void printMatrix(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numNodes = MAX_NODES;
    int numEdges = 6; // Number of edges in the graph

    initializeMatrix(numNodes);

    // Adding edges to the graph with weights
    addEdge(0, 1, 2);
    addEdge(0, 2, 1);
    addEdge(1, 2, 3);
    addEdge(1, 3, 4);
    addEdge(1, 4, 5);
    addEdge(2, 4, 2);

    printMatrix(numNodes);

    return 0;
}
