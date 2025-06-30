#include <stdio.h>

#define INF 99999  // A large number representing infinity
#define MAX 100    // Maximum number of vertices

void floydWarshall(int W[][MAX], int n) {
    int D_prev[MAX][MAX], D_curr[MAX][MAX];
    int k, i, j;

    // Step 1: D(0) = W
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            D_prev[i][j] = W[i][j];

    // Step 2: for k = 1 to n
    for (k = 0; k < n; k++) {
        // Step 3: create new matrix D(k)
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Step 6: d(k)_ij = min(d(k-1)_ij, d(k-1)_ik + d(k-1)_kj)
                if (D_prev[i][k] != INF && D_prev[k][j] != INF &&
                    D_prev[i][k] + D_prev[k][j] < D_prev[i][j])
                    D_curr[i][j] = D_prev[i][k] + D_prev[k][j];
                else
                    D_curr[i][j] = D_prev[i][j];
            }
        }

        // Copy D_curr to D_prev for next iteration
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                D_prev[i][j] = D_curr[i][j];
    }

    // Step 7: return D(n)
    printf("\nAll Pairs Shortest Paths Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D_prev[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", D_prev[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j, W[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &W[i][j]);

    floydWarshall(W, n);

    return 0;
}
