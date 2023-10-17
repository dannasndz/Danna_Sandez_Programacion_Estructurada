
#include "puente.h"

typedef struct _nombre
{
    char ap_paterno[50];
    char ap_materno[50];
    char nombre[50];
} Tnombre;

typedef struct _fecha
{
    int mes;
    int dia;
    int anio;
} Tfecha;

typedef struct _datos
{
    Tnombre nom;
    Tfecha nacimiento;
    int sexo;
    char estado[40];

} Tdatos;

Tdatos data_curp(void);
int dia_n(int mes, int anio);

int main()
{
    int op;
    do
    {
        system("CLS");
        printf("--- Generador de CURP ---\n");
        printf("¿Quieres generar tu CURP?\n");
        printf("1-Si\n2-No\n");
        op = validar("Ingresa una opcion numerica: ", 1, 2);
        system("CLS");
        if (op == 1)
        {
            data_curp();
        }

    } while (op != 2);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

Tdatos data_curp(void)
{
    Tdatos humano;
    char ape1[50], ape2[50], nom[50];
    int dia, mes, anio;
    int sexo;
    int op = 0;
    do // apellido paterno
    {
        printf("Apellido paterno: ");
        fflush(stdin);
        gets(ape1);
        strcpy(humano.nom.ap_paterno, ape1);
        op = alfabetico(ape1);
        system("PAUSE");
        system("CLS");
    } while (op != 1);
    mayus(ape1);

    do // apellido materno
    {
        printf("Apellido materno: ");
        fflush(stdin);
        gets(ape2);
        strcpy(humano.nom.ap_materno, ape2);
        op = alfabetico(ape2);
        system("PAUSE");
        system("CLS");
    } while (op != 1);
    mayus(ape2);

    do // nombre
    {
        printf("Nombre: ");
        fflush(stdin);
        gets(nom);
        strcpy(humano.nom.nombre, nom);
        op = alfabetico(nom);
        system("PAUSE");
        system("CLS");

    } while (op != 1);
    mayus(nom);

    // fecha de nacimiento
    anio = validar("Año de nacimiento AAAA: ", 1900, 2023);
    humano.nacimiento.anio = anio;
    system("CLS");
    mes = validar("Mes de nacimiento MM:  ", 1, 12);
    humano.nacimiento.mes = mes;
    system("CLS");
    dia = dia_n(mes, anio);
    humano.nacimiento.dia = dia;
    system("CLS");
    
    //sexo
    sexo=validar("Sexo\n1-M\n2-H\n",1,2);
    humano.sexo=sexo;
    system("CLS");

    // Estado
    
}

int dia_n(int mes, int anio)
{
    int diasEnMes;

    switch (mes)
    {
    case 2:
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            diasEnMes = 29;
        }
        else
        {
            diasEnMes = 28;
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        diasEnMes = 30;
        break;

    default:
        diasEnMes = 31;
        break;
    }

    return validar("Dia de nacimiento DD: ", 1, diasEnMes);
}
