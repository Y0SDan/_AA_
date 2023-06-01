#include <stdio.h>
#define MAX 100

void dfs(int v);
int g[MAX][MAX], visited[MAX], n;

int main() {
    int i, j;
    printf("Ingrese el número de vértices: ");
    scanf("%d", &n);
    printf("\nIngrese la matriz de adyacencia del grafo:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nEl recorrido en profundidad es: ");
    dfs(0);
    return 0;
}

void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (!visited[i] && g[v][i])
            dfs(i);
}
