#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет площать круга с заданной стороной
 * @param side сторона круга
 * @return Рассчитанное значение
 */
double s(const double side);

/**
 * @brief Считывает с клавиатуры занчение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double side1 = getDouble();
    double side2 = getDouble();
    printf("Circle area  is %lf\n",s(side1));
    printf("Circle area  is %lf",s(side2));
    return 0;
}

double s(const double side)
{
    return pow(side,2) / (4.0 * 3.14);
}

double getDouble()
{
    double side1 = 0.0;
    scanf("%lf",&side1);
    return side1;
}
