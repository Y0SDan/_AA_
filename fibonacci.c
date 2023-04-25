#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Programa recursivo para calcular la sucesión de Fibonacci */
int FibRec(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return FibRec(n-1) + FibRec(n-2);
    }
}

/* Algoritmo iterativo que utiliza una tabla para almacenar los cálculos */
int FibIter(int n) {
    int tabla[n+1];
    tabla[0] = 1;
    tabla[1] = 1;
    for (int i = 2; i <= n; i++) {
        tabla[i] = tabla[i-1] + tabla[i-2];
    }
    return tabla[n];
}

/* Algoritmo iterativo que utiliza solo dos variables para almacenar los dos últimos términos calculados */
int FibIter2(int n) {
    int x = 1;
    int y = 1;
    int suma;
    for (int i = 2; i <= n; i++) {
        suma = x + y;
        y = x;
        x = suma;
    }
    return suma;
}

int main(){
    int n,v,r;
    clock_t start, end;
    double timeUsed;

    printf("Ingresa el valor de fibonacci que deseas calcular: ");
    scanf("%d",&n);
    printf("\n");

    printf("1 -> Recursivo\n");
    printf("2 -> Iterativo (tabla)\n");
    printf("3 -> Iterativo (x,y)\n");
    printf("Ingrese el metodo que desea usar: ");
    scanf("%d",&v);

    switch (v)
    {
    case 1:
        start = clock();
        r = FibRec(n);
        end = clock();
        break;
    case 2:
        start = clock();
        r = FibIter(n);
        end = clock();
        break;
    case 3:
        start = clock();
        r = FibIter2(n);
        end = clock();
        break;
    default:
        break;
    }

    printf("\nEl valor de la posicion %d en la sucesion de fibonacci es: %d\n\n: ",n,r);
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("La funcion tardó %lf segundos en completarse\n",timeUsed);

    return 0;
}

//COEBLOCKS -> compilaores