# 📚 Resolución de Tareas - Métodos Numéricos

Este directorio almacena los módulos de resolución para la suite de problemas oficiales del libro de texto **Análisis Numérico (Burden, Faires & Burden, 10a Edición)**. 

Cada programa ha sido inyectado al motor central del proyecto, utilizando la arquitectura modular del sistema (`../core`, `../metodos`, `../errores`, `../teoremas`) para garantizar precisión de punto flotante a nivel de registros del procesador.

---

## 🗂️ Índice Correlativo de Ejercicios (Syllabus)

Para mantener la simplicidad en el sistema de compilación y evitar colisiones entre capítulos, los archivos se identifican mediante un numeral secuencial de dos dígitos (`01.c`, `02.c`, etc.). A continuación, se detalla el mapeo exacto de cada script frente a las secciones y requerimientos del curso:

* **`00.c`** → **Test Bench Universal**: Banco de pruebas central que ejecuta en paralelo los 6 algoritmos de búsqueda de raíces utilizando el polinomio universal $f(x) = x^2 - 4$.
* **`01.c`** → **Sección 1.1 - Ejercicios 1a, 1c**: Demostración analítica y límites del Teorema del Valor Intermedio (TVI).
* **`02.c`** → **Sección 1.1 - Ejercicios 2c, 2d**: Evaluación del TVI y límites de continuidad en funciones racionales.
* **`03.c`** → **Sección 1.1 - Ejercicios 3b, 3c**: Algoritmos de barrido (escaneo) para localización automática de intervalos de raíces.
* **`04.c`** → **Sección 1.1 - Ejercicios 7b, 7d**: Verificación de las condiciones del Teorema de Rolle ($f'(c) = 0$).
* **`05.c`** → **Sección 1.1 - Ejercicio 10**: Aplicación geométrica y física de extremos absolutos.
* **`06.c`** → **Sección 1.2 - Ejercicios 1a, 1d**: Cálculo de errores absolutos, relativos y porcentuales en representación de máquina.
* **`07.c`** → **Sección 1.2 - Ejercicios 5b, 5d**: Evaluación del error real de truncamiento en Polinomios de Taylor ($P_2(x)$).
* **`08.c`** → **Sección 1.2 - Ejercicios 6b, 6d**: Simulación de pérdida de dígitos significativos por cancelación sustractiva en la ALU.
* **`09.c`** → **Sección 1.2 - Ejercicios 7b, 7c**: Determinación de cotas de error y tasas de convergencia de series numéricas.
* **`10.c`** → **Sección 2.1 - Ejercicio 11**: Localización precisa de raíces por Bisección aplicando la cota teórica para una tolerancia de $10^{-5}$.
* **`11.c`** → **Sección 2.2 - Ejercicios 1 y 2**: Análisis algebraico y convergencia del Teorema del Punto Fijo en entornos cerrados.
* **`12.c`** → **Sección 2.2 - Ejercicio 7**: Resolución iterativa de Punto Fijo para $x^4 - 3x^2 - 3 = 0$ en el intervalo $[1, 2]$ con tolerancia $10^{-2}$.
* **`13.c`** → **Sección 2.3 - Ejercicios 1 y 3**: Cálculo comparativo de velocidad de convergencia en las primeras iteraciones: Newton-Raphson vs. Secante vs. Posición Falsa.
* **`14.c`** → **Sección 2.3 - Ejercicio 5**: Resolución de problemas de alta curvatura con Newton-Raphson a precisión estricta de $10^{-4}$.

*Nota: Los numerales posteriores (`15.c` en adelante) se asignarán correlativamente conforme se expandan los módulos del motor central para cubrir las unidades de Interpolación, Integración Numérica y Sistemas de Ecuaciones.*

---

## ⚙️ Sistema de Compilación (Build System)

El `Makefile` de este directorio gestiona las dependencias del motor y automatiza el enlazado binario de cada script de forma simplificada.

### 1. Compilación de un ejercicio individual
Para compilar y enlazar un programa específico (por ejemplo, el Test Bench Universal o la primera tarea):
```bash
make 00
make 01
```

### 2. Compilación de todos los ejercicio
Para compilar y enlazar un programa específico (por ejemplo, el Test Bench Universal o la primera tarea):
```bash
make tareas
```
### 2. Compilación de todos los ejercicio
Para generar simultáneamente los binarios de toda la suite de ejercicios en una sola operación:
```bash
make tareas
```
### 3. Compilación de todos los ejercicio
Elimina todos los archivos objeto .o y los ejecutables temporales generados para restablecer el repositorio:
```bash
make clean
```


