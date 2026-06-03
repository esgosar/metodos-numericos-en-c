#include <math.h>
#include "aritmetica.h"

/*
DATA TYPE   NAME                ARGUMENTS                       */
double      redondear           (double numero, int decimales)
{
    /*
    DATA TYPE   NAME                VALUE                       */
    double      multiplicador   =   pow(10.0, decimales);       // 10^6
    double      desplazado      =   numero * multiplicador;     // 314592.65 = 3.14159265...*10^6

    // 314592.65... > 0 -> 314593.15 = 314592.65... + 0.5 -> 314593 = (long long)314593.15 -> 3.141593 = 314593/10^6
    return ((desplazado >= 0.0) ? (double)((long long)(desplazado + 0.5)) : (double)((long long)(desplazado - 0.5))) / multiplicador;
}

double      truncar             (double numero, int decimales)
{
    /*
    DATA TYPE   NAME                VALUE                       */
    double      multiplicador   =   pow(10.0, decimales);
    double      desplazado      =   numero * multiplicador;
    
    // 314593 = (long long)314593.15... -> 3.141593 = 314593/10^6
    return (double)((long long)desplazado) / multiplicador;
}

double      tolerancia          (double l_max, double l_min) { return l_max - l_min; }