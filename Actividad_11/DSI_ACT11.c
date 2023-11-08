#include "puente.h"
#include "fantasma.h"

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
    char estado[30];
    int sexo;
    int edad;
    int matricula;
    int status;
    char curp[18];
} Tdatos;

/* prototipo de funciones */
Tdatos manual(void);
Tdatos autom(void);
Tdatos genCurp(Tdatos p, char cadena[]);
void print_reg(Tdatos registro[], int j);
void arch(Tdatos registro[], int n);
/* funciones auxiliares*/
int busq_seq(Tdatos registro[], int n, int num);
int busq_binaria(Tdatos registro[], int ri, int rf, int matricula);
int ordenar(Tdatos registro[], int n);
int quicksort(Tdatos students[], int low, int high);
int partition(Tdatos students[], int low, int high);
void swap(Tdatos students[], int i, int j);

int main()
{
    srand(time(NULL));
    Tdatos registro[2000], persona;
    int op, mat, encontrado, ordenado, op2;
    int k = 0, i = 0;
    do
    {
        system("CLS");
        printf(" ---- MENU ----\n");
        printf("1- Agregar (manual)\n");
        printf("2- Agregar (automatico)\n");
        printf("3- Eliminar registro\n");
        printf("4- Buscar\n");
        printf("5- Ordenar\n");
        printf("6- Imprimir\n");
        printf("7- Archivo de texto\n");
        printf("0- SALIR\n");
        op = validar("Ingresa una opcion NUMERICA: ", 0, 7);
        system("CLS");

        switch (op)
        {
        case 1: // agregar 1 registro manualmente
            if (k < 2000)
            {
                persona = manual();
                while (busq_seq(registro, i, persona.matricula) != -1) // validar la matricula
                {
                    persona.matricula = validar("Por favor ingresa otra matricula: ", 30000, 399999);
                }
                registro[i++] = persona; // agregar la variable tipo Tdatos al registro
                k++;                     // contador para numero de registros creados
                printf("Registro lleno con exito!\n");
            }
            else
            {
                printf("El registro llego a su maxima capacidad\n");
            }
            ordenado = 0; // bandera para saber si el registro esta ordenado
            system("PAUSE");
            break;
        case 2: // agergar automatico
            if (k < 2000)
            {
                for (int j = 0; j < 100; j++)
                {
                    persona = autom();
                    while (busq_seq(registro, i, persona.matricula) != -1) // evaluar si la matricula se repite
                    {
                        persona.matricula = numAleatorio(30000, 399999);
                    }
                    registro[i++] = persona;
                    k++;
                }
                printf("Registro lleno exitosamente con 100 personas!\n");
            }
            else
            {
                printf("El registro llego a su maxima capacidad\n");
            }
            ordenado = 0;
            system("PAUSE");
            break;
        case 3: // eliminar
            mat = validar("Ingrese matricula para eliminar: ", 300000, 399999);
            system("CLS");
            if (ordenado == 1)
            {
                encontrado = busq_binaria(registro, 300000, 399999, mat);
                if (encontrado != -1)
                {
                    printf("MATRICULA: %d\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nFECHA DE NACIMIENTO: %02d/%02d/%d\nEDAD: %d\nSEXO: %s\nLUGAR DE NACIMIENTO: %s\nCURP: %s\n", registro[encontrado].matricula, registro[encontrado].nom.nombre, registro[encontrado].nom.ap_paterno, registro[encontrado].nom.ap_materno, registro[encontrado].nacimiento.dia, registro[encontrado].nacimiento.mes, registro[encontrado].nacimiento.anio, registro[encontrado].edad, (registro[encontrado].sexo == 1 ? "M" : "H"), registro[encontrado].estado, registro[encontrado].curp);
                    printf("\n\n1nDeseas eliminar al usuario %d?", registro[encontrado].matricula);
                    op2 = validar("\n1-Si\n2-No\n", 1, 2);
                    system("CLS");
                    if (op2 == 1)
                    {
                        registro[encontrado].status = 0; // desactivar status
                        printf("La matricula ahora es inactiva\n");
                    }
                }
                else
                {
                    printf("La matricula no se encuentra en el registro\n");
                }
            }
            else
            {
                encontrado = busq_seq(registro, i, mat);
                if (encontrado != -1) // si se encuentra la matricula en los registros
                {
                    printf("MATRICULA: %d\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nFECHA DE NACIMIENTO: %02d/%02d/%d\nEDAD: %d\nSEXO: %s\nLUGAR DE NACIMIENTO: %s\nCURP: %s\n", registro[encontrado].matricula, registro[encontrado].nom.nombre, registro[encontrado].nom.ap_paterno, registro[encontrado].nom.ap_materno, registro[encontrado].nacimiento.dia, registro[encontrado].nacimiento.mes, registro[encontrado].nacimiento.anio, registro[encontrado].edad, (registro[encontrado].sexo == 1 ? "M" : "H"), registro[encontrado].estado, registro[encontrado].curp);
                    printf("\n\n1nDeseas eliminar al usuario %d?", registro[encontrado].matricula);
                    op2 = validar("\n1-Si\n2-No\n", 1, 2);
                    system("CLS");
                    if (op2 == 1)
                    {
                        registro[encontrado].status = 0; // desactivar status
                        printf("La matricula ahora es inactiva\n");
                    }
                }
                else
                {
                    printf("La matricula no se encuentra en el registro\n");
                }
            }
            system("PAUSE");
            break;
        case 4: // buscar
            mat = validar("Ingrese una matricula para buscar: ", 300000, 399999);
            system("CLS");
            if (ordenado == 1)
            {
                encontrado = busq_binaria(registro, 300000, 399999, mat);
                if (encontrado != -1) // si se encuentra
                {
                    if (registro[encontrado].status == 0)
                    {
                        printf("Matricula inactiva\n");
                    }
                    else
                    {
                        printf("MATRICULA: %d\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nFECHA DE NACIMIENTO: %02d/%02d/%d\nEDAD: %d\nSEXO: %s\nLUGAR DE NACIMIENTO: %s\nCURP: %s\n", registro[encontrado].matricula, registro[encontrado].nom.nombre, registro[encontrado].nom.ap_paterno, registro[encontrado].nom.ap_materno, registro[encontrado].nacimiento.dia, registro[encontrado].nacimiento.mes, registro[encontrado].nacimiento.anio, registro[encontrado].edad, (registro[encontrado].sexo == 1 ? "M" : "H"), registro[encontrado].estado, registro[encontrado].curp);
                    }
                }
                else // no se encuentra
                {
                    printf("La matricula no se encuentra en el registro\n");
                }
            }
            else
            {
                encontrado = busq_seq(registro, i, mat);
                if (encontrado != -1) // si se encuentra la matricula en los registros
                {
                    if (registro[encontrado].status == 0) // alumno con status inactivo. NO HAY MATRICULA
                    {
                        printf("Matricula inactiva\n");
                    }
                    else // alumno activo, SI hay matricula
                    {
                        printf("MATRICULA: %d\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nFECHA DE NACIMIENTO: %02d/%02d/%d\nEDAD: %d\nSEXO: %s\nLUGAR DE NACIMIENTO: %s\nCURP: %s\n", registro[encontrado].matricula, registro[encontrado].nom.nombre, registro[encontrado].nom.ap_paterno, registro[encontrado].nom.ap_materno, registro[encontrado].nacimiento.dia, registro[encontrado].nacimiento.mes, registro[encontrado].nacimiento.anio, registro[encontrado].edad, (registro[encontrado].sexo == 1 ? "M" : "H"), registro[encontrado].estado, registro[encontrado].curp);
                    }
                }
                else // no se encuentra la matricula
                {
                    printf("La matricula que buscas no se encuentra en el registro\n");
                }
            }
            system("PAUSE");
            break;
        case 5: // ordenar
            if (ordenado == 1)
            {
                printf("Registro ya se encuentra ordenado\n");
            }
            else
            {
                if (i <= 500)
                {
                    ordenado = ordenar(registro, i); // ordenas registro
                }
                else
                {
                    ordenado= quicksort(registro, 0, i - 1);
                }
                printf("Registro ordenado\n");
            }
            system("PAUSE");
            break;
        case 6: // imprimir
            print_reg(registro, i);
            break;
        case 7: // archivo de texto
            arch(registro, i);
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
    return 0;
}

Tdatos autom(void)
{
    Tdatos persona;
    persona.status = 1;
    persona.matricula = numAleatorio(300000, 399999);
    strcpy(persona.nom.ap_paterno, apellido[rand() % 99]);
    mayus(persona.nom.ap_paterno);
    strcpy(persona.nom.ap_materno, apellido[rand() % 99]);
    mayus(persona.nom.ap_materno);
    int sex, num_nom;
    sex = numAleatorio(1, 2);
    num_nom = numAleatorio(1, 2);
    if (sex == 1) // mujer
    {
        if (num_nom == 1)
        {
            strcpy(persona.nom.nombre, nom_mujer[rand() % 19]);
        }
        else
        {
            strcpy(persona.nom.nombre, nom_mujer[rand() % 19]);
            strcat(persona.nom.nombre, " ");
            strcat(persona.nom.nombre, nom_mujer[rand() % 19]);
        }
        persona.sexo = 1;
    }
    else
    {
        if (num_nom == 1)
        {
            strcpy(persona.nom.nombre, nom_hombre[rand() % 19]);
        }
        else
        {
            strcpy(persona.nom.nombre, nom_hombre[rand() % 19]);
            strcat(persona.nom.nombre, " ");
            strcat(persona.nom.nombre, nom_hombre[rand() % 19]);
        }
        persona.sexo = 2;
    }
    mayus(persona.nom.nombre);
    persona.edad = numAleatorio(17, 50);
    strcpy(persona.estado, est_ados[rand() % 32]);
    persona.nacimiento.dia = numAleatorio(1, 28);
    persona.nacimiento.mes = numAleatorio(1, 12);
    persona.nacimiento.anio = numAleatorio(1990, 2010);
    genCurp(persona, persona.curp);

    return persona;
}

Tdatos genCurp(Tdatos p, char cadena[])
{
    Tdatos persona;
    persona = p;
    int apComp1 = 0;
    int apComp2 = 0;
    int nomComp = 0;
    // hace mayusuclas los nombres
    mayus(persona.nom.ap_paterno);
    mayus(persona.nom.nombre);
    mayus(persona.nom.ap_materno);

    // saber si tiene apellido compuesto
    if (strlen(persona.nom.ap_paterno) != 0)
    {
        if (nomCompuesto(persona.nom.ap_paterno) == 1) // tiene ap compuesto
        {
            apComp1 = 1;
            carctEspecial(persona.nom.ap_paterno, cadena);
            enie(persona.nom.ap_paterno);
            dieresis(persona.nom.ap_paterno);
            apeCompuesto(persona.nom.ap_paterno, cadena);
        }
        else // no tiene apellido compuesto
        {
            ape(persona.nom.ap_paterno, cadena);
        }
    }
    else
    {
        cadena[0] = 'X';
        cadena[1] = 'X';
    }

    // imprimir letra inicial del segundo apellido
    if (strlen(persona.nom.ap_materno) != 0) // checa si tiene apellido materno
    {
        if (nomCompuesto(persona.nom.ap_materno) == 1) // tiene ap compuesto
        {
            apComp2 = 1;
            carctEspecial(persona.nom.ap_materno, cadena);
            enie(persona.nom.ap_materno);
            dieresis(persona.nom.ap_materno);
            apeCompuestoMa(persona.nom.ap_materno, cadena);
        }
        else // no tiene ap compuesto
        {
            apeMa(persona.nom.ap_materno, cadena);
        }
    }
    else
    {
        cadena[2] = 'X';
    }

    if (nomCompuesto(persona.nom.nombre) == 1) // tiene nombre compuesto
    {
        nomComp = 1;
        enie(persona.nom.nombre);
        dieresis(persona.nom.nombre);
        mariajose(persona.nom.nombre, cadena);
    }
    else
    {
        carctEspecial(persona.nom.nombre, cadena);
        enie(persona.nom.nombre);
        dieresis(persona.nom.nombre);
        cadena[3] = persona.nom.nombre[0];
    }

    // imprimir fecha de nacimiento
    sprintf(cadena + 4, "%02d", persona.nacimiento.anio % 100);
    sprintf(cadena + 6, "%02d", persona.nacimiento.mes);
    sprintf(cadena + 8, "%02d", persona.nacimiento.dia);

    // imprimir sexo
    if (persona.sexo == 1)
    {
        cadena[10] = 'M';
    }
    else
    {
        cadena[10] = 'H';
    }

    // imprimir estado
    if (strlen(persona.estado) != 0)
    {
        estado(persona.estado, cadena, 11);
    }
    else
    {
        cadena[11] = 'N';
        cadena[12] = 'E';
    }
    // imprimir consonantes del apellido paterno

    if (strlen(persona.nom.ap_paterno) != 0)
    {
        if (apComp1 == 1) // primer apellido
        {                 // el appelido es compuesto
            cons_compuesto(persona.nom.ap_paterno, cadena, 13);
        }
        else
        {
            cons(persona.nom.ap_paterno, cadena, 13);
        }
    }
    else
    {
        cadena[13] = 'X';
    }
    // imprimir consonante de apellido materno
    if (strlen(persona.nom.ap_materno) != 0)
    {
        if (apComp2 == 1) // materno
        {
            cons_compuesto(persona.nom.ap_materno, cadena, 14);
        }
        else
        {
            cons(persona.nom.ap_materno, cadena, 14);
        }
    }
    else // no tiene apellido materno
    {
        cadena[14] = 'X';
    }
    // imprimir primer consonante del nombre
    if (nomComp == 1) // nombre
    {
        cons_compuesto(persona.nom.nombre, cadena, 15);
    }
    else
    {
        cons(persona.nom.nombre, cadena, 15);
    }

    // imprimir diferenciador de nacimiento
    if (persona.nacimiento.anio <= 1999)
    {
        cadena[16] = '0';
    }
    else
    {
        cadena[16] = 'A';
    }

    // imprimir digito verificador
    int num = numAleatorio(0, 9);
    sprintf(cadena + 17, "%d", num);

    // verificar si es una clave antisonante
    antisonante(cadena);

    strcpy(cadena, cadena);

    return persona;
}

Tdatos manual(void)
{
    Tdatos humano;

    int op = 0;
    int op2 = 0;
    humano.status = 1;
    humano.matricula = validar("Matricula: ", 300000, 399999);
    system("PAUSE");
    system("CLS");

    // nombre
    op = validar("Tienes apellido paterno?\n1-Si\n2-No\nIngresa una opcion: ", 1, 2);
    system("CLS");
    if (op == 1)
    {
        cadena("Apellido paterno: ", humano.nom.ap_paterno);
    }
    else
    {
        noAP(humano.nom.ap_paterno);
    }

    system("CLS");

    op2 = validar("Tienes apellido materno?\n1-Si\n2-No\nIngresa una opcion: ", 1, 2);
    system("CLS");
    if (op2 == 1)
    {
        cadena("Apellido materno: ", humano.nom.ap_materno);
    }
    else
    {
        noAP(humano.nom.ap_materno);
    }

    system("CLS");

    cadena("Nombre: ", humano.nom.nombre);
    // fecha de nacimiento
    humano.nacimiento.anio = validar("Año de nacimiento AAAA: ", 1893, 2023);
    system("CLS");
    if (humano.nacimiento.anio == 2023)
    {
        humano.nacimiento.anio = validar("Mes de nacimiento MM: ", 1, 10);
    }
    else
    {
        humano.nacimiento.mes = validar("Mes de nacimiento MM:  ", 1, 12);
    }

    humano.nacimiento.dia = dia_n(humano.nacimiento.mes, humano.nacimiento.anio);
    // edad
    humano.edad = validar("Edad: ", 10, (2023 - humano.nacimiento.anio));
    system("CLS");
    // sexo
    humano.sexo = validar("        ----SEXO----\n1-Mujer\n2-Hombre\nIngresa una opcion NUMERICA: ", 1, 2);
    system("CLS");
    // Estado
    printf("   ----ESTADO----\n");
    estadox(humano.estado, humano.curp, 11);
    system("CLS");
    genCurp(humano, humano.curp);

    return humano;
}

void print_reg(Tdatos registro[], int j)
{
    int i, k, l = 0;
    printf("No.                 MATRICULA                 NOMBRE(S)               APELLIDO PATERNO                APELLIDO MATERNO             FECHA DE NACIMIENTO               EDAD                 SEXO               LUAGR NAC                       CURP\n\n");
    for (i = 0; i < j; i++)
    {
        k = 0;
        while (k < 40)
        {
            if (registro[l].status == 1)
            {
                printf("%-18d   %-20d   %-23s   %-29s   %-26s   %02d/%02d/%-26d   %-18d   %-15s   %-23s   %-5s\n", l + 1, registro[l].matricula, registro[l].nom.nombre, registro[l].nom.ap_paterno, registro[l].nom.ap_materno, registro[l].nacimiento.dia, registro[l].nacimiento.mes, registro[l].nacimiento.anio, registro[l].edad, (registro[l].sexo == 1 ? "M" : "H"), registro[l].estado, registro[l].curp);
            }
            l++;
            k++;
        }
        i += 40;
        system("PAUSE");
    }
}

int busq_seq(Tdatos registro[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (registro[i].matricula == num)
        {
            return i;
        }
    }
    return -1;
}

int busq_binaria(Tdatos registro[], int ri, int rf, int matricula)
{
    while (ri <= rf)
    {
        int medium = ri + (rf - ri) / 2;

        // Checa si el numero se encuentra en medio
        if (registro[medium].matricula == matricula)
        {
            return medium;
        }

        if (registro[medium].matricula < matricula) // si el numero es mayor ignora el lado izquierdo
        {
            ri = medium + 1;
        }
        else // si el numero es menor, ignora el lado derecho
        {
            rf = medium - 1;
        }
    }
    // el numero no se encuentra
    return -1;
}

int ordenar(Tdatos registro[], int n)
{
    int i, j;
    Tdatos temporal;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (registro[j].matricula < registro[i].matricula)
            {
                temporal = registro[i];
                registro[i] = registro[j];
                registro[j] = temporal;
            }
        }
    }
    return 1;
}

