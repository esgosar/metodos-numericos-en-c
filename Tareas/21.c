#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6

// Ejercicio 13b: x = 5/(x^2) + 2
double g_13b(double x) {
    if (x == 0.0) return NAN;
    return redondear((5.0 / (x * x)) + 2.0, DEC);
}

// Ejercicio 13e: x = 6^(-x)
double g_13e(double x) {
    return redondear(pow(6.0, -x), DEC);
}

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #21: Ejercicios 13b y 13e (Tol = 10^-5)\n");
    printf("==============================================================\n");

    double tolerancia = 1e-5;
    int max_iter = 30;

    printf("\n--- Inciso 13b (Intervalo sugerido: [2, 3]) ---\n");
    punto_fijo(g_13b, 2.5, tolerancia, max_iter, DEC);

    printf("\n--- Inciso 13e (Intervalo sugerido: [0, 1]) ---\n");
    punto_fijo(g_13e, 0.5, tolerancia, max_iter, DEC);

    return 0;
}