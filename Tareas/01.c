#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../teoremas/validacion.h" // Inyectamos el modulo de validacion oficial

#define DEC 6

double f1_a(double x) { 
    return redondear((x * cos(x)) - (2.0 * x * x) + (3.0 * x) - 1.0, DEC); 
}

double f1_c(double x) { 
    return redondear((2.0 * x * cos(2.0 * x)) - pow(x - 2.0, 2), DEC); 
}

int main() {
    printf("==============================================================\n");
    printf("   TAREA #1: PROBLEMA 1 (a, c) | Ejecucion Directa\n");
    printf("==============================================================\n");
    
    // ---------------------------------------------------------------------
    // INCISO A
    // ---------------------------------------------------------------------
    printf("Inciso a en [%g, %g]: f(a) = %g | f(b) = %g\n", 0.2, 0.3, f1_a(0.2), f1_a(0.3));
    if (teorema_valor_intermedio(f1_a, 0.2, 0.3)) {
        printf(" -> [EXITO] Teorema del Valor Intermedio confirmado.\n\n");
    }

    printf("Inciso a en [%g, %g]: f(a) = %g | f(b) = %g\n", 1.2, 1.3, f1_a(1.2), f1_a(1.3));
    if (teorema_valor_intermedio(f1_a, 1.2, 1.3)) {
        printf(" -> [EXITO] Teorema del Valor Intermedio confirmado.\n\n");
    }
    
    // ---------------------------------------------------------------------
    // INCISO C
    // ---------------------------------------------------------------------
    printf("Inciso c en [%g, %g]: f(a) = %g | f(b) = %g\n", 2.0, 3.0, f1_c(2.0), f1_c(3.0));
    if (teorema_valor_intermedio(f1_c, 2.0, 3.0)) {
        printf(" -> [EXITO] Teorema del Valor Intermedio confirmado.\n\n");
    }

    printf("Inciso c en [%g, %g]: f(a) = %g | f(b) = %g\n", 3.0, 4.0, f1_c(3.0), f1_c(4.0));
    if (teorema_valor_intermedio(f1_c, 3.0, 4.0)) {
        printf(" -> [EXITO] Teorema del Valor Intermedio confirmado.\n\n");
    }
    
    return 0;
}