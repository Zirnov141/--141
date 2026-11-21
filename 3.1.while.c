#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * @brief считывание вещественного числа с проверкой ввода
 * @param message текст подсказки для пользователя
 * @return считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief проверка корректности шага табулирования
 * @param step шаг изменения аргумента
 */
void checkStep(const double step);

/**
 * @brief проверка корректности границ отрезка
 * @param xbegin начало отрезка
 * @param xend конец отрезка
 */
void checkSegment(const double xbegin, const double xend);

/**
 * @brief проверка принадлежности точки области определения функции
 * @param x значение аргумента
 * @return true, если функция определена в точке; иначе false
 */
bool isOOF(const double x);

/**
 * @brief вычисление значения функции y = 3x - 14 + e^x - e^(-x)
 * @param x значение аргумента
 * @return вычисленное значение функции
 */
double getY(const double x);

/**
 * @brief главная функция программы
 * @return 0 при успешном завершении
 */
int main()
{
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");
    checkStep(step);
    checkSegment(xbegin, xend);
    double x = xbegin;
    while (x <= xend + step / 2.0)
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

