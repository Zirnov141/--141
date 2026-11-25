#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief считывание целого числа с проверкой ввода
 * @param текст для пользователя
 * @return считанное значение типа int
 */
int getInt(const char* message);

/**
 * @brief считывание вещественного числа с проверкой ввода
 * @param текст подсказки для пользователя
 * @return считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief проверка что верхний предел суммирования n положителен
 * @param n верхний индекс суммирования
 */
void checkPositive(const int n);

/**
 * @brief проверка корректности заданной точности e
 * @param e минимальный по модулю учитываемый член ряда
 */
void checkEpsilon(const double e);

/**
 * @brief вычисление суммы членов ряда от k = 0 до n
 * @param n верхний индекс суммирования
 * @return вычисленная сумма ряда
 */
double sumN(const int n);

/**
 * @brief вычисление суммы членов ряда по модулю не меньших e
 * @param e заданная точность
 * @return вычисленная сумма ряда
 */
double sumE(const double e);

/**
 * @brief вычисление рекуррентного множителя
 * @param i текущий индекс члена ряда
 * @return значение рекуррентного коэффициента
 */

double getCoef(const int i);

/**
 * @brief главная функция программы
 * @return 0 при успешном завершении
 */
int main() 
{
    int n = getInt("Enter n: ");
    checkPositive(n);
    double e = getValue("Enter e: ");
    checkEpsilon(e);
    printf("Summ of %d elements is: %lf\n", n, sumN(n));
    printf("Summ of elements less %lf is: %lf\n", e, sumE(e));
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

int getInt(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
}

void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e)
{
    if (e <= 0)
    {
        printf("Error, e have to be positive\n");
        exit(1);
    }
}

double sumN(const int n)
{
    double a = 1.0;
    double result = a;
    for (int i = 0; i < n; i++)
    {
        a *= getCoef(i); 
        result += a; 
    }
    return result;
}

double getCoef(const int i)
{
    return -1.0 / ((i + 1) * (i + 2));
}

double sumE(const double e)
{
    double a = 1.0;
    double result = 0;
    for (int i = 0; fabs(a) >= e - DBL_EPSILON; i++)
    {
        result += a;
        a *= getCoef(i);
    }
    return result;
}
