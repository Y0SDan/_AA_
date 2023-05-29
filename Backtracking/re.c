#include <stdio.h>
#include <stdbool.h>

#define n 8

int tablero[n][n];
int mov_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int mov_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void Rey(int k, int x, int y, bool *exito) {
    int orden = 0;
    *exito = false;
    while (!(*exito) && orden < 8) {
        orden++;
        int u = x + mov_x[orden];
        int v = y + mov_y[orden];
        if (u >= 0 && u < n && v >= 0 && v < n && tablero[u][v] == 0) {
            tablero[u][v] = k;
            if (k < n*n) {
                Rey(k+1, u, v, exito);
                if (!(*exito)) {
                    tablero[u][v] = 0;
                }
            } else {
                *exito = true;
            }
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
    bool exito;

    tablero[x0][y0] = 1;
    Rey(2, x0, y0, &exito);

    if (exito) {
        printf("Se encontró una solución:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", tablero[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No se encontró una solución.\n");
    }

    return 0;
}