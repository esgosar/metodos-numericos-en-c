#include <stdio.h>
#include <math.h>
#include "solvers.h"
#include "../core/aritmetica.h"

/*
DATA TYPE   NAME        ARGUMENTS                                                                                           */
double      biseccion   (double (*f)(double),
                        double  a,
                        double  b,
                        double  tolerancia,
                        int     max_iter,
                        int     decimales)
{
// Paso 1: Validar signos opuestos mediante el Teorema del Valor Intermedio
    double fa = redondear(f(a), decimales);
    double fb = redondear(f(b), decimales);
    
    if (fa * fb >= 0.0) {
        printf("[ERROR] f(a) y f(b) no tienen signos opuestos. Biseccion no puede iniciar.\n");
        return -1.0;
    }

    // Cabezal de la tabla especificada en la Página 2 del PDF
    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-11s | %-9s |\n", 
           "n", "a", "b", "p", "f(a)", "f(b)", "f(p)", "f(a)*f(p)", "Error");
    printf("|-----|-----------|-----------|-----------|-----------|-----------|-----------|-------------|-----------|\n");

    double p, fp, error;
    
    for (int n = 1; n <= max_iter; n++) {
        p   = redondear((a + b) / 2.0, decimales); // Paso 2: Aproximación [cite: 3, 5]
        fp  = redondear(f(p), decimales);
        fa  = redondear(f(a), decimales);
        fb  = redondear(f(b), decimales);
        double prod = redondear(fa * fp, decimales);
        
        error = redondear((b - a) / 2.0, decimales); // Paso 4: Error del método [cite: 8]

        // Imprime la fila con formato exacto al PDF
        printf("| %-3d | %-9.6f | %-9.6f | %-9.6f | %-9.6f | %-9.6f | %-9.6f | %-11.6f | %-9.6f |\n", 
               n, a, b, p, fa, fb, fp, prod, error);

        // Paso 5: Criterio de parada (Error < Tolerancia) [cite: 9, 10]
        if (error < tolerancia) {
            printf("\n[✓] Raiz encontrada con éxito en la iteracion %d: p = %.6f\n", n, p);
            return p;
        }

        // Paso 3: Cambio de intervalo [cite: 4]
        if (prod > 0.0) {
            a = p; // Siguiente iteración [p, b] [cite: 6]
        } else {
            b = p; // Siguiente iteración [a, p] [cite: 7]
        }
    }

    printf("\n[x] Se alcanzo el limite maximo de iteraciones sin converger completamente.\n");
    return p;
}