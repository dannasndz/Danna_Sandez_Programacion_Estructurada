// Danna Sandez Islas 373080
//  03 de septiembre de 2023
//  Menu de llamadas con condiciones anidadas
//  SD_ACT04_05
#include <stdio.h>

int main()
{
    float ST, IVA, MIN, TIPO, TOTAL;

    printf("1-LLAMADA LOCAL\n");
    printf("2-LLAMADA NACIONAL\n");
    printf("3-LLAMADA INTERNACIONAL\n");
    printf("¿QUE TIPO DE LLAMADA DESEA?\n");
    scanf("%f", &TIPO);

    if (TIPO == 1)
    {
        printf("LLAMADA LOCAL\n");
        ST = 3;
    }
    else
    {
        if (TIPO == 2)
        {
            printf("LLAMADA NACIONAL\n");
            printf("¿CUANTOS MINUTOS HABLÓ?\n");
            scanf("%f", &MIN);
            if (MIN <= 3)
            {
                ST = 7;
            }
            else
            {
                ST = 7 + ((MIN - 3) * 2);
            }
        }
        else
        {
            if (TIPO == 3)
            {
                printf("LLAMADA INTERNACIONAL\n");
                printf("¿CUANTOS MINUTOS HABLÓ?\n");
                scanf("%f", &MIN);
                if (MIN <= 2)
                {
                    ST = 9;
                }
                else
                {
                    ST = 9 + ((MIN - 2) * 4);
                }
            }
        }
    }

    IVA = ST * 0.16;
    TOTAL = ST + IVA;

    printf("EL SUBTOTAL ES=%.2f \n", ST);
    printf("EL IVA ES=%.2f \n", IVA);
    printf("EL TOTAL ES=%.2f \n", TOTAL);

    return 0;
}
