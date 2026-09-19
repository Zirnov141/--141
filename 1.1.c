#include <stdio.h>
#include <math.h> 
/**
 * @brief вычисляет значение функции по заданной формуле
 * @param x - значение переменной х
 * @param y - значение переменной y
 * @return рассчитанное значение
 */
 double A(const double x,const double y, const double z);
 /**
 * @brief вычисляет значение функции по заданной формуле
 * @param x - значение переменной х
 * @param y - значение переменной y
 * @return рассчитанное значение
 */
  double B(const double x,const double y, const double z);


/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
 int main()
 {
    const double x = 1.4;
    const double y = 3.1;
    const double z = 0.5;
    printf("A = %lf\n",A(x,y,z));
    printf("B = %lf\n",B(x,y,z));
    
    return 0;
 }
 double A(const double x, const double y, const double z)
 {
    return sqrt(z * x * sin(2.0 * x) + exp(-2.0 * x) * (x + y));
}

double B(const double x, const double y, const double z)
{
    return exp(2.0 * x) * log(z + x) - pow(y, 3.0 * x) * log(y - x);
}
