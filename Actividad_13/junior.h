#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int validar(char mensj[], int ri, int rf);
void gen_nom(char nombre[], char sexo[], char apPat[], char apMat[]);
void gen_nom_arch(char nom_arch[]);
int alfabetico(char cadena[]);
void mayus(char cadena[]);

/**** Desarrollo de funciones****/
int validar(char mensj[], int ri, int rf)
{
    int num;
    char cadena[20];
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        if (cadena[0] >= 'a')
        {
            printf("Error\n");
        }
        else
        {
            if (cadena[0] >= 'A')
            {
                printf("Error\n");
            }
            else
            {
                num = atoi(cadena); // cambia a numeros la cadena
            }
        }
    } while (num < ri || num > rf);

    return num; // retorna el valor que haya tomado num, entre los rangos dados por el usuario
}

int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

void gen_nom(char nombre[], char sexo[], char apPat[], char apMat[])
{
    char nom_hombre[20][30] = {"SEBASTIAN", "CARLOS", "PEDRO", "LUIS", "MIGUEL", "JAVIER", "ALEJANDRO", "ANDRES", "FERNANDO", "ROBERTO", "CARLOS", "MANUEL", "ANTONIO", "MIGUEL", "ANGEL", "ALEJANDRO", "JOSE", "FELIPE", "JOSE"};
    char nom_mujer[20][30] = {"ANA", "MARIA", "SOFIA", "LUISA", "LAURA", "ISABEL", "ELENA", "CARMEN", "CLARA", "PATRICIA", "ISABEL", "JOSE", "VICTORIA", "FERNANDA", "CARMEN", "ELENA", "GABRIELA", "LUISA", "BEATRIZ", "ALEJANDRA"};
    char apellido[60][100] = {"SAAVEDRA", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ", "FERNANDEZ", "GONZALEZ", "DIAZ", "HERNANDEZ", "TORRES", "GARCIA", "RAMIREZ", "SANCHEZ", "FLORES", "VARGAS", "MENDOZA", "CASTILLO", "ROJAS", "GUTIERREZ", "ORTEGA", "HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "TORRES", "RAMIREZ", "RUIZ", "MORALES", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA"};
    int sex = numAleatorio(1, 2);
    if (sex == 1)
    {
        strcpy(nombre, nom_mujer[rand() % 19]);
        strcpy(sexo, "MUJER");
    }
    else
    {
        strcpy(nombre, nom_hombre[rand() % 19]);
        strcpy(sexo, "HOMBRE");
    }
    strcpy(apPat, apellido[rand() % 30]);
    strcpy(apMat, apellido[rand() % 30]);
}

int alfabetico(char cadena[])
{
    int i = 0;

    if (cadena[0] == ' ' || cadena[0] == '\0')
    {
        return -1;
    }

    while (cadena[i] != '\0')
    {
        if (!((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] == ' ' && cadena[i + 1] != ' ') || cadena[i] == '/' || cadena[i] == '-' || cadena[i] == '.' || cadena[i] == -92 || cadena[i] == -91 || (unsigned char)cadena[i] == 142 || (unsigned char)cadena[i] == 132 || (unsigned char)cadena[i] == 137 || (unsigned char)cadena[i] == 211 || (unsigned char)cadena[i] == 139 || (unsigned char)cadena[i] == 216 || (unsigned char)cadena[i] == 148 || (unsigned char)cadena[i] == 153 || (unsigned char)cadena[i] == 154 || (unsigned char)cadena[i] == 129 || (unsigned char)cadena[i] == 132 || (unsigned char)cadena[i] == 137 || (unsigned char)cadena[i] == 139 || (unsigned char)cadena[i] == 148 || (unsigned char)cadena[i] == 129 || (unsigned char)cadena[i] == 160 || (unsigned char)cadena[i] == 181 || (unsigned char)cadena[i] == 130 || (unsigned char)cadena[i] == 144 || (unsigned char)cadena[i] == 161 || (unsigned char)cadena[i] == 214 || (unsigned char)cadena[i] == 162 || (unsigned char)cadena[i] == 224 || (unsigned char)cadena[i] == 163 || (unsigned char)cadena[i] == 233 || cadena[i] == 39 || (unsigned char)cadena[i] == 239))
        {
            return -1;
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
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