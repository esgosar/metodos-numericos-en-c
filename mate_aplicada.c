#include <stdio.h>
#include <math.h>
#include "mate_aplicada.h"
/*
DATA TYPE   NAME                        ARGUMENTS               FUNCTION
*/
double      f                           (double x)              { return x*cos(x)-2*x*x+3*x-1; }
double      round_rule                  (double valor)          { return round(valor * 1000000.0) / 1000000.0; }
bool        teorema_valor_intermedio    (double a, double b)    { return (round_rule(f(a)) * round_rule(f(b)) < 0); }

