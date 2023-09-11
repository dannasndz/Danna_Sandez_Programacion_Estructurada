#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

// PROTOTIPOS DE FUNCIONES
void menu(void);
void num_desc(void);
void par_impar(void);
void mayor_menor(void);
void tabla(void);

// FUNCION PRINCIPAL
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

// DESARROLLO DE FUNCIONES

void menu(void) // Funcion menu
{
    int op;
    printf("\n");
    printf("  Selecciona una opcion NUMERICA! \n");
    printf("\n");
    printf("1- Numeros enteros descendentes \n");
    printf("2- 40 numeros aleatorios \n");
    printf("3- Numero mayor y numero menor \n");
    printf("4- Tabla de multiplicar \n");
    printf("\n");
    printf("Ingrese la opcion numerica que desea: ");
    scanf("%d", &op);
    printf("\n");

    switch (op) // evaluar la opcion que eligio el usuario 
    {
    case 1: // usuario eligio numeros enteros descendetes
        num_desc();
        break;
    case 2: // usuario eligio 40 numeros aleatorios
        par_impar();
        break;
    case 3: // usuario eligio numero mayor y numero menor
        mayor_menor();
        break;
    case 4: // usuario eligio tabla de multiplicar
        tabla();
        break;
    default: // el usuario eligio una opcion incorrecta
        printf("La opcion que elegiste es incorrecta! Por favor seleccione una opcion que este dentro del menu. ");
        getch();
        printf("\n");
        menu();
        break;
    }
}

void num_desc(void)  // funcion que imprime los numeros descendientes de N 
{
    // variables locales
    int n, i;
    i=0;
    printf(" NUMEROS MENORES DE FORMA DESCENDENTE !\n");
    printf("Ingresa el numero que mas te guste: ");
    scanf("%d",&n);
    printf("\n");
    // desarrollo de funcion
    if (n>0) // mientras N sea mayor a 0 se cumple 
    {
        printf("Los numeros descendientes de %d son: \n", n);
        while (i<n)
        {
            i++;
            printf("%d \n", n-i);

        }
    }
    else
    {
        printf("El numero que ingresaste no tiene enteros positivos menores! ");
        getch();
        printf("\n");
        num_desc(); // envia al usuario a la funcion de nuevo para que ingrese una opcion correcta
    }
    getch();
    printf("\n");
    menu(); // envia al menu al usuario
}

void par_impar(void) // funcion que genera 40 numeros aleatorios e imprime si son par, impar, cuantos parese impares hay y la suma de ellos
{
    // variables locales
    int num,p,ip,sp, sip;
    sp=0;
    sip=0;
    p=0;
    ip=0;

    printf("Generador de 40 numeros aleatorios!! \n");
    // desarrollo de funcion
    for (int i = 0; i < 40; i++)
    {
        num= rand()% 201; // generar numeros aleatorios entre 0 y 200
        printf ("%d -- ", num);
        if (num%2==0) // condicion para saber si es par
        {
            printf("Es par \n");
            sp=sp+num; // acumulador de numeros pares
            p++; // contador de numeros impares
        }
        else
        {
            printf("Es impar \n");
            sip=sip+num; // acumulador de numeros impares
            ip++; // contador de numero impares
        }
    }
    printf("\n");
    printf("La cantidad de numeros pares es: %d \n",p);
    printf("La suma de los numeros pares es: %d \n", sp);
    printf("La cantidad de numeros impares es: %d \n",ip);
    printf("La suma de los numeros impares es: %d \n", sip);
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void mayor_menor(void) // funcion que genera 35 numeros aleatorios entre 100 y 200 e imprime el mayor y menor 
{
    // variables y constantes locales
    #define N 35
    int i,num;
    int menor=201;
    int mayor=99;
    i=0; // contador 
    // desarrollo de funcion 
    while (i<N)
    {
        num= rand()% 101 + 100; // generador de numeros aleatorios entre 100 y 200
        if (num>mayor)
        {
            mayor=num;
        }
        else
        {
            menor=num;
        }
        i++;
    }
    printf("El numero mayor es: %d \n", mayor);
    printf("El numero menor es: %d \n",menor);
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void tabla(void) // funcion que genera tablas de multiplicar 
{
    // variable local
    int num;

    printf("        Generador Tabla de Multiplicar! \n");
    printf("Elige un numero dentro del 1 y el 20 para generar la tabla: ");
    scanf("%d",&num);
    printf("\n");

    // desarrollo de funcion

    if (num>=1 && num<=20) // si el numero que ingreso el usuario cumple la condicion entra a hacer la tabla
    {
        printf("Tabla del %d \n",num);
        for (int i = 1; i < 11; i++)
        {
            printf(" %d x %d = %d\n", i,num, (i*num));
        }
    }
    else // si no 
    {
        printf("El numero que escogiste no entra dentro de 1 y 20! Por favor intentalo de nuevo con un numero correcto \n");
        getch();
        printf("\n");
        tabla(); // envia al usuario a la funcion tabla para que pueda ingresar un numero correcto
    }
    getch();
    printf("\n");
    menu();  // envia al usuario a la funcion menu
}