#include "rational_numbers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
rational_t add(rational_t a, rational_t b)
{
    rational_t result;
    printf("addition\n");
    result.numerator = ((a.numerator * b.denominator) + (a.denominator * b.numerator));  
    result.denominator = (a.denominator * b.denominator);
    // result.denominator = 3;
    // printf("%i\n",.numerator);
    result = reduce(result);
    printf("%i\n",result.denominator);
    return result;
}
rational_t subtract(rational_t a, rational_t b)
{
    rational_t result;
    printf("substraction\n");
    result.numerator = ((a.numerator * b.denominator) - (a.denominator * b.numerator));  
    result.denominator = (a.denominator * b.denominator);
    // result.denominator = 3;
    // printf("%i\n",.numerator);
    result = reduce(result);
    // printf("%i\n",a.numerator);
    // printf("%i\n",b.numerator);
    return result;
}

rational_t multiply(rational_t a, rational_t b)
{
    rational_t result;
    printf("multiply\n");
    result.numerator = (a.numerator * b.numerator);
    result.denominator = (a.denominator * b.denominator);
    result = reduce(result);
    return result;
}

rational_t divide(rational_t a, rational_t b)
{
    rational_t result;
    printf("%i\n",b.numerator);
    printf("debug %i and %i $$$ seconde %i and %i\n",a.numerator,a.denominator,b.numerator,b.denominator);
    // if (b.numerator != 0)
    // {
    result.numerator = (a.numerator * b.denominator);
    result.denominator = (b.numerator * a.denominator);
    // }
    // result.numerator = 1;
    // result.denominator = 3;
    printf("debug after %i and %i\n",result.numerator,result.denominator);
    // printf("%i\n",b.numerator);
    result = standard(result);
    return result;
}

rational_t absolute(rational_t a)
{
    printf("absolute\n");
    rational_t result = reduce(a);
    printf("before value changes %i and %i\n",result.numerator,result.denominator);
    result.numerator = abs(result.numerator);
    result.denominator = abs(result.denominator);
    printf("end of the absolute %i and %i $$$$ %i  and %i\n",a.numerator,a.denominator,result.numerator,result.denominator);
    // printf("%i\n",b.numerator);
    return result;
}
rational_t exp_rational(rational_t a,int16_t n)
{
    rational_t result;
    printf("rational\n");
    printf("before value changes %i and %i and value of n %i\n",a.numerator,a.denominator,n);
    if (n < 0)
    {
    result.numerator = floor(pow(a.denominator,abs(n)));
    result.denominator = floor(pow(a.numerator,abs(n))); 
    }
    else{
    result.numerator = floor(pow(a.numerator,n));
    result.denominator = floor(pow(a.denominator,n));
    }
    // result.denominator = 3;
    printf("after debug %i and %i\n",result.numerator,result.denominator);
    // printf("%i\n",n);
    // printrational\nf("");
    result = standard(result);
    return result;
}

float exp_real(uint16_t x,rational_t a)
{
    // rational_t result;
    // // result.numerator = 1;
    // result.denominator = 3;
    printf("before change %i and %i\n",a.numerator,a.denominator);
    printf("%i\n",x);
    float temp =(float)pow(x,a.numerator);
    // printf("%f\n",temp);
    
    // return pow((floor(pow(x,a.numerator))),1 / a.numerator);
    // printf("%f\n",1.0 / a.denominator);
    return pow(temp,1.0 / a.denominator);
}

rational_t reduce(rational_t a)
{
    printf("reduce\n");
    rational_t result = standard(a);
    int reducer = gcd(result.numerator,result.denominator);
    result.numerator = result.numerator / reducer;
    result.denominator = result.denominator / reducer;
    // printf("%i\n",a.numerator);
    // printf("%i\n",b.numerator);
    return result;
}

rational_t standard(rational_t input)
{
    printf("debug standard\n");
    rational_t result;
    if (input.denominator < 0)
    {
        printf("debug comparison done\n");
        result.numerator = (int)input.numerator * -1;
        result.denominator = (int)input.denominator * -1;
    }
    else {
        result.numerator = input.numerator;
        result.denominator = input.denominator;
    }
    printf("end of standard before %i and %i $$$ and after %i and %i\n",input.numerator,input.denominator,result.numerator,result.denominator);
    return result;
}


int gcd(int numerator, int denominator)
{
    int lowest = 0;
    int greatest_commom_divisor = 0;
    printf("start of the gcd\n");
    if (numerator < denominator)
        lowest = numerator;
    else
        lowest = denominator;
    if (lowest < 0)
        lowest = lowest * -1;
    if (numerator == 0 || denominator == 0)
    {
        if (numerator == 0)
            return denominator;
        else 
            return numerator;
    }
    for (int i = 1; i <= lowest; i++)
    {
        if ((numerator % i == 0) && (denominator % i == 0))
            greatest_commom_divisor = i;
    }
    printf("end of gcd of %i and %i is %i\n",numerator,denominator,greatest_commom_divisor);
    return greatest_commom_divisor;
}