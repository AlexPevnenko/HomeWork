#include "stdio.h"
#include "locale.h"
#include "math.h"
#include "assert.h"

bool check_number(int,int,int);
void find_roots(double, double, double);



int main() 
{
    setlocale(LC_ALL,"Russian");
    double a, b, c;
    int test_a, test_b, test_c;
    //ввод работает четко
    printf("\tДанная программа находит действительные корни квадратного уравнения\n");
    printf("Введите коэффициенты квадратного уравнения:\n");
    test_a=scanf_s("%lg", &a);
    test_b=scanf_s("%lg", &b);
    test_c=scanf_s("%lg", &c);
    //все супер , классно , но нет проверки , что введено - число или говно 
    bool test = check_number(test_a, test_b, test_c);
    if (test == false) 
    {
        printf("\nВведенные значения не являются корректными!\n");
        return 1;
    }
    else
    {
        //теперь находим сколько корней должно быть 
        find_roots(a, b, c);
        return 0;
    }
}

void find_roots(double a, double b, double c) 
{
    if (a != 0 && b == 0 && c == 0) //v
    {
        printf("Корень равен 0");
    }
    else if (a != 0)
    {
        double D = b * b - 4 * a * c;
        if (D > 0) //v
        {
            double x_1 = (-b + sqrt(D)) / (2 * a);
            double x_2 = (-b - sqrt(D)) / (2 * a);
            printf("\nКорни квадратного уравнения равны:\nx_1=%lg\nx_2=%lg\n", x_1, x_2);
        }
        else if (D == 0) //v
        {
            double x = (-b) / (2 * a);
            printf("\nКорень квадратного уравнения равен:\nx=%lg\n", x);
        }
        else //v
        {
            printf("\nДействительных корней данное уравнение не имеет!\n");
        }

    }
    else //v
    {
        printf("Корень- любое число\n");
    }
}

bool check_number(int test_a, int test_b, int test_c) 
{
    if (test_a == 0 || test_b == 0 || test_c == 0)
    {
        return false;
    }
    else return true;
}