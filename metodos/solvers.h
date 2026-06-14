#ifndef SOLVERS_H
#define SOLVERS_H

#include <math.h>

/* ==========================================================================================
 * [MODULO 1]: BUSQUEDA DE RAICES EN UNA VARIABLE (Ecuaciones No Lineales 1D)
 * ==========================================================================================
 * OUTPUT REGISTER   | FUNCTION POINTER     | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
 * (64-bit IEEE754)  | (Code Address)       | (Type)        (Identifier)         | (Set Theory)
 * ==========================================================================================
 */

double                 biseccion            (double         (*f)(double),        // f: ℝ → ℝ
                                             double         a,                   // a ∈ ℝ
                                             double         b,                   // b ∈ ℝ | b > a
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

double                 newton_raphson       (double         (*f)(double),        // f: ℝ → ℝ
                                             double         (*df)(double),       // f': ℝ → ℝ
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

double                 punto_fijo           (double         (*g)(double),        // g: ℝ → ℝ (Iteradora)
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

double                 secante              (double         (*f)(double),        // f: ℝ → ℝ
                                             double         p0,                  // p0 ∈ ℝ (n-2)
                                             double         p1,                  // p1 ∈ ℝ (n-1)
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

double                 posicion_falsa       (double         (*f)(double),        // f: ℝ → ℝ
                                             double         p0,                  // p0 ∈ ℝ
                                             double         p1,                  // p1 ∈ ℝ | f(p0)*f(p1)<0
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

double                 pos_falsa_modificada (double         (*f)(double),        // f: ℝ → ℝ
                                             double         p0,                  // p0 ∈ ℝ
                                             double         p1,                  // p1 ∈ ℝ | f(p0)*f(p1)<0
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ==========================================================================================
 * [MODULO 2]: RAICES COMPLEJAS Y POLINOMIALES (Proximamente)
 * ==========================================================================================
// double              muller_real          (double         (*f)(double),        ...
// double complex      muller_imaginario    (double complex (*f)(double complex),...
 * ========================================================================================== */

/* ==========================================================================================
 * [MODULO 3]: INTERPOLACION Y APROXIMACION POLINOMIAL (Proximamente)
 * ==========================================================================================
// double              lagrange             (double* x,                   ...
// double              neville              (double* x,                   ...
// double              dif_divididas_newton (double* x,                   ...
 * ========================================================================================== */

/* ==========================================================================================
 * [MODULO 4]: SISTEMAS DE ECUACIONES LINEALES Y NO LINEALES (Proximamente)
 * ==========================================================================================
// void                jacobi               (double** matriz_A,            ...
// void                gauss_seidel         (double** matriz_A,            ...
 * ========================================================================================== */

#endif // SOLVERS_H