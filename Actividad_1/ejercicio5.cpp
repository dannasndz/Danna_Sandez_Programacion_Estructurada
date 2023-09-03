// Danna Sandez Islas 373080
// 22/08/23
// calificaciones anidado por el verdadero
// SD_ACT01_05

#include <stdio.h>

int main (){

    float prom;
    int cal1, cal2, cal3;

    printf("Ingrese su 1er calificacion: \n");
    scanf("%d",&cal1);
    printf("Ingrese su 2da calificacion: \n");
    scanf("%d",&cal2);
    printf("Ingrese su 3er calificacion: \n");
    scanf("%d",&cal3);

    prom=(cal1+cal2+cal3)/3;
    printf("Tu promedio es= %.2f \n",prom);

    if (prom<30){
        printf("Repetir \n");
    } else if (prom >=30 && prom <60){
        printf("Extraordinario \n");
    }else if(prom >=60 && prom <70){
        printf("Suficiente \n");
    }else if (prom >=70 && prom <80){
        printf("Regular \n");
    }else if (prom >=80 && prom <90){
        printf("Bien \n");
    }else if (prom >=90 && prom <98){
        printf("Muy bien\n");
    }else if(prom >=98 && prom <=100){
        printf("Excelente \n");
    }else{
        printf("Error en promedio \n");
    }

    return 0;
}