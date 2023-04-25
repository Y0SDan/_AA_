#include <stdio.h>

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
    int n = 5, k = 2;

    printf("Coeficiente binomial de %d y %d usando función recursiva: %d\n", n, k, coeficiente_binomial_recursivo(n, k));
    printf("Coeficiente binomial de %d y %d usando programación dinámica: %d\n", n, k, coeficiente_binomial_dinamico(n, k));

    return 0;
}
