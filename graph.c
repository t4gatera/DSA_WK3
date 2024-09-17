#include <stdio.h>
#include <stdlib.h>

// Define a structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Define a structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;  // pointer to the head of the list
};

// Define a structure for a graph
struct Graph {
    int V;                      // number of vertices
    struct AdjList* array;       // array of adjacency lists
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    
    // Create an array of adjacency lists
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head NULL
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest (add dest to src's adjacency list)
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to free memory allocated for the adjacency list nodes
void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; v++) {
        struct AdjListNode* adjList = graph->array[v].head;
        struct AdjListNode* temp;
        
        // Free the linked list for each vertex
        while (adjList) {
            temp = adjList;
            adjList = adjList->next;
            free(temp);  // Free each node
        }
    }

    // Free the array of adjacency lists
    free(graph->array);

    // Finally, free the graph structure itself
    free(graph);
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

