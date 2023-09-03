// Danna Sandez Islas 373080
// 26/08/23
// numeros en ascendente
// SD_ACT01_09

#include <stdio.h>

int main()
{

    float num1, num2, num3;

    printf("Ingrese el primer numero: \n");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%f", &nnm2);
    printf("Ingrese el tercer numero: \n");
    scanf("%f", &num3);

    printf("NUMEROS EN ASCENDETE \n");

    if (num1 < num2 && num2 < num3)
    {
        printf("%.2f, %.2f, %.2f", num1, num2, num3);
    }
    else if (num2 < num1 && num1 < num3)
    {
        printf("%.2f, %.2f, %.2f", num2, num1, num3);
    }
    else if (num3 < num2 && num2 < num1)
    {
        printf("%.2f, %.2f, %.2f", num3, num2, num1);
    }

    return 0;
}