#ifndef METRICAS_H
#define METRICAS_H

/* ==========================================================================================
MODULO: METRICAS DE ERROR Y ANALISIS DE PRECISION CONTINUA
==========================================================================================
OUTPUT REGISTER | FUNCTION POINTER | INPUT ARGUMENTS (STACK ALLOCATION) | MATH DOMAIN
(64-bit IEEE754)| (Code Address)   | (Type)  (Identifier)               | (Set Theory)
========================================================================================== */

double               error_absoluto     (double   valor_real,                // Vr, Va ∈ ℝ
                                         double   valor_aproximado);

double               error_relativo     (double   valor_real,                // Vr, Va ∈ ℝ | Vr ≠ 0
                                         double   valor_aproximado);

double               error_porcentual   (double   valor_real,                // Vr, Va ∈ ℝ | Vr ≠ 0
                                         double   valor_aproximado);

/* ========================================================================================== */

#endif