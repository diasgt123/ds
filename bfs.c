#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Queue{
    int data[MAX];
    int front, rear;
};

int visited[MAX];
int n; // number of vertices
int adj[MAX][MAX]; // adjacency matrix

void BFS(int start){
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    q.data[++q.rear] = start;
    visited[start] = 1;
    while(q.front != q.rear){
        int vertex = q.data[++q.front];
        printf("%d ", vertex);

        for(int i=0; i<n; i++){
            if(adj[vertex][i] == 1 && visited[i] == 0){
                q.data[++q.rear] = i;
                visited[i] = 1;
            }
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

    BFS(startVertex);

    return 0;
}

