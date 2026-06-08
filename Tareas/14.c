#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

double f11(double x) { 
    return (x + 2.0) * (x + 1.0) * x * pow(x - 1.0, 3.0) * (x - 2.0); 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 11: Analisis de Convergencia Múltiple\n");
    printf("==============================================================\n");

    printf("\n--- Inciso A: Intervalo [-3, 2.5] ---\n");
    biseccion(f11, -3.0, 2.5, 1e-3, 100, 6);

    printf("\n--- Inciso B: Intervalo [-2.5, 3] ---\n");
    biseccion(f11, -2.5, 3.0, 1e-3, 100, 6);

    printf("\n--- Inciso C: Intervalo [-1.75, 1.5] ---\n");
    biseccion(f11, -1.75, 1.5, 1e-3, 100, 6);

    printf("\n--- Inciso D: Intervalo [-1.5, 1.75] ---\n");
    biseccion(f11, -1.5, 1.75, 1e-3, 100, 6);

    return 0;
}