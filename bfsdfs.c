#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void init_graph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj_matrix[i][j] = 0;
        }
        visited[i] = 0;
    }
}

void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

void bfs(int start, int vertices) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];

        printf("%d ", cur);

        for (int i = 0; i < vertices; i++) {
            if (adj_matrix[cur][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void dfs(int start, int vertices) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++) {
        if (adj_matrix[start][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

int main() {
    int vertices, edges, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    init_graph(vertices);

    int  end;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &start, &end);
        add_edge(start, end);
    }

    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    printf("BFS: ");
    bfs(start, vertices);

    printf("\nDFS: ");
    dfs(start, vertices);

    return 0;
}
