#include <stdio.h>
#include <math.h>

// Bus de integracion de modulos del sistema
#include "core/aritmetica.h"
#include "errores/metricas.h"
#include "errores/excepciones.h"
#include "teoremas/validacion.h"
// #include "metodos/solvers.h" // Descomenta esto cuando comiences a programar Biseccion/Newton

#define DEC 6 // Precision global del Test Bench

/* ==========================================================================================
 * FUNCION DE PRUEBA DEL SISTEMA (DUMMY FUNCTION)
 * Ecuacion: f(x) = x^3 - x - 2
 * Raiz conocida aproximadamente en x = 1.521
 * ==========================================================================================
 */
double f_prueba(double x) {
    // Simulando el paso por la ALU con truncamiento estricto
    double resultado = pow(x, 3.0) - x - 2.0;
    return redondear(resultado, DEC);
}

int main() {
    printf("\n");
    printf("=================================================================================\n");
    printf("              MOTOR DE METODOS NUMERICOS - CENTRAL TEST BENCH\n");
    printf("=================================================================================\n");
    printf(" [SYSTEM]: Inicializando Unidad Aritmetico Logica (ALU)...\n");
    printf(" [FPU STATUS]: Redondeo estricto configurado a %d decimales.\n", DEC);
    printf("---------------------------------------------------------------------------------\n\n");

    /* ----------------------------------------------------------------------------------
     * PRUEBA 1: VERIFICACION DE ARITMETICA Y REDONDEO FPU
     * ---------------------------------------------------------------------------------- */
    printf(">> TEST MODULO 1: ALU Y PRECISION DE PUNTO FLOTANTE\n");
    double pi_raw = 3.14159265358979;
    printf("   Entrada cruda (Raw) : %.12f\n", pi_raw);
    printf("   Salida procesada    : %g\n", redondear(pi_raw, DEC));
    printf("   [STATUS] -> OK.\n\n");

    /* ----------------------------------------------------------------------------------
     * PRUEBA 2: SUPERVISOR DE TEOREMAS MATEMATICOS
     * ---------------------------------------------------------------------------------- */
    printf(">> TEST MODULO 2
