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