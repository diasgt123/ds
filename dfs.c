#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int visited[MAX];
int n; // number of vertices
int adj[MAX][MAX]; // adjacency matrix

void DFS(int vertex){
    visited[vertex] = 1;
    printf("%d ", vertex);

    for(int i=0; i<n; i++){
        if(adj[vertex][i] == 1 && visited[i] == 0){
            DFS(i);
        }
    }
}

int main(){
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    DFS(startVertex);

    return 0;
}

