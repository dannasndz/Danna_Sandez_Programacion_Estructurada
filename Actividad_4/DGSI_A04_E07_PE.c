//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// Promedio de calificaciones y eliminacion de la menor con condiciones anidadas
// SD_ACT04_07

#include <stdio.h>
int main()
{

    float cal1, cal2, cal3, cal4, cal5, prom, menor;

    printf("Ingrese su primera calificacion: \n");
    scanf("%f", &cal1);
    printf("Ingrese su segunda calificacion: \n");
    scanf("%f", &cal2);
    printf("Ingrese su tercera calificacion: \n");
    scanf("%f", &cal3);
    printf("Ingrese su cuarta calificacion: \n");
    scanf("%f", &cal4);
    printf("Ingrese su quinta calificacion: \n");
    scanf("%f", &cal5);
    menor = cal1;

    if (cal2 < menor)
    {
        menor = cal2;
    }
    else
    {
        if (cal3 < menor)
        {
            menor = cal3;
        }
        else
        {
            if (cal4 < menor)
            {
                menor = cal4;
            }
            else
            {
                if (cal5 < menor)
                {
                    menor = cal5;
                }
            }
        }
    }

    prom= ((cal1+cal2+cal3+cal4+cal5)-menor)/4;
 
    printf("El promedio final es %.2f\n", prom);

    return 0;
}