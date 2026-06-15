import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, cos
from metodos.interpolacion import lagrange

mp.dps = 50
DEC = 6

def f(x):
    return cos(x)

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 1a")
    print("===================================================================\n")

    x_nodos = [mp.mpf('0.0'), mp.mpf('0.6'), mp.mpf('0.9')]
    y_nodos = [f(x) for x in x_nodos]
    x_eval = mp.mpf('0.45')
    valor_real = f(x_eval)

    # GRADO 1 (Encendemos mostrar_polinomio)
    print(f"--- POLINOMIO DE GRADO 1 (Nodos: {x_nodos[0]} y {x_nodos[1]}) ---")
    p1_eval = lagrange(x_nodos[:2], y_nodos[:2], x_eval, mostrar_polinomio=True, decimales=6)
    print(f"Resultado -> P1({x_eval}) = {p1_eval:.{DEC}f}")
    print(f"Error Absoluto = {float(abs(p1_eval - valor_real)):.{DEC}f}\n")

    # GRADO 2 (Encendemos mostrar_polinomio)
    print(f"--- POLINOMIO DE GRADO 2 (Nodos: {x_nodos[0]}, {x_nodos[1]} y {x_nodos[2]}) ---")
    p2_eval = lagrange(x_nodos[:3], y_nodos[:3], x_eval, mostrar_polinomio=True, decimales=6)
    print(f"Resultado -> P2({x_eval}) = {p2_eval:.{DEC}f}")
    print(f"Error Absoluto = {float(abs(p2_eval - valor_real)):.{DEC}f}\n")