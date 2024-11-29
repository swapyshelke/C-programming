#include <stdio.h>

// Function to print the DFS traversal of the graph
void DFS(int graph[10][10], int start, int visited[10]) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < 10; i++) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform DFS traversal for the given graph
void DFS_Traversal(int graph[10][10], int num_vertices) {
    int visited[10] = {0};

    for (int i = 0; i < num_vertices; i++) {
        if (visited[i] == 0) {
            DFS(graph, i, visited);
        }
    }
}

// Main function
int main() {
    int graph[10][10], num_vertices, num_edges, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex for DFS traversal: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    DFS_Traversal(graph, num_vertices);
    printf("\n");

    return 0;
}
