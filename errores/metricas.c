#include <math.h>
#include "metricas.h"
#include "excepciones.h"                         // Controlador de interrupciones local

/* ==========================================================================================
 * MODULO: METRICAS DE ERROR E INFERENCIA DE PRECISION
 * ==========================================================================================
 * OUTPUT REGISTER   | FUNCTION POINTER     | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
 * (64-bit IEEE754)  | (Code Address)       | (Type)        (Identifier)         | (Set Theory)
 * ==========================================================================================
 */

double                 error_absoluto       (double         valor_real,          // Vr ∈ ℝ
                                             double         valor_aproximado)    // Va ∈ ℝ
{ return fabs(valor_real - valor_aproximado); }

double                 error_relativo       (double         valor_real,          // Vr ∈ ℝ | Vr ≠ 0
                                             double         valor_aproximado)    // Va ∈ ℝ
{
    if (valor_real == 0.0) { disparar_excepcion(EXC_ALU_DIVISION_CERO); return NAN; }
    return fabs((valor_real - valor_aproximado) / valor_real); 
}

double                 error_porcentual     (double         valor_real,          // Vr ∈ ℝ | Vr ≠ 0
                                             double         valor_aproximado)    // Va ∈ ℝ
{ 
    double rel = error_relativo(valor_real, valor_aproximado);
    return isnan(rel) ? NAN : rel * 100.0; 
}