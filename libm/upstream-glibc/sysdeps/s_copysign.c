#include <math.h>

double __copysign(double x, double y)
{
    return __builtin_copysign(x, y);
}

__weak_reference (__copysign, __copysignl);
