#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error en los argumentos\n");
        system("PAUSE");
        return -1;
    }

    FILE *fa;
    int  i = 0;

    fa = fopen("datos.dat", "rb");

    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        long fileSize = ftell(fa);
        i = fileSize / sizeof(Tdatos);
        fclose(fa);
    }
    else
    {
        return 0;
    }

    return i;
}