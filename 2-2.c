#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
 * @brief считывает вещественное число с консоли и проверяет на корректность
 * @return считанное вещественное число 
 */
double getDouble();

/**
 * @brief вычисляет значение функции для заданного параметра 
 * @param x аргумент функции введенный пользователем
 * @param a параметр функции
 * @return Рассчитанное значение функции y
 */
double y(const double x, const double a);

/**
 * @brief Главная функция программы
 * @return  0 при успешном завершении
 */
int main()
{
    const double a = 1.6;

    printf("Enter x: ");
    double x = getDouble();
    printf("y = %lf\n", y(x, a));
    return 0;
}

/**
 * @brief считывает вещественное число с консоли и проверяет на корректность
 * @return считанное вещественное число 
 */
double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

/**
 * @brief вычисляет значение функции для заданного параметра 
 * @param x аргумент функции введенный пользователем
 * @param a параметр функции
 * @return Рассчитанное значение функции y
 */
double y(const double x, const double a)
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
