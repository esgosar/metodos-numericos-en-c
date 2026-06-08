#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6

// a. x = 0.5 * (x^3 + 1)
double g3_a(double x) {
    return redondear(0.5 * (pow(x, 3.0) + 1.0), DEC);
}

// b. x = 2/x - 1/x^2
double g3_b(double x) {
    return (x != 0.0) ? redondear((2.0 / x) - (1.0 / (x * x)), DEC) : NAN;
}

// c. x = sqrt(2 - 1/x)
double g3_c(double x) {
    if (x == 0.0) return NAN;
    double dentro = 2.0 - (1.0 / x);
    return (dentro >= 0.0) ? redondear(sqrt(dentro), DEC) : NAN;
}

// d. x = -cbrt(1 - 2x)
double g3_d(double x) {
    return redondear(-cbrt(1.0 - 2.0 * x), DEC);
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 3: Calculo de p1 a p4 (p0 = 0.5)\n");
    printf("==============================================================\n");

    printf("\n--- Metodo A ---\n");
    punto_fijo(g3_a, 0.5, 1e-6, 4, DEC);

    printf("\n--- Metodo B ---\n");
    punto_fijo(g3_b, 0.5, 1e-6, 4, DEC);

    printf("\n--- Metodo C ---\n");
    punto_fijo(g3_c, 0.5, 1e-6, 4, DEC);

    printf("\n--- Metodo D ---\n");
    punto_fijo(g3_d, 0.5, 1e-6, 4, DEC);

    return 0;
}