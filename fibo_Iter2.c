#include <stdio.h>
#include <time.h>

/* Algoritmo iterativo que utiliza una tabla para almacenar los cálculos */
long double FibIter(int n) {
    static long double tabla[50000001] = {0}; // alojamiento en el segmento de datos estáticos
    int i;

    tabla[0] = 1;
    tabla[1] = 1;
    for (i = 2; i <= n; i++) {
        tabla[i] = tabla[i-1] + tabla[i-2];
    }
    return tabla[n];
}

int main() {
    int n = 5000000; // valor inicial
    int incremento = 5000000; // incremento en cada iteración
    int max = 50000000; // valor final
    clock_t start, end;
    double cpu_time_used;
    
    printf("n\tTiempo de ejecucion (segundos)\n");
    while (n <= max) {
        start = clock();
        FibIter(n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%d\t%f\n", n, cpu_time_used);
        n += incremento;
    }

    return 0;
}
