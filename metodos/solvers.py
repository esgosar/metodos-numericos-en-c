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

def secante(f, p0, p1, tolerancia, max_iter, decimales=6):
    p0 = mp.mpf(p0)
    p1 = mp.mpf(p1)
    tol = mp.mpf(tolerancia)

    print(f"\n| {'n':<3} | {'p_n-1':<9} | {'p_n':<9} | {'p_n+1':<9} | {'Error':<9} |")
    print("-" * 62)

    q0 = f(p0)
    q1 = f(p1)

    for n in range(2, max_iter + 1):
        if (q1 - q0) == 0:
            print("Excepción: Pendiente nula (división por cero).")
            return float('nan')

        p = p1 - q1 * (p1 - p0) / (q1 - q0)
        error = abs(p - p1)

        print(f"| {n:<3} | {float(p0): 9.{decimales}f} | {float(p1): 9.{decimales}f} | {float(p): 9.{decimales}f} | {float(error): 9.{decimales}f} |")

        if error < tol:
            print(f"\n[✓] Secante: Convergencia en iteración {n}: p = {float(p):.{decimales}f}")
            return float(p)

        p0, q0 = p1, q1
        p1, q1 = p, f(p)

    print("Excepción: Límite de iteraciones alcanzado.")
    return float(p)

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