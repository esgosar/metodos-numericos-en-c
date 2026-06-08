#include <stdio.h>
#include <math.h>
#include "solvers.h"
#include "../core/aritmetica.h"
#include "../errores/excepciones.h"              // Bus de interrupciones de hardware
#include "../teoremas/validacion.h"              // Supervisor del Teorema (TVI)

/* ==========================================================================================
 MODULO: SOLVERS ALGORITMICOS PARA ENCONTRAR RAICES
 ==========================================================================================
 OUTPUT REGISTER   | FUNCTION POINTER     | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
 (64-bit IEEE754)  | (Code Address)       | (Type)        (Identifier)         | (Set Theory)
 ========================================================================================== */

double                 biseccion            (double         (*f)(double),        // f: ℝ → ℝ
                                             double         a,                   // a ∈ ℝ
                                             double         b,                   // b ∈ ℝ | b > a
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales)           // decimales ∈ ℕ
{
    // ENLACE CORREGIDO: Se inyecta la direccion de 'f' hacia el supervisor logico
    if (!teorema_valor_intermedio(f, a, b)) return NAN;

    // Cabezal de la tabla matricial especificada en la Página 2 del PDF
    printf("\n| %-3s | %-9s | %-9s | %-9s | %-9s | %-9s | %-9s | %-11s | %-9s |\n", 
           "n", "a", "b", "p", "f(a)", "f(b)", "f(p)", "f(a)*f(p)", "Error");
    printf("|-----|-----------|-----------|-----------|-----------|-----------|-----------|-------------|-----------|\n");

    /* --- ASIGNACION DE REGISTROS DE TRABAJO (STACK) --- */
    double                 p                  = 0.0;
    double                 fp                 = 0.0;
    double                 fa                 = 0.0;
    double                 fb                 = 0.0;
    double                 prod               = 0.0;
    double                 error              = 0.0;

    for (int n = 1; n <= max_iter; n++) {
        // 1. EL ESPACIO SE MANTIENE EXACTO (Doble precision)
        p     = (a + b) / 2.0; 
        error = (b - a) / 2.0; 

        // 2. EL MOTOR FPU EVALUA LA FUNCION CON REDONDEO
        fp    = redondear(f(p), decimales);
        fa    = redondear(f(a), decimales);
        fb    = redondear(f(b), decimales);
        // prod  = fa * fp; NO REDONDEAR porque genera underflow en cantidades muy pequeñas. 

        

        // La impresion (printf) se encarga de mostrarlos cortados visualmente,
        // pero en la memoria de la computadora siguen siendo exactos.
        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-9.*f | %-11.*f | %-9.*f |\n", 
               n, decimales, a, decimales, b, decimales, p, decimales, fa, decimales, fb, decimales, fp, decimales, prod, decimales, error);

        if (error < tolerancia) {
            // AQUI SI REDONDEAMOS EL RESULTADO FINAL PARA ENTREGARLO
            double resultado_final = redondear(p, decimales);
            printf("\n[✓] Biseccion: Convergencia alcanzada en la iteracion %d: p = %.*f\n", n, decimales, resultado_final);
            return resultado_final;
        }

        // En lugar de calcular prod y hacer: if (prod > 0.0)
        // Evaluamos directamente si fa y fp tienen el mismo signo:
        if ((fa > 0.0 && fp > 0.0) || (fa < 0.0 && fp < 0.0)) { 
            a = p; 
        } else { 
            b = p; 
        }
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return p;
}

/* ========================================================================================== */

double                 newton_raphson       (double         (*f)(double),        // f: ℝ → ℝ
                                             double         (*df)(double),       // f': ℝ → ℝ
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales)           // decimales ∈ ℕ
{
    // Cabezal de la tabla matricial especificada en la Página 2 del PDF de Newton
    printf("\n| %-3s | %-9s | %-9s | %-9s |\n", "n", "Xn", "Xn+1", "Error");
    printf("|-----|-----------|-----------|-----------|\n");

    /* --- ASIGNACION DE REGISTROS DE TRABAJO (STACK) --- */
    double                 xn                 = redondear(x0, decimales);
    double                 xn_siguiente       = 0.0;
    double                 fx                 = 0.0;
    double                 dfx                = 0.0;
    double                 error              = 0.0;

    for (int n = 1; n <= max_iter; n++) {
        fx  = redondear(f(xn), decimales);
        dfx = redondear(df(xn), decimales);

        // INTERRUPCION FPU: Pendiente nula (Evita indeterminación logica x / 0.0)
        if (dfx == 0.0) {
            disparar_excepcion(EXC_NEWTON_DERIVADA_CERO);
            return NAN;
        }

        xn_siguiente = redondear(xn - (fx / dfx), decimales);
        error        = redondear(fabs(xn - xn_siguiente), decimales);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, xn, decimales, xn_siguiente, decimales, error);

        if (error < tolerancia) {
            printf("\n[✓] Newton-Raphson: Convergencia alcanzada en la iteracion %d: x = %.*f\n", n, decimales, xn_siguiente);
            return xn_siguiente;
        }

        xn = xn_siguiente;
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return xn;
}

/* ========================================================================================== */

double                 punto_fijo           (double         (*g)(double),        // g: ℝ → ℝ (Iteradora)
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales)           // decimales ∈ ℕ
{
    // Cabezal de la tabla matricial especificada en la Página 2 del PDF de Punto Fijo
    printf("\n| %-3s | %-9s | %-9s | %-9s |\n", "n", "x_n", "g(x_n)", "Error");
    printf("|-----|-----------|-----------|-----------|\n");

    /* --- ASIGNACION DE REGISTROS DE TRABAJO (STACK) --- */
    double                 xn                 = redondear(x0, decimales);
    double                 gx                 = 0.0;
    double                 error              = 0.0;

    for (int n = 1; n <= max_iter; n++) {
        gx    = redondear(g(xn), decimales);
        error = redondear(fabs(xn - gx), decimales);

        printf("| %-3d | %-9.*f | %-9.*f | %-9.*f |\n", 
               n, decimales, xn, decimales, gx, decimales, error);

        if (error < tolerancia) {
            printf("\n[✓] Punto Fijo: Convergencia alcanzada en la iteracion %d: x = %.*f\n", n, decimales, gx);
            return gx;
        }

        xn = gx;
    }

    disparar_excepcion(EXC_TIMEOUT_ITERACIONES);
    return xn;
}