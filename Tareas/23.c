#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 5

// --- Funciones del Problema 1 ---
double f_prob1(double x)   { return (x * x) - 6.0; }
double df_prob1(double x)  { return 2.0 * x; }

// --- Funciones del Problema 2 ---
double f_prob2(double x)   { return -pow(x, 3.0) - cos(x); }
double df_prob2(double x)  { return -3.0 * (x * x) + sin(x); }

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #23: Problemas 1 y 2 - Evaluacion de p2\n");
    printf("==============================================================\n");

    printf("\n--- PROBLEMA 1 (f(x) = x^2 - 6, p0 = 1) ---\n");
    newton_raphson(f_prob1, df_prob1, 1.0, 1e-5, 2, DEC); // max_iter = 2 para hallar p2

    printf("\n--- PROBLEMA 2 (f(x) = -x^3 - cos(x), p0 = -1) ---\n");
    newton_raphson(f_prob2, df_prob2, -1.0, 1e-5, 2, DEC); // max_iter = 2 para hallar p2

    printf("\n--- TEST DE EXCEPCION: PROBLEMA 2 con p0 = 0 ---\n");
    // Al ser x0 = 0, df(0) = -3(0)^2 + sin(0) = 0. Tu codigo disparara la excepcion.
    newton_raphson(f_prob2, df_prob2, 0.0, 1e-5, 5, DEC);

    return 0;
}