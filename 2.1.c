#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief режимы вычислений
 */
enum Menu {
    PERIMETER = 1, /**< расчет и вывод периметра треугольника */
    AREA = 2 /**< расчет и вывод площади треугольника */
};

/**
 * @brief считывание числа
 * @return - считанное значение с плавающей точкой
 */
double getDouble();

/**
 * @brief расчет длины стороны
 * @param x1 координата x первой точки
 * @param y1 координата y первой точки
 * @param x2 координата x второй точки
 * @param y2 координата y второй точки
 * @return длина отрезка между двумя точками
 */
double getSide(const double x1, const double y1, const double x2, const double y2);

/**
 * @brief проверка треугольника
 * @param a сторона ab
 * @param b сторона bc
 * @param c сторона ca
 */
void check(const double a, const double b, const double c);

/**
 * @brief расчет периметра
 * @param a сторона AB
 * @param b сторона BC
 * @param c сторона CA
 * @return сумма длин всех сторон
 */
double getPerimeter(const double a, const double b, const double c);

/**
 * @brief расчет площади
 * @param a сторона AB
 * @param b сторона BC
 * @param c сторона CA
 * @return площадь треугольника 
 */
double getArea(const double a, const double b, const double c);

/**
 * @brief главная функция
 * @return - 0 при успешном завершении
 */
int main()
{
    printf("Enter x1: "); double x1 = getDouble();
    printf("Enter y1: "); double y1 = getDouble();
    
    printf("Enter x2: "); double x2 = getDouble();
    printf("Enter y2: "); double y2 = getDouble();
    
    printf("Enter x3: "); double x3 = getDouble();
    printf("Enter y3: "); double y3 = getDouble();

    double a = getSide(x1, y1, x2, y2);
    double b = getSide(x2, y2, x3, y3);
    double c = getSide(x3, y3, x1, y1);

    check(a, b, c);

    double perimeter = getPerimeter(a, b, c);
    double area = getArea(a, b, c);

    
    printf("\nWhat to calculate?\n%d - Perimeter\n%d - Area\nchoice: ", PERIMETER, AREA);
    int choice = (int)getDouble(); 

    switch (choice)
    {
        case PERIMETER: 
            printf("Perimeter is %lf\n", perimeter);
            break;      
            
        case AREA:     
            printf("Square is %lf\n", area);
            break;      
            
        default:       
            printf("Error");
            exit(1);    
    }

    return 0; 
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error");
        exit(1);
    }
    return value;
}

double getSide(const double x1, const double y1, const double x2, const double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void check(const double a, const double b, const double c)
{
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) 
    {
        printf("Error");
        exit(1);
    }
}

double getPerimeter(const double a, const double b, const double c)
{
    return a + b + c; 
}

double getArea(const double a, const double b, const double c)
{
    double p = getPerimeter(a, b, c) / 2.0;       
    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}
