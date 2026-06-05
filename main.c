#include <stdio.h>
#include <math.h>
#include "core/aritmetica.h"
#include "errores/metricas.h"
#include "metodos/solvers.h"

// Ecuación del Ejercicio 1a
double ecuacion_libro(double x) {
    return (x * cos(x)) - (2.0 * x * x) + (3.0 * x) - 1.0;
}

int main() {
    printf("=================================================================================\n");
    printf("   SISTEMA DE CALCULO NUMERICO COMPLETO - METODO DE BISECCION\n");
    printf("=================================================================================\n");
    
    double tol_iso = tolerancia(0.0005, 0.0000); // Tolerancia de máquina de ejemplo
    printf("Tolerancia del Proceso (ISO): %.6f\n", tol_iso);

    // Ejecutamos la bisección en el intervalo [0.2, 0.3] buscando la primera raíz
    biseccion(ecuacion_libro, 0.2, 0.3, tol_iso, 20, 6);
    
    return 0;
}