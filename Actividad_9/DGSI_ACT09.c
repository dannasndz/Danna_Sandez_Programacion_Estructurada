/*
    Danna Sandez Islas 373080
    03 de Octubre de 2023
    Actividad 09
    SD_ACT09
*/

#include "bocanada.h"
#define N 4
#define M 4

void menu(void);
void llenarVect(int vector[], int n, int ri, int rf);
int repetidoVect(int num, int i, int vector[]);
void llenarMatriz4x4(int matriz[][M], int n, int m, int vect[]);
void printVect(int vector[], int n);
void printMatriz(int n, int m, int matriz[][m]);
void ordenar(int vector[], int n);
int busq_seq(int vector[], int n,int ri, int rf);

int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

void menu(void)
{
    int vector[15];
    int vect[N * M];
    int matriz[N][M];
    int op,num;
    do
    {
        system("CLS");
        printf("---- MENU ----\n");
        printf("1- Llenar vector\n");
        printf("2- Llenar matriz\n");
        printf("3- Imprimir vector\n");
        printf("4- Imprimir matriz\n");
        printf("5- Ordenar vector\n");
        printf("6- Buscar valor en el vector\n");
        printf("0- SALIR\n");
        op = validar("Ingresa una opcion NUMERICA: ", 0, 6);
        system("CLS");

        switch (op)
        {
        case 1:
            llenarVect(vector, 15, 100, 200);
            printf("El vector se lleno exitosamente!\n");
            break;
        case 2:
            llenarVect(vect, (N * M), 1, 16);
            llenarMatriz4x4(matriz, N, M, vect);
            printf("La matriz se lleno exitosamente!\n");
            break;
        case 3:
            printVect(vector, 15);
            break;
        case 4:
            printMatriz(N,M,matriz);
            break;
        case 5:
            ordenar(vector, 15);
            printf("Vector ordenado exitosamente!\n");
            break;
        case 6:
            num= busq_seq(vector, 15,100,200);
            if (num == -1)
            {
                printf("El numero no se encuentra dentro del vector\n");
            }
            else 
            {
                printf("Numero en la posicion %d\n",num);
            }
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
}