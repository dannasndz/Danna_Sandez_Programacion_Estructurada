#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Prototipo de funciones */
int numAleatorio(int ri, int rf);
int validar(char mensj[], int ri, int rf);
void mayus(char cadena[]);

char nom_hombre[20][30] = {"SEBASTIAN", "CARLOS", "PEDRO", "LUIS", "MIGUEL", "JAVIER", "ALEJANDRO", "ANDRES", "FERNANDO", "ROBERTO", "CARLOS", "MANUEL", "ANTONIO", "MIGUEL", "ANGEL", "ALEJANDRO", "JOSE", "FELIPE", "JOSE"};
char nom_mujer[20][30] = {"ANA", "MARIA", "SOFIA", "LUISA", "LAURA", "ISABEL", "ELENA", "CARMEN", "CLARA", "PATRICIA", "ISABEL", "JOSE", "VICTORIA", "FERNANDA", "CARMEN", "ELENA", "GABRIELA", "LUISA", "BEATRIZ", "ALEJANDRA"};
char apellido[60][100] = {"SAAVEDRA", "RODRIGUEZ", "LOPEZ", "MARTINEZ", "PEREZ", "FERNANDEZ", "GONZALEZ", "DIAZ", "HERNANDEZ", "TORRES", "GARCIA", "RAMIREZ", "SANCHEZ", "FLORES", "VARGAS", "MENDOZA", "CASTILLO", "ROJAS", "GUTIERREZ", "ORTEGA", "HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "TORRES", "RAMIREZ", "RUIZ", "MORALES", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA"};

/* Desarrollo de funciones  */

int numAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}

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

