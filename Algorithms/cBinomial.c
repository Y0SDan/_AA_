#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Función recursiva para calcular coeficientes binomiales
int coeficiente_binomial_recursivo(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return coeficiente_binomial_recursivo(n-1, k-1) + coeficiente_binomial_recursivo(n-1, k);
    }
}

// Función utilizando programación dinámica para calcular coeficientes binomiales
int coeficiente_binomial_dinamico(int n, int k) {
    int **tabla = (int **)malloc((n+1)*sizeof(int *));
    int i, j;

    for (i = 0; i <= n; i++) {
        tabla[i] = (int *)malloc((k+1)*sizeof(int));
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                tabla[i][j] = 1;
            } else {
                tabla[i][j] = tabla[i-1][j-1] + tabla[i-1][j];
            }
        }
    }

    int resultado = tabla[n][k];

    for (i = 0; i <= n; i++) {
        free(tabla[i]);
    }

    free(tabla);

    return resultado;
}

int main() {
    int n,k,r;
    clock_t start,end;
    double time_used;


    printf("Ingresa el valor de n: ");
    scanf("%d",&n);

    printf("Ingresa el valor de k: ");
    scanf("%d",&k);

   /* start = clock();
    r = coeficiente_binomial_recursivo(n,k);
    end = clock();
    printf("Coeficiente binomial de %d y %d usando función recursiva: %d\n", n, k, r);
    time_used =((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El programa tardó %lf segundos en completarse\n\n",time_used);*/

    start = clock();
    r = coeficiente_binomial_dinamico(n,k);
    end = clock();
    printf("Coeficiente binomial de %d y %d usando función dinamica: %d\n", n, k, r);
    time_used =((double) (end - start)) / CLOCKS_PER_SEC;
    printf("El programa tardó %lf segundos en completarse\n\n",time_used);

    return 0;
}
