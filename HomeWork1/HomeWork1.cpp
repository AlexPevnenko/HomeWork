#include <stdio.h>
#include "stdlib.h"
#include "locale.h"
#include <math.h>
#include <assert.h>

#define ZERO 0.1e-8 //разрешаемая погреность 

//--------------------------------------------------------------------------
//Решает квадратное уравнение ax*x+bx+c=0
//@param [in] a-coefficient
//@param [in] b-coefficient
//@param [in] c-coefficient
//--------------------------------------------------------------------------
void find_roots (double, double, double);

//--------------------------------------------------------------------------
//Функция для сравнения с нулем и проверки точности
//@peram [in] Checked number
//
//return Yes(1) or Not(0)
//--------------------------------------------------------------------------
int eq_num_zero (double);

int main () 
{
    setlocale (LC_ALL,"Russian");

    double a = NAN, b = NAN, c = NAN;

    printf ("Введите коэффициенты квадратного уравнения:\n");

    scanf_s ("%lg", &a);
    
    scanf_s ("%lg", &b);

    scanf_s ("%lg", &c);
    
    find_roots (a, b, c);
    
    return 0;
    
}


void find_roots (double a, double b, double c) 
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    if (!eq_num_zero (a) && eq_num_zero (b) && eq_num_zero (c) )
    {
        printf("Корень равен 0");
    }

    else if (!eq_num_zero (a))
    {
        double D = b * b - 4 * a * c;
        if (D > 0) 
        {
            double x_1 = (-b + sqrt(D)) / (2 * a);
            double x_2 = (-b - sqrt(D)) / (2 * a);
            printf("\nКорни квадратного уравнения равны:\nx_1=%0.3lg\nx_2=%0.3lg\n", x_1, x_2);
        }

        else if (D == 0) 
        {
            double x = (-b) / (2 * a);
            printf("\nКорень квадратного уравнения равен:\nx=%0.3lg\n", x);
        }

        else if (D < 0)
        {
            printf("\nДействительных корней данное уравнение не имеет!\n");
        }

    }

    else if (eq_num_zero (a) && eq_num_zero (b) && eq_num_zero (c))
    {
        printf("Корень- любое число\n");
    }
    else if (eq_num_zero (a))
    {
        printf ("\nУравнение линейное\n");

    }
}

int eq_num_zero (double num_test)
{
    if (num_test < ZERO)
    {
         return 1;
    }

    else 
    {
        return 0;
    }
}