#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывание вещественного числа с проверкой ввода
 * @param message текст подсказки для пользователя
 * @return считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief проверка корректности порогового значения h
 * @param h предельное значение суммы
 */
void checkLimit(const double h);

/**
 * @brief главная функция программы
 * @return 0 при успешном завершении
 */
int main()
{
    double h = getValue("Enter h: ");
    checkLimit(h);
    int n = 0;
    int s = 0;
    while (s < h)
    {
        n++;
        s += n;
    }
    printf("Last term = %d, Sum = %d\n", n, s);
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

void checkLimit(const double h)
{
    if (h <= 0)
    {
        printf("Error, h have to be positive");
        exit(1);
    }
}
