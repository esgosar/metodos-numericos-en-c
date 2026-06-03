#include <stdio.h>
#include <math.h>
#include "errores/metricas.h" // Observa cómo llamamos al subdirectorio

int main() {
    double v_real = M_PI; // Constante pi de math.h (aprox 3.14159265...)
    double v_aprox = 3.14;
    
    printf("====================================================\n");
    printf("   PRUEBA DE MODULO DE ERRORES\n");
    printf("====================================================\n\n");
    
    printf("Valor Real (V_R)       : %.8f\n", v_real);
    printf("Valor Aproximado (V_A) : %.8f\n\n", v_aprox);
    
    printf("Error Absoluto         : %.8f\n", error_absoluto(v_real, v_aprox));
    printf("Error Relativo         : %.8f\n", error_relativo(v_real, v_aprox));
    printf("Error Porcentual       : %.4f %%\n", error_porcentual(v_real, v_aprox));
    
    return 0;
}