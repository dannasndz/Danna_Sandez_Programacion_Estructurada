#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void cons_compuesto(char cadena[], char *clave, int posicion);
int cons(char campo[], char *clave, int posicion);
int cONS2(char campo[], int lugar, char *clave, int posicion);
void estadox(char cadena[], char cadena2[], int pos);
void estado(char cadena[], char clave[], int posicion);

char nom_hombre[20][30] = {"Sebastian", "Carlos", "Pedro", "Luis", "Miguel", "Javier", "Alejandro", "Andres", "Fernando", "Roberto", "Carlos", "Manuel", "Antonio", "Miguel", "Angel", "Alejandro", "Jose", "Felipe", "Jose"};
char nom_mujer[20][30] = {"Ana", "Maria", "Sofia", "Luisa", "Laura", "Isabel", "Elena", "Carmen", "Clara", "Patricia", "Isabel", "Jose", "Victoria", "Fernanda", "Carmen", "Elena", "Gabriela", "Luisa", "Beatriz", "Alejandra"};
char apellido[104][100] = {"Saavedra", "Rodriguez", "Lopez", "Martinez", "Perez", "Fernandez", "Gonzalez", "Diaz", "Hernandez", "Torres", "Garcia", "Ramirez", "Sanchez", "Flores", "Vargas", "Mendoza", "Castillo", "Rojas", "Gutierrez", "Ortega", "Haro", "Solano", "Sandez", "Lopez", "Meza", "Perez", "torres", "ramirez", "ruiz", "morales", "jimenez", "soto", "herrera", "delgado", "castro", "rios", "medina", "vargas", "mendoza", "reyes", "blanco", "navarro", "guzman", "romero", "ortega", "jimenez", "soto", "herrera", "delgado", "castro", "rios", "medina", "silva", "castro", "rios", "montoya", "pena", "vidal", "aguilar", "cordero", "mora", "sosa", "rosales", "lugo", "serrano", "caceres", "robles", "salazar", "leon", "gallegos", "cordova", "del valle", "navarro", "paredes", "zamora", "valdez", "duran", "cisneros", "gutierrez", "salinas", "avila", "rivas", "pizarro", "guerra", "espinoza", "calderon", "pantoja", "miranda", "rojas", "segura", "villanueva", "roldan", "benitez", "luna", "valencia", "cervantes", "Escobar", "Zuniga", "barrios"};
char est_ados[33][50] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO ", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "EXTRANJERO"};

void cons_compuesto(char cadena[], char *clave, int posicion)
{
    mayus(cadena);
    char contra[23][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y", "MA.", "MA", "J", "J."};
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
        while (l < 23)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n = strlen(contra[l]);
                lugar += n + 1;
            }
            l++;
        }
        /*if (cadena[k] == '.')
        {
            k++;
            k++;
        }*/

        if (cadena[k] == ' ')
        {
            k++;
        }

        i++;
    }

    if (lugar > 0)
    {
        cONS2(cadena, (lugar + 1), clave, 13);
        return;
    }

    int len = strlen(cadena);
    int b1 = 0;
    int b2 = 0;
    int m = 0;
    char jose[5] = "JOSE";
    char maria[6] = "MARIA";

    do
    {
        if (cadena[m] == jose[m])
        {
            m++;
        }
        else
        {
            b1 = 1;
        }
    } while (b1 == 0 && m < 4);

    if (b1 == 0)
    {
        for (int i = 5; i < len; i++)
        {
            if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
            {
                clave[13] = cadena[i];
                return;
            }
        }
    }
    int h = 0;
    do
    {
        if (cadena[h] == maria[h])
        {
            h++;
        }
        else
        {
            b2 = 1;
        }
    } while (b2 == 0 && h < 5);

    if (b2 == 0)
    {
        for (int i = 6; i < len; i++)
        {
            if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
            {
                clave[posicion] = cadena[i];
                return;
            }
        }
    }

    if (b1 == 1 || b2 == 1)
    {
        int len = strlen(cadena);
        int i;
        for (i = 1; i < len; i++)
        {
            if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
            {
                clave[posicion] = cadena[i];
                return;
            }
        }
        if (cadena[i - 1] != '\0')
        {
            if (cadena[i - 1] == 'A' || cadena[i - 1] == 'E' || cadena[i - 1] == 'I' || cadena[i - 1] == 'O' || cadena[i - 1] != 'U')
            {
                cadena[i - 1] = 'X';
                clave[posicion] = cadena[i - 1];
                return;
            }
        }
    }
}

int cONS2(char campo[], int lugar, char *clave, int posicion)
{
    int len = strlen(campo);
    for (int i = lugar; i < len; i++)
    {
        if (campo[i] != 'A' && campo[i] != 'E' && campo[i] != 'I' && campo[i] != 'O' && campo[i] != 'U')
        {
            clave[posicion] = campo[i];
            return 1;
        }
    }
    return 0;
}

int cons(char campo[], char *clave, int posicion)
{
    int len = strlen(campo);
    int i = 1;
    for (i = 1; i < len; i++)
    {
        if (campo[i] != 'A' && campo[i] != 'E' && campo[i] != 'I' && campo[i] != 'O' && campo[i] != 'U')
        {
            if (campo[i] == -92 || campo[i] == -91 || campo[i] == 47 || campo[i] == 45 || campo[i] == 39 || (unsigned char)campo[i] == 239)
            {
                campo[i] = 'X';
                clave[posicion] = campo[i];
                return 1;
            }
            else
            {
                clave[posicion] = campo[i];
                return 1;
            }
        }
    }
    if (campo[i - 1] != '\n')
    {
        if (campo[i - 1] == 'A' || campo[i - 1] == 'E' || campo[i - 1] == 'I' || campo[i - 1] == 'O' || campo[i - 1] == 'U')
        {
            campo[i - 1] = 'X';
            clave[posicion] = campo[i - 1];
            return 1;
        }
    }
    return 0;
}

void estado(char cadena[], char clave[], int posicion)
{
    char etd[32][3] = {"AS", "BC", "BS", "CC", "CL", "CM", "CS", "CH", "CC", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS"};
    char estados[33][50] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO ", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "EXTRANJERO"};
    int i = 0;
    do
    {
        if ((strcmp(cadena, estados[i]) == 0))
        {
            for (int j = 0; j < 2; j++)
            {
                clave[posicion] = etd[i][j];
                posicion++;
            }
            return;
        }
        i++;
    } while (i < 32);
}

void estadox(char cadena[], char cadena2[], int pos)
{
    int est;
    char estados[33][50] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO ", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "EXTRANJERO"};
    int n = sizeof(estados) / sizeof(estados[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d- %s\n", i, estados[i]);
    }
    est = validar("Ingrese una opcion NUMERICA: ", 0, 33);

    int j = strlen(estados[est]);
    if (est == 33)
    {
        cadena2[pos] = 'N';
        cadena2[pos + 1] = 'E';
    }
    else
    {
        for (int i = 0; i < j; i++)
        {
            cadena[i]= estados[est][i];
        }
    }
}