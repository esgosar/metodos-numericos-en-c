#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

double f13(double x) { 
    return (x * x) - 3.0; 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 13: Aproximacion de raiz cuadrada de 3\n");
    printf("==============================================================\n");

    printf("\nEvaluando en [1, 2] con Tol: 10^-4\n");
    biseccion(f13, 1.0, 2.0, 1e-4, 100, 6);

    return 0;
}