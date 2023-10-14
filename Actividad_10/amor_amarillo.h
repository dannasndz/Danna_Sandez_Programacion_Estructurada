
/* Librerias */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* prototipo de funciones */
int numAleatorio(int ri, int rf);
int validar(char mensj[], int ri, int rf);
void mayus(char cadena[]);

/* cadenas de nombres */
char nom_hombre[20][30] = {"Juan", "Carlos", "Pedro", "Luis", "Miguel", "Javier", "Alejandro", "Andres", "Fernando", "Roberto", "Carlos", "Manuel", "Antonio", "Miguel", "Angel", "Alejandro", "Jose", "Felipe", "Jose"};
char nom_mujer[20][30] = {"Ana", "Maria", "Sofia", "Luisa", "Laura", "Isabel", "Elena", "Carmen", "Clara", "Patricia", "Isabel", "Jose", "Victoria", "Fernanda", "Carmen", "Elena", "Gabriela", "Luisa", "Beatriz", "Alejandra"};
char ape[104][100] = {"Gomez", "Rodriguez", "Lopez", "Martinez", "Perez", "Fernandez", "Gonzalez", "Diaz", "Hernandez", "Torres", "Garcia", "Ramirez", "Sanchez", "Flores", "Vargas", "Mendoza", "Castillo", "Rojas", "Gutierrez", "Ortega","Haro", "Solano", "Sandez", "Lopez", "Meza", "Perez", "torres", "ramirez", "ruiz", "morales","jimenez", "soto", "herrera", "delgado", "castro", "rios", "medina", "vargas", "mendoza", "reyes", "blanco", "navarro", "guzman", "romero", "ortega", "jimenez", "soto", "herrera", "delgado", "castro", "rios", "medina", "silva", "castro", "rios", "montoya", "pena", "vidal", "aguilar", "cordero", "mora", "sosa", "rosales", "lugo", "serrano", "caceres", "robles", "salazar", "leon", "gallegos", "cordova", "del valle", "navarro", "paredes", "zamora", "valdez", "duran", "cisneros", "gutierrez", "salinas", "avila", "rivas", "pizarro", "guerra", "espinoza", "calderon", "pantoja", "miranda", "rojas", "segura", "villanueva", "roldan", "benitez", "luna", "valencia", "cervantes", "Escobar","Zuniga","barrios"};


/* desarrollo de funciones */
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

