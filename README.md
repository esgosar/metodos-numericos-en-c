# Calculadora de Métodos Numéricos en Python 🧮

Este repositorio contiene un entorno de desarrollo robusto para el cálculo y análisis de Métodos Numéricos. Está diseñado con una arquitectura modular que separa la lógica de los algoritmos matemáticos de los scripts de resolución de tareas específicas.

Todo el núcleo matemático está impulsado por la librería `mpmath`, garantizando cálculos de altísima precisión (hasta 50 decimales por defecto) y soporte nativo para números complejos.

## ✨ Características Principales

* **Búsqueda de Raíces:**
  * Método de la Secante.
  * Método de Müller (con soporte automático para navegación en el plano complejo y hallazgo de raíces imaginarias conjugadas).
* **Interpolación Polinomial:**
  * Construcción de Polinomios de Lagrange (con despliegue algebraico de la ecuación en consola).
  * Método de Neville con generación automática de la matriz triangular iterativa.
* **Análisis de Error Estricto:**
  * Cálculo automático de Cotas de Error Teóricas usando el Teorema del Error de Lagrange.
  * Diferenciación automática de funciones complejas (enésimas derivadas) y escaneo de intervalos para maximizar la productoria y encontrar el peor caso garantizado.
* **Formatos y Reportes:**
  * Salida por terminal estructurada en tablas dinámicas.
  * Alineación de decimales y notaciones para facilitar la comparación de resultados.

## 📂 Estructura del Proyecto

El proyecto sigue una estricta filosofía de "No repetición de código" (DRY), dividido en dos áreas principales:

```text
.
├── metodos/                  # 🧠 Núcleo de algoritmos genéricos
│   ├── interpolacion.py      # Lógica de Lagrange, Neville y Cotas de error
│   └── solvers.py            # Buscadores de raíces (Secante, Müller, etc.)
│
├── Tareas/                   # 📝 Scripts ejecutables por ejercicio/unidad
│   ├── 01.py      
│   ├── 02.py      
│   ├── 03.py     
│   └── ...                   
│
└── README.md                 # Documentación del proyecto
