#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
 * @brief считывание вещественного числа с проверкой ввода
 * @param текст подсказки для пользователя
 * @return считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief проверка корректности заданной точности
 * @param e погрешность вычисления ряда
 */
void checkEpsilon(const double e);

/**
 * @brief проверка корректности границ интервала и шага
 * @param xbegin начало интервала
 * @param xend конец интервала
 * @param step шаг табулирования
 */
void checkInterval(const double xbegin, const double xend, const double step);

/**
 * @brief вычисление точного значения заданной функции
 * @param x значение аргумента
 * @return вычисленное значение функции
 */
double getFunction(const double x);

/**
 * @brief вычисление рекуррентного множителя для перехода к следующему члену ряда
 * @param x значение аргумента
 * @param n текущий номер члена ряда
 * @return коэффициент перехода к следующему члену ряда
 */
double getCoef(const double x, const int n);

/**
 * @brief вычисление суммы функционального ряда в точке с заданной точностью
 * @param x значение аргумента
 * @param e заданная точность
 * @return сумма членов ряда
 */
double getSeriesSum(const double x, const double e);

/**
 * @brief главная функция программы
 * @return 0 при успешном завершении
 */
int main()
{
    const double X_BEGIN = 0.1;
    const double X_END = 0.8;
    const double STEP = 0.1;
    const int MAX_ITER = 1000000;

    checkInterval(X_BEGIN, X_END, STEP);
    double e = getValue("Enter epsilon (for example 4e-5): ");
    checkEpsilon(e);

    printf("\n%10s | %15s | %15s\n", "x", "f(x)", "S(x)");


    for (double x = X_BEGIN; x <= X_END + STEP / 2.0; x += STEP)
    {
        double f = getFunction(x);
        double s = getSeriesSum(x, e);
        printf("%10.4lf | %15.8lf | %15.8lf\n", x, f, s);
    }

    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error\n");
        exit(1);
    }
    return value;
}

void checkEpsilon(const double e)
{
    if (e <= 0)
    {
        printf("Error, epsilon has to be positive\n");
        exit(1);
    }
}

void checkInterval(const double xbegin, const double xend, const double step)
{
    if (step <= 0 || xbegin > xend)
    {
        printf("Error, invalid interval or step\n");
        exit(1);
    }
}

double getFunction(const double x)
{
    return log(1.0 / (2.0 + 2.0 * x + x * x));
}

double getCoef(const double x, const int n)
{
    double t = 1.0 + x;
    return -((double)n / (n + 1)) * t * t;
}

double getSeriesSum(const double x, const double e)
{
    double t = 1.0 + x;
    double a = -t * t;
    double sum = 0.0;
    int n = 1;
    const int MAX_ITER = 1000000;

    while (fabs(a) >= e - DBL_EPSILON && n < MAX_ITER)
    {
        sum += a;
        a *= getCoef(x, n);
        n++;
    }
    return sum;
}
