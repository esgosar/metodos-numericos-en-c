#include <math.h>
#include "metricas.h"

/*
DATA TYPE   NAME                ARGUMENTS                                       FUNCTION                                                                                */
double      error_absoluto      (double valor_real,
                                 double valor_aproximado)
{ return fabs(valor_real - valor_aproximado); }
double      error_relativo      (double valor_real,
                                 double valor_aproximado)
{ return valor_real == 0.0 ? 0.0 : fabs((valor_real - valor_aproximado) / valor_real); }
double      error_porcentual    (double valor_real,
                                 double valor_aproximado)
{ return error_relativo(valor_real, valor_aproximado) * 100.0; }