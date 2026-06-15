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
# FUNCIONES - EJERCICIO 12 (Despejes g(x) a partir de f(x) = 0)
# =====================================================================
def g_12b(x):
    # Despeje de x^3 - 2x - 5 = 0  =>  x = cbrt(2x + 5)
    return (2*x + 5)**(mp.mpf(1)/3)

def g_12d(x):
    # Despeje de x - cos(x) = 0  =>  x = cos(x)
    return cos(x)

if __name__ == "__main__":
    print("=========================================================")
    print("   UNIDAD 2.5 - EJERCICIO 12")
    print("=========================================================\n")

    print("\n" + "-"*60)
    print("[Ejercicio 12b] f(x) = x^3 - 2x - 5 = 0")
    print("Usando g(x) = cbrt(2x + 5)")
    print("Tolerancia: 10^-5 | Punto inicial: p0 = 0.0")
    steffensen(g_12b, 0.0, TOL, MAX_ITER, DEC)

    print("\n" + "-"*60)
    print("[Ejercicio 12d] f(x) = x - cos(x) = 0")
    print("Usando g(x) = cos(x)")
    print("Tolerancia: 10^-5 | Punto inicial: p0 = 0.3")
    steffensen(g_12d, 0.3, TOL, MAX_ITER, DEC)