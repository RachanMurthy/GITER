#include <stdio.h>
#define INFINITY 999

int prim(int cost[10][10], int source, int n) {
    int i, j, sum = 0, MST[10];
    int Key[10], Parent[10];
    int min, u, v;

    // Initialize vertices
    for (i = 1; i <= n; i++) {
        Parent[i] = source;
        MST[i] = 0; 
        Key[i] = cost[source][i];
    }
    MST[source] = 1;

    // Construct MST
    for (i = 1; i < n; i++) {
        min = INFINITY;
        for (j = 1; j <= n; j++) {
            if (!MST[j] && Key[j] < min) {
                min = Key[j];
                u = j;
            }
        }
        MST[u] = 1;
        sum += Key[u];
        printf("\n%d -> %d", Parent[u], u);

        for (v = 1; v <= n; v++) {
            if (!MST[v] && cost[u][v] < Key[v]) {
                Key[v] = cost[u][v];
                Parent[v] = u;
            }
        }
    }
    return sum;
}

int main() {
    int a[10][10], n, i, j, m, source;

    // Input number of vertices
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);

    // Input cost matrix
    printf("\nEnter the cost matrix:\n 0-self loop and 999-no edge:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    // Input source vertex
    printf("\nEnter the source:\n");
    scanf("%d", &source);

    // Compute MST using Prim's algorithm
    m = prim(a, source, n);

    // Output the cost of the MST
    printf("\nThe cost of the spanning tree = %d", m);

    return 0;
}
