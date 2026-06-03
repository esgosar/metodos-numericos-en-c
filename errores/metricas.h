#ifndef METRICAS_H
#define METRICAS_H


/*
DATA TYPE   NAME                ARGUMENTS                                       */
double      error_absoluto      (double valor_real, double valor_aproximado);
double      error_relativo      (double valor_real, double valor_aproximado);
double      error_porcentual    (double valor_real, double valor_aproximado);

#endif