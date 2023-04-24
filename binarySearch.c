#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int busqueda_binaria(int arr[], int inicio, int fin, int objetivo) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == objetivo)
            return medio;
        else if (arr[medio] < objetivo)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

int main() {
    int n, objetivo, resultado;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL)); // inicializa la semilla para la función rand()
    printf("El arreglo generado aleatoriamente es:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // genera un número aleatorio entre 0 y 99
        printf("%d ", arr[i]);
    }

    // Ordenar el arreglo antes de buscar
    bubble_sort(arr, n);

    printf("\nIngrese el número que desea buscar: ");
    scanf("%d", &objetivo);
    clock_t inicio = clock();
    resultado = busqueda_binaria(arr, 0, n-1, objetivo);
    clock_t fin = clock();
    double tiempo_ejecucion = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    if (resultado == -1)
        printf("El número no se encuentra en el arreglo\n");
    else
        printf("El número se encuentra en el índice %d del arreglo\n", resultado);
    printf("El tiempo de ejecución del algoritmo fue de %.8f segundos.\n", tiempo_ejecucion);
    return 0;
}