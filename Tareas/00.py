import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from metodos.solvers import (
    biseccion, newton_raphson, punto_fijo, 
    secante, posicion_falsa_modificada
)

# Constantes del entorno
DEC = 6
TOL = 1e-5

# f(x) = x^2 - 4  (Raíz = 2.0)
def f_test(x):
    return (x * x) - 4.0

def df_test(x):
    return 2.0 * x

def g_test(x):
    return (x / 2.0) + (2.0 / x)

if __name__ == "__main__":
    max_iter = 100

    print("================================================================================")
    print("   TEST INTEGRAL UNIVERSAL: f(x) = x^2 - 4 (Raiz = 2.0) - ALTA PRECISIÓN")
    print("================================================================================")

    print("\n[1] TEST: Biseccion")
    biseccion(f_test, 1.0, 3.0, TOL, max_iter, DEC)

    print("\n[2] TEST: Newton-Raphson")
    newton_raphson(f_test, df_test, 3.0, TOL, max_iter, DEC)

    print("\n[3] TEST: Punto Fijo")
    punto_fijo(g_test, 3.0, TOL, max_iter, DEC)

    print("\n[4] TEST: Secante")
    secante(f_test, 3.0, 2.5, TOL, max_iter, DEC)

    print("\n[5] TEST: Posicion Falsa Modificada (Illinois)")
    posicion_falsa_modificada(f_test, 1.0, 3.0, TOL, max_iter, DEC)ls