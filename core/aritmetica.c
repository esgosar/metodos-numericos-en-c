#include <math.h>
#include "aritmetica.h"

/* ==========================================================================================
MODULO: ARITMETICA DE MAQUINA Y MANIPULACION DE REGISTROS
==========================================================================================
OUTPUT REGISTER   | FUNCTION POINTER     | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
(64-bit IEEE754)  | (Code Address)       | (Type)        (Identifier)         | (Set Theory)
========================================================================================== */

double                 redondear            (double         numero,              // x ∈ ℝ
                                             int            decimales)           // d ∈ ℕ
{
    /* --- ASIGNACION DE MEMORIA LOCAL (STACK) ---
    TYPE (64-bit)       IDENTIFIER           VALUE (PROCESSOR ALU)              */
    double                 multiplicador      = pow(10.0, decimales);            // 10^d
    double                 desplazado         = numero * multiplicador;          // e.g. 3.14159265 * 10^6 = 3141592.65...

    // [Operación de ALU]: 314592.65 > 0  ->  314592.65 + 0.5 = 314593.15  ->  (long long) = 314593  ->  314593 / 10^6 = 3.141593
    return ((desplazado >= 0.0) ? (double)((long long)(desplazado + 0.5)) : (double)((long long)(desplazado - 0.5))) / multiplicador;
}

double                 truncar              (double         numero,              // x ∈ ℝ
                                             int            decimales)           // d ∈ ℕ
{
    /* --- ASIGNACION DE MEMORIA LOCAL (STACK) ---
    TYPE (64-bit)       IDENTIFIER           VALUE (PROCESSOR ALU)            */
    double                 multiplicador      = pow(10.0, decimales);
    double                 desplazado         = numero * multiplicador;
    
    // [Operación de ALU]: (long long)314593.15...  ->  314593  ->  314593 / 10^6 = 3.141593
    return (double)((long long)desplazado) / multiplicador;
}

double                 tolerancia           (double         l_max,               // L_max ∈ ℝ
                                             double         l_min)               // L_min ∈ ℝ
{ return l_max - l_min; }