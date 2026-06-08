#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6

// Ejercicio 14b: De x^3 - 2x - 5 = 0  ->  g(x) = cbrt(2x + 5)
double g_14b(double x) {
    return redondear(cbrt(2.0 * x + 5.0), DEC);
}

// Ejercicio 14c: De 3x^2 - e^x = 0  ->  g(x) = sqrt(e^x / 3)
double g_14c(double x) {
    return redondear(sqrt(exp(x) / 3.0), DEC);
}

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #22: Ejercicios 14b y 14c (Tol = 10^-5)\n");
    printf("==============================================================\n");

    double tolerancia = 1e-5;
    int max_iter = 30;

    printf("\n--- Inciso 14b (Intervalo: [2, 3]) ---\n");
    punto_fijo(g_14b, 2.5, tolerancia, max_iter, DEC);

    printf("\n--- Inciso 14c (Intervalo determinado: [0, 1]) ---\n");
    punto_fijo(g_14c, 0.5, tolerancia, max_iter, DEC);

    return 0;
}