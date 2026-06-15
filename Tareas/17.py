import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import lagrange

mp.dps = 50
DEC = 6

def formatear_nodos(nodos):
    return ", ".join([f"{float(x)}" for x in nodos])

if __name__ == "__main__":
    # ===================================================================
    #                           EJERCICIO 5a
    # ===================================================================
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 5a (Aproximación en x = 8.4)")
    print("===================================================================\n")

    x_eval_a = mp.mpf('8.4')

    datos_ej5_a = {
        mp.mpf('8.1'): mp.mpf('16.94410'),
        mp.mpf('8.3'): mp.mpf('17.56492'),
        mp.mpf('8.6'): mp.mpf('18.50515'),
        mp.mpf('8.7'): mp.mpf('18.82091')
    }

    tabla_valores_a = []

    # GRADO 1 (n=1)
    nodos_g1_a = [mp.mpf('8.3'), mp.mpf('8.6')]
    y_g1_a = [datos_ej5_a[x] for x in nodos_g1_a]
    p1_eval_a = lagrange(nodos_g1_a, y_g1_a, x_eval_a, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_a.append((1, formatear_nodos(nodos_g1_a), float(p1_eval_a)))

    # GRADO 2 (n=2)
    nodos_g2_a = [mp.mpf('8.3'), mp.mpf('8.6'), mp.mpf('8.7')]
    y_g2_a = [datos_ej5_a[x] for x in nodos_g2_a]
    p2_eval_a = lagrange(nodos_g2_a, y_g2_a, x_eval_a, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_a.append((2, formatear_nodos(nodos_g2_a), float(p2_eval_a)))

    # GRADO 3 (n=3)
    nodos_g3_a = [mp.mpf('8.3'), mp.mpf('8.6'), mp.mpf('8.7'), mp.mpf('8.1')]
    y_g3_a = [datos_ej5_a[x] for x in nodos_g3_a]
    p3_eval_a = lagrange(nodos_g3_a, y_g3_a, x_eval_a, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_a.append((3, formatear_nodos(nodos_g3_a), float(p3_eval_a)))

    # TABLA RESUMEN 5A
    print("===================================================================")
    print("                       TABLA DE APROXIMACIONES                     ")
    print("===================================================================")
    print(f"{'n':<4} | {'x_0, x_1, ..., x_n':<25} | {'P_n(8.4)':<15}")
    print("-" * 55)
    for fila in tabla_valores_a:
        print(f"{fila[0]:<4} | {fila[1]:<25} | {fila[2]:.{DEC}f}")
    print("-" * 55)
    print("\n\n")

    # ===================================================================
    #                           EJERCICIO 5d
    # ===================================================================
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 5d (Aproximación en x = 0.9)")
    print("===================================================================\n")

    x_eval_d = mp.mpf('0.9')

    datos_ej5_d = {
        mp.mpf('0.6'): mp.mpf('-0.17694460'),
        mp.mpf('0.7'): mp.mpf('0.01375227'),
        mp.mpf('0.8'): mp.mpf('0.22363362'),
        mp.mpf('1.0'): mp.mpf('0.65809197')
    }

    tabla_valores_d = []

    # GRADO 1 (n=1)
    nodos_g1_d = [mp.mpf('0.8'), mp.mpf('1.0')]
    y_g1_d = [datos_ej5_d[x] for x in nodos_g1_d]
    p1_eval_d = lagrange(nodos_g1_d, y_g1_d, x_eval_d, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_d.append((1, formatear_nodos(nodos_g1_d), float(p1_eval_d)))

    # GRADO 2 (n=2)
    nodos_g2_d = [mp.mpf('0.7'), mp.mpf('0.8'), mp.mpf('1.0')]
    y_g2_d = [datos_ej5_d[x] for x in nodos_g2_d]
    p2_eval_d = lagrange(nodos_g2_d, y_g2_d, x_eval_d, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_d.append((2, formatear_nodos(nodos_g2_d), float(p2_eval_d)))

    # GRADO 3 (n=3)
    nodos_g3_d = [mp.mpf('0.6'), mp.mpf('0.7'), mp.mpf('0.8'), mp.mpf('1.0')]
    y_g3_d = [datos_ej5_d[x] for x in nodos_g3_d]
    p3_eval_d = lagrange(nodos_g3_d, y_g3_d, x_eval_d, mostrar_polinomio=True, decimales=DEC)
    tabla_valores_d.append((3, formatear_nodos(nodos_g3_d), float(p3_eval_d)))

    # TABLA RESUMEN 5D
    print("===================================================================")
    print("                       TABLA DE APROXIMACIONES                     ")
    print("===================================================================")
    print(f"{'n':<4} | {'x_0, x_1, ..., x_n':<25} | {'P_n(0.9)':<15}")
    print("-" * 55)
    for fila in tabla_valores_d:
        print(f"{fila[0]:<4} | {fila[1]:<25} | {fila[2]:.{DEC}f}")
    print("-" * 55)