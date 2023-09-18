#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// PRTOTIPO DE FUNCIONES
void menu(void);
void fibWhile(void);
void fibFor(void);
void fibDoWhile(void);
void factFor(void);
void factWhile(void);
void factDoWhile(void);

// FUNCION PRINCIPAL
int main()
{
    menu();

    return 0;
}

// DESARROLLO DE FUNCIONES

void menu(void)
{
    int op;
    printf(" Seleccione una opcion NUMERICA \n");
    printf(" 1- Fibonacci \n");
    printf(" 2- Factorial \n");
    printf(" 3- Cantidad de digitos \n");
    printf(" Ingrese la opcion NUMERICA que desea: \n");
    scanf("%d", &op);

    system("CLS");

    switch (op)
    {
        int op;
    case 1:
        printf("Que fibonacci desea utiliza? \n");
        printf("1- Fibonacci Ciclo FOR \n");
        printf("2- Fibonacci Ciclo WHILE \n");
        printf("3- Fibonacci ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fibFor();
            break;
        case 2:
            fibWhile();
            break;
        case 3:
            fibDoWhile();
            break;
        default:
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS");
            main();
            break;
        }
        break;
    case 2:
        printf("Que Factorial desea utiliza? \n");
        printf("1- Factorial Ciclo FOR \n");
        printf("2- Factorial Ciclo WHILE \n");
        printf("3- Factorial ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            factFor();
            break;
        case 2:
            factWhile();
            break;
        case 3:
            factDoWhile();
            break;

        default:
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS");
            main();
            break;
        }
        break;
    case 3:
        break;

    default:
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        getch();
        system("CLS");
        menu();
        break;
    }
}

void fibFor(void)
{
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        res = a + s;
        printf("%d", res);
        a = s;
        s = res;
    }
}

void fibWhile(void) // funcion fibonacci
{
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        res = a + s;
        printf("%d", res);
        a = s;
        s = res;
        i++;
    }
}

void fibDoWhile(void)
{
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);
    int i = 0;
    do
    {
        i++;
        res = a + s;
        printf("%d", res);
        a = s;
        s = res;
    } while (i < n);
}

void factFor(void)
{
    int num, a, s;
    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    a = num * (num - 1);
    for (int i = 2; i < num; i++)
    {
        s = a * (num - i);
        a = s;
    }
    printf("%d", a);
}

void factWhile(void)
{
    int num, i, a, s;
    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    i = 2;
    a = num * (num - 1);
    while (i < num)
    {
        s = a * (num - i);
        a = s;

        i++;
    }

    printf("%d", a);
}

void factDoWhile(void)
{
    int num, i, a, s;

    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    i = 2;
    a = num * (num - 1);
    do
    {
        s = a * (num - i);
        a = s;
        i++;
    } while (i < num);

    printf("%d", a);
}