//  Danna Sandez Islas 373080
//  19 de septiembre de 2023
//  Actividad 07
//  SD_ACT07

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// prototipo de funciones

/***** PARTE 1 *****/
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

/***** PARTE 2 *****/
void mayus(char cadena[]);
void min(char cadena[]);
void capital(char cadena[]);
void caracter(char cadena[]);
void inversa(char cadena[]);
void sinEspacio(char cadena[]);
void alfabetico(char cadena[]);
void completa(char cadena[]);
void palindromo(char cadena[]);
int validar(char palabra[]);

// Funcion principal
int main()
{
    // variables locales
    int op;
    char cadena[100];

    printf("A que parte de la practica deseas ingresar? \n");
    printf("1- Parte 1\n");
    printf("2- Parte 2\n");
    printf("3- Salir\n");
    printf("Ingresa una opcion numerica: ");
    scanf("%d", &op);
    system("CLS");

    if (op == 1 || op == 2) // leer cadena
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
    parte2:
    case 2: // parte 2
        printf("BIENVENIDO A LA PARTE 2 DE LA PRACTICA!\n\n");
        printf("  Que funcion desea utilizar?\n");
        printf("1- Cadena a MAYUSCULAS\n");
        printf("2- Cadena a MINUSCULAS\n");
        printf("3- Cadena a CAPITAL\n");
        printf("4- Cadena y cantidad de caracteres\n");
        printf("5- Cadena al reves\n");
        printf("6- Nueva cadena sin espacios\n");
        printf("7- Cadena perfecta\n");
        printf("8- Cadena con todas las anteriores\n");
        printf("9- Cadena palindromo\n");
        printf("0- SALIR\n\n");
        printf("Ingrese una opcion NUMERICA: ");
        scanf("%d", &op);
        system("CLS");
        switch (op)
        {
        case 1:
            mayus(cadena);
            break;
        case 2:
            min(cadena);
            break;
        case 3:
            capital(cadena);
            break;
        case 4:
            caracter(cadena);
            break;
        case 5:
            inversa(cadena);
            break;
        case 6:
            sinEspacio(cadena);
            break;
        case 7:
            alfabetico(cadena); 
            break;
        case 8:
            completa(cadena);
            break;
        case 9:
            palindromo(cadena);
            break;
        case 0:
            printf("Gracias por usar el programa hasta luego!");
            break;
        default:
            printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
            system("PAUSE");
            system("CLS");
            goto parte2;
            break;
        }
        break;
    case 3: // salir
        printf("Gracias por usar el programa hasta luego!");
        break;
    default:
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        system("PAUSE");
        system("CLS");
        main(); // envia al usuario a la funcion main
        break;
    }
}

// DESARROLLO DE FUNCIONES

/***** PARTE 1 *****/

void salida1(char cadena[]) // mayusculas
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

void salida2(char cadena[]) // inverso
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

void salida3(char cadena[]) // vertical
{
    int caracter = 0;

    while (cadena[caracter] != '\0')
    {
        printf("%c\n", cadena[caracter]);
        caracter++;
    }
}

void salida4(char cadena[]) // vertical inverso
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

void salida5(char cadena[]) // eliminar letra final
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

void salida6(char cadena[]) // eliminar letra final inverso
{
    int caracter = 0;
    char aux;
    while (cadena[caracter] != '\0')
    {
        caracter++;
    }
    for (int i = 0; i < caracter / 2; i++) // voltear cadena
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

void salida7(char cadena[]) // eliminar letra inicial
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

void salida8(char cadena[]) // eliminar letra inicial inversa
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

void salida9(char cadena[]) // mostrar solo consonantes
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

void salida10(char cadena[]) // mostrar solo vocales
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

void capital(char cadena[]) // convertir a Capital
{
    int i;
    // primera letra mayuscula
    if (cadena[0] >= 'a')
    {
        if (cadena[0] <= 'z')
        {
            cadena[0] = cadena[0] - 32;
        }
    }
    for (i = 1; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == ' ')
        {
            i++;
            if (cadena[i] >= 'a')
            {
                if (cadena[i] <= 'z')
                {
                    cadena[i] = cadena[i] - 32;
                }
            }
        }
    }
    printf("%s", cadena);
}

void caracter(char cadena[]) // cantidad de caracteres
{
    int caract = 0;
    while (cadena[caract] != '\0')
    {
        caract++;
    }
    printf("La cadena: %s, tiene %d caracteres", cadena, caract);
}

void inversa(char cadena[]) // cadena inversa
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

void sinEspacio(char cadena[]) // convertir cadena sin espacios 
{
    char SE[100];
    int i, j;
    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            SE[j] = cadena[i];
            printf("%c", SE[j]);
            j++;
        }
    }
}

void alfabetico(char cadena[]) // solo cadena alfabetica y espacio sencillo
{
    char res[100];
    int j=0;
    if (cadena[0] == ' ')
    {
        printf("ERROR");
        return; // no cumple
    }
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' '))
        {
            res[j]=cadena[i];
            printf("%c", res[i]);
            j++;
        }
        else
        {
            printf("ERROR");
            return;
        }
    }
}

void completa(char cadena[]) // imprimir cadena con todo lo anterior
{
    mayus(cadena);
    printf("\n");
    min(cadena);
    printf("\n");
    capital(cadena);
    printf("\n");
    sinEspacio(cadena);
    printf("\n");
    inversa(cadena);
}

void palindromo(char cadena[]) // mostrar si la cadena es palindromo o no
{
    int res;
    res = validar(cadena);
    if (res == 0)
    {
        printf("Cadena valida\n");
        system("PAUSE");
    }
    else
    {
        printf("Cadena no valida. No puedes ingresar numeros, doble espacio ni minisuculas.\n");
        system("PAUSE");
        return;
    }
    system("CLS");

    int largo = 0;
    while (cadena[largo] != '\0')
    {
        largo++;
    }

    int i = 0;
    int j = largo - 1;
    while (i < j)
    {
        if (cadena[i] != cadena[j])
        {
            printf("No es palindromo"); // No es un palíndromo
            return;
        }
        i++;
        j--;
    }
    printf("Si es palindromo");
}

int validar(char palabra[]) // funcion auxiliar para validar la funcion palindromo
{
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (palabra[i] >= '0' && palabra[i] <= '9')
        {
            return 1;
            break;
        }
        if (palabra[i] >= 'a' && palabra[i] <= 'z')
        {
            return 2;
            break;
        }
        if (palabra[i] == ' ' && palabra[i + 1] == ' ')
        {
            return 3;
            break;
        }
    }
    return 0;
}
