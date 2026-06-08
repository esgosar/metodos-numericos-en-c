#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6

double g7(double x) {
    return redondear(pow(3.0 * (x * x) + 3.0, 0.25), 5);
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 7: Punto Fijo (Tol: 10^-2 | Decimales: 3)\n");
    printf("==============================================================\n");

    printf("\n--- Evaluando con p0 = 1.0 en el intervalo [1, 2] ---\n");
    punto_fijo(g7, 1.0, 1e-2, 100, DEC);

    return 0;
}