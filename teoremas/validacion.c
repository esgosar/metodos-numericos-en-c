#ifndef METRICAS_H
#define METRICAS_H

// Calcula el error absoluto: magnitud de la diferencia exacta
double error_absoluto(double valor_real, double valor_aproximado);

// Calcula el error relativo: proporción del error respecto al valor real
double error_relativo(double valor_real, double valor_aproximado);

// Calcula el error relativo porcentual
double error_porcentual(double valor_real, double valor_aproximado);

#endif