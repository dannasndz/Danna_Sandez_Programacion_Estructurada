#include <stdio.h>

// PRTOTIPO DE FUNCIONES
void menu(void);
void fibonacci(void);
void factorial(void);

// FUNCION PRINCIPAL
int main()
{
    menu();

    return 0;
}

// DESARROLLO DE FUNCIONES

void menu( void)
{
    int op;
    printf(" Seleccione una opcion NUMERICA \n");
    printf(" 1- Fibonacci \n");
    printf(" 2- Factorial \n");
    printf(" 3- Cantidad de digitos \n");
    printf(" Ingrese la opcion NUMERICA que desea: \n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        fibonacci();
        break;
    case 2:
        factorial();
        break;

    default:
        break;
    }
}

void fibonacci(void) // funcion fibonacci
{
    int n,  a=-1, s=1,res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);

for (int i = 0; i < n; i++)
{
    res= a+s;
    printf("%d", res);
    a=s;
    s=res;
}


}

void factorial(void)
{
    int num, i,a,r,s;
    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    i=2;
    a= num * (num-1);
    while (i < num)
    {
        s= a * (num-i);
        a=s;

        i++;
    }

    printf("%d", a);
}