#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// PRTOTIPO DE FUNCIONES
void menu(void);
void fibWhile(void);
void fibFor(void);
void fibDoWhile(void);
void factFor(void);
void factWhile(void);
void factDoWhile(void);
void digFor(void);
void digWhile(void);
void digDoWhile(void);
// Parte 2
void menu2(void);
void tablas(void);
int validar(char mensj[],int ri,int rf);
void calif(void);
void numeros(void);

// FUNCION PRINCIPAL
int main()
{
    int op;
    printf("A que parte de la practica deseas ingresar? \n");
    printf("1- Parte 1\n");
    printf("2- Parte 2\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        menu();
        break;
    case 2:
        menu2();
        break;

    default:
        break;
    }

    return 0;
}

// DESARROLLO DE FUNCIONES

// PARTE 1

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
        printf("Que Contador de Digitos desea utiliza? \n");
        printf("1- Contador Ciclo FOR \n");
        printf("2- Contador Ciclo WHILE \n");
        printf("3- Contador ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            digFor();
            break;
        case 2:
            digWhile();
            break;
        case 3:
            digDoWhile();
            break;
        default:
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS");
            main();
            break;
        }
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

void digFor(void)
{
    int num, x = 1;
    int i;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);

    for (i = 0; num >= x; i++)
    {
        x = x * 10;
    }
    printf("La cantidad de digitos que tiene %d es: %d", num, i);
}

void digWhile(void)
{
    int num;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);

    int dig = 0, x = 1;

    while (num >= x)
    {
        x = x * 10;
        dig++;
    }
    printf("La cantidad de digitos que tiene %d es: %d", num, dig);
}

void digDoWhile(void)
{
    int num;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);

    int dig = 0, x = 1;
    do
    {
        dig++;
        x = x * 10;
    } while (num >= x);
    printf("La cantidad de digitos que tiene %d es: %d", num, dig);
}

// PARTE DOS, DESARROLLO

int validar( char mensj[], int ri, int rf)
{
    int num;
    char cadena[1000];
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num= atoi(cadena);

    } while (num<ri || num>rf);

    return num;
    
}

void calif(void)
{
    int cal;
    int sde=0;

    for (int i = 0; i < 40; i++)
    {
        printf("Hola alumno numero %d\n",i+1);
        int suma=0;
        for (int j = 0; j < 5; j++)
        {
            cal=validar( "Ingresa tu calificacion:", 0, 100); 
            suma+=cal;
        }
        int prom=(suma/2);
        if (prom<50)
        {
            sde++;
        }  
        system("CLS");     
    }
    printf("La cantidad de alumnos sin derecho a examen es: %d",sde);
    
}

void menu2 (void)
{
    numeros();
    //calif();
    //tablas();

}

void tablas (void)
{
    int num=1;

    while (num<11)
    {
        printf("Tabla del %d \n",num);
        for (int i = 1; i < 11; i++)
        {
            printf(" %d x %d = %d\n", num,i, (i*num));
        }
        getch();
        system ("CLS");
        num++;
    }
    
}

void numeros(void)
{
    int n,ri,rf;
    int num,media;
    int suma=0;
    printf("Cuantos numeros deseas ingresar? \n");
    scanf("%d",&n);
    printf("Cual es el rango menor que te gustaria usar?\n");
    scanf("%d",&ri);
    printf("Cual es el rango superior que te gustaria usar?\n");
    scanf("%d",&rf);
    system("CLS");

    for (int i = 0; i < n; i++)
    {
        num= validar("Ingresa un numero: ",ri,rf);
        suma+=num;
        getch();
        system("CLS");
    }
    media= suma/n;
    printf("La suma de los %d numeros es: %d\n",n,suma);
    printf("La media aritmetica de los %d numeros es: %d",n,media);
    
}



