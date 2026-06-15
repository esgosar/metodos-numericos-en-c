import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import lagrange, cota_error_lagrange

mp.dps = 50
DEC = 6

# Funciones generadoras separadas para evitar colisiones
def f_a(x):
    return x * mp.log(x)

def f_d(x):
    return mp.sin(mp.exp(x) - 2)

def buscar_max_derivada(func, orden, nodos, x_eval, pasos=1000):
    todos_los_puntos = nodos + [x_eval]
    a = min(todos_los_puntos)
    b = max(todos_los_puntos)
    max_val = mp.mpf(0)
    for i in range(pasos + 1):
        x_actual = a + (b - a) * mp.mpf(i) / mp.mpf(pasos)
        val_deriv = abs(mp.diff(func, x_actual, orden))
        if val_deriv > max_val:
            max_val = val_deriv
    return max_val

if __name__ == "__main__":
    # ===================================================================
    #                           EJERCICIO 7a
    # ===================================================================
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 7a (Errores para f(x) = x * ln(x))")
    print("===================================================================\n")

    x_eval_a = mp.mpf('8.4')
    val_real_a = f_a(x_eval_a)

    datos_ej5_a = {
        mp.mpf('8.1'): mp.mpf('16.94410'),
        mp.mpf('8.3'): mp.mpf('17.56492'),
        mp.mpf('8.6'): mp.mpf('18.50515'),
        mp.mpf('8.7'): mp.mpf('18.82091')
    }

    tabla_errores_a = []

    # GRADO 1 (n=1)
    nodos_g1_a = [mp.mpf('8.3'), mp.mpf('8.6')]
    y_g1_a = [datos_ej5_a[x] for x in nodos_g1_a]
    p1_eval_a = lagrange(nodos_g1_a, y_g1_a, x_eval_a, mostrar_polinomio=False)
    err_real_g1_a = abs(p1_eval_a - val_real_a)
    max_d_g1_a = buscar_max_derivada(f_a, 2, nodos_g1_a, x_eval_a)
    cota_g1_a = cota_error_lagrange(nodos_g1_a, x_eval_a, max_d_g1_a)
    tabla_errores_a.append((1, float(err_real_g1_a), f"{float(cota_g1_a):.{DEC}f}"))

    # GRADO 2 (n=2)
    nodos_g2_a = [mp.mpf('8.3'), mp.mpf('8.6'), mp.mpf('8.7')]
    y_g2_a = [datos_ej5_a[x] for x in nodos_g2_a]
    p2_eval_a = lagrange(nodos_g2_a, y_g2_a, x_eval_a, mostrar_polinomio=False)
    err_real_g2_a = abs(p2_eval_a - val_real_a)
    max_d_g2_a = buscar_max_derivada(f_a, 3, nodos_g2_a, x_eval_a)
    cota_g2_a = cota_error_lagrange(nodos_g2_a, x_eval_a, max_d_g2_a)
    tabla_errores_a.append((2, float(err_real_g2_a), f"{float(cota_g2_a):.{DEC}f}"))

    # TABLA COMPARATIVA 7A
    print("===================================================================")
    print("                     TABLA DE COMPARACIÓN DE ERRORES               ")
    print("===================================================================")
    print(f"{'n':<4} | {'Error real':<15} | {'Cota de error':<15}")
    print("-" * 44)
    for fila in tabla_errores_a:
        print(f"{fila[0]:<4} | {fila[1]:.{DEC}f}        | {fila[2]:<15}")
    print("-" * 44)
    
    print(f"\nValor Analítico Real f(8.4) = {float(val_real_a):.{DEC}f}\n\n")

    # ===================================================================
    #                           EJERCICIO 7d
    # ===================================================================
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 7d (Errores para f(x) = sin(e^x - 2))")
    print("===================================================================\n")

    x_eval_d = mp.mpf('0.9')
    val_real_d = f_d(x_eval_d) # <-- Usando la función f_d

    datos_ej5_d = {
        mp.mpf('0.6'): mp.mpf('-0.17694460'),
        mp.mpf('0.7'): mp.mpf('0.01375227'),
        mp.mpf('0.8'): mp.mpf('0.22363362'),
        mp.mpf('1.0'): mp.mpf('0.65809197')
    }

    tabla_errores_d = []

    # GRADO 1 (n=1)
    nodos_g1_d = [mp.mpf('0.8'), mp.mpf('1.0')]
    y_g1_d = [datos_ej5_d[x] for x in nodos_g1_d]
    p1_eval_d = lagrange(nodos_g1_d, y_g1_d, x_eval_d, mostrar_polinomio=False)
    err_real_g1_d = abs(p1_eval_d - val_real_d)
    max_d_g1_d = buscar_max_derivada(f_d, 2, nodos_g1_d, x_eval_d) # <-- Usando f_d
    cota_g1_d = cota_error_lagrange(nodos_g1_d, x_eval_d, max_d_g1_d)
    tabla_errores_d.append((1, float(err_real_g1_d), f"{float(cota_g1_d):.{DEC}f}"))

    # GRADO 2 (n=2)
    nodos_g2_d = [mp.mpf('0.7'), mp.mpf('0.8'), mp.mpf('1.0')]
    y_g2_d = [datos_ej5_d[x] for x in nodos_g2_d]
    p2_eval_d = lagrange(nodos_g2_d, y_g2_d, x_eval_d, mostrar_polinomio=False)
    err_real_g2_d = abs(p2_eval_d - val_real_d)
    max_d_g2_d = buscar_max_derivada(f_d, 3, nodos_g2_d, x_eval_d) # <-- Usando f_d
    cota_g2_d = cota_error_lagrange(nodos_g2_d, x_eval_d, max_d_g2_d)
    tabla_errores_d.append((2, float(err_real_g2_d), f"{float(cota_g2_d):.{DEC}f}"))

    # TABLA COMPARATIVA 7D
    print("===================================================================")
    print("                     TABLA DE COMPARACIÓN DE ERRORES               ")
    print("===================================================================")
    print(f"{'n':<4} | {'Error real':<15} | {'Cota de error':<15}")
    print("-" * 44)
    for fila in tabla_errores_d:
        print(f"{fila[0]:<4} | {fila[1]:.{DEC}f}        | {fila[2]:<15}")
    print("-" * 44)
    
    print(f"\nValor Analítico Real f(0.9) = {float(val_real_d):.{DEC}f}")