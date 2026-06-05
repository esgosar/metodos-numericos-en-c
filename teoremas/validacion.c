#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "validacion.h"
#include "../core/aritmetica.h"
#include "../errores/excepciones.h"              // Bus de interrupciones externo

/* ==========================================================================================
 * MODULO: TEOREMAS MATEMATICOS Y COMPROBACIONES LOGICAS
 * ==========================================================================================
 * OUTPUT REGISTER   | FUNCTION POINTER             | INPUT ARGUMENTS (STACK ALLOCATION)| MATH DOMAIN
 * (Hardware Type)   | (Code Address)               | (Type)        (Identifier)        | (Set Theory)
 * ==========================================================================================
 */

double                 f                            (double         x)                  // x ∈ ℝ
{ return (x * cos(x)) - (2.0 * x * x) + (3.0 * x) - 1.0; }                              

// Retorno: Registro de 8-bits (0x00 = false, 0x01 = true)
bool                   teorema_valor_intermedio     (double         a,                  // a ∈ ℝ
                                                     double         b)                  // b ∈ ℝ | a < b
{ 
    bool status = (redondear(f(a), 6) * redondear(f(b), 6)) < 0.0; 
    if (!status) disparar_excepcion(EXC_TVI_SIGNOS_IGUALES);
    return status;
}