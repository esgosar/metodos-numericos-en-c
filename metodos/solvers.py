from mpmath import mp, isnan
# ==========================================================================================
# [MODULO 1]: BUSQUEDA DE RAICES EN UNA VARIABLE (Ecuaciones No Lineales 1D)
# MOTOR DE PRECISION ARBITRARIA (Wolfram/MATLAB Emulator)
# ==========================================================================================
mp.dps = 50  # Precisión matemática interna de 50 decimales

def biseccion(f, a, b, tolerancia, max_iter, decimales=6):
    a = mp.mpf(a)
    b = mp.mpf(b)
    tol = mp.mpf(tolerancia)

    if f(a) * f(b) >= 0:
        print("[!] Error TVI: La función no cambia de signo en el intervalo.")
        return float('nan')

    print(f"\n| {'n':<3} | {'a':<9} | {'b':<9} | {'p':<9} | {'f(a)':<9} | {'f(b)':<9} | {'f(p)':<9} | {'Error':<9} |")
    print("-" * 92)

    for n in range(1, max_iter + 1):
        p = (a + b) / 2
        error = (b - a) / 2

        fa, fb, fp = f(a), f(b), f(p)

        print(f"| {n:<3} | {float(a): 9.{decimales}f} | {float(b): 9.{decimales}f} | {float(p): 9.{decimales}f} | {float(fa): 9.{decimales}f} | {float(fb): 9.{decimales}f} | {float(fp): 9.{decimales}f} | {float(error): 9.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Bisección: Convergencia alcanzada en iteración {n}: p = {float(p):.{decimales}f}")
            return float(p)

        if (fa > 0 and fp > 0) or (fa < 0 and fp < 0):
            a = p
        else:
            b = p

    print("Excepción: Límite de iteraciones alcanzado.")
    return float(p)

# ==========================================================================================

def newton_raphson(f, x0, tolerancia, max_iter, decimales=6):
    xn = mp.mpf(x0)
    tol = mp.mpf(tolerancia)

    print(f"\n| {'n':<3} | {'Xn':<12} | {'Xn+1':<12} | {'Error':<12} |")
    print("-" * 55)

    for n in range(1, max_iter + 1):
        fx = f(xn)
        # MAGIA: Python calcula la primera derivada automáticamente
        dfx = mp.diff(f, xn) 

        if dfx == 0:
            print("Excepción: Derivada nula detectada.")
            return float('nan')

        xn_siguiente = xn - (fx / dfx)
        error = abs(xn_siguiente - xn)

        print(f"| {n:<3} | {float(xn): 10.{decimales}f} | {float(xn_siguiente): 10.{decimales}f} | {float(error): 10.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Newton-Raphson: Convergencia en iteración {n}: x = {float(xn_siguiente):.{decimales}f}")
            return float(xn_siguiente)

        xn = xn_siguiente

    return float(xn)

# ==========================================================================================

def newton_modificado(f, x0, tolerancia, max_iter, decimales=6):
    xn = mp.mpf(x0)
    tol = mp.mpf(tolerancia)

    print(f"\n| {'n':<3} | {'Xn':<12} | {'Xn+1':<12} | {'Error':<12} |")
    print("-" * 55)

    for n in range(1, max_iter + 1):
        fx = f(xn)
        # MAGIA: Primera y segunda derivada automáticas (grado 1 y grado 2)
        dfx = mp.diff(f, xn, 1) 
        ddfx = mp.diff(f, xn, 2)

        denominador = (dfx**2) - (fx * ddfx)

        if denominador == 0:
            return float('nan')

        xn_siguiente = xn - (fx * dfx) / denominador
        error = abs(xn_siguiente - xn)

        print(f"| {n:<3} | {float(xn): 10.{decimales}f} | {float(xn_siguiente): 10.{decimales}f} | {float(error): 10.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Newton Modificado: Convergencia en iteración {n}: x = {float(xn_siguiente):.{decimales}f}")
            return float(xn_siguiente)

        xn = xn_siguiente

    return float(xn)

# ==========================================================================================

