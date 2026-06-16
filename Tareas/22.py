import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import neville  # <-- ¡Importamos para validar!

mp.dps = 50
DEC = 4

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.2 - EJERCICIO 5 (Deducción Inversa e Interpolación)")
    print("===================================================================\n")

    x_eval = mp.mpf('0.4')
    x0, x1, x2, x3 = mp.mpf('0.0'), mp.mpf('0.25'), mp.mpf('0.5'), mp.mpf('0.75')
    
    P0, P1, P3 = mp.mpf('1'), mp.mpf('2'), mp.mpf('8')
    P01, P23, P123, P0123 = mp.mpf('2.6'), mp.mpf('2.4'), mp.mpf('2.96'), mp.mpf('3.016')

    # Despeje analítico inverso
    P012 = ((x_eval - x0) * P123 - P0123 * (x3 - x0)) / (x_eval - x3)
    P12 = (P012 * (x2 - x0) + (x_eval - x2) * P01) / (x_eval - x0)
    P2 = ((x_eval - x2) * P3 - P23 * (x3 - x2)) / (x_eval - x3)

    print(f">> VALOR DEDUCIDO: P_2 = f(0.5) = {float(P2):.{DEC}f}\n")

    print("===================================================================")
    print("   VALIDACIÓN: Regenerando la tabla completa con el método externo")
    print("===================================================================")
    
    # Montamos los vectores completos usando el P2 obtenido
    nodos_completos = [x0, x1, x2, x3]
    y_completos = [P0, P1, P2, P3]
    
    # Ejecutamos el Neville reutilizable
    Matriz_Validacion = neville(nodos_completos, y_completos, x_eval)
    
    # Imprimir la tabla resultante para verificar visualmente contra la imagen
    headers = f"{'x_i':<6} | {'Grado 0':<8} | {'Grado 1':<8} | {'Grado 2':<8} | {'Grado 3':<8}"
    print(headers)
    print("-" * len(headers))
    for i in range(4):
        fila_str = f"{float(nodos_completos[i]):<6.2f} | "
        valores = [f"{float(Matriz_Validacion[i][j]):.<8.4f}" if j <= i else f"{'-':<8}" for j in range(4)]
        fila_str += " | ".join(valores)
        print(fila_str)
    print("-" * len(headers))