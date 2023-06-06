#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 120

void breadth_first_search(int g[MAX][MAX], int n, int start, bool visited[MAX], int values[MAX], int search_value, bool *found) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    while (front != rear) {
        int current = queue[front++];
        if (values[current] == search_value) {
            *found = true;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (g[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

void depth_first_search(int g[MAX][MAX], int n, int start, bool visited[MAX], int values[MAX], int search_value, bool *found) {
    visited[start] = true;
    if (values[start] == search_value) {
        *found = true;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (g[start][i] && !visited[i])
            depth_first_search(g, n, i, visited, values, search_value, found);
    }
}

int main() {
    int g[MAX][MAX], n = MAX, i, j, values[MAX];
    bool visited[MAX] = {false}, found = false;
    srand(time(0));
    printf("Matriz de adyacencia generada aleatoriamente:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                g[i][j] = 0;
            else if (j > i)
                g[i][j] = g[j][i] = rand() % 2;
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    printf("\nValores aleatorios asignados a cada nodo:\n");
    for (i = 0; i < n; i++) {
        values[i] = rand() % 150;
        printf("Nodo %d: %d\n", i, values[i]);
    }
    int search_value, search_method;
    while (true) {
        printf("\nIngresa un número para buscar en el grafo (ingresa -1 para salir): ");
        scanf("%d", &search_value);
        if (search_value == -1)
            break;
        printf("\nSelecciona el método de búsqueda:\n1. Búsqueda en anchura (BFS)\n2. Búsqueda en profundidad (DFS)\n");
        scanf("%d", &search_method);
        clock_t start_time, end_time;
        double time_taken;
        start_time = clock();
        if (search_method == 1)
            breadth_first_search(g, n, 0, visited, values, search_value, &found);
        else
            depth_first_search(g, n, 0, visited, values, search_value, &found);
        end_time = clock();
        time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        if (found)
            printf("\nEl número %d está en el grafo.\n", search_value);
        else
            printf("\nEl número %d no está en el grafo.\n", search_value);
        printf("Tiempo que tardó el algoritmo de búsqueda: %f segundos\n", time_taken);
    }
    return 0;
}
