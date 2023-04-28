#include <stdio.h>
#include <time.h>

// Función utilizando programación dinámica para calcular coeficientes binomiales
int coeficiente_binomial_dinamico(int n, int k) {
    int tabla[n+1][k+1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i) {
                tabla[i][j] = 1;
            } else {
                tabla[i][j] = tabla[i-1][j-1] + tabla[i-1][j];
            }
        }
    }

    return tabla[n][k];
}

int main() {
    int n, k, r;
    clock_t start, end;
    double time_used;

    printf("n\tk\tTiempo (seg)\n");
    for (n = 1; n <= 10; n++) {
        for (k = 1; k <= n; k++) {
            if (k == 1) {
                start = clock();
            }
            r = coeficiente_binomial_dinamico(n, k);
            if (k == n) {
                end = clock();
                time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("%d\t%d\t%.5lf\n", n, k, time_used);
            }
        }
    }

    return 0;
}