void arch(Tdatos registro[], int n)
{
    int l;
    FILE *fa;
    fa = fopen("C:\\Users\\User\\Desktop\\o.o\\3er SEM\\PE\\Danna_Sandez_Programacion_Estructurada\\Danna_Sandez_Programacion_Estructurada\\Actividad_11\\output\\registros.txt", "w");
    fprintf(fa, "No.                 MATRICULA                 NOMBRE(S)               APELLIDO PATERNO                APELLIDO MATERNO             FECHA DE NACIMIENTO               EDAD                 SEXO               LUAGR NAC                       CURP\n\n");
    for (l = 0; l < n; l++)
    {
        if (registro[l].status == 1)
        {
            fprintf(fa, "%-18d   %-20d   %-23s   %-29s   %-26s   %02d/%02d/%-26d   %-18d   %-15s   %-23s   %-5s\n", l + 1, registro[l].matricula, registro[l].nom.nombre, registro[l].nom.ap_paterno, registro[l].nom.ap_materno, registro[l].nacimiento.dia, registro[l].nacimiento.mes, registro[l].nacimiento.anio, registro[l].edad, (registro[l].sexo == 1 ? "M" : "H"), registro[l].estado, registro[l].curp);
        }
    }

    printf("Archivo escrito con exito\n");
    fclose(fa);
}

//**** FUNCTIONS FOR QUICKSORT ***
void swap(Tdatos students[], int i, int j)
{
    Tdatos temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(Tdatos students[], int low, int high)
{
    Tdatos pivot;
    pivot.matricula = students[high].matricula;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].matricula <= pivot.matricula)
        {
            i++;
            swap(students, i, j);
        }
    }
    swap(students, i + 1, high);
    return i + 1;
}

int quicksort(Tdatos students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);

        quicksort(students, low, pi - 1);
        quicksort(students, pi + 1, high);
    }
    return 1;
}