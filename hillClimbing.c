#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función objetivo (aqui se debe reemplazar con la función que se desea optimizar)
double objetivo(double x) {
    //return -x * x + 4 * x;
    //return sin(x);
    //return pow(x,3) - 3 * (pow(x,2)) + x;
    double e = 2.71828;
    double n = -1 * pow(x,2);
    return pow(e,n);

}

// Función que implementa el algoritmo Hill Climbing
double hillClimbing(double initial_x, double step_size) {
    double current_x = initial_x;
    double best_x = current_x;
    double best_score = objetivo(current_x);

    while (1) {
        double next_x = current_x + step_size;
        double next_score = objetivo(next_x);

        if (next_score > best_score) {
            best_x = next_x;
            best_score = next_score;
        } else {
            break; // El máximo local ha sido encontrado
        }

        current_x = next_x;
    }

    return best_x;
}

int main() {
    double initial_x = 0.0; // Punto de inicio para la búsqueda
    double step_size = 0.01; // Tamaño del paso

    double result = hillClimbing(initial_x, step_size);

    printf("Máximo local encontrado en x = %f\n", result);
    printf("Valor del máximo local = %f\n", objetivo(result));

    return 0;
}
