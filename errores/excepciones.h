#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

/* ==========================================================================================
 * ESTRUCTURA: REGISTRO DE ESTADOS Y CÓDIGOS DE INTERRUPCIÓN (STATUS FLAGS)
 * ==========================================================================================
 * HEX / VALUE    | CONSTANT IDENTIFIER          | SYSTEM DESCRIPTION
 * (32-bit int)   | (Enum Label)                 | (Hardware / Logic Trigger Condition)
 * ========================================================================================== */
typedef enum {
    EXC_NINGUNA                 = 0,             // Flujo normal. Operacion exitosa.
    EXC_TVI_SIGNOS_IGUALES      = 1,             // Falla logica: Ausencia de cruce por cero (Raiz no garantizada).
    EXC_NEWTON_DERIVADA_CERO    = 2,             // Falla en ALU: Pendiente nula (Riesgo de division por cero).
    EXC_TIMEOUT_ITERACIONES     = 3,             // Advertencia: Desbordamiento de ciclos permitidos.
    EXC_ALU_DIVISION_CERO       = 4              // Falla en ALU: Division por cero en calculo de metricas.
} ExcepcionHardware;


/* ==========================================================================================
 * MODULO: CONTROLADOR DE INTERRUPCIONES Y MANEJO DE EXCEPCIONES (I/O)
 * ==========================================================================================
 * OUTPUT REGISTER   | FUNCTION POINTER             | INPUT ARGUMENTS (STACK ALLOCATION) 
 * (Hardware Type)   | (Code Address)               | (Type)              (Identifier)        
 * ========================================================================================== */
void                   disparar_excepcion           (ExcepcionHardware    codigo);

#endif