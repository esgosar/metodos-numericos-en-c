#ifndef SOLVERS_H
#define SOLVERS_H

/* ==========================================================================================
 * MODULO: SOLVERS ALGORITMICOS PARA ENCONTRAR RAICES
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

double                 newton_raphson       (double         (*f)(double),        // f: ℝ → ℝ
                                             double         (*df)(double),       // f': ℝ → ℝ
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

double                 punto_fijo           (double         (*g)(double),        // g: ℝ → ℝ (Iteradora)
                                             double         x0,                  // x0 ∈ ℝ
                                             double         tolerancia,          // Tol ∈ ℝ⁺
                                             int            max_iter,            // max_iter ∈ ℕ
                                             int            decimales);          // decimales ∈ ℕ

/* ========================================================================================== */

#endif