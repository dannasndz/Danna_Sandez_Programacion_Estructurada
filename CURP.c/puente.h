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
int dia_n(int mes, int anio);
void cadena(char mnsj[], char destino[]);
void mariajose(char text[], char clave[]);
void print_est(int i);
int ape(char campo[], char clave[]);
void apeMa(char campo[], char clave[]);
void apeCompuesto(char cadena[], char clave[]);
void apeCompuestoMa(char cadena[], char clave[]);
void nomCompuesto2(char cadena[], char clave[]);
void dieresis(char campo[]);
void carctEspecial(char cadena[], char clave[]);
int cons2(char campo[], int lugar);
void enie(char campo[]);
void consCompuesto(char cadena[]);
int consonante(char campo[]);
int consNombre(char campo[]);
int antisonante(char clave[]);
void nomClave(char cadena[], char clave[], int lugar);
void noAP(char destino[]);

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
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' ') || cadena[i] == '/' || cadena[i] == '-' || cadena[i] == '.' || cadena[i] == -92 || cadena[i] == -91 || (unsigned char)cadena[i] == 142 || (unsigned char)cadena[i] == 132 || (unsigned char)cadena[i] == 137 || (unsigned char)cadena[i] == 211 || (unsigned char)cadena[i] == 139 || (unsigned char)cadena[i] == 216 || (unsigned char)cadena[i] == 148 || (unsigned char)cadena[i] == 153 || (unsigned char)cadena[i] == 154 || (unsigned char)cadena[i] == 129 || (unsigned char)cadena[i] == 132 || (unsigned char)cadena[i] == 137 || (unsigned char)cadena[i] == 139 || (unsigned char)cadena[i] == 148 || (unsigned char)cadena[i] == 129 || (unsigned char)cadena[i] == 160 || (unsigned char)cadena[i] == 181 || (unsigned char)cadena[i] == 130 || (unsigned char)cadena[i] == 144 || (unsigned char)cadena[i] == 161 || (unsigned char)cadena[i] == 214 || (unsigned char)cadena[i] == 162 || (unsigned char)cadena[i] == 224 || (unsigned char)cadena[i] == 163 || (unsigned char)cadena[i] == 233 || cadena[i] == 39 || (unsigned char)cadena[i] == 239))
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
    char estados[33][50] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "COAHUILA", "COLIMA", "CHIAPAS", "CHIHUAHUA", "DISTRITO DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO ", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "EXTRANJERO"};
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

void cadena(char mnsj[], char destino[])
{
    int op;
    do
    {
        printf("%s", mnsj);
        fflush(stdin);
        gets(destino);
        system("CLS");
        op = alfabetico(destino);
    } while (op != 1);
    mayus(destino);
}

void noAP(char destino[])
{
    destino[0] = '\0';
}

void print_est(int i)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%c", est[i].abre[j]);
    }
}