def punto_fijo(g, x0, tolerancia, max_iter, decimales=6):
    x_prev = mp.mpf(x0)
    tol = mp.mpf(tolerancia)
    xn = g(x_prev)

    print(f"\n| {'n':<3} | {'x_n':<9} | {'g(x_n)':<9} | {'Error':<9} |")
    print("-" * 47)

    for n in range(1, max_iter + 1):
        error = abs(xn - x_prev)
        x_next = g(xn)

        print(f"| {n:<3} | {float(xn): 9.{decimales}f} | {float(x_next): 9.{decimales}f} | {float(error): 9.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Punto Fijo: Convergencia en iteración {n}: x = {float(xn):.{decimales}f}")
            return float(xn)

        x_prev = xn
        xn = x_next

    print("Excepción: Límite de iteraciones alcanzado.")
    return float(xn)

# ==========================================================================================

def secante(f, x0, x1, tolerancia, max_iter, decimales=6):
    x0, x1 = mp.mpf(x0), mp.mpf(x1)
    tol = mp.mpf(tolerancia)
    
    print(f"\n| {'n':<3} | {'Xn':<12} | {'Error':<12} |")
    print("-" * 35)
    
    for n in range(1, max_iter + 1):
        fx0 = f(x0)
        fx1 = f(x1)
        if fx1 - fx0 == 0:
            return float('nan')
        
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
        error = abs(x2 - x1)
        
        print(f"| {n:<3} | {float(x2): 10.{decimales}f} | {float(error): 10.{decimales}f} |")
        
        if error < tol:
            print(f"\n[✓] Secante: Convergencia en iteración {n}: x = {float(x2):.{decimales}f}")
            return float(x2)
            
        x0, x1 = x1, x2
    return float(x1)

# ==========================================================================================

def posicion_falsa(f, a, b, tolerancia, max_iter, decimales=6):
    a, b = mp.mpf(a), mp.mpf(b)
    tol = mp.mpf(tolerancia)
    
    print(f"\n| {'n':<3} | {'Xn':<12} | {'Error':<12} |")
    print("-" * 35)
    
    x_old = a
    for n in range(1, max_iter + 1):
        fa = f(a)
        fb = f(b)
        if fb - fa == 0:
            return float('nan')
            
        x = b - fb * (b - a) / (fb - fa)
        error = abs(x - x_old)
        
        print(f"| {n:<3} | {float(x): 10.{decimales}f} | {float(error): 10.{decimales}f} |")
        
        if error < tol or abs(f(x)) < tol:
            print(f"\n[✓] Posición Falsa: Convergencia en iteración {n}: x = {float(x):.{decimales}f}")
            return float(x)
            
        if fa * f(x) < 0:
            b = x
        else:
            a = x
        x_old = x
    return float(x)

# ==========================================================================================

def posicion_falsa_modificada(f, p0, p1, tolerancia, max_iter, decimales=6):
    p0, p1 = mp.mpf(p0), mp.mpf(p1)
    tol = mp.mpf(tolerancia)

    if f(p0) * f(p1) >= 0:
        return float('nan')

    print(f"\n| {'n':<3} | {'p0':<9} | {'p1':<9} | {'p':<9} | {'f(p0)':<9} | {'f(p1)':<9} | {'f(p)':<9} |")
    print("-" * 87)

    q0, q1 = f(p0), f(p1)

    for n in range(2, max_iter + 1):
        p = p1 - q1 * (p1 - p0) / (q1 - q0)
        q = f(p)
        error = abs(p - p1)

        print(f"| {n:<3} | {float(p0): 9.{decimales}f} | {float(p1): 9.{decimales}f} | {float(p): 9.{decimales}f} | {float(q0): 9.{decimales}f} | {float(q1): 9.{decimales}f} | {float(q): 9.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Pos. Falsa Mod (Illinois): Convergencia en iteración {n}: p = {float(p):.{decimales}f}")
            return float(p)

        if q * q1 < 0:
            p0, q0 = p1, q1
            p1, q1 = p, q
        else:
            q0 = q0 / 2  # Algoritmo de Illinois
            p1, q1 = p, q

    return float(p)

# ==========================================================================================

