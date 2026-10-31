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
  * @param- c сторона первой пластинки
  * @param- d сторона первой пластинки
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

int cancutout(const double r,const double a,const double b,const double c,const double d)
{
    double max_d2 = 4.0 * r * r;
    double w, h;

  int cancutout(const double r, const double a, const double b, const double c, const double d)
{
    double max_d2 = 4.0 * r * r;
    double w, h;

    w = a + c;
    if (b > d) 
    {
        h = b;
    } 
    else 
    {
        h = d;
    }
    if (w * w + h * h <= max_d2) 
    {
        return 1;
    }

    w = a + d;
    if (b > c) 
    {
        h = b;
    } 
    else 
    {
        h = c;
    }
    if (w * w + h * h <= max_d2) 
    {
        return 1;
    }

    w = b + c;
    if (a > d) 
    {
        h = a;
    } 
    else 
    {
        h = d;
    }
    if (w * w + h * h <= max_d2) 
    {
        return 1;
    }

    w = b + d;
    if (a > c) 
    {
        h = a;
    } 
    else 
    {
        h = c;
    }
    if (w * w + h * h <= max_d2) 
    {
        return 1;
    }

    return 0;
}
}
