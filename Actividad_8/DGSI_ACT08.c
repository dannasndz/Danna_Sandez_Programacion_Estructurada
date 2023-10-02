/*
    Danna Sandez Islas 373080
    1 de Octubre de 2023
    Actividad 08
    SD_ACT07
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*** PROTOTIPO DE FUNCIONES ***/
void menu(void);
int validar(char mensj[], int ri, int rf);
void llenar(int vector1[]);
int repetido(int num, int i, int vector2[]);
void llenar2(int vector2[]);
void llenar3(int vector3[], int vect2[], int vect1[]);
void imprimir(int vect1[], int vect2[], int vect3[]);
void matriz4x4(int matriz[][4], int vect1[], int vect2[]);
void imprimirMatriz(int matriz[][4]);

/*** Funcion main ***/
int main()
{

    menu();

    return 0;
}

/*** DESAROLLO DE FUNCIONES ***/

/* Funcion menu donde se desarrolla el programa */
void menu(void)
{
    srand(time(NULL));
    int vector1[10];
    int vector2[10];
    int vector3[20];
    int matriz[4][4];
    int op;
    do
    {
        system("CLS");
        printf("  ---- MENU----\n\n");
        printf("1- Llenar VECTOR 1 (manualmente)\n");
        printf("2- Llenar VECTOR 2 (aleatoriamente)\n");
        printf("3- Llenar VECTOR 3 (con VECTOR 1 y VECTOR 2)\n");
        printf("4- Imprimir vectores\n");
        printf("5- Llenar matriz 4x4\n");
        printf("6- Imprimir matriz\n");
        printf("0- SALIR\n");
        printf("Ingresa una opcion numerica: ");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1: // llenar vector 1 manualmente
            llenar(vector1);
            system("PAUSE");
            break;
        case 2: // llenar vector 2 aleatoriamente
            llenar2(vector2);
            system("PAUSE");
            break;
        case 3: // llenar vector 3, con vector 1 y vector 2
            llenar3(vector3, vector2, vector1);
            system("PAUSE");
            break;
        case 4: // imprimir vectores
            imprimir(vector1, vector2, vector3);
            system("PAUSE");
            break;
        case 5: // llenar matriz 4x4
            matriz4x4(matriz, vector1, vector2);
            system("PAUSE");
            break;
        case 6: // imprimir matriz
            imprimirMatriz(matriz);
            system("PAUSE");
            break;
        default:
            if (op != 0)
            {
                printf("Por favor ingresa una opcion correcta.\n");
                system("PAUSE");
            }
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
}

/* Funcion para validar argumentos dados por el usuario  */
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

/* Funcion para llenar un vector con datos dados por el usuario */
void llenar(int vector1[])
{
    // variables locales
    int num;
    int i;
    /* desarrollo de la funcion */
    for (i = 0; i < 10; i++)
    {
        printf("   Posicion [%d] del vector\n", i);
        num = validar("Ingresa un numero entre 30 y 70 por favor: ", 30, 70);
        vector1[i] = num;
        system("CLS");
    }
}

/* Funcion que verifica si el numero aleatorio dado ya se encuentra dentro del vector*/
int repetido(int num, int i, int vector2[])
{
    for (int j = 0; j < i; j++)
    {
        if (num == vector2[j])
        {
            return 1; // si el numero ya esta dentro del vector, retorna 1
        }
    }
    return 0; // si el numero no se encuentra dentro del vector, retorna 0
}

/* Funcion para llenar un vector de manera aleatoria sin numeros repetidos */
void llenar2(int vector2[])
{
    // variables locales
    int num;
    int i;
    /* Desarrollo de funcion */
    for (i = 0; i < 10; i++)
    {
        do
        {
            num = rand() % 20 + 1;
        } while (repetido(num, i, vector2));
        vector2[i] = num;
    }
    printf("El vector se lleno con numeros aleatorios entre 1-20 exitosamente\n");
}

/* Funcion para llenar un vector con otros dos vectores */
void llenar3(int vector3[], int vect2[], int vect1[])
{
    for (int i = 0; i < 20; i++)
    {
        if (i < 10) // Se llenan las primeras 10 posiciones con el vector 1
        {
            vector3[i] = vect1[i];
        }
        else // se llenan las ultimas 10 posiciones con el vector 2
        {
            vector3[i] = vect2[i - 10];
        }
    }
    printf("Vector de 20 espacios completo exitosamente!\n");
}

/* Funcion para imprimir los vectores */
void imprimir(int vect1[], int vect2[], int vect3[])
{
    int i;
    printf("--Vector 1--\n");
    for (i = 0; i < 10; i++)
    {
        printf("Vector[%d] --> %d\n", i, vect1[i]);
    }
    system("PAUSE");
    system("CLS");
    printf("--Vector 2--\n");
    for (i = 0; i < 10; i++)
    {
        printf("Vector[%d] --> %d\n", i, vect2[i]);
    }
    system("PAUSE");
    system("CLS");
    printf("--Vector 3--\n");
    for (i = 0; i < 20; i++)
    {
        printf("Vector[%d] --> %d\n", i, vect3[i]);
    }
}

/* Funcion para llenar una matriz con 2 vectores */
void matriz4x4(int matriz[][4], int vect1[], int vect2[])
{
    // Variables locales
    int i, j, k = 0;
    /* Desarrollo de funcion */
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (k < 10) // Se llenan los primeros 10 espacios con el vector 1
            {
                matriz[i][j] = vect1[k];
            }
            else // Se llenan los ultimos 6 espacios con el vector 2
            {
                matriz[i][j] = vect2[k - 6];
            }
            k++;
        }
    }
    printf("La matriz 4x4 se lleno exitosamene!\n");
}

/* Funcion para imprimir la matriz */
void imprimirMatriz(int matriz[][4])
{
    printf("~~~ Matriz 4x4 ~~~\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}