int dia_n(int mes, int anio)
{
    int diasMes;

    switch (mes)
    {
    case 2:
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            diasMes = 29;
        }
        else
        {
            diasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        diasMes = 30;
        break;
    default:
        diasMes = 31;
        break;
    }

    return validar("Dia de nacimiento DD: ", 1, diasMes);
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

void mariajose(char text[], char clave[])
{
    char temp2[20];
    int i = 0;
    int k = 0;
    int flag = 0;
    int lugar = 0;
    int flag2 = 0;
    int nombre = 0;
    int otronom;

    while (text[i] != '\0' && flag2 == 0)
    {
        int j = 0;
        nombre = 0;
        otronom = 0;
        while (text[k] != ' ' && text[k] != '\0')
        {
            temp2[j] = text[k];
            j++;
            k++;
            otronom = 1;
        }
        temp2[j] = '\0';

        if (strcmp(temp2, "MARIA") == 0)
        {
            lugar += 6;
            nombre = 1;
        }
        else
        {
            if (strcmp(temp2, "JOSE") == 0)
            {
                lugar += 5;
                nombre = 1;
            }
            else
            {
                if (strcmp(temp2, "MA") == 0)
                {
                    lugar += 3;
                    nombre = 1;
                }
                else
                {
                    if (strcmp(temp2, "J.") == 0)
                    {
                        lugar += 3;
                        nombre = 1;
                    }
                    else
                    {
                        if (strcmp(temp2, "MA.") == 0)
                        {
                            lugar += 4;
                            nombre = 1;
                        }
                        else
                        {
                            if (strcmp(temp2, "J") == 0)
                            {
                                lugar += 2;
                                nombre = 1;
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
        nomCompuesto2(text, clave);
    }
    else
    {
        if (otronom == 1 && lugar > 0)
        {
            if (nomCompuesto(text) == 1)
            {
                nomClave(text, clave, lugar);
            }
        }
        else
        {
            if (nombre == 1)
            {
                clave[3] = text[lugar];
            }
        }
    }
}

void apeCompuesto(char cadena[], char clave[])
{
    char contra[23][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
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
        while (l < 19)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n = strlen(contra[l]);
                lugar += n + 1;
            }
            l++;
        }
        if (cadena[k] == ' ')
        {
            k++;
        }

        i++;
    }

    int len = strlen(cadena);
    if (lugar > 0)
    {
        clave[0] = cadena[lugar];
        for (int i = lugar; i < len; i++)
        {
            if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
            {
                clave[1] = cadena[i];
                return;
            }
        }
    }

    if (lugar == 0)
    {
        // system("PAUSE");
        if (cadena[0] == -92 || cadena[0] == -91)
        {
            cadena[0] = 'X';
            clave[0] = cadena[0];
        }
        else
        {
            clave[0] = cadena[0];
        }

        for (int i = 1; i < len; i++)
        {
            if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
            {
                clave[1] = cadena[i];
                return;
            }
        }
    }
}

int ape(char campo[], char clave[])
{
    int len = strlen(campo);
    mayus(campo);
    // carctEspecial(campo, clave);
    dieresis(campo);
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        clave[0] = campo[0];
    }
    else
    {
        clave[0] = campo[0];
    }

    int i = 1;
    for (i = 1; i < len; i++)
    {
        if (campo[i] == 'A' || campo[i] == 'E' || campo[i] == 'I' || campo[i] == 'O' || campo[i] == 'U')
        {
            clave[1] = campo[i];
            return 1;
        }
        else
        {
            if (campo[i] == 39 || (unsigned char)campo[i] == 239 || campo[i] == 47 || campo[i] == 45)
            {
                clave[1] = 'X';
                return 1;
            }
        }
    }

    // clave[1] = 'X';
    if (campo[i - 1] != '\0')
    {
        if (campo[i - 1] != 'A' || campo[i - 1] != 'E' || campo[i - 1] != 'I' || campo[i - 1] != 'O' || campo[i - 1] != 'U')
        {
            campo[i - 1] = 'X';
            clave[1] = campo[i - 1];
            return 1;
        }
    }
    return 1;
}

void apeMa(char campo[], char clave[])
{
    dieresis(campo);
    carctEspecial(campo, clave);
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        clave[2] = campo[0];
    }
    else
    {
        clave[2] = campo[0];
    }
}

void enie(char campo[])
{
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
    }
}

void carctEspecial(char cadena[], char clave[])
{
    /* int n = strlen(campo);
     for (int i = 0; i < n; i++)
     {
         if ((campo[i] == 47 || campo[i] == 45 || campo[i] == 46))
         {
             campo[i] = 'X';
             clave[2] = campo[i]; /// le agregue esto
         }
     }*/
    int i = 0;
    for (i = 0; i < 2; i++)
    {
        if (cadena[i] == '/' || cadena[i] == '-' || cadena[i] == 39 || (unsigned char)cadena[i] == 239)
        {
            cadena[i] = 'X';
            clave[i] = cadena[i];
        }
    }
}

void dieresis(char campo[])
{
    int len = strlen(campo);
    int i;
    for (i = 0; i < len; i++)
    {
        if ((unsigned char)campo[i] == 142 || (unsigned char)campo[i] == 132 || (unsigned char)campo[i] == 160 || (unsigned char)campo[i] == 181)
        {
            campo[i] = 'A';
        }
        else
        {
            if ((unsigned char)campo[i] == 211 || (unsigned char)campo[i] == 137 || (unsigned char)campo[i] == 130 || (unsigned char)campo[i] == 144)
            {
                campo[i] = 'E';
            }
            else
            {
                if ((unsigned char)campo[i] == 216 || (unsigned char)campo[i] == 139 || (unsigned char)campo[i] == 161 || (unsigned char)campo[i] == 214)
                {
                    campo[i] = 'I';
                }
                else
                {
                    if ((unsigned char)campo[i] == 153 || (unsigned char)campo[i] == 148 || (unsigned char)campo[i] == 162 || (unsigned char)campo[i] == 224)
                    {
                        campo[i] = 'O';
                    }
                    else
                    {
                        if ((unsigned char)campo[i] == 154 || (unsigned char)campo[i] == 129 || (unsigned char)campo[i] == 163 || (unsigned char)campo[i] == 233)
                        {
                            campo[i] = 'U';
                        }
                    }
                }
            }
        }
    }
}

int cons2(char campo[], int lugar)
{
    int len = strlen(campo);
    for (int i = lugar; i < len; i++)
    {
        if (campo[i] != 'A' && campo[i] != 'E' && campo[i] != 'I' && campo[i] != 'O' && campo[i] != 'U')
        {
            printf("%c", campo[i]);
            return 1;
        }
    }
    return 0;
}

int consonante(char campo[])
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
                printf("%c", campo[i]);
                return 1;
            }
            else
            {
                printf("%c", campo[i]);
                return 1;
            }
        }
    }
    if (campo[i - 1] != '\n')
    {
        if (campo[i - 1] == 'A' || campo[i - 1] == 'E' || campo[i - 1] == 'I' || campo[i - 1] == 'O' || campo[i - 1] == 'U')
        {
            campo[i - 1] = 'X';
            printf("%c", campo[i - 1]);
            return 1;
        }
    }
    return 0;
}

