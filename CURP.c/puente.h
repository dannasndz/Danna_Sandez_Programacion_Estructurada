#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipo de funciones*/

int validar(char mensj[], int ri, int rf);
int alfabetico(char cadena[]);
void mayus(char cadena[]);

/*Desarrollo de funciones*/

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

/*
    Funcion para validar una cadena unicamente alfabetica, y con espacios sencillos.
    Parametros: cadena a validar.
    Valor de retonor: -1 si es incorrecta, 1 si es correcta
*/

int alfabetico(char cadena[])
{
    int i = 0;

    if (cadena[0] == ' ' || cadena[0] == '\0')
    {
        printf("ERROR\n");
        return -1;
    }

    while (cadena[i] != '\0')
    {
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' ')))
        {
            printf("ERROR\n");
            return -1;
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        printf("ERROR\n");
        return -1;
    }

    return 1;
}

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
}

