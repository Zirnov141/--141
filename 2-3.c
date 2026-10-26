#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывание числа
 * @return - считанное положительное значение с плавающей точкой
 */
double getDouble();

/**
 * @brief проверка корректности исходных данных (должны быть строго больше нуля)
 * @param r радиус заготовки
 * @param a сторона первой пластинки
 * @param b сторона первой пластинки
 * @param c сторона второй пластинки
 * @param d сторона второй пластинки
 */
void checkData(const double r, const double a, const double b, const double c, const double d);

/**
 * @brief проверка возможности размещения двух пластинок в окружности
 * @param r радиус заготовки
 * @param a сторона первой пластинки
 * @param b сторона первой пластинки
 * @param c сторона второй пластинки
 * @param d сторона второй пластинки
 * @return 1, если можно вырезать; 0, если нельзя
 */
int canCutOut(const double r, const double a, const double b, const double c, const double d);

/**
 * @brief главная функция
 * @return - 0 при успешном завершении
 */
int main()
{
    printf("Enter circle radius (r): "); 
    double r = getDouble();
    
    printf("Enter 1st rectangle side a: "); 
    double a = getDouble();
    printf("Enter 1st rectangle side b: "); 
    double b = getDouble();
    
    printf("Enter 2nd rectangle side c: "); 
    double c = getDouble();
    printf("Enter 2nd rectangle side d: "); 
    double d = getDouble();

    // Проверка входных данных на корректность
    checkData(r, a, b, c, d);

    // Проверка логического условия задачи
    if (canCutOut(r, a, b, c, d))
    {
        printf("\nResult: YES, you can cut out both rectangles.\n");
    }
    else
    {
        printf("\nResult: NO, you cannot cut out both rectangles.\n");
    }

    return 0; 
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input Error");
        exit(1);
    }
    return value;
}

void checkData(const double r, const double a, const double b, const double c, const double d)
{
    if (r <= 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0) 
    {
        printf("Error: All geometric dimensions must be greater than zero.");
        exit(1);
    }
}

int canCutOut(const double r, const double a, const double b, const double c, const double d)
{
    // Квадрат диаметра круга (максимально допустимый квадрат диагонали)
    double max_diagonal_sq = 4.0 * r * r;
    double w, h, current_diagonal_sq;

    // Вариант 1: Стыковка по сторонам a и c (ширина = a + c, высота = max(b, d))
    w = a + c;
    h = (b > d) ? b : d;
    current_diagonal_sq = w * w + h * h;
    if (current_diagonal_sq <= max_diagonal_sq) return 1;

    // Вариант 2: Стыковка по сторонам a и d (ширина = a + d, высота = max(b, c))
    w = a + d;
    h = (b > c) ? b : c;
    current_diagonal_sq = w * w + h * h;
    if (current_diagonal_sq <= max_diagonal_sq) return 1;

    // Вариант 3: Стыковка по сторонам b и c (ширина = b + c, высота = max(a, d))
    w = b + c;
    h = (a > d) ? a : d;
    current_diagonal_sq = w * w + h * h;
    if (current_diagonal_sq <= max_diagonal_sq) return 1;

    // Вариант 4: Стыковка по сторонам b и d (ширина = b + d, высота = max(a, c))
    w = b + d;
    h = (a > c) ? a : c;
    current_diagonal_sq = w * w + h * h;
    if (current_diagonal_sq <= max_diagonal_sq) return 1;

    // Если ни один вариант компоновки не поместился в круг
    return 0;
}
