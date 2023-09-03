
// Danna Sandez Islas 373080
//  03 de septiembre de 2023
//  Numero mayor con condiciones anidadas
//  SD_ACT04_03

#include <stdio.h>

int main()
{
    float n1, n2, n3, n4, n5, n6, mayor;

    printf("Ingrese un numero: \n");
    scanf("%f", &n1);
    printf("Ingrese un numero: \n");
    scanf("%f", &n2);
    printf("Ingrese un numero: \n");
    scanf("%f", &n3);
    printf("Ingrese un numero: \n");
    scanf("%f", &n4);
    printf("Ingrese un numero: \n");
    scanf("%f", &n5);
    printf("Ingrese un numero: \n");
    scanf("%f", &n6);

    mayor = n1;

    if (n2 > mayor)
    {
        mayor = 2;
    }
    if (n3 > mayor)
    {
        mayor = n3;
    }
    if (n4 > mayor)
    {
        mayor = n4;
    }

    if (n5 > mayor)
    {
        mayor = n5;
    }

    if (n6 > mayor)
    {
        mayor = n6;
    }


printf("El numero mayor es: %.2f", mayor);

return 0;
}