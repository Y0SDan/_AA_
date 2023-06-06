#include <stdio.h>

#define MAX 10

void bfs(int v);
int g[MAX][MAX], visited[MAX], n;

int main() {
 int i, j, node;
 n = MAX;
 printf("Ingrese la matriz de adyacencia del grafo:\n");
 for (i = 0; i < n; i++)
 for (j = 0; j < n; j++)
 scanf("%d", &g[i][j]);
 for (i = 0; i < n; i++)
 visited[i] = 0;
 printf("\nIngrese el nodo que desea buscar: ");
 scanf("%d", &node);
 if (node < 0 || node >= n) {
 printf("Nodo inválido\n");
 return 0;
 }
 bfs(0);
 if (visited[node])
 printf("\nEl nodo %d está en el grafo\n", node);
 else
 printf("\nEl nodo %d no está en el grafo\n", node);
 return 0;
}

void bfs(int v) {
 int queue[MAX], front = -1, rear = -1, i;
 queue[++rear] = v;
 visited[v] = 1;
 while (front != rear) {
 v = queue[++front];
 for (i = 0; i < n; i++)
 if (!visited[i] && g[v][i]) {
 queue[++rear] = i;
 visited[i] = 1;
 }
 }
}
