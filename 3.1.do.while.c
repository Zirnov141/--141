#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double getValue(const char* message);
void checkStep(const double step);
void checkSegment(const double xbegin, const double xend);
bool isOOF(const double x);
double getY(const double x);

int main()
{
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");
    checkStep(step);
    checkSegment(xbegin, xend);

    double x = xbegin;
    do
    {
        if (isOOF(x))
        {
            printf("x = %lf, y = %lf\n", x, getY(x));
        }
        else
        {
            printf("x = %lf, y is not defined\n", x);
        }
        x += step;
    }
    while (x <= xend + step / 2.0);

    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Error, step have to be positive");
        exit(1);
    }
}

void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Error, segment begin have to be less or equal segment end");
        exit(1);
    }
}

bool isOOF(const double x)
{
    return isfinite(getY(x));
}

double getY(const double x)
{
    return 3.0 * x - 14.0 + exp(x) - exp(-x);
}
