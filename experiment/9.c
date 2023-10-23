#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // For undirected graphs
}

void printGraph(struct Graph* graph) {
    printf("THE ADJACENCY MATRIX IS\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf(" %d", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void DFS(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            printf("%d ", i + 1);
            DFS(graph, i, visited);
        }
    }
}

int main() {
    int V;
    printf("ENTER THE NUMBER VERTICES: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0: ", i + 1, j + 1);
            int value;
            scanf("%d", &value);
            if (value == 1) {
                addEdge(graph, i, j);
            }
        }
    }

    printGraph(graph);

    char cont;
    do {
        int choice, sourceVertex;
        printf("\nENTER YOUR CHOICE (1 for DFS): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("ENTER THE SOURCE VERTEX: ");
            scanf("%d", &sourceVertex);
            printf("%d ", sourceVertex);
            int visited[V];
            for (int i = 0; i < V; i++) {
                visited[i] = 0;
            }
            DFS(graph, sourceVertex - 1, visited);
            printf("\n");
        } else {
            printf("Invalid choice.\n");
        }

        printf("DO YOU WANT TO CONTINUE (Y/N) ? ");
        scanf(" %c", &cont);

    } while (cont == 'Y' || cont == 'y');

    return 0;
}

