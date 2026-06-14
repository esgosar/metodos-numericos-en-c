import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from metodos.solvers import (
    biseccion, newton_raphson, punto_fijo, 
    secante, posicion_falsa_modificada
)

from mpmath import mp, cos, sin, sqrt

# Constantes del entorno
DEC = 6
TOL = 1e-5

# f(x) = x^2 - 4  (Raíz = 2.0)
def f_test(x):
    return cos(x+sqrt(2)) + x*(x/2+sqrt(2))

def df_test(x):
    return -sin(x+sqrt(2)) + x + sqrt(2)

if __name__ == "__main__":
    max_iter = 100

    print("\n[2] TEST: Newton-Raphson")
    newton_raphson(f_test, df_test, -1.5, TOL, max_iter, DEC)