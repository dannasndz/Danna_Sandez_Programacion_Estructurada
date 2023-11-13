#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error en los argumentos\n");
        system("PAUSE");
        return -1;
    }

    FILE *fa;
    char nomArchivo[30];
    char linea[90];
    int cont = 0;
    int status = atoi(argv[2]);

    strcpy(nomArchivo, argv[1]);

    if (status == 1)
    {
        strcat(nomArchivo, "_activos.txt");
    }
    else
    {
        strcat(nomArchivo, "_eliminados.txt");
    }
    fa = fopen(nomArchivo, "r");

    if (fa)
    {
        while (!feof(fa))
        {
            fgets(linea, 90, fa);
            if (strlen(linea) > 10)
            {
                cont++;
            }
        }
        fclose(fa);
    }
    else
    {
        return 0;
    }

    return cont;
}