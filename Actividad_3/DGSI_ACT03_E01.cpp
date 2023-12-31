
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// prototipo de funciones

void menu(void);
void cali_op(void);
void chin_anidado(void);
void chin_op(void);
void num_mayor(void);
void num_medio(void);
void num_asc(void);
void horoscopo(void);

// FUNCION PRINCIPAL

int main() 
{
    srand(time(NULL));
    menu();  // funcion menu donde el usuario puede seleccionar la opcion de su gusto

    return 0;
}

// DESARROLLO DE FUNCIONES

void menu()  // funcion menu 
{
    int op;
    printf("\n");
    printf("  Seleccione una opcion numerica: \n");
    printf("\n");
    printf("1- 3 calificaciones con promedio \n");
    printf("2- Chinchampu anidado \n");
    printf("3- Chinchampu switch \n");
    printf("4- 3 numeros y numero mayor \n");
    printf("5- 3 numeros y numero del medio \n");
    printf("6- 3 numeros en forma ascendete \n");
    printf("7- Horoscopo \n");
    printf("8- Salir \n");
    printf("Ingresa tu opcion: ");
    scanf("%d", &op);
    printf("\n");

    switch (op)  // switch segun sea la opcion seleccionada se abren casos para mandar llamar a las funciones que desarrollan los puntos
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
        num_medio();
        break;
    case 6: // funcion para leer 3 numeros y desplegarlos de forma ascendente
        num_asc();
        break;
    case 7: // funcion que segun tu mes de nacimiento genera un horospoco para ti
        horoscopo();
        break;
    case 8: // Caso en el que el usuario desee salir
        printf("Gracias! Nos vemos pronto! :D \n");
        break;
    default: // mensaje en caso de seleccion de opcion incorrecta
        printf("OPCION INCORRECTA, POR FAVOR SELECCIONA UNA OPCION CORRECTA \n");
        getch();
        printf("\n");
        menu();
        break;
    }

}

void cali_op(void)  // Funcion  de calificaciones optimizado
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

    if (prom < 80)
    {
        if (prom < 60)
        {
            if (prom < 30)
            {
                printf("Repetir");
            }
            else
            {
                printf("Extraordinario");
            }
        }
        else
        {
            printf("Suficiente");
        }
    }
    else
    {
        if (prom < 98)
        {
            if (prom < 90)
            {
                printf("Bien");
            }
            else
            {
                printf("Muy Bien");
            }
        }
        else
        {
            printf("Excelente");
        }
    }
    getch();
    printf("\n");
    menu();  // envia al usuario al menu cuando finaliza la tarea
}

void chin_anidado(void)  // chinchampu anidado
{
    int player, computer;

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    printf("Ingresa tu opcion:");
    scanf("%d", &player);
    printf("\n");

    computer = rand() % 3 + 1;  // se crea una jugada aleatoria para el computador entre priedra, papel o tijera

    if (player <= 0 && player >= 4)  // en caso de que el usuario seleccione una opcion incorrecta
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
    getch();
    printf("\n");
    menu();  // envia al usuario al menu
}

