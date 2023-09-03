//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// Horas trabajadas
// SD_ACT04_04

#include <stdio.h>

#define jn 40

int main()
{

    int horas, horasExtra;
    float salarioNorm, salarioExtra, salarioxhora, salarioTotal, pagoD, pagoT;

    printf("Ingrese las horas trabajadas: \n");
    scanf("%d", &horas);
    printf("Ingrese su salario por hora: \n");
    scanf("%f", &salarioxhora);

    if (horas <= jn)
    {
        salarioNorm = salarioxhora * horas;
        salarioExtra = 0;
        salarioTotal = salarioNorm;
    }
    else
    {
        salarioNorm = salarioxhora * jn;
        horasExtra = horas - jn;

        if (horasExtra <= 9)
        {
            pagoD = (horasExtra * (salarioxhora * 2));
        }
        else
        {
            if (horasExtra >= 10)
            {
                pagoT = (horasExtra * (salarioxhora * 3));
            }
        }
        salarioExtra = pagoD + pagoT;
        salarioTotal = salarioNorm + salarioExtra;
    }
    printf("Salario por hora: %.2f \n", salarioxhora);
    printf("Horas trabajadas: %.2d \n", horas);
    printf("Salario normal: %.2f \n", salarioNorm);
    printf("Salario extra: %.2f \n", salarioExtra);
    printf("Salario total: %.2f \n", salarioTotal);

    return 0;
}