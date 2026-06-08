#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 5

double f_prob3(double x)  { return (x * x) - 6.0; }
double df_prob3(double x) { return 2.0 * x; }

int main() {
    printf("==============================================================\n");
    printf("   PROGRAMA #24: Problema 3 - Newton alternativo (p0 = 3)\n");
    printf("==============================================================\n");

    // Buscaremos p3 haciendo un maximo de 3 iteraciones
    newton_raphson(f_prob3, df_prob3, 3.0, 1e-5, 3, DEC);

    return 0;
}