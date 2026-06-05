#include <math.h>
#include "metricas.h"

/* ==========================================================================================
MODULO: METRICAS DE ERROR E INFERENCIA DE PRECISION
==========================================================================================
OUTPUT REGISTER   | FUNCTION POINTER     | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
(64-bit IEEE754)  | (Code Address)       | (Type)        (Identifier)         | (Set Theory)
========================================================================================== */

double                 error_absoluto       (double         valor_real,          // Vr ∈ ℝ
                                             double         valor_aproximado)    // Va ∈ ℝ
{ return fabs(valor_real - valor_aproximado); }

double                 error_relativo       (double         valor_real,          // Vr ∈ ℝ | Vr ≠ 0
                                             double         valor_aproximado)    // Va ∈ ℝ
{ return (valor_real == 0.0) ? 0.0 : fabs((valor_real - valor_aproximado) / valor_real); }

double                 error_porcentual     (double         valor_real,          // Vr ∈ ℝ | Vr ≠ 0
                                             double         valor_aproximado)    // Va ∈ ℝ
{ return error_relativo(valor_real, valor_aproximado) * 100.0; }