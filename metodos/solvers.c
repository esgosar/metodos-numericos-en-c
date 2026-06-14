#include <stdio.h>
#include <math.h>
#include "solvers.h"
#include "../core/aritmetica.h"
#include "../errores/excepciones.h"
#include "../teoremas/validacion.h"

/* ==========================================================================================
 * MODULO 1: SOLVERS ALGORITMICOS PARA ENCONTRAR RAICES 1D
 * ========================================================================================== */

double biseccion(double (*f)(double), double a, double b, double tolerancia, int max_iter, int decimales) {
    if (!teorema_valor_intermedio(f, a, b)) return NAN;

    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-11s | %-9s |\n", 
           "n", "a", "b", "p", "f(a)", "f(b)", "f(p)", "f(a)*f(p)", "Error");
    printf("|-----|-----------|-----------|-----------|-----------|-----------|-----------|-------------|-----------|\n");

    double p = 0.0, fp = 0.0, fa = 0.0, fb = 0.0, prod = 0.0, error = 0.0;

    for (int n = 1; n <= max_iter; n++) {
        p     = (a + b) / 2.0; 
        error = (b - a) / 2.0; 

        fp    = redondear(f(p), decimales);
        fa    = redondear(f(a), decimales);
        fb    = redondear(f(b), decimales);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-11.*f | %-9.*f |\n", 
               n, decimales, a, decimales, b, decimales, p, decimales, fa, decimales, fb, decimales, fp, decimales, prod, decimales, error);

        if (error < tolerancia) {
            double resultado_final = redondear(p, decimales);
            printf("\n[✓] Biseccion: Convergencia alcanzada en la iteracion %d: p = %.*f\n", n, decimales, resultado_final);
            return resultado_final;
        }

        if ((fa > 0.0 && fp > 0.0) || (fa < 0.0 && fp < 0.0)) { a = p; } else { b = p; }
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return p;
}

/* ========================================================================================== */

double newton_raphson(double (*f)(double), double (*df)(double), double x0, double tolerancia, int max_iter, int decimales) {
    printf("\n| %-3s | %-9s | %-9s | %-9s |\n", "n", "Xn", "Xn+1", "Error");
    printf("|-----|-----------|-----------|-----------|\n");

    double xn = redondear(x0, decimales), xn_siguiente = 0.0, fx = 0.0, dfx = 0.0, error = 0.0;

    for (int n = 1; n <= max_iter; n++) {
        fx  = f(xn);   
        dfx = df(xn);  

        if (dfx == 0.0) {
            disparar_excepcion(EXC_NEWTON_DERIVADA_CERO);
            return NAN;
        }

        xn_siguiente = xn - (fx / dfx);
        error        = fabs(xn_siguiente - xn);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, xn, decimales, xn_siguiente, decimales, error);

        if (error < tolerancia) {
            printf("\n[✓] Newton-Raphson: Convergencia alcanzada en la iteracion %d: x = %.*f\n", n, decimales, xn_siguiente);
            return redondear(xn_siguiente, decimales);
        }

        xn = xn_siguiente;
    }
    
    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return xn;
}

/* ========================================================================================== */

