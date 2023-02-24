#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Depth-First Search (DFS) function
void DFS(int graph[][MAX_SIZE], bool visited[], int vertex, int numVertices) {
    int i;
    visited[vertex] = true;
    printf("%d ", vertex);

    for (i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, visited, i, numVertices);
        }
    }
}

// Breadth-First Search (BFS) function
void BFS(int graph[][MAX_SIZE], bool visited[], int vertex, int numVertices) {
    int queue[MAX_SIZE], front = 0, rear = 0, i;
    visited[vertex] = true;
    printf("%d ", vertex);
    queue[rear++] = vertex;

    while (front < rear) {
        int current = queue[front++];
        for (i = 0; i < numVertices; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                queue[rear++] = i;
            }
        }
    }
}

// Main function
int main() {
    int numVertices, i, j;
    int graph[MAX_SIZE][MAX_SIZE];
    bool visited[MAX_SIZE];

    // Read number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Read adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to false
    for (i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Run DFS on the graph
    printf("DFS: ");
    DFS(graph, visited, 0, numVertices);
    printf("\n");

    // Reset visited array to false
    for (i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Run BFS on the graph
    printf("BFS: ");
    BFS(graph, visited, 0, numVertices);
    printf("\n");

    return 0;
}
