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

int ternary_search(int arr[], int left, int right, int x)
{
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == x) {
            return mid1;
        }
        if (arr[mid2] == x) {
            return mid2;
        }
        if (x < arr[mid1]) {
            return ternary_search(arr, left, mid1 - 1, x);
        } else if (x > arr[mid2]) {
            return ternary_search(arr, mid2 + 1, right, x);
        } else {
            return ternary_search(arr, mid1 + 1, mid2 - 1, x);
        }
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    // Llenar el arreglo con números aleatorios entre 1 y 100
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    printf("El arreglo generado es:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordenar el arreglo antes de buscar
    bubble_sort(arr, n);

    printf("Ingrese el número a buscar: ");
    scanf("%d", &x);

    // Medir el tiempo de ejecución de la búsqueda ternaria
    clock_t start = clock();
    int result = ternary_search(arr, 0, n - 1, x);
    clock_t end = clock();
    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result == -1) {
        printf("El número no está presente en el arreglo.\n");
    } else {
        printf("El número está presente en el índice %d del arreglo.\n", result);
    }

    printf("Tiempo de ejecución: %f segundos.\n", time_used);

    return 0;
}