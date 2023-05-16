#include <stdio.h>
#include <time.h>
#include <limits.h>

typedef enum {
    M500, M200, M100, M50, M25, M5, M1
} MONEDAS;

typedef unsigned int VALORES[7];
typedef unsigned int SOLUCION[7];

void Cambio(unsigned int n, VALORES valor, SOLUCION cambio) {
    MONEDAS moneda;

    for (moneda = M500; moneda <= M1; moneda++) {
        cambio[moneda] = 0;
    }

    for (moneda = M500; moneda <= M1; moneda++) {
        while (valor[moneda] <= n) {
            cambio[moneda]++;
            n -= valor[moneda];
        }
    }
}

int main() {
    //unsigned int n = 1234;  // Cantidad a descomponer
    unsigned int n;
    VALORES valor = {500, 200, 100, 50, 25, 5, 1};  // Valores de las monedas
    SOLUCION cambio;
    clock_t inicio,fin;
    double tiempo_ejecucion;

    printf("\t\t\t\tAlgoritmo que que te dice cual es la cantidad minima de monedas que puedes dar de cambio\n\n");
    printf("Ingresa la cantidad a descomponer\n");
    scanf("%u",&n);
    //n = UINT_MAX;

    inicio = clock();

    Cambio(n, valor, cambio);

    fin = clock();

    tiempo_ejecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    printf("Descomposición de %u:\n", n);
    printf("M500: %d\n", cambio[M500]);
    printf("M200: %d\n", cambio[M200]);
    printf("M100: %d\n", cambio[M100]);
    printf("M50: %d\n", cambio[M50]);
    printf("M25: %d\n", cambio[M25]);
    printf("M5: %d\n", cambio[M5]);
    printf("M1: %d\n", cambio[M1]);

    printf("\nTiempo de ejecución: %f segundos\n", tiempo_ejecucion);

    return 0;
}