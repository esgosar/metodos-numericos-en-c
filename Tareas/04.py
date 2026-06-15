import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.solvers import steffensen, punto_fijo

mp.dps = 50
MAX_ITER = 100
DEC = 6

def g_ej7(x):
    # g(x) = (x + 1)^(1/3)
    return (x + 1)**(mp.mpf(1)/3)

if __name__ == "__main__":
    print("\n=== UNIDAD 2.5 - EJERCICIO 7 ===")
    
    print("\n[Método 1] Steffensen (Tol = 10^-4, p0 = 1)")
    steffensen(g_ej7, 1.0, 1e-4, MAX_ITER, DEC)
    
    print("\n[Método 2] Iteración de Punto Fijo (Tol = 10^-2, p0 = 1)")
    punto_fijo(g_ej7, 1.0, 1e-2, MAX_ITER, DEC)
    
    print("\n[Comparación]:")
    print("Steffensen alcanza 10^-4 de precisión en muchísimas menos iteraciones")
    print("que el método de Punto Fijo clásico, a pesar de que este último")
    print("solo exige una tolerancia de 10^-2.")