#include <stdio.h>
#include "excepciones.h"

/* --- ROM DATA: MATRIZ INMUTABLE DE MENSAJES DE ESTADO --- */
static const char* MAPA_MENSAJES[] = {
    "Operacion concluida con exito.",
    "FATAL EXCEPTION: Violacion del TVI. f(a) y f(b) comparten signo logico.",
    "FATAL EXCEPTION: Division por cero en ALU (Derivada igual a 0.0).",
    "WARNING EXCEPTION: Limite maximo de ciclos de iteracion alcanzado sin convergencia.",
    "FATAL EXCEPTION: Division por cero en ALU (Valor real es 0.0)."
};

/* ========================================================================================== */

void disparar_excepcion(ExcepcionHardware codigo) {
    // Extraccion indexada O(1) directo a la salida estandar (stdout)
    printf("%s\n", MAPA_MENSAJES[codigo]);
}