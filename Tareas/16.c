#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

double f15(double x) { 
    return (x * x * x) - 25.0; 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 15: Aproximacion de raiz cubica de 25\n");
    printf("==============================================================\n");

    printf("\nEvaluando en [2, 3] con Tol: 10^-4\n");
    biseccion(f15, 2.0, 3.0, 1e-4, 100, 6);

    return 0;
}