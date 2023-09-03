//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// Chinchampu con condiciones anidadas
// SD_ACT04_08
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int player, computer;
    int time();

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    scanf("%d", &player);

    srand(time(NULL));
    computer = rand() % 3 + 1;

    if (player <= 0 && player >= 4)
    {
        printf("ERROR OPCION INCORRECTA \n");
        return 1;
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

    return 0;
}