import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, cos, sin
from metodos.interpolacion import cota_error_lagrange

mp.dps = 50
DEC = 6

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 3a")
    print("===================================================================\n")

    # Nodos y punto a evaluar
    x_nodos_p1 = [mp.mpf('0.0'), mp.mpf('0.6')]
    x_nodos_p2 = [mp.mpf('0.0'), mp.mpf('0.6'), mp.mpf('0.9')]
    x_eval = mp.mpf('0.45')

    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 1 (n = 1)
    # ---------------------------------------------------------
    # Derivada (n+1) = 2.  f''(x) = -cos(x).
    # Máximo absoluto en [0.0, 0.6] ocurre en x = 0.0
    max_deriv_p1 = abs(-cos(0.0))
    
    cota_p1 = cota_error_lagrange(x_nodos_p1, x_eval, max_deriv_p1)

    print("[Cota de Error - Polinomio Grado 1]")
    print("Intervalo analizado: [0.0, 0.6]")
    print("Derivada usada: f''(x) = -cos(x)")
    print(f"Máximo absoluto de la derivada: |-cos(0.0)| = {float(max_deriv_p1):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p1):.{DEC}f}\n")

    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 2 (n = 2)
    # ---------------------------------------------------------
    # Derivada (n+1) = 3.  f'''(x) = sin(x).
    # Máximo absoluto en [0.0, 0.9] ocurre en x = 0.9
    max_deriv_p2 = abs(sin(0.9))
    
    cota_p2 = cota_error_lagrange(x_nodos_p2, x_eval, max_deriv_p2)

    print("[Cota de Error - Polinomio Grado 2]")
    print("Intervalo analizado: [0.0, 0.9]")
    print("Derivada usada: f'''(x) = sin(x)")
    print(f"Máximo absoluto de la derivada: |sin(0.9)| = {float(max_deriv_p2):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p2):.{DEC}f}\n")
    
    print("-" * 67)
    print("NOTA: Puedes comparar estas cotas máximas teóricas con el 'Error Absoluto'")
    print("real calculado en el Ejercicio 1a. El error real SIEMPRE debe ser menor")
    print("o igual a esta cota. Es la garantía matemática de Lagrange.")