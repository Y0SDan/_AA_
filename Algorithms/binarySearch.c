#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n){
    int i,j,temp;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int inicio, int fin, int objetivo){
    int medio;

    while(inicio <= fin){
        medio = inicio + (fin - inicio) / 2;
        if(arr[medio] == objetivo){
            return medio;
        }else if(arr[medio] < objetivo){
            inicio = medio + 1;
        }else{
            fin = medio - 1;
        }
    }
    return -1;
}

int main(){
    int n,objetivo,resultado,i;

    printf("Ingrese el tamano del arreglo: ");
    scanf("%d",&n);
    int arr[n];

    srand(time(NULL));// inicializa la semilla para la funcion rand()

    //printf("\nEl arreglo generado aletoriamente es:\n");
    for(i = 0; i < n; i++){
        arr[i] = rand() % 100000; //genera un numero aleatorio entre 0 y 99
        //printf("%d ", arr[i]);
    }

    //ordenar el arreglo antes de buscar
    bubbleSort(arr,n);
    
    /*printf("\n\nEl arreglo ordenado es:\n");
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }*/

    printf("\n\nIngrese el numero que desa buscar: ");
    scanf("%d",&objetivo);

    clock_t inicio = clock();

    resultado = binarySearch(arr, 0, n-1, objetivo);

    clock_t fin = clock();

    double timE = ((float) (fin - inicio)) / CLOCKS_PER_SEC;

    if(resultado == -1){
        printf("El numero no se encuentra en el arreglo\n");
    }else{
        printf("El numero se encuenrtra en el indice %d del arreglo\n",resultado);
    }

    printf("El tiempo de ejecucion del algoritmo: \"binarySearch\" fue de %lf segundos.\n", timE);

    return 0;
}