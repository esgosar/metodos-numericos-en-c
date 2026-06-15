import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.solvers import muller

mp.dps = 50
TOL = 1e-3
MAX_ITER = 50
DEC = 6

def f_5a(x): return x**3 - 9*x**2 + 12
def df_5a(x): return mp.diff(f_5a, x)

def f_5b(x): return x**4 - 2*x**3 - 5*x**2 + 12*x - 5
def df_5b(x): return mp.diff(f_5b, x)

if __name__ == "__main__":
    print("\n=== EJERCICIO 5a ===")
    print("--- Ceros ---")
    muller(f_5a, -1.2, -1.1, -1.0, TOL, MAX_ITER, DEC)
    muller(f_5a, 1.0, 1.1, 1.2, TOL, MAX_ITER, DEC)
    muller(f_5a, 8.7, 8.8, 8.9, TOL, MAX_ITER, DEC)
    print("--- Puntos Críticos ---")
    muller(df_5a, -0.1, 0.0, 0.1, TOL, MAX_ITER, DEC)
    muller(df_5a, 5.9, 6.0, 6.1, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 5b ===")
    print("--- Ceros ---")
    muller(f_5b, -2.6, -2.5, -2.4, TOL, MAX_ITER, DEC)
    muller(f_5b, 0.5, 0.6, 0.7, TOL, MAX_ITER, DEC)
    muller(f_5b, 1.3, 1.4, 1.5, TOL, MAX_ITER, DEC)
    muller(f_5b, 2.2, 2.3, 2.4, TOL, MAX_ITER, DEC)
    print("--- Puntos Críticos ---")
    muller(df_5b, -1.6, -1.5, -1.4, TOL, MAX_ITER, DEC)
    muller(df_5b, 0.9, 1.0, 1.1, TOL, MAX_ITER, DEC)
    muller(df_5b, 1.9, 2.0, 2.1, TOL, MAX_ITER, DEC)