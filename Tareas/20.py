import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.interpolacion import lagrange

mp.dps = 50
DEC = 6

def f(x):
    return mp.exp(2*x) * mp.cos(3*x)

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 13a (Cota de Error en un Intervalo)")
    print("===================================================================\n")

    nodos = [mp.mpf('0.0'), mp.mpf('0.3'), mp.mpf('0.6')]
    y_nodos = [f(x) for x in nodos]
    
    print("--- 1. CONSTRUCCIÓN DEL POLINOMIO ---")
    # Para construirlo solo le damos un punto falso cualquiera para que lo imprima
    lagrange(nodos, y_nodos, mp.mpf(0), mostrar_polinomio=True, decimales=DEC)

    print("--- 2. COTA DE ERROR ABSOLUTO EN [0.0, 0.6] ---")
    pasos = 10000
    a, b = mp.mpf('0.0'), mp.mpf('0.6')
    
    max_derivada = mp.mpf(0)
    max_productoria = mp.mpf(0)
    
    # Escaneo del intervalo para maximizar el teorema de error
    for i in range(pasos + 1):
        x_act = a + (b - a) * mp.mpf(i) / mp.mpf(pasos)
        
        # 1. Maximizar |f'''(x)|
        val_deriv = abs(mp.diff(f, x_act, 3))
        if val_deriv > max_derivada:
            max_derivada = val_deriv
            
        # 2. Maximizar |(x-0.0)(x-0.3)(x-0.6)|
        prod = abs((x_act - nodos[0]) * (x_act - nodos[1]) * (x_act - nodos[2]))
        if prod > max_productoria:
            max_productoria = prod

    # Cálculo final: ( M / 3! ) * Max_Prod
    cota_maxima = (max_derivada / mp.factorial(3)) * max_productoria

    print(f"Máximo absoluto de f'''(x) en el intervalo = {float(max_derivada):.{DEC}f}")
    print(f"Máximo de la productoria en el intervalo = {float(max_productoria):.{DEC}f}")
    print(f"Cota de Error Absoluto Máxima en [0.0, 0.6] = {float(cota_maxima):.{DEC}f}")