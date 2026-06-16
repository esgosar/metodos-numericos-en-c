import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, cos, sin
from metodos.interpolacion import cota_error_lagrange

mp.dps = 50
DEC = 6

def f(x): 
    return cos(x)

def g(x):
    return (1+x) ** 0.5


if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 3a")
    print("===================================================================\n")

    # Nodos y punto a evaluar (Ajustados a x1 = 0.6)
    x_nodos_p1 = [mp.mpf('0.0'), mp.mpf('0.6')]
    x_nodos_p2 = [mp.mpf('0.0'), mp.mpf('0.6'), mp.mpf('0.9')]
    x_eval = mp.mpf('0.45')

    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 1 (n = 1)
    # ---------------------------------------------------------
    # El teorema exige la derivada de orden (n+1) = 2.
    # El máximo absoluto de f''(x) en [0.0, 0.3] ocurre en x = 0.0
    max_deriv_p1 = abs(mp.diff(f, mp.mpf('0.0'), 2)) # <- Se añade el '2' para la segunda derivada
    
    cota_p1 = cota_error_lagrange(x_nodos_p1, x_eval, max_deriv_p1)

    print("[Cota de Error - Polinomio Grado 1]")
    print(f"Intervalo analizado: [{float(x_nodos_p1[0]):.1f}, {float(x_nodos_p1[1]):.1f}]")
    print(f"Derivada calculada automáticamente: f''(x)")
    print(f"Máximo absoluto de la derivada: = {float(max_deriv_p1):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p1):.{DEC}f}\n")

    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 2 (n = 2)
    # ---------------------------------------------------------
    # El teorema exige la derivada de orden (n+1) = 3.
    # El máximo absoluto de f'''(x) en [0.0, 0.9] ocurre en x = 0.9
    max_deriv_p2 = abs(mp.diff(f, mp.mpf('0.9'), 3)) # <- Se añade el '3' para la tercera derivada
    
    cota_p2 = cota_error_lagrange(x_nodos_p2, x_eval, max_deriv_p2)

    print("[Cota de Error - Polinomio Grado 2]")
    print(f"Intervalo analizado: [{float(x_nodos_p2[0]):.1f}, {float(x_nodos_p2[2]):.1f}]")
    print("Derivada calculada automáticamente: f'''(x)")
    print(f"Máximo absoluto de la derivada: = {float(max_deriv_p2):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p2):.{DEC}f}\n")

    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 3b")
    print("===================================================================\n")


    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 1 (n = 1)
    # ---------------------------------------------------------
    # El teorema exige la derivada de orden (n+1) = 2.
    # El máximo absoluto de f''(x) en [0.0, 0.3] ocurre en x = 0.0
    max_deriv_p1 = abs(mp.diff(g, mp.mpf('0.0'), 2)) # <- Se añade el '2' para la segunda derivada
    
    cota_p1 = cota_error_lagrange(x_nodos_p1, x_eval, max_deriv_p1)

    print("[Cota de Error - Polinomio Grado 1]")
    print(f"Intervalo analizado: [{float(x_nodos_p1[0]):.1f}, {float(x_nodos_p1[1]):.1f}]")
    print(f"Derivada calculada automáticamente: f''(x)")
    print(f"Máximo absoluto de la derivada: = {float(max_deriv_p1):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p1):.{DEC}f}\n")

    # ---------------------------------------------------------
    # COTA DE ERROR - POLINOMIO GRADO 2 (n = 2)
    # ---------------------------------------------------------
    # El teorema exige la derivada de orden (n+1) = 3.
    # El máximo absoluto de f'''(x) en [0.0, 0.9] ocurre en x = 0.9
    max_deriv_p2 = abs(mp.diff(g, mp.mpf('0.9'), 3)) # <- Se añade el '3' para la tercera derivada
    
    cota_p2 = cota_error_lagrange(x_nodos_p2, x_eval, max_deriv_p2)

    print("[Cota de Error - Polinomio Grado 2]")
    print(f"Intervalo analizado: [{float(x_nodos_p2[0]):.1f}, {float(x_nodos_p2[2]):.1f}]")
    print("Derivada calculada automáticamente: f'''(x)")
    print(f"Máximo absoluto de la derivada: = {float(max_deriv_p2):.{DEC}f}")
    print(f"Cota de Error Máxima Garantizada = {float(cota_p2):.{DEC}f}\n")