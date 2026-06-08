#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

double f13(double x) { 
    return (x * x * x) - 25.0; 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 13: Aproximacion de raiz cubica de 3\n");
    printf("==============================================================\n");

    printf("\nEvaluando en [2,3] con Tol: 10^-4\n");
    biseccion(f13, 2.0, 3.0, 1e-4, 100, 6);

    return 0;
}