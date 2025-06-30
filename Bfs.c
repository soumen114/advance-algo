#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[MAX], dist[MAX], parent[MAX];
int adj[MAX][MAX];
int queue[MAX], front = 0, rear = -1;

// Queue operations
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

// BFS function
void BFS(int G[MAX][MAX], int n, int s) {
    for (int u = 0; u < n; u++) {
        if (u != s) {
            color[u] = WHITE;
            dist[u] = -1;         // α means unknown or infinite distance
            parent[u] = -1;       // NIL
        }
    }

    color[s] = GRAY;
    dist[s] = 0;
    parent[s] = -1;

    front = 0;
    rear = -1;
    enqueue(s);

    while (front <= rear) {
        int u = dequeue();
        for (int v = 0; v < n; v++) {
            if (G[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                enqueue(v);
            }
        }
        color[u] = BLACK;
    }
}

// Print distances
void print_distances(int n) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int n, e, u, v, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    BFS(adj, n, source);
    print_distances(n);

    return 0;
}
