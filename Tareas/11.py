import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.solvers import biseccion, newton_raphson, secante, posicion_falsa, muller

mp.dps = 50
TOL = 1e-4
MAX_ITER = 100
DEC = 6

def f_7(x):
    return 600*x**4 - 550*x**3 + 200*x**2 - 20*x - 1

if __name__ == "__main__":
    print("\n=== EJERCICIO 7a: Bisección [0.1, 1.0] ===")
    biseccion(f_7, 0.1, 1.0, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 7b: Newton (x0 = 0.55) ===")
    newton_raphson(f_7, 0.55, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 7c: Secante (x0 = 0.1, x1 = 1.0) ===")
    secante(f_7, 0.1, 1.0, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 7d: Posición Falsa [0.1, 1.0] ===")
    posicion_falsa(f_7, 0.1, 1.0, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 7e: Müller (x0 = 0.1, x1 = 0.55, x2 = 1.0) ===")
    muller(f_7, 0.1, 0.55, 1.0, TOL, MAX_ITER, DEC)