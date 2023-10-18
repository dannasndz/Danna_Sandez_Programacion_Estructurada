#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _estd
{
    char estado[30];
    char abre[2];
} testd;


/* Prototipo de funciones*/

int validar(char mensj[], int ri, int rf);
int alfabetico(char cadena[]);
void mayus(char cadena[]);
int estados(void);

testd est[]={
        {"Aguascalientes", "AS"},
        {"Baja California", "BC"},
        {"Baja California Sur", "BS"},
        {"Campeche", "CC"},
        {"Coahuila", "CL"},
        {"Colima", "CM"},
        {"Chiapas", "CS"},
        {"Chihuahua", "CH"},
        {"Ciudad de México", "CC"},
        {"Durango", "DG"},
        {"Guanajuato", "GT"},
        {"Guerrero", "GR"},
        {"Hidalgo", "HG"},
        {"Jalisco", "JC"},
        {"México", "MC"},
        {"Michoacán", "MN"},
        {"Morelos", "MS"},
        {"Nayarit", "NT"},
        {"Nuevo León", "NL"},
        {"Oaxaca", "OC"},
        {"Puebla", "PL"},
        {"Querétaro", "QT"},
        {"Quintana Roo", "QR"},
        {"San Luis Potosí", "SP"},
        {"Sinaloa", "SL"},
        {"Sonora", "SR"},
        {"Tabasco", "TC"},
        {"Tamaulipas", "TS"},
        {"Tlaxcala", "TL"},
        {"Veracruz", "VZ"},
        {"Yucatán", "YN"},
        {"Zacatecas", "ZS"}
    };

/*Desarrollo de funciones*/

int validar(char mensj[], int ri, int rf)
{
    // variables locales
    int num;
    char cadena[100];
    // desarrollo de funcion
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena); // cambia a numeros la cadena

    } while (num < ri || num > rf);

    return num; // retorna el valor que haya tomado num, entre los rangos dados por el usuario
}

/*
    Funcion para validar una cadena unicamente alfabetica, y con espacios sencillos.
    Parametros: cadena a validar.
    Valor de retonor: -1 si es incorrecta, 1 si es correcta
*/

int alfabetico(char cadena[])
{
    int i = 0;

    if (cadena[0] == ' ' || cadena[0] == '\0')
    {
        printf("ERROR\n");
        return -1;
    }

    while (cadena[i] != '\0')
    {
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' ')))
        {
            printf("ERROR\n");
            return -1;
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        printf("ERROR\n");
        return -1;
    }

    return 1;
}

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
}

int estados(void)
{
    int est;
    char estados[32][50] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO ", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS"};
    int n = sizeof(estados) / sizeof(estados[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d- %s\n", i, estados[i]);
    }
    est = validar("Ingrese una opcion NUMERICA: ", 0, 31);

    return est;
}
