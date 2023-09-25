//  Danna Sandez Islas 373080
//  19 de septiembre de 2023
//  Actividad 07
//  SD_ACT07

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// prototipo de funciones

char validar(char mensj[], int ri, int rf);
void salida1(char cadena[]);
void salida2(char cadena[]);
void salida3(char cadena[]);
void salida4(char cadena[]);
void salida5(char cadena[]);
void salida6(char cadena[]);
void salida7(char cadena[]);
void salida8(char cadena[]);
void salida9(char cadena[]);
void salida10(char cadena[]);
/* PARTE 2 */

// Funcion principal
int main()
{
    int op;
    char cadena[100];
    printf("A que parte de la practica deseas ingresar? \n");
    printf("1- Parte 1\n");
    printf("2- Parte 2\n");
    printf("3- Salir\n");
    printf("Ingresa una opcion numerica: ");
    scanf("%d", &op);
    system("CLS");

    if (op == 1)
    {
        printf("Ingrese una palabra: ");
        fflush(stdin);
        gets(cadena);
        system("PAUSE");
        system("CLS");
    }

    switch (op)
    {
        parte1:
    case 1: // Parte 1
        printf("BIENVENIDO A LA PARTE 1 DE LA PRACTICA!\n\n");
        printf("  Que funcion desea utilizar?\n");
        printf("1- Salida 1: MAYUSCULAS\n");
        printf("2- Salida 2: Al reves\n");
        printf("3- Salida 3: Vertical normal\n");
        printf("4- Salida 4: Vertical al reves\n");
        printf("5- Salida 5: Eliminar letra a letra\n");
        printf("6- Salida 6: Eliminar letra a letra al reves\n");
        printf("7- Salida 7: Eliminar letra a letra incial\n");
        printf("8- Salida 8: Eliminar letra a letra incial al reves\n");
        printf("9- Salida 9: Mostrar consonantes\n");
        printf("10- Salida 10: Monstrar vocales\n");
        printf("0- SALIR\n\n");
        printf("Ingrese una opcion NUMERICA: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            salida1(cadena);
            break;
        case 2:
            salida2(cadena);
            break;
        case 3:
            salida3(cadena);
            break;
        case 4:
            salida4(cadena);
            break;
        case 5:
            salida5(cadena);
            break;
        case 6:
            salida6(cadena);
            break;
        case 7:
            salida7(cadena);
            break;
        case 8:
            salida8(cadena);
            break;
        case 9:
            salida9(cadena);
            break;
        case 10:
            salida10(cadena);
            break;
        case 0:
            printf("Gracias por usar el programa hasta luego!");
            break;
        default:
            printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
            getch();
            system("CLS");
            goto parte1;
            break;
        }
        break;
    case 2:
        // parte 2
        break;
    case 3:
        // salir
        break;
    default:
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        getch();
        system("CLS");
        main(); // envia al usuario a la funcion main
        break;
    }
}

// DESARROLLO DE FUNCIONES

/***** PARTE 1 *****/

void salida1(char cadena[])
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

void salida2(char cadena[])
{
    int caracter = 0;
    char aux;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    int i;
    for (i = 0; i < caracter / 2; i++)
    {
        aux = cadena[i];
        cadena[i] = cadena[caracter - 1 - i];
        cadena[caracter - 1 - i] = aux;
    }
    printf("%s", cadena);
}

void salida3(char cadena[])
{
    int caracter = 0;

    while (cadena[caracter] != '\0')
    {
        printf("%c\n", cadena[caracter]);
        caracter++;
    }
}

void salida4(char cadena[])
{
    int caracter = 0;
    char aux;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter / 2; i++)
    {
        aux = cadena[i];
        cadena[i] = cadena[caracter - 1 - i];
        cadena[caracter - 1 - i] = aux;
    }
    int i = 0;
    while (cadena[i] != '\0')
    {
        printf("%c\n", cadena[i]);
        i++;
    }
}

void salida5(char cadena[])
{
    int caracter = 0;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter; i++)
    {
        for (int j = 0; j < caracter - i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void salida6(char cadena[])
{
    int caracter = 0;
    char aux;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter / 2; i++)
    {
        aux = cadena[i];
        cadena[i] = cadena[caracter - 1 - i];
        cadena[caracter - 1 - i] = aux;
    }

    for (int i = 0; i < caracter; i++)
    {
        for (int j = 0; j < caracter - i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void salida7(char cadena[])
{
    int caracter = 0;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter; i++)
    {
        for (int j = i; j < caracter; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void salida8(char cadena[])
{
    int caracter = 0;
    char aux;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter / 2; i++)
    {
        aux = cadena[i];
        cadena[i] = cadena[caracter - 1 - i];
        cadena[caracter - 1 - i] = aux;
    }

    for (int i = 0; i < caracter; i++)
    {
        for (int j = i; j < caracter; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void salida9(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];
        if (caracter >= 'a')
        {
            if (caracter <= 'z')
            {
                if (caracter != 'a')
                {
                    if (caracter != 'e')
                    {
                        if (caracter != 'i')
                        {
                            if (caracter != 'o')
                            {
                                if (caracter != 'u')
                                {
                                    printf("%c", cadena[i]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void salida10(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char caracter = cadena[i];
        if (caracter >= 'a')
        {
            if (caracter <= 'z')
            {
                if ((caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'))
                {
                    printf("%c", cadena[i]);
                }
            }
        }
    }
}

/****** PARTE 2 ******/