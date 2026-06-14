#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6
#define TOL 1e-5
#define PI 3.141592653589793
#define E  2.718281828459045

/* ==========================================================================================
 * FUNCION UNIVERSAL DE PRUEBA: f(x) = x^2 - 4 
 * Raiz esperada: x = 2.0
 * ========================================================================================== */

// 1. La funcion base f(x)
double f_test(double x) {
    return (x * x) - 4.0;
}

// 2. La derivada f'(x) para Newton-Raphson
double df_test(double x) {
    return 2.0 * x;
}

// 3. La iteradora g(x) para Punto Fijo: x = x/2 + 2/x
double g_test(double x) {
    return (x / 2.0) + (2.0 / x);
}

/* ==========================================================================================
 * RUTINA PRINCIPAL DE PRUEBAS
 * ========================================================================================== */

int main() {
    int max_iter = 100;

    printf("================================================================================\n");
    printf("   TEST INTEGRAL UNIVERSAL: f(x) = x^2 - 4 (Raiz = 2.0)\n");
    printf("================================================================================\n");

    // --- TEST 1: BISECCIÓN ---
    printf("\n[1] TEST: Biseccion\n");
    printf("Intervalo: [1.0, 3.0]\n");
    biseccion(f_test, 1.0, 3.0, TOL, max_iter, DEC);

    // --- TEST 2: NEWTON-RAPHSON ---
    printf("\n================================================================================\n");
    printf("\n[2] TEST: Newton-Raphson\n");
    printf("Semilla: p0 = 3.0\n");
    newton_raphson(f_test, df_test, 3.0, TOL, max_iter, DEC);

    // --- TEST 3: PUNTO FIJO ---
    printf("\n================================================================================\n");
    printf("\n[3] TEST: Punto Fijo\n");
    printf("Semilla: p0 = 3.0\n");
    punto_fijo(g_test, 3.0, TOL, max_iter, DEC);

    // --- TEST 4: SECANTE ---
    printf("\n================================================================================\n");
    printf("\n[4] TEST: Secante\n");
    printf("Semillas: p0 = 3.0, p1 = 2.5\n");
    secante(f_test, 3.0, 2.5, TOL, max_iter, DEC);

    // --- TEST 5: POSICION FALSA NORMAL ---
    printf("\n================================================================================\n");
    printf("\n[5] TEST: Posicion Falsa (Regula Falsi)\n");
    printf("Intervalo: [1.0, 3.0]\n");
    posicion_falsa(f_test, 1.0, 3.0, TOL, max_iter, DEC);

    // --- TEST 6: POSICION FALSA MODIFICADA (ILLINOIS) ---
    printf("\n================================================================================\n");
    printf("\n[6] TEST: Posicion Falsa Modificada (Algoritmo de Illinois)\n");
    printf("Intervalo: [1.0, 3.0]\n");
    pos_falsa_modificada(f_test, 1.0, 3.0, TOL, max_iter, DEC);

    printf("\n================================================================================\n");
    printf("   [✓] BATERIA DE PRUEBAS FINALIZADA CORRECTAMENTE \n");
    printf("================================================================================\n");

    return 0;
}