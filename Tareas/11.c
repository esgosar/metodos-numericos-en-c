#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

double f3(double x) { 
    return pow(x, 3.0) - 7.0 * pow(x, 2.0) + 14.0 * x - 6.0; 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 3: Biseccion (Tol: 10^-2)\n");
    printf("==============================================================\n");

    printf("\n--- Inciso A: Intervalo [0, 1] ---\n");
    biseccion(f3, 0.0, 1.0, 1e-2, 100, 6);

    printf("\n--- Inciso B: Intervalo [1, 3.2] ---\n");
    biseccion(f3, 1.0, 3.2, 1e-2, 100, 6);

    printf("\n--- Inciso C: Intervalo [3.2, 4] ---\n");
    biseccion(f3, 3.2, 4.0, 1e-2, 100, 6);

    return 0;
}