#include <stdio.h>
#include <math.h>
/**
 * @brief вычисляет давление воды на дно по формуле
 * @param h - высота столба воды в метрах
 * @return Рассчитанное значение давления
 */
double Pressure(const double h);
/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение высоты
 */
double readHeight();
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("water height: ");
    printf("Water pressure: %lf Pa\n", Pressure(readHeight()));
    return 0;
}

double Pressure(const double h)
{
    const double p = 1000.0; 
    const double g = 9.81;     

    return p * g * h;
}

double readHeight()
{
    double value = 0.0; 
    scanf("%lf", &value); 
    return value; 
}
