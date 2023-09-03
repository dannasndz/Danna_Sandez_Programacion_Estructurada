//Danna Sandez Islas 373080
// 22 de agosto de 2023
//Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
// SD_ACT01_01

#include <stdio.h>

int main (){
float suma=0, prom,cal;

for (int i=0; i<4;i++){
    printf("Ingrese su calificacion: \n");
    scanf("%f", &cal);
    suma=suma+cal;
}
prom=suma/4;
if (prom>=60){
    printf("Su pomedio es= %.2f, APROBADO",prom);
}
else (prom<60);
    printf("Su promedio es= %.2f, REPROBADO", prom);

return 0;
}