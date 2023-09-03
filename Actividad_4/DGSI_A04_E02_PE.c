// Danna Sandez Islas 373080
//  03 de septiembre de 2023
//  Menu de operaciones de medidas con if anidados
//  SD_ACT04_02

#include <stdio.h>

int main()
{
    float num, op, res;

    printf("MENU DE OPERACIONES \n");
    printf("1-CM a PULGADAS \n");
    printf("2-CM a PIES \n");
    printf("3-KM a MILLAS \n");
    printf("4-PULGADAS a CM \n");
    printf("5-PIES a CMM \n");
    printf("6-MILLAS a KM \n");
    scanf("%f", &op);

    printf("Ingrese la cifra que desea convertir \n");
    scanf("%f", &num);

    if (op == 1)
    {
        res = (num / 2.54);
    }
    else
    {
        if (op == 2)
        {
            res = (num / 30.48);
        }
        else
        {
            if (op == 3)
            {
                res = (num / 1.609);
            }
            else
            {
                if (op == 4)
                {
                    res = (num * 2.54);
                }
                else
                {
                    if (op == 5)
                    {
                        res = (num * 30.48);
                    }
                    else
                    {
                        if (op == 6)
                        {
                            res = (num * 1.609);
                        }
                    }
                }
            }
        }
    }

    printf("El resultado de la conversion es: %f", res);

    return 0;
}