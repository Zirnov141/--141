#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief режимы вычислений
 */
enum Menu {
    PERIMETER = 1,
    AREA = 2
};

/**
 * @brief считывание числа
 */
double getDouble();

/**
 * @brief расчет длины стороны
 */
double getSide(double x1, double y1, double x2, double y2);

/**
 * @brief проверка треугольника
 */
void check(double a, double b, double c);

/**
 * @brief расчет периметра
 */
double getPerimeter(double a, double b, double c);

/**
 * @brief расчет площади
 */
double getArea(double a, double b, double c);

/**
 * @brief главная функция
 */
int main()
{
    printf("Enter x1: "); double x1 = getDouble();
    printf("Enter y1: "); double y1 = getDouble();
    
    printf("Enter x2: "); double x2 = getDouble();
    printf("Enter y2: "); double y2 = getDouble();
    
    printf("Enter x3: "); double x3 = getDouble();
    printf("Enter y3: "); double y3 = getDouble();

    // измерение длины всех сторон треугольника
    double a = getSide(x1, y1, x2, y2);
    double b = getSide(x2, y2, x3, y3);
    double c = getSide(x3, y3, x1, y1);

    // проверка существования треугольника
    check(a, b, c);

    double perimeter = getPerimeter(a, b, c);
    double area = getArea(a, b, c);

    
    printf("\nWhat to calculate?\n%d - Perimeter\n%d - Area\nchoice: ", PERIMETER, AREA);
    int choice = (int)getDouble(); 

    // вывод выбора пользователя
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

double getSide(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void check(double a, double b, double c)
{
    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) 
    {
        printf("Error");
        exit(1);
    }
}

double getPerimeter(double a, double b, double c)
{
    return a + b + c; 
}

double getArea(double a, double b, double c)
{
    double p = getPerimeter(a, b, c) / 2.0;       
    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}
