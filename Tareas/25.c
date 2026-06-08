#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6
#define TOL 1e-4
#define PI 3.141592654

// --- Inciso A: x^3 - 2x^2 - 6 = 0 en [1, 4] ---
double f_5a(double x)  { return pow(x, 3.0) - 2.0 * (x * x) - 6.0; }
double df_5a(double x) { return 3.0 * (x * x) - 4.0 * x; }

// --- Inciso B: x^3 + 3x^2 - 1 = 0 en [-3, -2] ---
double f_5b(double x)  { return pow(x, 3.0) + 3.0 * (x * x) - 1.0; }
double df_5b(double x) { return 3.0 * (x * x) + 6.0 * x; }

// --- Inciso C: x - cos(x) = 0 en [0, pi/2] ---
double f_5c(double x)  { return x - cos(x); }
double df_5c(double x) { return 1.0 + sin(x); }

// --- Inciso D: x - 0.8 - 0.2*sin(x) = 0 en [0, pi/2] ---
double f_5d(double x)  { return x - 0.8 - 0.2 * sin(x); }
double df_5d(double x) { return 1.0 - 0.2 * cos(x); }

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #25: Problema 5 (a, b, c, d) - Tolerancia 10^-4\n");
    printf("==============================================================\n");

    int max_iter = 20;

    printf("\n--- Inciso 5a (Intervalo [1, 4] -> Semilla x0 = 2.5) ---\n");
    newton_raphson(f_5a, df_5a, 2.0, TOL, max_iter, DEC);

    printf("\n--- Inciso 5b (Intervalo [-3, -2] -> Semilla x0 = -2.5) ---\n");
    newton_raphson(f_5b, df_5b, -3.0, TOL, max_iter, DEC);

    printf("\n--- Inciso 5c (Intervalo [0, pi/2] -> Semilla x0 = 0.785398) ---\n");
    newton_raphson(f_5c, df_5c, 0.0, TOL, max_iter, DEC);

    printf("\n--- Inciso 5d (Intervalo [0, pi/2] -> Semilla x0 = 0.785398) ---\n");
    newton_raphson(f_5d, df_5d, 0.0, TOL, max_iter, DEC);

    return 0;
}