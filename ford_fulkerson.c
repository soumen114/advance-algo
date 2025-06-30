#include <stdio.h>
#include <string.h>
#include <limits.h>

#define V 6  // number of vertices (you can change it)

// DFS to find a path from s to t in residual graph
int dfs(int rGraph[V][V], int s, int t, int parent[]) {
    int visited[V];
    memset(visited, 0, sizeof(visited));

    int stack[V], top = -1;
    stack[++top] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (top >= 0) {
        int u = stack[top--];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = 1;
                if (v == t)
                    return 1; // found path
                stack[++top] = v;
            }
        }
    }
    return 0; // no path found
}

int fordFulkerson(int capacity[V][V], int s, int t) {
    int flow[V][V];  // flow matrix
    memset(flow, 0, sizeof(flow)); // (u,v).f ← 0

    int rGraph[V][V];  // residual graph Gf
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = capacity[u][v];

    int parent[V];  // to store augmenting path
    int max_flow = 0;

    // while there exists a path p from s to t in residual network Gf
    while (dfs(rGraph, s, t, parent)) {
        // cf(p) ← min { cf(u, v) | (u, v) is in p }
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }

        // for each edge (u,v) in p
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];

            // if (u,v) ∈ G.E (i.e., original capacity > 0)
            if (capacity[u][v] > 0) {
                flow[u][v] += path_flow; // (u,v).f ← (u,v).f + cf(p)
            } else {
                // else (v,u).f ← (v,u).f - cf(p)
                flow[v][u] -= path_flow;
            }

            // update residual capacities
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    // Example capacity matrix (input)
    int capacity[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    printf("Input capacity matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%3d ", capacity[i][j]);
        printf("\n");
    }

    int maxFlow = fordFulkerson(capacity, source, sink);

    printf("\nThe maximum possible flow is: %d\n", maxFlow);

    return 0;
}
