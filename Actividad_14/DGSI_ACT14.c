/*
    Danna Guadalupe Sandez Islas 373080
    21 de noviembre de 2023
    Actividad 14
    SD_ACT14
*/
#include "junior.h"

typedef int Tkey;
typedef struct _datos
{
    int status;
    Tkey enrollment;
    char name[30];
    char LastName1[50];
    char LastName2[50];
    char sex[15];
    char JobPstion[30];
    char state[30];
    int age;
    Tkey cellPhone;
} Tdatos;

/**************** Prototipo de funciones  ********************/
int mnsj(void);

/*********************** Funcion principal **********************/
int main()
{
    int op;

    do
    {
        system("CLS");
        op = mnsj();
        switch (op)
        {
        case 1:
            /* code */
            break;
        case 2:
            break;
        case 3:;
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
    return 0;
}

/************************* Desarrollo de funciones  *******************************/
int mnsj(void)
{
    int op;
    system("CLS");
    printf("     ---- MENU ----\n");
    printf("1- Agregar\n");
    printf("2- Eliminar\n");
    printf("3- Buscar\n");
    printf("4- Ordenar\n");
    printf("5- Imprimir registros archivo original\n");
    printf("6- Imrimir registros archivo ordenado\n");
    printf("7- Generar archivo texto\n");
    printf("8- Empaquetar\n");
    printf("0-  SALIR\n");
    op = validar("Ingresa una opcion numerica: ", 0, 8);
    system("CLS");

    return op;
}