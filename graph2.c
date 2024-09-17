#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph
struct Graph {
    int V;            // Number of vertices
    int** adjMatrix;  // Adjacency matrix
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize all entries to 0
        }
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge to the matrix
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // Since it's an undirected graph
}

// Function to print the graph using adjacency matrix
void printGraph(struct Graph* graph) {
    printf("Adjacency Matrix of the Graph:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->adjMatrix[i]);  // Free each row of the matrix
    }
    free(graph->adjMatrix);        // Free the adjacency matrix
    free(graph);                   // Free the graph structure itself
}

// Main function to create the graph and test the above functions
int main() {
    int V = 5;  // Number of vertices in the graph
    struct Graph* graph = createGraph(V);

    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph
    printGraph(graph);

    // Free the graph memory
    freeGraph(graph);

    return 0;
}

