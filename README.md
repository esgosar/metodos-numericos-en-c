# Numerical Analysis Calculator in Python 🧮

This repository contains a robust development environment for computing and analyzing Numerical Methods. It is designed with a modular architecture that separates the core logic of mathematical algorithms from the executable scripts for specific assignments.

The entire mathematical core is powered by the `mpmath` library, ensuring high-precision calculations (up to 50 decimal places by default) and native support for complex numbers.

## ✨ Key Features

* **Root-Finding:**
  * Secant Method.
  * Müller's Method (with automatic support for complex plane navigation and finding complex conjugate roots).
* **Polynomial Interpolation:**
  * Lagrange Polynomial construction (with algebraic expression of the equation printed in the console).
  * Neville's Method with automatic generation of the iterative triangular matrix.
* **Strict Error Analysis:**
  * Automatic calculation of Theoretical Error Bounds using Lagrange's Error Theorem.
  * Automatic differentiation of complex functions (nth derivatives) and interval scanning to maximize the product and find the guaranteed worst-case scenario.
* **Formatting and Reporting:**
  * Terminal output structured into dynamic tables.
  * Decimal alignment and clear notations to facilitate result comparison.

## 📂 Project Structure

The project follows a strict "Don't Repeat Yourself" (DRY) philosophy, divided into two main areas:

```text
.
├── metodos/                  # 🧠 Core generic algorithms
│   ├── interpolacion.py      # Lagrange, Neville, and Error Bound logic
│   └── solvers.py            # Root-finders (Secant, Müller, etc.)
│
├── Tareas/                   # 📝 Executable scripts per exercise/unit
│   ├── 01.py      
│   ├── 02.py      
│   ├── 03.py     
│   └── ...                   
│
└── README.md                 # Project documentation
```
