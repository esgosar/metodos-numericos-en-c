#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 5

// Ejercicio 12: g(x) óptimo para raíz cúbica de 25
double g_ejercicio12(double x) {
    if (x == 0.0) return NAN;
    double numerador = 2.0 * pow(x, 3.0) + 25.0;
    double denominador = 3.0 * (x * x);
    return redondear(numerador / denominador, DEC);
}

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #20: Ejercicio 12 - Calculo de raiz cubica de 25\n");
    printf("==============================================================\n");

    // Usamos x0 = 2.5 ya que 2^3 = 8 y 3^3 = 27 (la raíz está muy cerca de 3)
    double x0 = 2.5; 
    double tolerancia = 1e-4;
    int max_iter = 20;

    printf("\nBuscando aproximacion para g(x) = (2x^3 + 25) / 3x^2...\n");
    punto_fijo(g_ejercicio12, x0, tolerancia, max_iter, DEC);

    return 0;
}