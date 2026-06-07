# 📚 Resolución de Tareas - Métodos Numéricos

Este directorio contiene las implementaciones en C de los ejercicios asignados para la clase de Métodos Numéricos (Capítulo 1). 

Todo el código de estas tareas hace uso de la **Arquitectura Modular** del proyecto (ubicada en los directorios `../core`, `../errores` y `../teoremas`), garantizando una precisión matemática a 6 decimales.

## 🗂️ Índice de Ejercicios

Cada archivo `.c` corresponde a un bloque específico de la tarea asignada:

* **`1.c`** - **Problema 1 (a, c)**: Demostración analítica del Teorema del Valor Intermedio (TVI) comprobando el cambio de signo en intervalos dados.
* **`2.c`** - **Problema 2 (c, d)**: Evaluación del TVI resolviendo asintotas y verificando la existencia de raíces.
* **`3.c`** - **Problema 3 (b, c)**: Algoritmo de barrido (escaneo) para encontrar intervalos de tamaño 1 que contengan raíces, utilizando el motor central para certificar los hallazgos.
* **`4.c`** - **Problema 7 (b, d)**: Verificación de las condiciones del Teorema de Rolle ($f(a) = f(b)$) para garantizar la existencia de $f'(x) = 0$.
* **`5.c`** - **Problema 9 (b)**: Cálculo de Polinomios de Taylor ($P_2(x)$) y evaluación del error real de truncamiento.

## ⚙️ Sistema de Compilación (Build System)

Este directorio cuenta con un `Makefile` dinámico que enlaza automáticamente las tareas independientes con los módulos del motor central. 

Para utilizarlo, abre tu terminal, asegúrate de estar dentro de la carpeta `Tareas/` y ejecuta los siguientes comandos:

### 1. Compilar todas las tareas simultáneamente
Genera los binarios ejecutables para todos los problemas sin ejecutarlos.
```bash
make tareas
