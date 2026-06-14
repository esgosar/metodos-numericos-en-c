# 🐍 Migración a Python: El Oráculo de Alta Precisión
*(Rama: `refactor-python`)*

Este documento explica la historia y la justificación técnica detrás de la migración de nuestro Motor de Análisis Numérico desde el lenguaje C estándar hacia Python con precisión arbitraria.

---

## 📖 La Historia: El Muro de los 64-Bits

Originalmente, este proyecto fue construido con una arquitectura estricta en **C**, gestionando a bajo nivel el hardware, los registros del procesador (ALU) y las interrupciones.

Al llegar a la **Sección 2.4 (Ejercicio 1)** del libro de *Burden, Faires & Burden*, nos encontramos de frente con el gran enemigo del cálculo computacional: el límite físico de la norma **IEEE 754 de 64-bits** (implementado nativamente en C como el tipo de dato `double`).

### ¿Qué dicta la norma IEEE 754 y por qué nos limitó?
El estándar IEEE 754 de doble precisión asigna exactamente 64 bits físicos en la memoria para representar un número real: 1 bit para el signo, 11 bits para el exponente y 52 bits para la fracción (mantisa). 

Esta restricción arquitectónica obliga a que un tipo `double` solo pueda garantizar una precisión máxima de **15 a 17 dígitos decimales significativos**. Cualquier operación matemática que requiera retener información más allá de este límite sufre un truncamiento forzado por el hardware, chocando con el *Épsilon de Máquina*.

### El problema: Multiplicidad 4 y Cancelación Sustractiva
La función de este ejercicio es $f(x) = \cos(x+\sqrt{2}) + x(\frac{x}{2}+\sqrt{2})$, la cual posee una raíz en $x = -\sqrt{2}$ con una **multiplicidad de 4**. 

Cuando el algoritmo de Newton-Raphson se acerca a esta raíz, la naturaleza de la multiplicidad 4 provoca que el valor de la función $f(x_n)$ decrezca muchísimo más rápido que el acercamiento en $X$. 

**Ejemplo de la incongruencia en el Output:**
Para la iteración 18, nuestro valor de aproximación $x_n$ estaba a una distancia de apenas $0.0002$ ($2 \times 10^{-4}$) de la respuesta correcta. Sin embargo, al evaluar la función, matemáticamente ese error se eleva a la cuarta potencia: $(2 \times 10^{-4})^4 \approx 1.6 \times 10^{-15}$.

Al intentar calcular $f(x_n)$ y $f'(x_n)$ con magnitudes del orden de $10^{-15}$, los 52 bits de la mantisa del `double` se agotan. Aquí ocurre el desastre computacional:
1. **Cancelación Sustractiva:** Operaciones que deberían dar un remanente diminuto (ej. $1.4142135623730952 - 1.4142135623730950$) pierden todos sus bits significativos, y el procesador rellena el vacío con "ruido" o basura numérica.
2. **División de Ruido:** En la fórmula de Newton ($x_n - \frac{f(x_n)}{f'(x_n)}$), la computadora termina dividiendo dos números corruptos. 

Esto generó una **incongruencia visible en nuestra terminal en C**: en lugar de converger suavemente hacia `-1.414325`, nuestro algoritmo comenzó a dar saltos erráticos e inexactos, devolviendo un estancamiento en `-1.414429`. El procesador literalmente se quedó ciego ante los decimales microscópicos.

Para  superar las limitaciones físicas del hardware, nació la necesidad de esta migración.

---

## 1️⃣ ¿Por qué migramos a Python y abandonamos C para este fin?

El cambio se hizo por **poder de abstracción matemática y legibilidad**.

### El problema de escalar en C
Se podría argumentar que C cuenta con el tipo de dato `long double` o `__float128`. Sin embargo, esto solo agranda el contenedor físico; sigue siendo un límite duro. Si el problema presentara una multiplicidad mayor, estos tipos también colapsarían.

Para emular precisión verdaderamente infinita en C (usando la memoria RAM en lugar del procesador), la única ruta es utilizar librerías de terceros como **GMP / MPFR**. Es aquí donde C fracasa rotundamente para los métodos numéricos debido a la **sobrecarga de operadores**. C no permite usar símbolos matemáticos básicos (`+`, `-`, `/`, `*`) con objetos complejos.

### La comparativa técnica (El detonante de la migración)

Observa lo que ocurre al intentar programar la fórmula básica de iteración de Newton-Raphson: $x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$

**❌ En C con precisión arbitraria (MPFR):**
```c
// 1. Inicialización de objetos dinámicos en RAM (256 bits)
mpfr_t xn_siguiente, fx, dfx, division;
mpfr_inits2(256, xn_siguiente, fx, dfx, division, NULL);

// 2. Operaciones matemáticas forzadas mediante llamadas a funciones de memoria
mpfr_div(division, fx, dfx, MPFR_RNDN);                 // division = fx / dfx
mpfr_sub(xn_siguiente, xn, division, MPFR_RNDN);        // xn_siguiente = xn - division