double punto_fijo(double (*g)(double), double x0, double tolerancia, int max_iter, int decimales) {
    printf("\n| %-3s | %-9s | %-9s | %-9s |\n", "n", "x_n", "g(x_n)", "Error");
    printf("|-----|-----------|-----------|-----------|\n");

    double x_prev = redondear(x0, decimales);
    double val_g0 = g(x_prev);
    
    if (isnan(val_g0)) {
        disparar_excepcion(EXC_NEWTON_DERIVADA_CERO);
        return NAN;
    }
    
    double xn = redondear(val_g0, decimales); 

    for (int n = 1; n <= max_iter; n++) {
        double error = redondear(fabs(xn - x_prev), decimales);
        double val_gnext = g(xn);
        
        if (isnan(val_gnext)) {
            printf("| %-3d | %-9.*f | %-9s | %-9.*f |\n", n, decimales, xn, "NAN", decimales, error);
            disparar_excepcion(EXC_NEWTON_DERIVADA_CERO);
            return NAN;
        }
        
        double x_next = redondear(val_gnext, decimales);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f |\n", n, decimales, xn, decimales, x_next, decimales, error);

        if (error < tolerancia) {
            printf("\n[✓] Punto Fijo: Convergencia alcanzada en la iteracion %d: x = %.*f\n", n, decimales, xn);
            return xn;
        }

        x_prev = xn;
        xn     = x_next;
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return xn;
}

/* ==========================================================================================
 * NUEVOS METODOS A TESTEAR (Secante y Posicion Falsa)
 * ========================================================================================== */

double secante(double (*f)(double), double p0, double p1, double tolerancia, int max_iter, int decimales) {
    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s |\n", "n", "p_n-1", "p_n", "p_n+1", "Error");
    printf("|-----|-----------|-----------|-----------|-----------|\n");

    double q0 = f(p0);
    double q1 = f(p1);
    double p = 0.0, error = 0.0;

    for (int n = 2; n <= max_iter; n++) {
        // Validacion de pendiente cero (Evita division por cero)
        if ((q1 - q0) == 0.0) {
            disparar_excepcion(EXC_NEWTON_DERIVADA_CERO);
            return NAN;
        }

        // Formula de la Secante (sin redondear variables intermedias para maxima precision)
        p = p1 - q1 * (p1 - p0) / (q1 - q0);
        error = fabs(p - p1);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, p0, decimales, p1, decimales, p, decimales, error);

        if (error < tolerancia) {
            printf("\n[✓] Secante: Convergencia alcanzada en la iteracion %d: p = %.*f\n", n, decimales, p);
            return redondear(p, decimales);
        }

        // Shift de registros para siguiente ciclo
        p0 = p1;
        q0 = q1;
        p1 = p;
        q1 = f(p);
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return p;
}

/* ========================================================================================== */

double posicion_falsa(double (*f)(double), double p0, double p1, double tolerancia, int max_iter, int decimales) {
    if (!teorema_valor_intermedio(f, p0, p1)) return NAN;

    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s |\n", 
           "n", "p0", "p1", "p", "f(p0)", "f(p1)", "f(p)");
    printf("|-----|-----------|-----------|-----------|-----------|-----------|-----------|\n");

    double q0 = f(p0);
    double q1 = f(p1);
    double p = 0.0, q = 0.0, error = 0.0;

    for (int n = 2; n <= max_iter; n++) {
        p = p1 - q1 * (p1 - p0) / (q1 - q0);
        q = f(p);
        error = fabs(p - p1);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, p0, decimales, p1, decimales, p, decimales, q0, decimales, q1, decimales, q);

        if (error < tolerancia) {
            printf("\n[✓] Posicion Falsa 1: Convergencia en iteracion %d: p = %.*f\n", n, decimales, p);
            return redondear(p, decimales);
        }

        // Control de signos (Bracket preservation)
        if (q * q1 < 0.0) {
            p0 = p1;
            q0 = q1;
        } 
        p1 = p;
        q1 = q;
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return p;
}

/* ========================================================================================== */

double posicion_falsa_modificada(double (*f)(double), double p0, double p1, double tolerancia, int max_iter, int decimales) {
    if (!teorema_valor_intermedio(f, p0, p1)) return NAN;

    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s |\n", 
           "n", "p0", "p1", "p", "f(p0)", "f(p1)", "f(p)");
    printf("|-----|-----------|-----------|-----------|-----------|-----------|-----------|\n");

    double q0 = f(p0);
    double q1 = f(p1);
    double p = 0.0, q = 0.0, error = 0.0;

    for (int n = 2; n <= max_iter; n++) {
        p = p1 - q1 * (p1 - p0) / (q1 - q0);
        q = f(p);
        error = fabs(p - p1);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, p0, decimales, p1, decimales, p, decimales, q0, decimales, q1, decimales, q);

        if (error < tolerancia) {
            printf("\n[✓] Pos. Falsa Modificada (Illinois): Convergencia iteracion %d: p = %.*f\n", n, decimales, p);
            return redondear(p, decimales);
        }

        // Algoritmo de Illinois (Anti-Estancamiento)
        if (q * q1 < 0.0) {
            p0 = p1;
            q0 = q1;
            p1 = p;
            q1 = q;
        } else {
            // El truco de Illinois: Forzamos la caida de la secante reduciendo q0 a la mitad
            q0 = q0 / 2.0;
            p1 = p;
            q1 = q;
        }
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return p;
}