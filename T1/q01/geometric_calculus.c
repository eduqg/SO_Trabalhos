#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double side_length(double x1, double y1, double x2, double y2)
{
    double length = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    return length;
}

bool calculation_condition_existence(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double length1 = 0, length2 = 0, length3 = 0;
    double condition1 = 0 ;
    double condition2 = 0 ;
    double condition3 = 0 ;

    length1 = side_length(x1, y1, x2, y2);
    length2 = side_length(x2, y2, x3, y3);
    length3 = side_length(x3, y3, x1, y1);

    condition1 = abs(length2 - length3);
    condition2 = abs(length1 - length3);
    condition3 = abs(length1 - length2);

    if( condition1 < length1 && length1 < length2 + length3 &&
        condition2 < length2 && length2 < length1 + length3 &&
        condition3 < length3 && length3 < length1 + length2){
        return true;
    }
    else
    {
        return false;
    }

}

double calculates_perimeter(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double length1 = 0;
    double length2 = 0;
    double length3 = 0;

    length1 = side_length(x1, y1, x2, y2);
    length2 = side_length(x2, y2, x3, y3);
    length3 = side_length(x3, y3, x1, y1);

    return length1 + length2 + length3;
}

double calculates_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double length1 = 0;
    double length2 = 0;
    double length3 = 0;
    double result_area = 0;
    double semi_perimeter = 0;

    length1 = side_length(x1, y1, x2, y2);
    length2 = side_length(x2, y2, x3, y3);
    length3 = side_length(x3, y3, x1, y1);

    printf("Distancia 1 em calculo da área = %.2f\n", length1);
    printf("Distancia 2 em calculo da área = %.2f\n", length2);
    printf("Distancia 3 em calculo da área = %.2f\n", length3);

    semi_perimeter = (length1 + length2 + length3)/2.0;

    printf("Semi-perímetro em calculo da área = %.2f\n", semi_perimeter);

    result_area = sqrt(semi_perimeter*(semi_perimeter - length1)*(semi_perimeter - length2) * (semi_perimeter - length3));

    return result_area;
}
