#include <stdio.h>
#include "mate_aplicada.h" // Incluimos nuestro header personal (con comillas "")

int main() {
    printf("====================================================\n");
    printf("   LIBRERIA DE MATEMATICA APLICADA 3 - UNIDAD 1\n");
    printf("====================================================\n\n");
    
    // Verificamos el primer intervalo del ejercicio 1a
    teorema_valor_intermedio(0.2, 0.3) ? printf("  [✓] EXITO: El TVI garantiza al menos una raiz.\n\n") : printf("  [x] FALLO: El TVI no concluye nada.\n\n");
    
    // Verificamos el segundo intervalo del ejercicio 1a
    teorema_valor_intermedio(1.2, 1.3) ? printf("  [✓] EXITO: El TVI garantiza al menos una raiz.\n\n") : printf("  [x] FALLO: El TVI no concluye nada.\n\n");
    
    
    return 0;
}