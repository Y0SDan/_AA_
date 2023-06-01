#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define n 7            //Para el tamaño del tablero n*n
typedef unsigned int TABLERO[n][n];
TABLERO tablero;
int mov_x[8];
int mov_y[8];

void MovimientosPosibles() {
    mov_x[0] = 0; mov_y[0] = 1;
    mov_x[1] = -1; mov_y[1] = 1;
    mov_x[2] = -1; mov_y[2] = 0;
    mov_x[3] = -1; mov_y[3] = -1;
    mov_x[4] = 0; mov_y[4] = -1;
    mov_x[5] = 1; mov_y[5] = -1;
    mov_x[6] = 1; mov_y[6] = 0;
    mov_x[7] = 1; mov_y[7] = 1;
}

void Rey2(int k, int x, int y, int* numsoluciones) {
    int orden, u, v;
    orden = 0;
    
    do {
        //orden++;
        u = x + mov_x[orden];
        v = y + mov_y[orden];
        
        if (1 <= u && u <= n && 1 <= v && v <= n && tablero[u-1][v-1] == 0) {
            tablero[u-1][v-1] = k;
            
            if (k < n * n) {
                Rey2(k+1, u, v, numsoluciones);
            } else {
                (*numsoluciones)++;
            }
            
            tablero[u-1][v-1] = 0;
        }
        orden++;
    } while (orden != 8);
}

int main() {
    srand(time(NULL));
	clock_t inicio, fin;
	double tiempo_ejecucion;
    int numsoluciones = 0;
    int x0 = 1; // coordenada x inicial
    int y0 = 1; // coordenada y inicial
    
    inicio = clock();

    MovimientosPosibles();
    
    // Reiniciar el tablero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }
    
    tablero[x0-1][y0-1] = 1; // Colocar el rey en la casilla inicial
    
    Rey2(2, x0, y0, &numsoluciones);
    
    printf("Número de soluciones: %d\n", numsoluciones);
    
    fin = clock();
	tiempo_ejecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
	printf("\n\nTiempo de ejecucion: %f segundos", tiempo_ejecucion);

    return 0;
}