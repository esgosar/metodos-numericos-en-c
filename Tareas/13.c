#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define PI 3.141592654
#define E 2.718281828

double f6_a(double x) { 
    return 3*x - pow(E, x); 
}

double f6_d(double x) { 
    return x + 1.0 - 2.0 * sin(PI * x); 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 6 (a, d): Biseccion (Tol: 10^-4)\n");
    printf("==============================================================\n");

    printf("\n--- Inciso A: Intervalo [1, 2] ---\n");
    biseccion(f6_a, 1.0, 2.0, 1e-5, 100, 6);

    printf("\n--- Inciso D: Intervalo [0, 0.5] ---\n");
    biseccion(f6_d, 0.0, 0.5, 1e-5, 100, 6);

    printf("\n--- Inciso D: Intervalo [0.5, 1] ---\n");
    biseccion(f6_d, 0.5, 1.0, 1e-5, 100, 6);

    return 0;
}