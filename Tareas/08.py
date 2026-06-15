import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.solvers import muller

mp.dps = 50
TOL = 1e-4
MAX_ITER = 50
DEC = 6

def f_3b(x): return x**3 + 3*x**2 - 1
def f_3e(x): return x**3 + 4.001*x**2 + 4.002*x + 1.101
def f_3f(x): return x**5 - x**4 + 2*x**3 - 3*x**2 + x - 4

if __name__ == "__main__":
    print("\n=== EJERCICIO 3b (Grado 3: 3 Raíces Reales) ===")
    print("Raíz 1:")
    muller(f_3b, -3.0, -2.9, -2.8, TOL, MAX_ITER, DEC)
    print("Raíz 2:")
    muller(f_3b, -0.6, -0.5, -0.4, TOL, MAX_ITER, DEC)
    print("Raíz 3:")
    muller(f_3b, 0.3, 0.4, 0.5, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 3e (Grado 3: 3 Raíces Reales) ===")
    print("Raíz 1:")
    muller(f_3e, -2.7, -2.6, -2.5, TOL, MAX_ITER, DEC)
    print("Raíz 2:")
    muller(f_3e, -1.1, -1.0, -0.9, TOL, MAX_ITER, DEC)
    print("Raíz 3:")
    muller(f_3e, -0.4, -0.38, -0.3, TOL, MAX_ITER, DEC)

    print("\n=== EJERCICIO 3f (Grado 5: 1 Real, 4 Complejas) ===")
    print("Raíz Real Única:")
    muller(f_3f, 1.3, 1.4, 1.5, TOL, MAX_ITER, DEC)

    # Introducimos semillas complejas con mp.mpc(parte_real, parte_imaginaria)
    print("\nRaíz Compleja 1:")
    muller(f_3f, mp.mpc(0, 1), mp.mpc(0.5, 1), mp.mpc(-0.5, 1), TOL, MAX_ITER, DEC)
    
    print("\nRaíz Compleja 2 (Conjugada):")
    muller(f_3f, mp.mpc(0, -1), mp.mpc(0.5, -1), mp.mpc(-0.5, -1), TOL, MAX_ITER, DEC)
    
    print("\nRaíz Compleja 3:")
    muller(f_3f, mp.mpc(-1, 1), mp.mpc(-0.5, 1.5), mp.mpc(-1.5, 0.5), TOL, MAX_ITER, DEC)
    
    print("\nRaíz Compleja 4 (Conjugada):")
    muller(f_3f, mp.mpc(-1, -1), mp.mpc(-0.5, -1.5), mp.mpc(-1.5, -0.5), TOL, MAX_ITER, DEC)