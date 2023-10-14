
/* ----- Librerias ----- */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/* -------------------- */

/* ---- Prototipo de funciones ---- */
#define M 4
// validar
int validar(char mensj[], int ri, int rf);
// vectores
void llenarVect(int vector[], int n, int ri, int rf);
int repetidoVect(int num, int i, int vector[]);
void printVect(int vector[], int n);
// matriz
void llenarMatriz4x4(int matriz[][M], int n, int m, int vect[]);
int repetidoMat(int num, int n, int m, int matriz[][M]);
void printMatriz(int n, int m, int matriz[][M]);
// ordenar, buscar
void ordenar(int vector[], int n);
int busq_seq(int vector[], int n, int ri, int rf);
// alfabetico
void mayus(char cadena[]);
void min(char cadena[]);
// num aleatorio
int numAleatorio(int ri, int rf);

/* ---------------------------------------- */

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
        printf("Posicion[%d] --> %d\n", i , vector[i]);
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

int repetidoMat(int num, int n, int m, int matriz[][M])
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            if (num == matriz[j][k])
            {
                return 1; // si el numero ya esta dentro del vector, retorna 1
            }
        }
    }
    return 0; // si el numero no se encuentra dentro del vector, retorna 0
}

void printMatriz(int n, int m, int matriz[][M])
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
    num = validar("Que valor te gustaria buscar entre 100-200?: ", ri, rf);
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

// alfabetico

void mayus(char cadena[]) // mayusculas
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 97)
        {
            if (cadena[i] <= 122)
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    printf("%s", cadena);
}

void min(char cadena[]) // minusculas
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
    }
    printf("%s", cadena);
}

int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}