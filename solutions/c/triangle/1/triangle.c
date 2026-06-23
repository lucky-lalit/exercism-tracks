#include "triangle.h"
#include <stdio.h>
bool is_triangle(triangle_t sides)
{
    if (sides.a + sides .b >= sides.c && sides.b + sides .c >= sides.a && sides.a + sides .c >= sides.b)
        return true;
    return false;
}

bool is_equilateral(triangle_t sides)
{
    if ((sides.a == sides.b && sides.b == sides.c) && sides.a != 0)
        return true;
    return false;
}
bool is_isosceles(triangle_t sides)
{
    if ((sides.a == sides.b || sides.b == sides.c || sides.a == sides.c) && is_triangle(sides))
        return true;    
    return false;
}
bool is_scalene(triangle_t sides)
{
    if ((sides.a != sides.b && sides.b != sides.c && sides.a != sides.c) && is_triangle(sides))
        return true;
    return false;
}