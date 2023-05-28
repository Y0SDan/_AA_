#include <stdio.h>
#include <stdbool.h>

#define n 4// reemplaza ... con el valor deseado

typedef struct {
    int x;
    int y;
} Coordenada;

void MovimientosPosibles(int* mov_x, int* mov_y);
void Rey1(int k, int x, int y, bool* exito, int tablero[][n]);
void Rey2(int k, int x, int y, int* numsoluciones, int tablero[][n]);

int main() {
    int mov_x[8];
    int mov_y[8];

    MovimientosPosibles(mov_x, mov_y);

    int tablero[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }

    int x0 = 0;
    int y0 = 0;

    tablero[x0 - 1][y0 - 1] = 1;

    bool exito = false;

    Rey1(2, x0, y0, &exito, tablero);

    if (exito) {
        printf("Se encontró una solución.\n");
        // Imprimir el tablero con la solución encontrada
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d ", tablero[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No se encontró ninguna solución.\n");
    }

    int numsoluciones = 0;

    Rey2(2, x0, y0, &numsoluciones, tablero);

    printf("Número de soluciones encontradas: %d\n", numsoluciones);

    return 0;
}   

void Rey1(int k, int x, int y, bool* exito,int tablero[][n]) {
    int mov_x[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int mov_y[] = {2, -2, 1, -1, 2, -2, 1, -1};

    int orden = 0;
    int u, v;

    do {
        orden++;
        u = x + mov_x[orden - 1];
        v = y + mov_y[orden - 1];

        if (1 <= u && u <= n && 1 <= v && v <= n && tablero[u - 1][v - 1] == 0) {
            tablero[u - 1][v - 1] = k;

            if (k < n * n) {
                Rey1(k + 1, u, v, exito,tablero);
                if (!(*exito)) {
                    tablero[u - 1][v - 1] = 0;
                }
            } else {
                *exito = true;
            }
        }
    } while (!(*exito) && orden < 8);
}

void Rey2(int k, int x, int y, int* numsoluciones,int tablero[][n]) {
    int mov_x[8];
    int mov_y[8];

    MovimientosPosibles(mov_x, mov_y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }

    int orden = 0;
    int u, v;

    do {
        orden++;
        u = x + mov_x[orden - 1];
        v = y + mov_y[orden - 1];

        if (1 <= u && u <= n && 1 <= v && v <= n && tablero[u - 1][v - 1] == 0) {
            tablero[u - 1][v - 1] = k;

            if (k < n * n) {
                Rey2(k + 1, u, v, numsoluciones,tablero);
            } else {
                (*numsoluciones)++;
            }

            tablero[u - 1][v - 1] = 0;
        }
    } while (orden < 8);
}

void MovimientosPosibles(int* mov_x, int* mov_y) {
    mov_x[0] = 0;
    mov_y[0] = 1;
    mov_x[1] = -1;
    mov_y[1] = 1;
    mov_x[2] = -1;
    mov_y[2] = 0;
    mov_x[3] = -1;
    mov_y[3] = -1;
    mov_x[4] = 0;
    mov_y[4] = -1;
    mov_x[5] = 1;
    mov_y[5] = -1;
    mov_x[6] = 1;
    mov_y[6] = 0;
    mov_x[7] = 1;
    mov_y[7] = 1;
}