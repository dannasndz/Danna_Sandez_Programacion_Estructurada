/*
    Danna Sandez Islas 373080
    03 de Octubre de 2023
    Actividad 09
    SD_ACT09
*/

#include <stdio.h>
#include <time.h>
#include "libreriaRamirez.h"
#define N 4  
#define M 4

void menu(void);
void llenarVect(int vector[], int n, int ri, int rf);
int repetidoVect(int num, int i, int vector[]);
// int repetidoMatriz(int num, int i, int j, int matriz[][4]);
void matriz4x4(int matriz[][M], int n,  int m, int vect[]);
void printVect(int vector[], int n);
void printMatriz(int matriz[][M], int n, int m);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

void menu(void)
{
    int vector[15];
    int vect[N*M];
    int matriz[N][M];
    //llenarVect(vector, 15, 100, 200);
    llenarVect(vect, (N * M), 1, 16);
    matriz4x4(matriz, N, M, vect);
    //printVect(vector, 15);
    printMatriz(matriz,N,M);
}

/* Funcion que verifica si el numero aleatorio dado ya se encuentra dentro del vector*/
int repetidoVect(int num, int i, int vector[])
{
    for (int j = 0; j < i; j++)
    {
        if (num == vector[j])
        {
            return 1; // si el numero ya esta dentro del vector, retorna 1
        }
    }
    return 0; // si el numero no se encuentra dentro del vector, retorna 0
}

/* Funcion para llenar un vector con datos dados por el usuario */
void llenarVect(int vector[], int n, int ri, int rf)
{
    // variables locales
    int num;
    int i;
    int rango = (rf - ri) + 1;
    /* desarrollo de la funcion */
    for (i = 0; i < n; i++)
    {
        do
        {
            num = rand() % rango + ri;
        } while (repetido(num, i, vector) != 0);
        vector[i] = num;
    }
    printf("Vector lleno exitosamente con numeros aleatorios entre 100-200");
}

/*
int repetidoMatriz(int num, int i, int j, int matriz[][4])
{
    int k, l;
    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            if (num == matriz[k][l])
            {
                return 1; // si el numero ya esta dentro, retorna 1
            }
        }
    }
    return 0; // si el numero no se encuentra dentro, retorna 0
}
*/

void matriz4x4(int matriz[][M], int n, int m, int vect[])
{
    // Variables locales
    int i, j, k=0;
    /* Desarrollo de funcion */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz[i][j] = vect[k];
            k++;
        }
    }
    printf("La matriz 4x4 se lleno exitosamene!\n");
}

void printVect(int vector[], int n)
{
    int i;
    printf("--Vector --\n");
    for (i = 0; i < n; i++)
    {
        printf("Posicion[%d] --> %d\n", i+1, vector[i]);
    }
}

void printMatriz(int matriz[][M], int n, int m)
{
    printf("~~~ Matriz ~~~\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}