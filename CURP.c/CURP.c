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
    int estado;

} Tdatos;

/* Prototipo de funciones*/
Tdatos data_curp(void);
void print_curp(Tdatos persona);
/* Funciones auxiliares*/
void cadena(char mnsj[], char destino[]);
int dia_n(int mes, int anio);
int ape(Tdatos persona);
void print_est(int i);

int main()
{
    int op;
    Tdatos persona;
    do
    {
        system("CLS");
        printf("--- Generador de CURP ---\n");
        printf("Quieres generar tu CURP?\n");
        printf("1-Si\n2-No\n");
        op = validar("Ingresa una opcion numerica: ", 1, 2);
        system("CLS");
        if (op == 1)
        {
            persona = data_curp();
            printf("\n");
            print_curp(persona);
            printf("\n");
            system("PAUSE");
        }

    } while (op != 2);
    printf("Gracias por usar el programa. Hasta luego!");

    return 0;
}

Tdatos data_curp(void)
{
    Tdatos humano;
    // nombre
    cadena("Apellido paterno: ", humano.nom.ap_paterno);
    cadena("Apellido materno: ", humano.nom.ap_materno);
    cadena("Nombre: ", humano.nom.nombre);

    // fecha de nacimiento
    humano.nacimiento.anio = validar("Año de nacimiento AAAA: ", 1930, 2023);
    humano.nacimiento.mes = validar("Mes de nacimiento MM:  ", 1, 12);
    humano.nacimiento.dia = dia_n(humano.nacimiento.mes, humano.nacimiento.anio);
    system("CLS");
    // sexo
    humano.sexo = validar("        ----SEXO----\n1-Mujer\n2-Hombre\nIngresa una opcion NUMERICA: ", 1, 2);
    system("CLS");
    // Estado
    printf("   ----ESTADO----\n");
    humano.estado = estados();

    return humano;
}

void print_curp(Tdatos persona)
{

    mayus(persona.nom.ap_paterno);
    mayus(persona.nom.nombre);
    mayus(persona.nom.ap_materno);

    printf("%c", persona.nom.ap_paterno[0]);

    int n;
    do
    {
        n = ape(persona);
    } while (n != 1);

    printf("%c%c", persona.nom.ap_materno[0], persona.nom.nombre[0]);
    printf("%02d%02d%02d", persona.nacimiento.anio % 100, persona.nacimiento.mes, persona.nacimiento.dia);
    if (persona.sexo == 1)
    {
        printf("%s", "M");
    }
    else
    {

        printf("%s", "H");
    }
    if (persona.estado < 32)
    {
        print_est(persona.estado);
    }
    else
    {
        printf("%s","X");
    }
    
}

int ape(Tdatos persona)
{
    int len = sizeof(persona.nom.ap_paterno) / sizeof(persona.nom.ap_paterno[0]);
    for (int i = 1; i < len; i++)
    {
        if (persona.nom.ap_materno[i] == 'a' || 'e' || 'i' || 'o' || 'u')
        {
            printf("%c", persona.nom.ap_paterno[i]);
            return 1;
        }
    }
    return 0;
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

void print_est(int i)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%c", est[i].abre[j]);
    }
}
