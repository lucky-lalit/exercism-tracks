#include "complex_numbers.h"
#include <stdio.h>
#include <math.h>

complex_t c_add(complex_t a, complex_t b)
{
   // TODO: implement
    // printf("%f\n",a.real);
    // printf("%f\n",b.real);
    printf("addition");
    complex_t result;
    result.real = (a.real + b.real);
    result.imag = (a.imag + b.imag);
    return result;
}

complex_t c_sub(complex_t a, complex_t b)
{
   // TODO: implement
    // printf("%f\n",a.real);
    // printf("%f\n",b.real);
    printf("substraction");
    complex_t result;
    result.real = (a.real - b.real);
    result.imag = (a.imag - b.imag);
    return result;
}

complex_t c_mul(complex_t a, complex_t b)
{
   // TODO: implement
    // printf("%f\n",a.real);
    // printf("%f\n",b.real);
    printf("multiplication");
    complex_t result;
    result.real = ((a.real*b.real) - (a.imag * b.imag));
    result.imag = ((a.imag * b.real) + (a.real * b.imag));
    return result;
}

complex_t c_div(complex_t a, complex_t b)
{
    // TODO: implement
    // printf("%f\n",a.real);
    // printf("%f\n",b.real);
    printf("division");
    complex_t result;
    result.real = (((a.real * b.real) + (a.imag * b.imag)) / (pow(b.real,2) + pow(b.imag,2)));
    result.imag = (((a.imag * b.real) - (a.real * b.imag)) / (pow(b.real,2) + pow(b.imag,2)));
    return result;
}

double c_abs(complex_t x)
{
   // TODO: implement
    printf("absolute");
    // printf("%f\n",b.imag);
    return sqrt(pow(x.real,2) + pow(x.imag,2));
}

complex_t c_conjugate(complex_t x)
{
   // TODO: implement
    printf("conjugate");
    // printf("%f\n",b.real);
    complex_t result;
    result.real = x.real;
    result.imag = x.imag * (-1);
    return result;
}

double c_real(complex_t x)
{
   // TODO: implement
    printf("real");
    // printf("%f\n",x.real);
    // printf("%f\n",b.imag);
    return x.real;   
}

double c_imag(complex_t x)
{
   // TODO: implement
    printf("imag");
    // printf("%f\n",x.real);
    // printf("%f\n",x.imag);
    // printf("%f\n",b.imag);
    return x.imag;   
}

complex_t c_exp(complex_t x)
{
   // TODO: implement
    // printf("%f\n",x.real);
    // printf("%f\n",b.real);
    complex_t result;
    result.real = exp(x.real) * cos(x.imag);
    result.imag = exp(x.real) * sin(x.imag);
    return result;
    
}
