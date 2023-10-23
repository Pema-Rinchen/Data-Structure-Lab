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
    adjMatrix[endNode][startNode] = weight;
}

void deleteEdge(int startNode, int endNode) {
    adjMatrix[startNode][endNode] = INF;
    adjMatrix[endNode][startNode] = INF;
}

void printMatrix(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == INF) {
                printf("0 ");
            } else {
                printf("%d ", adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numNodes = MAX_NODES;

    initializeMatrix(numNodes);

    // Adding edges to the graph with weights
    addEdge(0, 1, 2);
    addEdge(0, 2, 1);
    addEdge(1, 2, 3);
    addEdge(1, 3, 4);
    addEdge(1, 4, 5);
    addEdge(2, 4, 2);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an edge\n");
        printf("2. Delete an edge\n");
        printf("3. Print the adjacency matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int startNode, endNode, weight;
        switch (choice) {
            case 1:
                printf("Enter start node, end node, and weight: ");
                scanf("%d %d %d", &startNode, &endNode, &weight);
                addEdge(startNode, endNode, weight);
                break;
            case 2:
                printf("Enter start node and end node to delete: ");
                scanf("%d %d", &startNode, &endNode);
                deleteEdge(startNode, endNode);
                break;
            case 3:
                printMatrix(numNodes);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
