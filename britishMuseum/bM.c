#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 26

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

bool bfs(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int src, int dest, int parent[]) {
    bool visited[MAX_VERTICES];
    memset(visited, 0, sizeof(visited));

    visited[src] = true;
    parent[src] = -1;

    // Queue for BFS
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;
    queue[rear++] = src;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < MAX_VERTICES; v++) {
            if (!visited[v] && adjacencyMatrix[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                queue[rear++] = v;

                if (v == dest)
                    return true;
            }
        }
    }

    return false;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf("%c ", j + 'A');
}

void printShortestPath(int parent[], int src, int dest) {
    printf("Camino más corto: ");
    printf("%c ", src + 'A');
    printPath(parent, dest);
    printf("\n");
}

int main() {
    int V = MAX_VERTICES;
    int E = (V * (V - 1)) / 2;
    Graph* graph = createGraph(V, E);

    int edgeIndex = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            graph->edge[edgeIndex].src = i;
            graph->edge[edgeIndex].dest = j;
            graph->edge[edgeIndex].weight = abs(i - j); // Usamos la diferencia entre los índices como peso
            edgeIndex++;
        }
    }

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for (int i = 0; i < E; i++) {
        int src = graph->edge[i].src;
        int dest = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    printf("Matriz de adyacencias:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    char target;
    printf("Ingrese una letra para buscar en el grafo: ");
    scanf(" %c", &target);
    int targetIndex = target - 'A';

    if (targetIndex < 0 || targetIndex >= MAX_VERTICES) {
        printf("La letra no se encuentra en el grafo.\n");
        return 0;
    }

    int parent[MAX_VERTICES];
    if (bfs(adjacencyMatrix, 0, targetIndex, parent))
        printShortestPath(parent, 0, targetIndex);
    else
        printf("No se encontró un camino hacia la letra %c.\n", target);

    return 0;
}
