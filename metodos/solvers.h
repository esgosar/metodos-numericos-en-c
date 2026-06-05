#ifndef SOLVERS_H
#define SOLVERS_H

/* ==========================================================================================
 * MODULO: SOLVERS ALGORITMICOS PARA ENCONTRAR RAICES
 * ==========================================================================================
 * OUTPUT REGISTER | FUNCTION POINTER | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
 * (64-bit IEEE754)| (Code Address)   | (Type)            (Identifier)     | (Set Theory)
 * ==========================================================================================
 */

double               biseccion          (double           (*funcion)(double),// f: ℝ → ℝ
                                         double           a,                 // a, b ∈ ℝ
                                         double           b,                 // b > a
                                         double           tolerancia,        // Tol ∈ ℝ⁺
                                         int              max_iter,          // max_iter ∈ ℕ
                                         int              decimales);        // decimales ∈ ℕ

/* ========================================================================================== */

#endif