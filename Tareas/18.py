import sys
import os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from mpmath import mp
from metodos.solvers import secante

mp.dps = 50
DEC = 6

# Función que calcula el coeficiente de x^3 dado un valor 'y' experimental
def ecuacion_coeficiente(y_val):
    y_val = mp.mpf(y_val)
    # Diferencias divididas de orden 1
    dd01 = (y_val - mp.mpf(0)) / (mp.mpf('0.5') - mp.mpf(0))
    dd12 = (mp.mpf(3) - y_val) / (mp.mpf(1) - mp.mpf('0.5'))
    dd23 = (mp.mpf(2) - mp.mpf(3)) / (mp.mpf(2) - mp.mpf(1))
    
    # Diferencias divididas de orden 2
    dd012 = (dd12 - dd01) / (mp.mpf(1) - mp.mpf(0))
    dd123 = (dd23 - dd12) / (mp.mpf(2) - mp.mpf('0.5'))
    
    # Diferencia dividida de orden 3 (Coeficiente de x^3)
    coef_x3 = (dd123 - dd012) / (mp.mpf(2) - mp.mpf(0))
    
    # Buscamos que el coeficiente sea igual a 6, por lo que f(y) = coef - 6 = 0
    return coef_x3 - mp.mpf(6)

if __name__ == "__main__":
    print("===================================================================")
    print("   UNIDAD 3.1 - EJERCICIO 9 (Búsqueda de Incógnita 'y')")
    print("===================================================================")
    print("Utilizando el método de la Secante para encontrar 'y'...\n")

    # Usamos nuestro solver de la Unidad 2!
    y_solucion = secante(ecuacion_coeficiente, 0.0, 5.0, 1e-10, 50, decimales=DEC)
    
    print(f"\n=> El valor exacto de 'y' es: {y_solucion}")
    print("   (Analíticamente corresponde a la fracción 17/4 = 4.25)")