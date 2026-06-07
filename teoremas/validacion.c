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

bool                   teorema_valor_intermedio     (double         (*f)(double),       // f: ℝ → ℝ
                                                     double         a,                  // a ∈ ℝ
                                                     double         b)                  // b ∈ ℝ | a < b
{ 
    // Ahora 'f' es dinamica y evalua exactamente lo que se le inyecte desde el solver
    bool status = (redondear(f(a), 6) * redondear(f(b), 6)) < 0.0; 
    if (!status) disparar_excepcion(EXC_TVI_SIGNOS_IGUALES);
    return status;
}