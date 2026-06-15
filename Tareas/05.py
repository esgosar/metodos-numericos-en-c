import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp, sqrt
from metodos.solvers import steffensen, punto_fijo, biseccion

mp.dps = 50
MAX_ITER = 100
TOL = 1e-4
DEC = 6

def f_ej10(x):
    return x**3 - 25

def g_ej10(x):
    # Despeje convergente para raíz cúbica: x = 5 / sqrt(x)
    return 5.0 / sqrt(x)

if __name__ == "__main__":
    print("\n=== UNIDAD 2.5 - EJERCICIO 10 ===")
    
    print("\n[Método 1] Steffensen (Tol = 10^-4, p0 = 3)")
    steffensen(g_ej10, 3.0, TOL, MAX_ITER, DEC)
    
    print("\n[Método 2] Iteración de Punto Fijo (Tol = 10^-4, p0 = 3)")
    punto_fijo(g_ej10, 3.0, TOL, MAX_ITER, DEC)
    
    print("\n[Método 3] Bisección (Tol = 10^-4, Intervalo [2, 3])")
    # Elegimos [2,3] porque 2^3=8 y 3^3=27
    biseccion(f_ej10, 2.0, 3.0, TOL, MAX_ITER, DEC)

    print("\n[Comparación]:")
    print("1. Steffensen es el más veloz.")
    print("2. Punto Fijo requiere más iteraciones pero es más estable computacionalmente.")
    print("3. Bisección es el más lento (requiere evaluar repetidamente las mitades),")
    print("   pero garantiza encontrar la raíz sin importar el despeje algebraico inicial.")