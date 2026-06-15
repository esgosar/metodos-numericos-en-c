from mpmath import mp, fabs, factorial

def _poly_add(p1, p2):
    """Suma dos polinomios representados como listas de coeficientes."""
    n = max(len(p1), len(p2))
    res = [mp.mpf(0)] * n
    for i in range(n):
        val1 = p1[i] if i < len(p1) else mp.mpf(0)
        val2 = p2[i] if i < len(p2) else mp.mpf(0)
        res[i] = val1 + val2
    return res

def _poly_mul_root(p, root):
    """Multiplica un polinomio P(x) por el binomio (x - root)."""
    res = [mp.mpf(0)] * (len(p) + 1)
    for i in range(len(p)):
        res[i+1] += p[i]           # Término multiplicado por x
        res[i] -= root * p[i]      # Término multiplicado por -root
    return res

def _format_float(val, decimales):
    """Formatea el número quitando ceros innecesarios a la derecha (ej: 1.0000 -> 1)."""
    # Convertimos el valor mpf a float de Python para que acepte el formato de texto
    s = f"{float(abs(val)):.{decimales}f}"
    
    if "." in s:
        s = s.rstrip("0").rstrip(".")
    return s if s else "0"

def lagrange(x_nodos, y_nodos, x_eval, mostrar_polinomio=False, decimales=6):
    """
    Evalúa el polinomio de interpolación de Lagrange expandido en su forma canónica.
    """
    x_eval = mp.mpf(x_eval)
    n = len(x_nodos)
    
    # El polinomio total iniciará en 0 (lista vacía de coeficientes)
    P_total = []
    
    for i in range(n):
        # Empezamos el numerador con 1
        num_poly = [mp.mpf(1)]
        den_val = mp.mpf(1)
        
        for j in range(n):
            if i != j:
                # Multiplicamos el polinomio actual por (x - x_j)
                num_poly = _poly_mul_root(num_poly, x_nodos[j])
                # Multiplicamos el denominador por (x_i - x_j)
                den_val *= (x_nodos[i] - x_nodos[j])
        
        # Multiplicamos todo el término por y_i / denominador
        factor = y_nodos[i] / den_val
        termino_i = [coef * factor for coef in num_poly]
        
        # Lo sumamos al polinomio final
        P_total = _poly_add(P_total, termino_i)
        
    # Construcción de la cadena de texto visual
    if mostrar_polinomio:
        terms_str = []
        # Recorremos desde la potencia mayor hasta la constante
        for grado in range(len(P_total)-1, -1, -1):
            coef = P_total[grado]
            if abs(coef) < 1e-15:  # Ignorar coeficientes nulos
                continue
                
            c_str = _format_float(coef, decimales)
            
            if grado == 0:
                x_str = ""
            elif grado == 1:
                x_str = "x"
            else:
                x_str = f"x^{grado}"
                
            term = f"{c_str}{x_str}"
            
            # Formato de signos
            if not terms_str:
                terms_str.append(f"-{term}" if coef < 0 else term)
            else:
                terms_str.append(f" - {term}" if coef < 0 else f" + {term}")
                
        polinomio_final = "".join(terms_str) if terms_str else "0"
        print(f"P{n-1}(x) = {polinomio_final}")

    # Evaluamos el polinomio usando el método de Horner (más estable)
    resultado = mp.mpf(0)
    for i in range(len(P_total)-1, -1, -1):
        resultado = resultado * x_eval + P_total[i]
        
    return float(resultado)

def cota_error_lagrange(x_nodos, x_eval, max_deriv_val):
    """
    Calcula la cota de error teórica para el polinomio de interpolación de Lagrange.
    
    :param x_nodos: Lista de puntos x [x0, x1, ..., xn]
    :param x_eval: Punto en el que se evalúa la aproximación
    :param max_deriv_val: Valor máximo absoluto de la derivada (n+1)-ésima en el intervalo
    :return: Valor numérico de la cota máxima de error
    """
    n = len(x_nodos) - 1
    x_eval = mp.mpf(x_eval)
    max_deriv_val = mp.mpf(max_deriv_val)
    
    # Productoria: (x - x0) * (x - x1) * ... * (x - xn)
    producto = mp.mpf(1)
    for xi in x_nodos:
        producto *= (x_eval - xi)
        
    # Aplicación estricta del teorema: (f^(n+1)(xi) / (n+1)!) * productoria
    cota = (max_deriv_val / factorial(n + 1)) * fabs(producto)
    
    return float(cota)