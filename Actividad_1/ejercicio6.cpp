// Danna Sandez Islas 373080
// 26/08/23
// calificacion anidado por el falso
// SD_ACT01_06

#include <stdio.h>

int main() {

    float cal1, cal2, cal3;
    float prom;

    printf("Ingrese la calificación 1: ");
    scanf("%f", &cal1);
    printf("Ingrese la calificación 2: ");
    scanf("%f", &cal2);
    printf("Ingrese la calificación 3: ");
    scanf("%f", &cal3);

    prom = (cal1+cal2+cal3)/3;

    if (prom < 30) {
        printf("Repetir\n");
    } else {
        if (prom < 60) {
            printf("Extraordinario\n");
        } else {
            if (prom < 70) {
                printf("Suficiente\n");
            } else {
                if (prom < 80) {
                    printf("Regular\n");
                } else {
                    if (prom < 90) {
                        printf("Bien\n");
                    } else {
                        if (prom < 98) {
                            printf("Muy bien\n");
                        } else {
                            if (prom <= 100) {
                                printf("Excelente\n");
                            } else {
                                printf("Error en promedio\n");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
