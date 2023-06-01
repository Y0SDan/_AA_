#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define n 13//numero de reinas; n>3

typedef struct{
    unsigned int array[n];
}SOLUCION;

SOLUCION X;
bool exito;

unsigned int ValAbs(unsigned int x, unsigned int y) {
    if (x > y) {
        return x - y;
    } else {
        return y - x;
    }
}

bool Valido(int k) {
    /*comprueba si el vector solucion X construido hasta el paso k
    es k-prometedor, es decir, si la reina puede situarse en la
    columna k */
    for (int i = 1; i < k; i++) {
        if (X.array[i-1] == X.array[k-1] || ValAbs(X.array[i-1], X.array[k-1]) == ValAbs(i,k)) {
            return false;
        }
    }
    return true;
}

void ComunicarSolucion(SOLUCION solucion) {
    printf("Solución encontrada:\n");
    
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) =>\n", i+1, solucion.array[i]);
    }
    
    printf("\n");
}

void Reinas2(int k) {
    if (k > n) {
        return;
    }
    
    X.array[k-1] = 0; // Iniciar opciones
    
    do {
        X.array[k-1]++; // Selección de nueva opción
        
        if (Valido(k)) { // Prueba de fracaso
            if (k != n) {
                Reinas2(k + 1); // Llamada recursiva
            } else {
                ComunicarSolucion(X);
            }
        }
    } while (X.array[k-1] != n);
}


int main() {
    srand(time(NULL));
	clock_t inicio, fin;
	double tiempo_ejecucion;
	inicio = clock();
    
    Reinas2(1); // Llamar a la función Reinas2 con k = 1 (comenzar en la primera reina)
    
    fin = clock();
	tiempo_ejecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
	printf("\n\nTiempo de ejecucion: %f segundos", tiempo_ejecucion);
    return 0;
}