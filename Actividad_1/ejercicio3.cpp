// Danna Sandez Islas 373080
// 22/08/23
// aprobado o reprobado
// SD_ACT01_03
#include <stdio.h>
int main (){
    float cal1,cal2,cal3,cal4,prom;
    printf("Ingrese su calificacion: \n");
    scanf("%f",&cal1);
    printf("Ingrese su calificacion: \n");
    scanf("%f",&cal2);
    printf("Ingrese su calificacion: \n");
    scanf("%f",&cal3);
    printf("Ingrese su calificacion: \n");
    scanf("%f",&cal4);
    prom=(cal1+cal2+cal3+cal4)/4;
    if (prom>=60){
        printf("Su promedio es %.2f APROBADO \n",prom);
    } else (prom<60);
    printf("Su promedio es= %.2f REPROBADO", prom);
    return 0;
}