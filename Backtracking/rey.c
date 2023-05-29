#include <stdio.h>
#include <stdbool.h>

#define n 8

int tablero[n][n];
int mov_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int mov_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void Rey(int k, int x, int y, int *numsoluciones) {
    for (int orden = 0; orden < 8; orden++) {
        int u = x + mov_x[orden];
        int v = y + mov_y[orden];
        if (u >= 0 && u < n && v >= 0 && v < n && tablero[u][v] == 0) {
            tablero[u][v] = k;
            if (k < n*n) {
                Rey(k+1, u, v, numsoluciones);
            } else {
                (*numsoluciones)++;
            }
            tablero[u][v] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }

    int x0 = 0;
    int y0 = 0;
    int numsoluciones = 0;

    tablero[x0][y0] = 1;
    Rey(2, x0, y0, &numsoluciones);

    printf("Se encontraron %d soluciones.\n", numsoluciones);

    return 0;
}
