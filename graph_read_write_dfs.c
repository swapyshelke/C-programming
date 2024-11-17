#include <stdio.h>

#define MAX_VERTICES 10  // Maximum number of vertices in the graph

void read_adjacency_matrix(int matrix[MAX_VERTICES][MAX_VERTICES], int *num_vertices) {
    printf("Enter the number of vertices: ");
    scanf("%d", num_vertices);
    
    printf("Enter the adjacency matrix (%d x %d):\n", *num_vertices, *num_vertices);
    for (int i = 0; i < *num_vertices; i++) {
        for (int j = 0; j < *num_vertices; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_graph(int matrix[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculate_degrees(int matrix[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    int in_degrees[MAX_VERTICES] = {0};
    int out_degrees[MAX_VERTICES] = {0};

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (matrix[i][j] == 1) {
                out_degrees[i]++;
                in_degrees[j]++;
            }
        }
    }

    printf("In-degrees: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", in_degrees[i]);
    }
    printf("\n");

    printf("Out-degrees: ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", out_degrees[i]);
    }
    printf("\n");
}

int main() {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;

    // Step 1: Read the adjacency matrix
    read_adjacency_matrix(matrix, &num_vertices);

    // Step 2: Display the graph
    display_graph(matrix, num_vertices);

    // Step 3: Calculate in-degrees and out-degrees
    calculate_degrees(matrix, num_vertices);

    return 0;
}
