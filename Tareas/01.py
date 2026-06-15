import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, cos, sqrt, exp, ln
from metodos.solvers import newton_raphson, newton_modificado

mp.dps = 50
DEC = 6
TOL = 1e-5
MAX_ITER = 100

# ==========================================
# DEFINIMOS LAS FUNCIONES ORIGINALES
# ==========================================

def f_b(x):
    return cos(x + sqrt(2)) + x * (x/2 + sqrt(2))

def f_d(x):
    return exp(6*x) + 3*(ln(2)**2)*exp(2*x) - ln(8)*exp(4*x) - ln(2)**3

# ==========================================
# EJECUCIÓN
# ==========================================
if __name__ == "__main__":
    print("\n=== UNIDAD 2.4 - EJERCICIO 1 ===")
    print("\n--- EJERCICIO 1b: Newton Estándar (x0 = -1.5) ---")
    newton_raphson(f_b, -1.5, TOL, MAX_ITER, DEC)

    print("\n--- EJERCICIO 1d: Newton Estándar (x0 = -0.5) ---")
    newton_raphson(f_d, -0.5, TOL, MAX_ITER, DEC)