#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6

// f(x) = x - 2^(-x)
double f5_a(double x) { 
    // Paso 1: Resolver la potencia y redondear
    double op1 = redondear(pow(2.0, -x), DEC);
    // Paso 2: Restar y redondear
    return redondear(x - op1, DEC); 
}

// f(x) = 2x * cos(2x) - (x+1)^2
double f5_c(double x) { 
    // Lado izquierdo
    double cos_val = redondear(cos(redondear(2.0 * x, DEC)), DEC);
    double izq = redondear(redondear(2.0 * x, DEC) * cos_val, DEC);
    
    // Lado derecho
    double der = redondear(pow(redondear(x + 1.0, DEC), 2.0), DEC);
    
    // Final
    return redondear(izq - der, DEC); 
}

int main() {
    printf("==============================================================\n");
    printf("   EJERCICIO 5 (a, c): Biseccion (Tol: 10^-3)\n");
    printf("==============================================================\n");

    printf("\n--- Inciso A: Intervalo [0, 1] ---\n");
    biseccion(f5_a, 0.0, 1.0, 1e-5, 100, 6);

    printf("\n--- Inciso C: Intervalo [-3, -2] ---\n");
    biseccion(f5_c, -3.0, -2.0, 1e-5, 100, 6);

    printf("\n--- Inciso C: Intervalo [-1, 0] ---\n");
    biseccion(f5_c, -1.0, 0.0, 1e-5, 100, 6);

    return 0;
}