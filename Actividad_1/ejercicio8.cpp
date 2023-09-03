// Danna Sandez Islas 373080
// 26/08/23
// numero de en medio
// SD_ACT01_08

#include <stdio.h>

int main (){

    float num1, num2, num3;

    printf("Ingrese el primer numero: \n");
    scanf("%f",&num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%f",&num2);
    printf("Ingrese el tercer numero: \n");
    scanf("%f",&num3);

    if(num1>num2 && num2>num3){
        printf("El numero %.f es el de en medio", num2);
    }else if(num2>num1 && num1>num3){
        printf("El numero %.2f es el de en medio", num1);
    }else{
        printf("El numero %.2f es el de en medio", num3);
    }

    return 0;
}