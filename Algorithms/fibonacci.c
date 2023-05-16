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
long double FibIter(int n) {
    long double tabla[n+1];
    int i;

    tabla[0] = 1;
    tabla[1] = 1;
    for (i = 2; i <= n; i++) {
        tabla[i] = tabla[i-1] + tabla[i-2];
    }
    return tabla[n];
}

/* Algoritmo iterativo que utiliza solo dos variables para almacenar los dos últimos términos calculados */
long double FibIter2(int n) {
    int i;
    long double x = 1;
    long double y = 1;
    long double suma;

    for (i = 2; i <= n; i++) {
        suma = x + y;
        y = x;
        x = suma;
    }
    return suma;
}

int main(){
    int n,v;
    long double r;
    clock_t start, end;
    double timeUsed;

    printf("Ingresa el valor de fibonacci que deseas calcular: ");
    scanf("%d",&n);
    printf("\n");

    /*printf("1 -> Recursivo\n");
    printf("2 -> Iterativo (tabla)\n");
    printf("3 -> Iterativo (x,y)\n");
    printf("Ingrese el metodo que desea usar: ");
    scanf("%d",&v);*/

    /*switch (v)
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
    }*/

    start = clock();
    r = FibRec(n);
    end = clock();
    printf("\nEl valor de la posicion %d en la sucesion de fibonacci implmentado por recursividad es: %d\n",n,r);
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("La funcion tardó %lf segundos en completarse\n\n",timeUsed);

    start = clock();
    r = FibIter(n);
    end = clock();
    printf("\nEl valor de la posicion %d en la sucesion de fibonacci implmentado por tablas es: %d\n",n,r);
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("La funcion tardó %lf segundos en completarse\n\n",timeUsed);


    printf("\nEl valor de la posicion %d en la sucesion de fibonacci es: %Lf\n\n: ",n,r);
    start = clock();
    r = FibIter2(n);
    end = clock();
    printf("\nEl valor de la posicion %d en la sucesion de fibonacci implementado por varibles es: %Lf\n",n,r);//son necesarios los ultimos dos valores calculados oara determinar cada cambio
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("La funcion tardó %lf segundos en completarse\n\n",timeUsed);

    return 0;
}

//COEBLOCKS -> compilaores