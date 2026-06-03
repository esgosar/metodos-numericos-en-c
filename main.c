#include <stdio.h>
#include "core/aritmetica.h"
#include "errores/metricas.h"

int main() {
    double valor_crudo = 3.1415926535;
    
    printf("====================================================\n");
    printf("   PRUEBA DEL MODULO CORE (ARITMETICA DE MAQUINA)\n");
    printf("====================================================\n\n");
    
    printf("Valor Original: %.10f\n\n", valor_crudo);
    
    // Prototipos dinámicos de redondeo y truncamiento
    printf("Redondeo Manual a 2 decimales : %.10f\n", redondear(valor_crudo, 2));
    printf("Redondeo Manual a 6 decimales : %.10f\n", redondear(valor_crudo, 6));
    printf("Truncado Manual a 4 decimales : %.10f\n\n", truncar(valor_crudo, 4));
    
    // Prueba de Tolerancia ISO
    double limite_superior = 12.005;
    double limite_inferior = 11.995;
    double tol = tolerancia(limite_superior, limite_inferior);
    
    printf("Especificaciones de Tolerancia ISO:\n");
    printf("  L_max: %.3f | L_min: %.3f\n", limite_superior, limite_inferior);
    printf("  Rango de Tolerancia (T): %.2f\n", tol);
    
    return 0;
}