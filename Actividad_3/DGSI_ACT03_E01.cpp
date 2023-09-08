
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NULL

void menu(void);
void cali_op(void);
void chin_anidado(void);
void chin_op(void);
void num_mayor(void);
void num_medio(void);

int main()
{
    int time();
    srand(time(NULL));
    menu();

    return 0;
}

void menu()
{
    int op;
    printf("Seleccione una opcion numerica: \n");
    printf("1- 3 calificaciones con promedio \n");
    printf("2- Chinchampu anidado \n");
    printf("3- Chinchampu switch \n");
    printf("4- 3 numeros y numero mayor \n");
    printf("5- 3 numeros y numero del medio \n");
    printf("6- 3 numeros en forma ascendete \n");
    printf("7- Horoscopo \n");
    scanf("%d", &op);
    switch (op)
    {
    case 1: // FUNCION PARA 3 CALIFICACIONES CON PROMEDIO, OPTIMIZADO
        cali_op();
        break;
    case 2: // funcion chinchampu anidado
        chin_anidado();
        break;
    case 3: // funcion chinchampu switch
        chin_op();
        break;
    case 4: // funcion que lea 3 numeros y desplegar el numero mayor
        num_mayor();
        break;
    case 5: // funcion para ller 3 numeros y desplegar el del medio

        break;
    case 6: // funcion para leer 3 numeros y desplegarlos de forma ascendente

        break;
    case 7: // funcion que segun tu mes de nacimiento genera un horospoco para ti

        break;
    default: // mensaje en caso de seleccion de opcion incorrecta
        printf("OPCION INCORRECTA, POR FAVOR SELECCIONA UNA OPCION CORRECTA \n");
        break;
    }
}

void cali_op()
{
    float cal1, cal2, cal3;
    float prom;

    printf("Ingrese la calificación 1: ");
    scanf("%f", &cal1);
    printf("Ingrese la calificación 2: ");
    scanf("%f", &cal2);
    printf("Ingrese la calificación 3: ");
    scanf("%f", &cal3);

    prom = (cal1 + cal2 + cal3) / 3;
}

void chin_anidado()
{
    int player, computer;

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    scanf("%d", &player);

    computer = rand() % 3 + 1;

    if (player <= 0 && player >= 4)
    {
        printf("ERROR OPCION INCORRECTA \n");
    }
    else
    {
        if ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2))
        {
            if (player == 1)
            {
                printf("Ganaste!, piedra gana contra tijera");
            }

            if (player == 2)
            {
                printf("Ganaste!, papel gana contra piedra");
            }
            if (player == 3)
            {
                printf("Ganaste!, tijera gana contra papel");
            }
        }
        else
        {
            if ((player == 1 && computer == 2) || (player == 2 && computer == 3) || (player == 3 && computer == 1))
            {
                if (player == 1)
                {
                    printf("Perdiste, piedra pierde contra papel :(");
                }
                if (player == 2)
                {
                    printf("Perdiste, papel pierde contra tijera :(");
                }
                if (player == 3)
                {
                    printf("Perdiste, tijera pierde contra piedra :(");
                }
            }
            else
            {
                if (player == computer)
                {
                    printf("EMPATE, WOW PIENSAS IGUAL QUE LA COMPUTADORA!");
                }
            }
        }
    }
}

void chin_op()
{
    int player, computer;

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    scanf("%d", &player);

    computer = rand() % 3 + 1; // numero random entre 1-3

    if (player < 1 && player > 3)
    {
        printf("ERROR, OPCION INCORRECTA \n");
    }
    else
    {
        switch (player)
        {
        case 1:
            switch (computer)
            {
            case 1:
                printf("EMPATE!, WOW, piensas igual que el computador! :0");
                break;
            case 2:
                printf("Perdiste!, piedra pierde contra papel! :(");
                break;
            case 3:
                printf("Ganaste!, piedra gana contra tijera! :D");
                break;
            }
            break;
        case 2:
            switch (computer)
            {
            case 1:
                printf("Ganaste!, papel gana contra piedra! :D");
                break;
            case 2:
                printf("EMPATE!, WOW, piensas igual que el computador! :0");
                break;
            case 3:
                printf("Perdiste!, papel pierde contra tijera! :(");
                break;
            }
            break;
        case 3:
            switch (computer)
            {
            case 1:
                printf("Perdiste!, tijera pierde contra piedra! :(");
                break;
            case 2:
                printf("Ganaste!, tijera gana contra papel! :D");
                break;
            case 3:
                printf("EMPATE, WOW, piensas igual que el computador! :0");
                break;
            }
            break;
        }
    }
}

void num_mayor()
{
    float n1, n2, n3;

    printf("Ingrese un numero: \n");
    scanf("%f", &n1);
    printf("Ingrese un numero: \n");
    scanf("%f", &n2);
    printf("Ingrese un numero: \n");
    scanf("%f", &n3);

    if (n1 > n2 && n1 > n3)
    {
        printf("El numero mayor es %f", n1);
    }
    else
    {
        if (n2 > n1 && n2 > n3)
        {
            printf("El numero mayor es %f", n2);
        }
        else
        {
            printf("El numero mayor es %f", n3);
        }
    }
}

void num_medio(void)
{
    float num1, num2, num3;

    printf("Ingrese el primer numero: \n");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: \n");
    scanf("%f", &num3);

    if (num1 < num2 && num2 < num3)
    {
        printf("El numero %.f es el de en medio", num2);
    }
    else
    {
        if (num2 > num1 && num1 > num3)
        {
            printf("El numero %.2f es el de en medio", num1);
        }
        else
        {
            printf("El numero %.2f es el de en medio", num3);
        }
    }
}