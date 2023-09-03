// Danna Sandez Islas 373080
// 22/08/23
// mujer u hombre
// SD_ACT01_04
#include <stdio.h>

int main (){
    int respuesta;
    printf("INGRESE EL NUMERO CORRESPONIENTE SEGUN SU SEXO \n");
    printf("1.- MUJER \n");
    printf("2.- HOMBRE \n");
    scanf("%d",&respuesta);
    if (respuesta==1){
        printf("HOLA, ERES MUJER \n");
    } else 
    printf("HOLA, ERES HOMBRE \n");
    
    return 0;
}