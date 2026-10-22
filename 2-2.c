#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
/** a глобальная константа
*/
const double a = 1.6;

double getDouble();
double y(const double x);
/**
 * @brief главная функция программы
 * @return 0 при успешном выполнении
 */
int main()
{
    printf("Enter x: ");
    double x = getDouble();
    printf("y = %lf\n", y(x));
    return 0;
}
/**
 * @brief считывает вещественное число с консоли и проверяет корректность 
 * @return считанное вещественное число
 */
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
/**
 * @brief вычисляет значение функции 
 * @param x аргумент функции
 * @return рассчитанное значение функции y
 */
double y(const double x)
{
    if (x > a)
    {
        return exp(a * x) - 2.5;
    }
    else if (fabs(x) < DBL_EPSILON) 
    {
        return 3.0;
    }
    else 
    {
        return (a / x) + sin(x);
    }
}
