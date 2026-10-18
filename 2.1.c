#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/**
 * @brief Перечисление для выбора режима вычислений
 */
enum Menu {
    PERIMETER = 1,
    AREA = 2
};

/**
 * @brief Считывает с клавиатуры занчение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что сторона - положительное число
 * @param side - считанное значение стороны квадрата
 */
void checkSide(const double side);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Enter x1: "); double x1 = getDouble();
    printf("Enter y1: "); double y1 = getDouble();
    
    printf("Enter x2: "); double x2 = getDouble();
    printf("Enter y2: "); double y2 = getDouble();
    
    printf("Enter x3: "); double x3 = getDouble();
    printf("Enter y3: "); double y3 = getDouble();

    double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    checkSide(a);
    checkSide(b);
    checkSide(c);

    if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
        printf("Error");
        exit(1);
    }

    printf("\nWhat to calculate?\n1 - Perimeter\n2 - Area\nchoice: ");
    
    int choice = (int)getDouble(); 

    double perimeter = a + b + c;
    double p = perimeter / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

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
    double side1 = 0.0;
    if (scanf("%lf", &side1) != 1)
    {
        printf("Error");
        exit(1);
    }
    return side1;
}

void checkSide(const double side)
{
   if (side <= 0)
   {
       printf("Error");
       exit(1);
   }
}
