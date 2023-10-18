#include <stdio.h>
#include <stdlib.h>

void leer_archivo(void);
void crear_archivo(void);
void datos(int edad, char nombre[]);

int main()
{
    int op;
    int edad;
    char nombre[20];
    printf("1- Cancion\n");
    printf("2- Art\n");
    printf("3- Ingresar datos\n");
    printf("Ingresa una opcion: ");
    scanf("%d", &op);
    system("CLS");
    switch (op)
    {
    case 1:
        leer_archivo();
        break;
    case 2:
        crear_archivo();
        break;
    case 3:
        printf("Ingresa tu edad: ");
        scanf("%d", &edad);
        printf("\nIngresa tu nombre: ");
        fflush(stdin);
        gets(nombre);
        datos(edad, nombre);
        break;
    }

    return 0;
}

void leer_archivo(void)
{
    FILE *cerati;
    char caract;
    cerati = fopen("C:\\Users\\User\\Desktop\\o.o\\3er SEM\\PE\\Danna_Sandez_Programacion_Estructurada\\Danna_Sandez_Programacion_Estructurada\\Taller\\archivo.txt", "r");
    if (cerati)
    {
        do
        {
            caract = fgetc(cerati);
            printf("%c", caract);

        } while (!feof(cerati));

        fclose(cerati);
    }
}

void crear_archivo(void)
{
    FILE *spinetta;
    char caract;

    spinetta = fopen("arte.txt.", "a");

    if (spinetta)
    {
        spinetta = fopen("C:\\Users\\User\\Desktop\\o.o\\3er SEM\\PE\\Danna_Sandez_Programacion_Estructurada\\Danna_Sandez_Programacion_Estructurada\\Taller\\output\\arte.txt", "r");
        if (spinetta)
        {
            do
            {
                caract = fgetc(spinetta);
                printf("%c", caract);
            } while (!feof(spinetta));
        }
        fclose(spinetta);
    }
}

void datos( int edad, char nombre[])
{
    FILE *charly;
    charly = fopen("datos.txt.", "a");
    if (charly)
    {
        charly = fopen("C:\\Users\\User\\Desktop\\o.o\\3er SEM\\PE\\Danna_Sandez_Programacion_Estructurada\\Danna_Sandez_Programacion_Estructurada\\Taller\\output\\datos.txt", "r++");
        if (charly)
        {
            fprintf(charly, "%-30s    %-30d", nombre, edad);
        }
        fclose(charly);
    }
}