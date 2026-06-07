#include <stdio.h>
#include <math.h>
#include "core/aritmetica.h"
#include "teoremas/validacion.h"
#include "metodos/solvers.h"

/* ==========================================================================================
 * ESPACIO DE USUARIO (USER SPACE): DEFINICIÓN DE SEÑALES FÍSICAS O ECUACIONES
 * ========================================================================================== */

// 1. Función principal f(x): La que antes estaba "quemada" adentro del motor
double         ecuacion_f           (double x) { 
    return (x * cos(x)) - (2.0 * x * x) + (3.0 * x) - 1.0; 
}

// 2. Derivada analítica f'(x): Requerida por la FPU para Newton-Raphson
double         ecuacion_df          (double x) { 
    return cos(x) - (x * sin(x)) - (4.0 * x) + 3.0; 
}

// 3. Función iteradora g(x): Despeje de x para Punto Fijo
double         ecuacion_g           (double x) { 
    return ((x * cos(x)) - (2.0 * x * x) - 1.0) / -3.0; 
}

/* ==========================================================================================
 * BANCO DE PRUEBAS DEL SISTEMA (MAIN ENTRY POINT)
 * ========================================================================================== */

int main() {
    printf("=================================================================================\n");
    printf("   ARCHITECTURE TEST: NUMERICAL COMPUTATION ENGINE\n");
    printf("=================================================================================\n\n");

    /* --- PARAMETROS DE CONFIGURACIÓN DEL HARDWARE --- */
    double         tol                = tolerancia(0.0001, 0.0); // Tolerancia estricta
    int            bits_precision     = 6;                       // Renderizado dinámico a 6 decimales
    int            ciclos_cpu         = 15;                      // Timeout (max iteraciones)

    printf("[FPU CONFIG]: Tolerancia: %.6f | Precision FPU: %d decimales | Ciclos Max: %d\n\n", 
           tol, bits_precision, ciclos_cpu);

    // ---------------------------------------------------------------------------------
    // TEST 1: METODO DE BISECCION (Inyectando el puntero 'ecuacion_f')
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: BISECCION [Intervalo: a = 0.0, b = 1.0]\n");
    biseccion(ecuacion_f, 0.0, 1.0, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 2: METODO DE NEWTON-RAPHSON (Inyectando 'ecuacion_f' y 'ecuacion_df')
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: NEWTON-RAPHSON [Punto Inicial x0 = 0.5]\n");
    newton_raphson(ecuacion_f, ecuacion_df, 0.5, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 3: METODO DE PUNTO FIJO (Inyectando iteradora 'ecuacion_g')
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: PUNTO FIJO [Punto Inicial x0 = 0.5]\n");
    punto_fijo(ecuacion_g, 0.5, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 4: PRUEBA DEL CONTROLADOR DE INTERRUPCIONES (Simulación de falla)
    // ---------------------------------------------------------------------------------
    printf(">> PROBANDO BUS DE EXCEPCIONES: Intento de Biseccion con violacion del TVI [1.0, 2.0]\n");
    // Al pasarle un intervalo donde no cruza el cero, el motor debe escupir el error 0x01
    biseccion(ecuacion_f, 1.0, 2.0, tol, ciclos_cpu, bits_precision);

    printf("\n[SYS] Fin de la ejecucion. Liberando memoria.\n");
    return 0;
}