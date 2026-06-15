import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, sin, cos
from metodos.solvers import steffensen

# Configuración de alta precisión
mp.dps = 50
MAX_ITER = 100
TOL = 1e-5
DEC = 6

# =====================================================================
# FUNCIONES - EJERCICIO 11 (g(x) dadas directamente)
# =====================================================================
def g_11b(x):
    return 0.5 * (sin(x) + cos(x))

def g_11d(x):
    return 5**(-x)


if __name__ == "__main__":
    print("=========================================================")
    print("   UNIDAD 2.5 - EJERCICIO 11")
    print("=========================================================\n")

    print("[Ejercicio 11b] g(x) = 0.5 * (sen(x) + cos(x))")
    print("Tolerancia: 10^-5 | Punto inicial: p0 = 0.0")
    steffensen(g_11b, 0.0, TOL, MAX_ITER, DEC)

    print("\n" + "-"*60)
    print("[Ejercicio 11d] g(x) = 5^(-x)")
    print("Tolerancia: 10^-5 | Punto inicial: p0 = 0.3")
    steffensen(g_11d, 0.3, TOL, MAX_ITER, DEC)