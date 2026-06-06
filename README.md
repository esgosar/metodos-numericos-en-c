# Métodos Numéricos

Este repositorio contiene un programa para el procesamiento de calculos con métodos numéricos escrito en C, diseñado bajo especificaciones de arquitectura de hardware.

El diseño cumple con las directrices algorítmicas e impresión de matrices especificadas en los flujos de cálculo numérico para **Bisección**, **Newton-Raphson** y **Punto Fijo**.

---

## 🛠️ Arquitectura y Estructura del Proyecto

El código está completamente segmentado aislando los resolvedores algorítmicos de la lógica matemática, las métricas de precisión y el bus de control de I/O.

```text
├── core/
│   ├── aritmetica.c       # Operaciones de redondeo, truncamiento y tolerancia.
│   └── aritmetica.h
├── errores/
│   ├── metricas.c         # Cálculo de errores absolutos, relativos y porcentuales
│   ├── metricas.h
│   ├── excepciones.c      # Matriz de mensajes e interrupciones del sistema
│   └── excepciones.h
├── teoremas/
│   ├── validacion.c       # Evaluador de funciones continuas y Supervisor del TVI
│   └── validacion.h
├── metodos/
│   ├── solvers.c          # Motor iterativo principal (Bisección, Newton, Punto Fijo)
│   └── solvers.h
└── main.c                 # Banco de pruebas central (Test Bench)
