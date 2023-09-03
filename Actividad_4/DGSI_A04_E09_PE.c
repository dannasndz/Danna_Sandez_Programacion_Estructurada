//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// Chinchampu con switch
// SD_ACT04_09

#include <stdio.h>
#include <stdlib.h>

int main (){

    int player, computer;
    int time();

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    scanf("%d", &player);

    srand(time(NULL));
    computer = rand() % 3 + 1; //numero random entre 1-3

    if (player<=0 && player>=4)
    {
        printf("ERROR, OPCION INCORRECTA \n");
        return 1;
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
            switch(computer)
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

    return 0;
}