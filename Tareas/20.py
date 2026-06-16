import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import lagrange

mp.dps = 50
DEC = 6

def f(x):
    return mp.exp(x)

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIOS 15b y 15c (f(x) = e^x)")
    print("===================================================================\n")

    # ---------------------------------------------------------
    # EJERCICIO 15b: Interpolación Lineal (n=1)
    # ---------------------------------------------------------
    print("--- [EJERCICIO 15b] Interpolación Lineal (x0 = 0.5, x1 = 1) ---")
    nodos_b = [mp.mpf('0.5'), mp.mpf('1.0')]
    y_nodos_b = [f(x) for x in nodos_b]
    
    x_eval_b = mp.mpf('0.75')
    p1_eval = lagrange(nodos_b, y_nodos_b, x_eval_b, mostrar_polinomio=True, decimales=DEC)
    
    print(f"Aproximación P1(0.75) = {float(p1_eval):.{DEC}f}")
    print(f"Valor Real f(0.75)    = {float(f(x_eval_b)):.{DEC}f}")
    print(f"Error Real            = {float(abs(p1_eval - f(x_eval_b))):.{DEC}f}\n")

    # ---------------------------------------------------------
    # EJERCICIO 15c: Interpolación Cuadrática (n=2)
    # ---------------------------------------------------------
    print("--- [EJERCICIO 15c] Interpolación Cuadrática (x0=0, x1=1, x2=2) ---")
    nodos_c = [mp.mpf('0.0'), mp.mpf('1.0'), mp.mpf('2.0')]
    y_nodos_c = [f(x) for x in nodos_c]
    
    # Evaluación en x = 0.25
    x_eval_c1 = mp.mpf('0.25')
    print("\n>> Aproximando f(0.25):")
    p2_eval_c1 = lagrange(nodos_c, y_nodos_c, x_eval_c1, mostrar_polinomio=True, decimales=DEC)
    print(f"Aproximación P2(0.25) = {float(p2_eval_c1):.{DEC}f}")
    print(f"Valor Real f(0.25)    = {float(f(x_eval_c1)):.{DEC}f}")
    print(f"Error Real            = {float(abs(p2_eval_c1 - f(x_eval_c1))):.{DEC}f}\n")

    # Evaluación en x = 0.75
    x_eval_c2 = mp.mpf('0.75')
    print(">> Aproximando f(0.75):")
    p2_eval_c2 = lagrange(nodos_c, y_nodos_c, x_eval_c2, mostrar_polinomio=False, decimales=DEC)
    print(f"Aproximación P2(0.75) = {float(p2_eval_c2):.{DEC}f}")
    print(f"Valor Real f(0.75)    = {float(f(x_eval_c2)):.{DEC}f}")
    print(f"Error Real            = {float(abs(p2_eval_c2 - f(x_eval_c2))):.{DEC}f}\n")