#include <stdio.h>
#include <math.h>
#include "validacion.h"
#include "../core/aritmetica.h"

/*
DATA TYPE   NAME                        ARGUMENTS               FUNCTION
*/
double      f                           (double x)              { return x*cos(x)-2*x*x+3*x-1; }
bool        teorema_valor_intermedio    (double a, double b)    { return redondear(f(a),6) * redondear(f(b),6) < 0; }

