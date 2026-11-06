#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывание числа
 * @return - считанное положительное значение с плавающей точкой
 */
 double getdouble();

 /**
  * @brief - проверка коректности исходных данных
  * @param- r радиус 
  * @param- a сторона первой пластинки
  * @param- b сторона первой пластинки
  * @param- c сторона второй пластинки
  * @param- d сторона второй пластинки
  */
void checkdata(const double r,const double a,const double b,const double c,const double d);

/**
 * @brief проверка возможности размещения двух пластинок в окружности
 * @param r радиус заготовки
 * @param a сторона первой пластинки
 * @param b сторона первой пластинки
 * @param c сторона второй пластинки
 * @param d сторона второй пластинки
 * @return 1, если можно вырезать; 0, если нельзя
 */
int cancutout(const double r,const double a,const double b,const double c,const double d);

/**
 * @brief главная функция 
 * @return 0 при успешном завершении
 */
int main()
{
    printf("enter radius:");
    double r = getdouble();
    
    printf("enter side a:"); 
    double a = getdouble();
    
    printf("enter side b: "); 
    double b = getdouble();
    
    printf("Enter side c: "); 
    double c = getdouble();
    
    printf("Enter side d: "); 
    double d = getdouble();
    checkdata(r,a,b,c,d);
    
    if (cancutout(r,a,b,c,d))
    {
        printf("\nresult: yes  you can cut out rectangles.\n");
    }
    else
    {
        printf("\nresult: no you can cut out rectangles.\n");
    }
    return 0;
}

double getdouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("input error\n");
        exit(1);
    }
    return value; 
}

void checkdata(const double r, const double a, const double b, const double c, const double d)
{
    if (r <= 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
    {
        printf("input error\n");
        exit(1);
    }
}

int cancutout(const double r, const double a, const double b, const double c, const double d)
{
    if ((a * a + b * b) > 4.0 * r * r) 
    {
        return 0;
    }
    if ((c * c + d * d) > 4.0 * r * r) 
    {
        return 0;
    }


    if ((a + c) * (a + c) + (b + d) * (b + d) <= 4.0 * r * r) 
    {
        return 1;
    }
    if (fmax(a, c) * fmax(a, c) + (b + d) * (b + d) <= 4.0 * r * r) 
    {
        return 1;
    }
    if ((a + c) * (a + c) + fmax(b, d) * fmax(b, d) <= 4.0 * r * r) 
    {
        return 1;
    }


    if ((a + d) * (a + d) + (b + c) * (b + c) <= 4.0 * r * r) 
    {
        return 1;
    }
    if (fmax(a, d) * fmax(a, d) + (b + c) * (b + c) <= 4.0 * r * r) 
    {
        return 1;
    }
    if ((a + d) * (a + d) + fmax(b, c) * fmax(b, c) <= 4.0 * r * r) 
    {
        return 1;
    }


    if ((b + c) * (b + c) + (a + d) * (a + d) <= 4.0 * r * r) 
    {
        return 1;
    }
    if (fmax(b, c) * fmax(b, c) + (a + d) * (a + d) <= 4.0 * r * r) 
    {
        return 1;
    }
    if ((b + c) * (b + c) + fmax(a, d) * fmax(a, d) <= 4.0 * r * r) 
    {
        return 1;
    }


    if ((b + d) * (b + d) + (a + c) * (a + c) <= 4.0 * r * r) 
    {
        return 1;
    }
    if (fmax(b, d) * fmax(b, d) + (a + c) * (a + c) <= 4.0 * r * r) 
    {
        return 1;
    }
    if ((b + d) * (b + d) + fmax(a, c) * fmax(a, c) <= 4.0 * r * r) 
    {
        return 1;
    }

    return 0;
}
