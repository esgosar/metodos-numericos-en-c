#include <stdio.h>
#include <math.h>
#include "../core/aritmetica.h"
#include "../metodos/solvers.h"

#define DEC 6
#define TOL 1e-5
#define PI 3.141592654

double f(double x)  { return cos(x+sqrt(2))+ x*(x/2+sqrt(2)); }
double df(double x) { return -sin(x+sqrt(2)) + x + sqrt(2); }

int main() {
    printf("==============================================================\n");
    printf("    Unidad 2, Sección 2.4, Ejercicio 1\n");
    printf("==============================================================\n");

    int max_iter = 100;

    newton_raphson(f, df,-1.5, TOL, max_iter, DEC);

    return 0;
}