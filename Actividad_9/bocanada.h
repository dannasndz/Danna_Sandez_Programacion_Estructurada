
/* ---- Prototipo de funciones ---- */
#define M 4
// validar
int validar(char mensj[], int ri, int rf);
//vectores
void llenarVect(int vector[], int n, int ri, int rf);
int repetidoVect(int num, int i, int vector[]);
void printVect(int vector[], int n);
//matriz
void llenarMatriz4x4(int matriz[][M], int n, int m, int vect[]);
void printMatriz(int matriz[][M], int n, int m);
// ordenar, buscar
void ordenar(int vector[], int n);
int busq_seq(int vector[], int n, int ri, int rf);

/* ---------------------------------------- */

/* ----- Librerias ----- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* -------------------- */

/* ---- Desarrollo de funciones ---- */

// Funcion para validar numeros dados por el usuario
int validar(char mensj[], int ri, int rf)
{
    // variables locales
    int num;
    char cadena[100];
    // desarrollo de funcion
    do
    { 
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena); // cambia a numeros la cadena

    } while (num < ri || num > rf);

    return num; // retorna el valor que haya tomado num, entre los rangos dados por el usuario
}

// Funcion para llenar un vector con datos random 
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
        } while (repetidoVect(num, i, vector) != 0);
        vector[i] = num;
    }
}

// Funcion que verifica si el numero aleatorio dado ya se encuentra dentro del vector
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

void printVect(int vector[], int n)
{
    int i;
    printf("--Vector --\n");
    for (i = 0; i < n; i++)
    {
        printf("Posicion[%d] --> %d\n", i + 1, vector[i]);
    }
}

void llenarMatriz4x4(int matriz[][M], int n, int m, int vect[])
{
    // Variables locales
    int i, j, k = 0;
    /* Desarrollo de funcion */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz[i][j] = vect[k];
            k++;
        }
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

void ordenar(int vector[], int n)
{
    int i, j;
    int temporal;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[i])
            {
                temporal = vector[i];
                vector[i] = vector[j];
                vector[j] = temporal;
            }
        }
    }
}

int busq_seq(int vector[], int n, int ri, int rf)
{
    int num;
    num=validar("Que valor te gustaria buscar entre 100-200?: ",ri,rf);
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}