int consNombre(char campo[])
{
    int len = strlen(campo);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (campo[i] != 'A' && campo[i] != 'E' && campo[i] != 'I' && campo[i] != 'O' && campo[i] != 'U')
        {
            printf("%c", campo[i]);
            return 1;
        }
    }
    if (campo[i - 1] != '\0')
    {
        if (campo[i - 1] == 'A' || campo[i - 1] == 'E' || campo[i - 1] == 'I' || campo[i - 1] == 'O' || campo[i - 1] != 'U')
        {
            campo[i - 1] = 'X';
            printf("%c", campo[i - 1]);
            return 1;
        }
    }
    return 0;
}

void consCompuesto(char cadena[])
{
    char contra[27][3] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y", "MA.", "MA", "J", "J."};
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
        if (cadena[k] == '.')
        {
            k++;
            k++;
        }

        if (cadena[k] == ' ')
        {
            k++;
        }

        i++;
    }

    if (lugar > 0)
    {
        cons2(cadena, lugar + 1);
    }

    int len = strlen(cadena);
    int b1 = 0;
    int b2 = 0;
    int m = 0;
    char jose[4] = "JOSE";
    char maria[5] = "MARIA";

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
                printf("%c", cadena[i]);
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
                printf("%c", cadena[i]);
                return;
            }
        }
    }

    if (b1 == 1 || b2 == 1)
    {
        int len = strlen(cadena);
        int i = 1;
        for (i = 1; i < len; i++)
        {
            if (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')
            {
                printf("%c", cadena[i]);
                return;
            }
        }
        if (cadena[i - 1] != '\0')
        {
            if (cadena[i - 1] == 'A' || cadena[i - 1] == 'E' || cadena[i - 1] == 'I' || cadena[i - 1] == 'O' || cadena[i - 1] != 'U')
            {
                cadena[i - 1] = 'X';
                printf("%c", cadena[i - 1]);
                return;
            }
        }
    }
}

void apeCompuestoMa(char cadena[], char clave[])
{
    char contra[23][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
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
                lugar += n + 1;
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
        clave[2] = cadena[lugar];
    }
    if (lugar == 0)
    {
        if (cadena[0] == -92 || cadena[0] == -91)
        {
            cadena[0] = 'X';
            clave[2] = cadena[0];
        }
        else
        {
            clave[2] = cadena[0];
        }
    }
}

void nomCompuesto2(char cadena[], char clave[])
{
    char contra[23][4] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
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
        while (l < 19)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n = strlen(contra[l]);
                lugar += n + 1;
            }
            l++;
        }
        if (cadena[k] == ' ')
        {
            k++;
        }

        i++;
    }

    if (lugar > 0)
    {
        clave[3] = cadena[lugar];
    }
    if (lugar == 0)
    {
        if (cadena[0] == -92 || cadena[0] == -91)
        {
            cadena[0] = 'X';
            clave[3] = cadena[0];
        }
        else
        {
            clave[3] = cadena[0];
        }
    }
}

int antisonante(char clave[])
{
    char antisonante[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    int i = 0;
    int j = 0;
    int letra = 0;
    int encontrado;
    do
    {
        encontrado = 0;
        do
        {
            if (clave[j] == antisonante[i][j])
            {
                letra++;
                j++;
            }
            else
            {
                encontrado = 1;
            }

        } while (encontrado == 0 && j < 4);

        if (letra == 4)
        {
            clave[1] = 'X';
            return 1;
        }

        i++;
    } while (encontrado == 1 && i < 81);
    return 0;
}

void nomClave(char cadena[], char clave[], int lugar)
{
    char contra[19][5] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
    char temp[20];
    int i = 0;
    int k = 0;
    int n = 0;
    int l;
    while (cadena[i] != '\0')
    {
        int j = 0;
        while (cadena[k] != ' ' && cadena[k] != '\0')
        {
            temp[j] = cadena[k];
            j++;
            k++;
        }
        temp[j] = '\0';

        for (l = 0; l < 19; l++)
        {
            if (strcmp(temp, contra[l]) == 0)
            {
                n += strlen(temp) + 1;
            }
        }
        k++;
        i++;
    }

    clave[3] = cadena[n + lugar];
}