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
int numAleatorio(int ri, int rf);
void mariajose(char text[]);
int ape(char campo[]);
void dieresis(char campo[]);
void carctEspecial(char campo[]);

testd est[] = {
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
    {"Zacatecas", "ZS"}};

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
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' ') || cadena[i] == '/' || cadena[i] == '-' || cadena[i] == '.' || cadena[i] == -92 || cadena[i] == -91 || (unsigned char)cadena[i] == 142 || (unsigned char)cadena[i] == 132 || (unsigned char)cadena[i] == 137 || (unsigned char)cadena[i] == 211 || (unsigned char)cadena[i] == 139 || (unsigned char)cadena[i] == 216 || (unsigned char)cadena[i] == 148 || (unsigned char)cadena[i] == 153 || (unsigned char)cadena[i] == 154 || (unsigned char)cadena[i] == 129))
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
    est = validar("Ingrese una opcion NUMERICA: ", 0, 32);

    return est;
}

int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

int nomCompuesto(char cadena[])
{
    int i = 0;
    int espacio = 0;
    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' '))
        {
            if (cadena[i] == ' ')
            {
                espacio++;
            }
        }
        i++;
    }
    if (espacio > 0)
    {
        return 1; // Es un nombre compuesto
    }

    return -1;
}

void mariajose(char text[])
{
    char temp2[20];
    int i = 0;
    int k = 0;
    int flag = 0;
    int lugar = 0;
    int flag2 = 0;

    while (text[i] != '\0' && flag2 == 0)
    {
        int j = 0;
        while (text[k] != ' ' && text[k] != '\0')
        {
            temp2[j] = text[k];
            j++;
            k++;
        }
        temp2[j] = '\0';

        if (strcmp(temp2, "MARIA") == 0)
        {
            lugar += 6;
        }
        else
        {
            if (strcmp(temp2, "JOSE") == 0)
            {
                lugar += 5;
            }
            else
            {
                if (strcmp(temp2, "MA") == 0)
                {
                    lugar += 3;
                }
                else
                {
                    if (strcmp(temp2, "J.") == 0)
                    {
                        lugar += 3;
                    }
                    else
                    {
                        if (strcmp(temp2, "MA.") == 0)
                        {
                            lugar += 4;
                        }
                        else
                        {
                            if (strcmp(temp2, "J") == 0)
                            {
                                lugar += 2;
                            }
                            else
                            {
                                flag2 = 1;
                            }
                        }
                    }
                }
            }
        }
        if (text[k] == ' ')
        {
            k++;
        }

        if (i == 0 && lugar == 0)
        {
            flag = 1;
        }

        i++;
    }

    if (flag == 1)
    {
        printf("%c", text[0]);
    }
    else
    {
        printf("%c", text[lugar]);
    }
}

void apeCompuesto(char cadena[])
{
    char contra[23][3] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
    char temp[20];
    int i = 0;
    int k = 0;
    int n = 0;
    int lugar = 0;

    while (cadena[i] != '\0')
    {
        int j = 0;
        int l = 0;
        while (cadena[k] != ' ' && cadena[k] != '\0')
        {
            temp[j] = cadena[k];
            j++;
            k++;
        }
        temp[j] = '\0';
        while (strcmp(temp, contra[l]) == 1)
        {
            l++;
            if (strcmp(temp, contra[l]) == 0)
            {
                n = strlen(contra[l]);
                lugar += n+1;
            }
        }
        if (cadena[k] == ' ')
        {
            k++;
        }

        i++;
    }

    if (lugar > 0)
    {
        printf("%c", cadena[lugar]);
        int len = strlen(cadena);
        for (int i = lugar; i < len; i++)
        {
            if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
            {
                printf("%c", cadena[i]);
                return;
            }
        }
    }
}

int ape(char campo[])
{
    int len = strlen(campo);
    dieresis(campo);
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        printf("%c", campo[0]);
    }
    else
    {
        carctEspecial(campo);
        printf("%c", campo[0]);
    }

    for (int i = 1; i < len; i++)
    {
        if (campo[i] == 'a' || 'e' || 'i' || 'o' || 'u')
        {
            printf("%c", campo[i]);
            return 1;
        }
    }

    return 0;
}

void carctEspecial(char campo[])
{
    for (int i = 0; i < 2; i++)
    {
        if (campo[i] == '/' || campo[i] == '-' || campo[i] == '.')
        {
            campo[i] = 'X';
        }
    }
}

void dieresis(char campo[])
{
    int len = strlen(campo);
    int i;
    for (i = 0; i < len; i++)
    {
        if ((unsigned char)campo[i] == 142)
        {
            campo[i] = 'A';
        }
        else
        {
            if ((unsigned char)campo[i] == 211)
            {
                campo[i] = 'E';
            }
            else
            {
                if ((unsigned char)campo[i] == 216)
                {
                    campo[i] = 'I';
                }
                else
                {
                    if ((unsigned char)campo[i] == 153)
                    {
                        campo[i] = 'O';
                    }
                    else
                    {
                        if ((unsigned char)campo[i] == 154)
                        {
                            campo[i] = 'U';
                        }
                    }
                }
            }
        }
    }
}