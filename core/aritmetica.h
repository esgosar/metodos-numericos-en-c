#ifndef ARITMETICA_H
#define ARITMETICA_H

/* ==========================================================================================
MODULO: ARITMETICA DE MAQUINA Y CONTROL DE DENSE-BITS
==========================================================================================
OUTPUT REGISTER | FUNCTION POINTER | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
(64-bit IEEE754)| (Code Address)   | (Type)  (Identifier)               | (Set Theory)
========================================================================================== */

double               redondear          (double   numero,                    // x ∈ ℝ, d ∈ ℤ
                                         int      decimales);

double               truncar            (double   numero,                    // x ∈ ℝ, d ∈ ℤ
                                         int      decimales);

double               tolerancia         (double   l_max,                     // Lmax, Lmin ∈ ℝ
                                         double   l_min);

/* ========================================================================================== */

#endif