def muller(f, x0, x1, x2, tolerancia, max_iter, decimales=6):
    # Usamos mp.mpc para habilitar explícitamente la navegación en el plano complejo
    x0, x1, x2 = mp.mpc(x0), mp.mpc(x1), mp.mpc(x2)
    tol = mp.mpf(tolerancia)
    
    # Helper interno para imprimir bonito (oculta la 'j' si es un número puramente real)
    def fmt_cplx(val):
        r = float(mp.re(val))
        i = float(mp.im(val))
        if abs(i) < 1e-12:  # Prácticamente real
            return f"{r: 10.{decimales}f}"
        else:
            signo = "+" if i >= 0 else "-"
            return f"{r: 10.{decimales}f} {signo} {abs(i):.{decimales}f}j"

    # Ampliamos la columna de Xn porque los complejos ocupan más espacio visual
    print(f"\n| {'n':<3} | {'Xn':<26} | {'Error':<12} |")
    print("-" * 50)
    
    for n in range(3, max_iter + 1):
        h1 = x1 - x0
        h2 = x2 - x1
        
        # Protección si los puntos colisionan
        if h1 == 0 or h2 == 0 or (h2 + h1) == 0:
            return complex(x2)
            
        d1 = (f(x1) - f(x0)) / h1
        d2 = (f(x2) - f(x1)) / h2
        d = (d2 - d1) / (h2 + h1)
        
        b = d2 + h2 * d
        # mpmath maneja raíces de números negativos automáticamente gracias a mp.mpc
        D = mp.sqrt(b**2 - 4 * f(x2) * d)
        
        # Maximizar el denominador usando el módulo complejo (abs)
        E = b + D if abs(b + D) > abs(b - D) else b - D
            
        if E == 0:
            return complex(x2)
            
        h = -2 * f(x2) / E
        x3 = x2 + h
        error = abs(x3 - x2)  # Módulo del vector de error en el plano complejo
        
        str_x3 = fmt_cplx(x3)
        print(f"| {n:<3} | {str_x3:<26} | {float(error): 10.{decimales}f} |")
        
        if error < tol:
            print(f"\n[✓] Müller: Convergencia en iteración {n}: x = {str_x3.strip()}")
            return complex(x3)
            
        x0, x1, x2 = x1, x2, x3
        
    return complex(x2)
    
# ==========================================================================================

def secante(f, x0, x1, tolerancia, max_iter, decimales=6):
    x0, x1 = mp.mpf(x0), mp.mpf(x1)
    tol = mp.mpf(tolerancia)
    
    print(f"\n| {'n':<3} | {'Xn':<12} | {'Error':<12} |")
    print("-" * 35)
    
    for n in range(1, max_iter + 1):
        fx0 = f(x0)
        fx1 = f(x1)
        if fx1 - fx0 == 0:
            return float('nan')
        
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
        error = abs(x2 - x1)
        
        print(f"| {n:<3} | {float(x2): 10.{decimales}f} | {float(error): 10.{decimales}f} |")
        
        if error < tol:
            return float(x2)
            
        x0, x1 = x1, x2
    return float(x1)

# ==========================================================================================

def steffensen(g, p0, tolerancia, max_iter, decimales=6):
    p0 = mp.mpf(p0)
    tol = mp.mpf(tolerancia)

    print(f"\n| {'n':<3} | {'p0':<12} | {'p1':<12} | {'p2':<12} | {'p':<12} | {'Error':<12} |")
    print("-" * 80)

    for n in range(1, max_iter + 1):
        p1 = g(p0)
        p2 = g(p1)
        
        denominador = p2 - 2*p1 + p0
        if denominador == 0:
            return float('nan')
            
        p = p0 - ((p1 - p0)**2) / denominador
        error = abs(p - p0)

        print(f"| {n:<3} | {float(p0): 10.{decimales}f} | {float(p1): 10.{decimales}f} | {float(p2): 10.{decimales}f} | {float(p): 10.{decimales}f} | {float(error): 10.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Steffensen: Convergencia en iteración {n}: p = {float(p):.{decimales}f}")
            return float(p)

        p0 = p

    return float(p)