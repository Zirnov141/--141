#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

#define A 1.6
double getDouble();
double y(const double x);

int main()
{
    printf("Введите x: ");
    double x = getDouble();
    printf("y = %lf\n", y(x));
    return 0;
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf",&value) != 1)
        {
            printf("Error");
            exit(1);
        }
    return value;
}

double y(const double x)
{
    if (x > A)
    {
        return exp(A * x) - 2.5;
    }
    else if (fabs(x) < DBL_EPSILON) 
    {
        return 3.0;
    }
    else 
    {
        return (A / x) + sin(x);
    }
}
