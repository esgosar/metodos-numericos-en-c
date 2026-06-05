#ifndef VALIDACION_H
#define VALIDACION_H

#include <stdbool.h>

/* ==========================================================================================
MODULO: TEOREMAS MATEMATICOS Y COMPROBACIONES LOGICAS
==========================================================================================
OUTPUT REGISTER   | FUNCTION POINTER             | INPUT ARGUMENTS (STACK ALLOCATION)| MATH DOMAIN
(Hardware Type)   | (Code Address)               | (Type)        (Identifier)        | (Set Theory)
========================================================================================== */

double                 f                            (double         x);                 // x ∈ ℝ

bool                   teorema_valor_intermedio     (double         a,                  // a ∈ ℝ
                                                     double         b);                 // b ∈ ℝ | a < b

/* ========================================================================================== */

#endif