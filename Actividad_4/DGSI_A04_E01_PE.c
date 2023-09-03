//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// Menu de operaciones con if anidados
// SD_ACT04_01


#include <stdio.h>

int main()
{

    int n1, n2, op, res;

    printf("MENU DE OPERACIONES \n");
    printf("1-Suma \n");
    printf("2-Resta \n");
    printf("3-Multiplicacion \n");
    printf("4-Division \n");
    scanf("%d", &op);

    printf("Que numero desea utilizar? \n");
    scanf("%d", &n1);
    printf("Que numero desea utilizar? \n");
    scanf("%d", &n2);

    if (op == 1)
    {
        res = n1 + n2;
    }
    else
    {
        if(op == 2)
        {
            res = n1 - n2;
        }
        else
        {
            if (op == 3)
            {
                res = n1 * n2;
            }
            else
            {
                if (op == 4)
                {
                    res = n1 * n2;
                }
            }
        }

    }

    printf("El resultado de tu operaciones: %d", res);

    return 0;
}