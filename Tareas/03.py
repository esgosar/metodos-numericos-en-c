import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, sin
from metodos.solvers import steffensen

mp.dps = 50
DEC = 6

def g_ej4(x):
    return 1 + (sin(x))**2

if __name__ == "__main__":
    print("\n=== UNIDAD 2.5 - EJERCICIO 4 ===")
    print("Hallar p0^(1) y p0^(2) usando Steffensen")
    
    # Nos piden solo los dos primeros valores calculados de p
    # Le ponemos max_iter=2 y tolerancia estricta para forzar las 2 iteraciones
    steffensen(g_ej4, 1.0, 1e-15, 2, DEC)