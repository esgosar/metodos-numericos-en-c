#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define PI 3.141592654
#define E 2.718281828
#define L 10
#define R 1
#define V 12.4


double f(double h) { 
    return pow(R, 2) * asin(h / R) - h * sqrt(pow(R, 2) - pow(h, 2)) + (V / L - 0.5 * PI * pow(R, 2));
}


int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 15 \n");
    printf("==============================================================\n");

    printf("\n--- Inciso A: Intervalo [0, 1] ---\n");
    biseccion(f, 0.0, 1.0, 1e-3, 100, 6);

    return 0;
}