void chin_op(void) //chinchampu optimizado 
{
    int player, computer;

    printf("   CHINCHAMPU \n");
    printf("Que deseas jugar? \n");
    printf("1-Piedra \n");
    printf("2-Papel \n");
    printf("3-Tijera \n");
    printf("SELECCIONA UNA OPCION NUMERICA \n");
    printf("Ingresa tu opcion:");
    scanf("%d", &player);
    printf("\n");

    computer = rand() % 3 + 1; // numero random entre 1-3

    // PROGRAMA
    if (player < 1 && player > 3) 
    {
        printf("ERROR, OPCION INCORRECTA \n");
    }
    else
    {
        switch (player)  // segun la opcion del usuario se despliegan los siguientes casos
        {
        case 1: // usuario escogio piedra
            switch (computer) // segun la opcion aleatoria del computador se despliegan los siguientes casos
            {
            case 1: // computador escogio piedra
                printf("EMPATE!, WOW, piensas igual que el computador! :0 \n");
                break;
            case 2: // computador escogio papel
                printf("Perdiste!, piedra pierde contra papel! :( \n");
                break;
            case 3: // computador escogio tijera
                printf("Ganaste!, piedra gana contra tijera! :D \n");
                break;
            }
            break;
        case 2:  // usuario escogio papel
            switch (computer) // segun la opcion aleatoria del computador se despliegan los siguientes casos
            {
            case 1: // computador escogio piedra
                printf("Ganaste!, papel gana contra piedra! :D \n");
                break;
            case 2: // computador escogio papel
                printf("EMPATE!, WOW, piensas igual que el computador! :0 \n");
                break;
            case 3: // computador escogio tijera
                printf("Perdiste!, papel pierde contra tijera! :( \n");
                break;
            }
            break;
        case 3: // usuario escogio tijera
            switch (computer) // segun la opcion aleatoria del computador se despliegan los siguientes casos
            {
            case 1: // computador escogio piedra
                printf("Perdiste!, tijera pierde contra piedra! :( \n");
                break;
            case 2: // usuario escogio papel
                printf("Ganaste!, tijera gana contra papel! :D \n");
                break;
            case 3: // usuario escogio tijera
                printf("EMPATE, WOW, piensas igual que el computador! :0 \n");
                break;
            }
            break;
        }
    }
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void num_mayor(void) // funcion numero mayor
{
    float n1, n2, n3;

    printf("   NUMERO MAYOR \n");
    printf("Ingrese un numero: ");
    scanf("%f", &n1);
    printf("Ingrese un numero: ");
    scanf("%f", &n2);
    printf("Ingrese un numero: ");
    scanf("%f", &n3); 
    printf("\n");

    // PROGRAMA

    if (n1 > n2 && n1 > n3)
    {
        printf("El numero mayor es %.2f", n1);
    }
    else
    {
        if (n2 > n1 && n2 > n3)
        {
            printf("El numero mayor es %.2f", n2);
        }
        else
        {
            printf("El numero mayor es %.2f", n3);
        }
    }
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void num_medio(void) // funcion numero medio 
{
    float num1, num2, num3;
    printf("  NUMERO DEL MEDIO \n");
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &num3);
    printf("\n");

    // PROGRAMA

    if (num1 < num2 && num2 < num3)
    {
        printf("El numero %.f es el de en medio", num2);
    }
    else
    {
        if (num2 < num1 && num1 < num3)
        {
            printf("El numero %.2f es el de en medio", num1);
        }
        else
        {
            printf("El numero %.2f es el de en medio", num3);
        }
    }
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void num_asc(void) // funcion numeros en ascendente 
{
    float n1, n2, n3;

    // Variables locales
    printf("Ingrese el primer numero: ");
    scanf("%f", &n1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &n2);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &n3);
    printf("\n");

    printf("NUMEROS EN ASCENDETE \n");

    // PROGRAMA 

    if (n1 < n2 && n2 < n3)
    {
        printf("%.2f, %.2f, %.2f", n1, n2, n3);
    }
    else
    {
        if (n2 < n1 && n1 < n3)
        {
            printf("%.2f, %.2f, %.2f", n2, n1, n3);
        }
        else
        {
            printf("%.2f, %.2f, %.2f", n3, n2, n1);
        }
    }
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}

void horoscopo(void) // funcion horoscopos 
{
    // variables locales

    int mes, dia;

    printf("\n");
    printf("  HOROSCOPO SEMANAL!!\n");
    printf("\n");
    printf("Ingresa tu dia de nacimiento: \n");
    scanf("%d", &dia);
    printf("Ingresa tu mes de nacimiento de forma NUMERICA: \n");
    scanf("%d", &mes);

    // programa 

    if ((mes < 1 || mes > 12) || (dia < 1 || dia > 31)) // en caso de que el usuario ingrese mal la fecha 
    {
        printf("La fecha que ingresaste es incorrecta, por favor intentalo de nuevo! \n");
    }
    else
    {
        switch (mes)
        {
        case 1: // mes de enero
            if (dia <= 19)
            {
                printf(" --CAPRICORNIO--\n");
                printf("\n");
                printf("Esta semana esta llena de cambios repentinos asi que preparate!. Nuevas oportunidades te esperan, mantente positiv@, tu color de la semana es el amarillo!\n");
            }
            else
            {
                printf(" --ACUARIO--\n");
                printf("\n");
                printf("Nuevas oportunidades laborales se te acerca, esa propuesta que tanto esperabas esta por llegar. Tu color de la semana es azul!\n");
            }

            break;
        case 2: // mes de febrero
            if (dia <= 18)
            {
                printf(" --ACUARIO--\n");
                printf("\n");
                printf("Nuevas oportunidades laborales se te acercan, esa propuesta que tanto esperabas esta por llegar. Tu color de la semana es azul!\n");
            }
            else
            {
                if (dia >= 19 && dia <= 28)
                {
                    printf(" --PISCIS--\n");
                    printf("\n");
                    printf("En cuestiones del amor, si estas solter@ nuevos prospectos se avecinan, pero si tienes pareja puede que salgan a la luz algunos secretos. Tu color de la semana es rojo!\n");
                }
                else // else en caso de que el usuario ingrese mal la fecha 
                {
                    printf("Febrero de 2023 no tiene mas de 28 dias! Escribe correctamente tu fecha de nacimiento por favor. /n");
                }
                getch();
                printf("\n");
                horoscopo();
            }
            break;
        case 3: // mes de marzo
            if (dia <= 20)
            {
                printf(" --PISCIS--\n");
                printf("\n");
                printf("En cuestiones del amor, si estas solter@ nuevos prospectos se avecinan, pero si tienes pareja puede que salgan a la luz algunos secretos. Tu color de la semana es rojo!\n");
            }
            else
            {
                printf(" --ARIES--\n");
                printf("\n");
                printf("Cuidado con los escalones o pisos resbalosos, puede que sufras algun accidente en esta semana. Tu color de la semana es el morado! \n");
            }
            break;
        case 4: // mes de abril
            if (dia <= 19)
            {
                printf(" --ARIES--\n");
                printf("\n");
                printf("Cuidado con los escalones o pisos resbalosos, puede que sufras algun accidente en esta semana. Tu color de la semana es el morado! \n");
            }
            else
            {
                if (dia >= 20 && dia <= 30)
                {
                    printf(" --TAURO--\n");
                    printf("\n");
                    printf("En terminos economicos recibiras dinero de diversas fuentes, eres un iman del dinero!. Tu color de la semana es el blanco! \n");
                }
                else // else en caso de que el usuario ingrese mal la fecha 
                {
                    printf("Abril no tiene mas de 30 dias! Escribe correctamente tu fecha de nacimiento por favor. /n");
                }
                getch();
                printf("\n");
                horoscopo();
            }
            break;
        case 5: // mes de mayo
            if (dia <= 20)
            {
                printf(" --TAURO--\n");
                printf("\n");
                printf("En terminos economicos recibiras dinero de diversas fuentes, eres un iman del dinero!. Tu color de la semana es el blanco! \n");
            }
            else
            {
                printf(" --GEMINIS--\n");
                printf("\n");
                printf("Tendras que tomar vitaminas y jugos de naranja! Puede que se avecine una gripa. Tu color de la semana es el negro! \n");
            }
            break;
        case 6: // mes de junio
            if (dia <= 20)
            {
                printf(" --GEMINIS--\n");
                printf("\n");
                printf("Tendras que tomar vitaminas y jugos de naranja! Puede que se avecine una gripa. Tu color de la semana es el negro! \n");
            }
            else
            {
                if (dia >= 21 && dia <= 30)
                {
                    printf(" --CANCER--\n");
                    printf("\n");
                    printf("Nuevas oportunidades de labor se te avesinan! Atento a las señales. Tu color de la semana es el dorado! \n");
                }
                else // else en caso de que el usuario ingrese mal la fecha 
                {
                    printf("Junio no tiene mas de 30 dias! Escribe correctamente tu fecha de nacimiento por favor. /n");
                }
                getch();
                printf("\n");
                horoscopo();
            }
            break;
        case 7: // mes de julio
            if (dia <= 22)
            {
                printf(" --CANCER--\n");
                printf("\n");
                printf("Nuevas oportunidades de labor se te avesinan! Atento a las señales. Tu color de la semana es el dorado! \n");
            }
            else
            {
                printf(" --LEO--\n");
                printf("\n");
                printf("Se haran planes de viajes nacionales! Ten a la mano tu pasaporte. Tu color de la semana es el rosa! \n");
            }
            break;
        case 8: // mes de agosto
            if (dia <= 22)
            {
                printf(" --LEO--\n");
                printf("\n");
                printf("Se haran planes de viajes nacionales! Ten a la mano tu pasaporte. Tu color de la semana es el rosa! \n");
            }
            else
            {
                printf(" --VIRGO--\n");
                printf("\n");
                printf("En el ambito laboral se avesinan nuevos ascensos. Tu color de la semana es el verde! \n");
            }
            break;
        case 9: // mes de septiembre
            if (dia <= 22)
            {
                printf(" --VIRGO--\n");
                printf("\n");
                printf("En el ambito laboral se avesinan nuevos ascensos. Tu color de la semana es el verde! \n");
            }
            else
            {
                if (dia >= 23 && dia <= 30)
                {
                    printf(" --LIBRA--\n");
                    printf("\n");
                    printf("Se sienten las vibras muy pesadas a tu alrededor, cuida mucho tu circulo social. Tu color de la semana es guinda!\n");
                }
                else // else en caso de que el usuario ingrese mal la fecha 
                {
                    printf("Septiembre no tiene mas de 30 dias! Escribe correctamente tu fecha de nacimiento por favor. /n");
                }
                getch();
                printf("\n");
                horoscopo();
            }
            break;
        case 10: // mes de octubre
            if (dia <= 22)
            {
                printf(" --LIBRA--\n");
                printf("\n");
                printf("Se sienten las vibras muy pesadas a tu alrededor, cuida mucho tu circulo social. Tu color de la semana es cafe!\n");
            }
            else
            {
                printf(" --ESCORPIO--\n");
                printf("\n");
                printf("Cambios positivos se aproximan en tu vida, adaptate a ellos lo mejor que puedas, tendras mucho crecimiento personal. Tu color de la semana es plateado!\n");
            }
            break;
        case 11: // mes de noviembre
            if (dia < 21)
            {
                printf(" --ESCORPIO--\n");
                printf("\n");
                printf("Cambios positivos se aproximan en tu vida, adaptate a ellos lo mejor que puedas, tendras mucho crecimiento personal. Tu color de la semana es plateado!\n");
            }
            else
            {
                if (dia >= 22 && dia <= 30)
                {
                    printf(" --SAGITARIO--\n");
                    printf("\n");
                    printf("Realiza acciones caritativas, tomate tiempos de reflexion sobre tus acciones, te ayudara mucho. Tu color de la semana es naranja!\n");
                }
                else // else en caso de que el usuario ingrese mal la fecha 
                {
                    printf("Noviembre no tiene mas de 30 dias! Escribe correctamente tu fecha de nacimiento por favor. /n");
                }
                getch();
                printf("\n");
                horoscopo();
            }
            break;
        case 12: // mes de diciembre
            if (dia <= 21)
            {
                printf(" --SAGITARIO--\n");
                printf("\n");
                printf("Realiza acciones caritativas, tomate tiempos de reflexion sobre tus acciones, te ayudara mucho. Tu color de la semana es naranja!\n");
            }
            else
            {
                printf(" --CAPRICORNIO--\n");
                printf("\n");
                printf("Esta semana esta llena de cambios repentinos asi que preparate!. Nuevas oportunidades te esperan, mantente positiv@, tu color de la semana es el amarillo!\n");
            }
            break;
        }
    }
    getch();
    printf("\n");
    menu(); // envia al usuario a la funcion menu 
}