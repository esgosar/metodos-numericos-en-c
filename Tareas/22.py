import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import neville  # <-- ¡Reutilizando nuestro método externo!

mp.dps = 50
DEC = 6

def imprimir_tabla_neville(nodos, Q):
    n = len(nodos)
    headers = f"{'x_i':<8} | " + " | ".join([f"Grado {j:<4}" for j in range(n)])
    print(headers)
    print("-" * len(headers))
    for i in range(n):
        fila_str = f"{float(nodos[i]):<8.4f} | "
        valores_fila = []
        for j in range(i + 1):
            valores_fila.append(f"{float(Q[i][j]):.{DEC}f}")
        for j in range(i + 1, n):
            valores_fila.append(f"{'-':<{DEC+2}}")
        fila_str += " | ".join(valores_fila)
        print(fila_str)
    print("-" * len(headers))

if __name__ == "__main__":
    # -----------------------------------------------------------------
    # EJERCICIO 1b
    # -----------------------------------------------------------------
    print("===================================================================")
    print("   UNIDAD 3.2 - EJERCICIO 1b (Neville reutilizado en x = -1/3)")
    print("===================================================================\n")

    x_eval_b = mp.mpf('-1') / mp.mpf('3')
    nodos_b = [mp.mpf('-0.75'), mp.mpf('-0.5'), mp.mpf('-0.25'), mp.mpf('0.0')]
    y_b = [mp.mpf('-0.07181250'), mp.mpf('-0.02475000'), mp.mpf('0.33493750'), mp.mpf('1.10100000')]

    # Llamada al método externo
    Q_b = neville(nodos_b, y_b, x_eval_b)
    imprimir_tabla_neville(nodos_b, Q_b)
    
    print(f"\nAproximación Grado 1: {float(Q_b[3][1]):.{DEC}f}")
    print(f"Aproximación Grado 2: {float(Q_b[3][2]):.{DEC}f}")
    print(f"Aproximación Grado 3: {float(Q_b[3][3]):.{DEC}f}\n\n")

    # -----------------------------------------------------------------
    # EJERCICIO 1d
    # -----------------------------------------------------------------
    print("===================================================================")
    print("   UNIDAD 3.2 - EJERCICIO 1d (Neville reutilizado en x = 0.9)")
    print("===================================================================\n")

    x_eval_d = mp.mpf('0.9')
    nodos_d = [mp.mpf('0.6'), mp.mpf('0.7'), mp.mpf('0.8'), mp.mpf('1.0')]
    y_d = [mp.mpf('-0.17694460'), mp.mpf('-0.01375227'), mp.mpf('0.22363362'), mp.mpf('0.65809197')]

    # Llamada al método externo
    Q_d = neville(nodos_d, y_d, x_eval_d)
    imprimir_tabla_neville(nodos_d, Q_d)
    
    print(f"\nAproximación Grado 1: {float(Q_d[3][1]):.{DEC}f}")
    print(f"Aproximación Grado 2: {float(Q_d[3][2]):.{DEC}f}")
    print(f"Aproximación Grado 3: {float(Q_d[3][3]):.{DEC}f}")