# ⚙️ Métodos Numéricos - Motor Computacional en C

Este repositorio contiene un motor para el procesamiento de cálculos de análisis numérico escrito en C estándar.

El diseño cumple con las directrices algorítmicas e impresión de matrices especificadas en los flujos de cálculo numérico para **Bisección**, **Newton-Raphson**, **Punto Fijo** y validación de **Teoremas Fundamentales del Cálculo**.

---

## 🛠️ Arquitectura y Estructura del Proyecto

El código base está completamente segmentado, aislando los resolvedores algorítmicos de la lógica matemática pura (ALU), las métricas de precisión y el bus de control de interrupciones.

```text
├── core/
│   ├── aritmetica.c       # Operaciones de FPU: redondeo, truncamiento y tolerancia
│   └── aritmetica.h
├── errores/
│   ├── metricas.c         # Cálculo de errores absolutos, relativos y porcentuales
│   ├── metricas.h
│   ├── excepciones.c      # Matriz de mensajes e interrupciones del sistema (Halt)
│   └── excepciones.h
├── teoremas/
│   ├── validacion.c       # Supervisor de hardware para el Teorema del Valor Intermedio (TVI)
│   └── validacion.h
├── metodos/
│   ├── solvers.c          # Motor iterativo principal (Bisección, Newton, Punto Fijo)
│   └── solvers.h
├── Tareas/                # 📂 Directorio de ejercicios prácticos resueltos (Cap. 1)
│   ├── 1.c, 2.c ...       # Scripts de tareas inyectados al motor central
│   ├── Makefile           # Pipeline de procesamiento masivo para ejercicios
│   └── README.md          # Documentación específica de los problemas resueltos
├── main.c                 # Banco de pruebas central (Test Bench)
└── Makefile               # Sistema automatizado de compilación global
