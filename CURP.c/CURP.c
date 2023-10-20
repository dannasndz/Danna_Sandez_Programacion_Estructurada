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
int ape(char campo[]);
void print_est(int i);
int consonante(char campo[]);
void enie(char campo[]);
void carctEspecial(char campo[]);
void apeMa(char campo[]);

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

/* Desarrollo de funciones */

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
    // hace mayusuclas los nombres
    mayus(persona.nom.ap_paterno);
    mayus(persona.nom.nombre);
    mayus(persona.nom.ap_materno);
    // imprime la primer letra del apellido y la siguiente vocal, ya se valida enie aki
    ape(persona.nom.ap_paterno);
    // imprime la primer letra del apellido materno y valida enie
    apeMa(persona.nom.ap_materno);
    // enie(persona.nom.ap_materno);
    //  nombre
    if (nomCompuesto(persona.nom.nombre) == 1)
    {
        // aki verifico si no se llama maria, jose, etc y tengo que cambiar la tercer posicion por la inicial del segundo nombre
        mariajose(persona.nom.nombre);
    }
    else
    {
        carctEspecial(persona.nom.nombre);
        enie(persona.nom.nombre);
    }
    // anio de nacimiento
    printf("%02d%02d%02d", persona.nacimiento.anio % 100, persona.nacimiento.mes, persona.nacimiento.dia);

    ////////////
    if (persona.sexo == 1)
    {
        printf("%s", "M");
    }
    else
    {
        printf("%s", "H");
    }
    if (persona.estado < 33)
    {
        print_est(persona.estado);
    }
    else
    {
        printf("%s", "X");
    }
    do
    {
    } while (consonante(persona.nom.ap_paterno) != 1);

    do
    {
    } while (consonante(persona.nom.ap_materno) != 1);

    do
    {
    } while (consonante(persona.nom.nombre) != 1);
    if (persona.nacimiento.anio <= 1999)
    {
        printf("%d", 0);
    }
    else
    {
        printf("%s", "A");
    }

    printf("%d", numAleatorio(0, 9));
 
}

/* Desarrollo de funciones auxiliares */

int ape(char campo[])
{
    int len = strlen(campo);
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        printf("%c", campo[0]);
    }
    else
    {
        carctEspecial(campo);
        printf("%c", campo[0]);
    }

    for (int i = 1; i < len; i++)
    {
        if (campo[i] == 'a' || 'e' || 'i' || 'o' || 'u')
        {
            printf("%c", campo[i]);
            return 1;
        }
    }

    return 0;
}

void apeMa(char campo[])
{
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        printf("%c", campo[0]);
    }
    else
    {
        carctEspecial(campo);
        printf("%c", campo[0]);
    }
}

int consonante(char campo[])
{
    int len = strlen(campo);
    for (int i = 1; i < len; i++)
    {
        if (campo[i] != 'a' && campo[i] != 'e' && campo[i] != 'i' && campo[i] != 'o' && campo[i] != 'u' && campo[i] != 'A' && campo[i] != 'E' && campo[i] != 'I' && campo[i] != 'O' && campo[i] != 'U')
        {
            printf("%c", campo[i]);
            return 1;
        }
    }
    return 0;
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

void enie(char campo[])
{
    if (campo[0] == -92 || campo[0] == -91)
    {
        campo[0] = 'X';
        printf("%c", campo[0]);
    }
    else
    {
        printf("%c", campo[0]);
    }
}

void carctEspecial(char campo[])
{
    for (int i = 0; i < 2; i++)
    {
        if (campo[i] == '/' || campo[i] == '-' || campo[i] == '.')
        {
            campo[i] = 'X';
           
        }
    }
}