#include <stdio.h>
#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("Stack full\n");
        return;
    }
    stack[++top] = value;
}

void DFS(int start, int n) {
    visited[start] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[start][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }

    push(start);
}

int main() {
    int n, e, u, v, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Directed graph
    }

    printf("Enter any starting vertex: ");
    scanf("%d", &start);

    // DFS from start
    DFS(start, n);

    // Handle disconnected components
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            DFS(i, n);
        }
    }

    printf("\nTopological Order: ");
    while(top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
