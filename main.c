#include <stdio.h>
#include <math.h>
#include "core/aritmetica.h"
#include "teoremas/validacion.h"
#include "metodos/solvers.h"
#include "errores/metricas.h"

// Derivada exacta de f(x) para Newton-Raphson: f'(x) = cos(x) - x*sin(x) - 4x + 3
double df_proyecto(double x) { 
    return cos(x) - (x * sin(x)) - (4.0 * x) + 3.0; 
}

// Despeje g(x) para Punto Fijo desde f(x) = 0: x = (x*cos(x) - 2x^2 - 1) / -3
double g_proyecto(double x) { 
    return ((x * cos(x)) - (2.0 * x * x) - 1.0) / -3.0; 
}

int main() {
    printf("=================================================================================\n");
    printf("   ARCHITECTURE TEST: ADVANCED COMPUTER NUMERICAL ENGINE\n");
    printf("=================================================================================\n\n");

    // Configuración de la ALU de control
    double tol = tolerancia(0.0001, 0.0000); // Tol = 0.0001
    int bits_precision = 6;                  // Forzar visualización matricial a 6 decimales
    int ciclos_cpu = 15;                     // Límite de iteraciones antes de la interrupción

    printf("[FPU STATUS]: Tolerancia cargada: %.6f | Precision FPU: %d decimales\n\n", tol, bits_precision);

    // ---------------------------------------------------------------------------------
    // TEST 1: EJECUCIÓN DEL SOLVER DE BISECCIÓN
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: BISECCION [Intervalo: a = 0.0, b = 1.0]\n");
    biseccion(f, 0.0, 1.0, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 2: EJECUCIÓN DEL SOLVER DE NEWTON-RAPHSON
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: NEWTON-RAPHSON [Punto Inicial x0 = 0.5]\n");
    newton_raphson(f, df_proyecto, 0.5, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 3: EJECUCIÓN DEL SOLVER DE PUNTO FIJO
    // ---------------------------------------------------------------------------------
    printf(">> DISPARANDO SUBPROCESO: PUNTO FIJO [Punto Inicial x0 = 0.5]\n");
    punto_fijo(g_proyecto, 0.5, tol, ciclos_cpu, bits_precision);
    printf("\n---------------------------------------------------------------------------------\n");

    // ---------------------------------------------------------------------------------
    // TEST 4: PRUEBA DE CONTROL DE EXCEPCIONES (Simulación de Fallas)
    // ---------------------------------------------------------------------------------
    printf(">> PROBANDO INTERRUPCIONES SIMULADAS (Supervisor de Teoremas):\n");
    printf("Intentando biseccion en intervalo invalido [1.0, 2.0]...\n");
    biseccion(f, 1.0, 2.0, tol, ciclos_cpu, bits_precision);

    return 0;
}