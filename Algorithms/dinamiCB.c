#include <stdio.h>
#include <time.h>

int FibIter(int n) {
    int tabla[n+1];
    tabla[0] = 1;
    tabla[1] = 1;
    for (int i = 2; i <= n; i++) {
        tabla[i] = tabla[i-1] + tabla[i-2];
    }
    return tabla[n];
}

int main(){
    int i,r;
    clock_t start, end;
    double time_used;

    for(i = 1; i < 50; i++){
        start = clock();
        r = FibIter(i);
        end = clock();

        printf("El termino %d de la serie fibonacci es %d \n",i,r);
        time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("El programa tardo en ejcutarse %lf segundos\n",time_used);
    }

    return 0;
}