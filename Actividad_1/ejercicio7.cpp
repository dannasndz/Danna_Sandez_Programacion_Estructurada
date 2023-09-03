// Danna Sandez Islas 373080
// 26/08/23
// numero menor
// SD_ACT01_07

#include <stdio.h>

int main (){

    float num1, num2, num3;

    printf("Ingrese el primer numero: \n");
    scanf("%f",&num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%f",&num2);
    printf("Ingrese el tercer numero: \n");
    scanf("%f",&num3);

    if (num1 < num2) {
        if (num1 < num3) {
            printf("El número menor es %.2f\n", num1);
        } else {
            printf("El número menor es %.2f\n", num3);
        }
    } else {
        if (num2 < num3) {
            printf("El número menor es %.2f\n", num2);
        } else {
            printf("El número menor es %.2f\n", num3);
        }
    }

    return 0;
}