/*
    Danna Guadalupe Sandez Islas 373080
    21 de noviembre de 2023
    Actividad 14
    SD_ACT14
*/
#include "junior.h"

typedef int Tkey;

typedef struct _indice
{
    Tkey noempleado;
    int indice;
} Tindice;

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

/**************** Prototipo de funciones  ********************/
int mnsj(void);
Tdatos gen_per(void);

int crg_bin(Tdatos registro[], Tindice index[], int *i, int N);
int cont_reg(char nomArchivo[]);
void agregar(Tdatos registro[], int i);
void eliminar(Tdatos registros[], Tindice index[], int i, int ord);
void buscar(Tindice index[], Tdatos registros[], int i, int ord);
void print_ord(Tindice index[], Tdatos registros[], int i);

int busq_seq(Tindice index[], int n, int num);
int busq_binaria(Tindice index[], int rf, int key);
int busq_opt(Tindice index[], int n, int key, int flag);

int burbuja(Tindice registro[], int n);
/*********************** Funcion principal **********************/
int main()
{
    int op;
    /* datos pal arch */
    int N = cont_reg("datos.dat");
    int i = 0;
    N *= 1.25;
    Tindice indice[N];
    Tdatos registros[N], temp;
    /* cargar archivo BINARIO */
    int cargado = 0;
    cargado = crg_bin(registros, indice, &i, N);
    /* banderas */
    int ord;
    do
    {
        system("CLS");
        op = mnsj();
        switch (op)
        {
        case 1: // agregar
            if ((i + 1) <= N)
            {
                temp = gen_per();
                while (busq_opt(indice, i, temp.enrollment, ord) != -1)
                {
                    temp.enrollment = numAleatorio(300000, 399999);
                }
                registros[i] = temp; // agregado a el vector de registro
                indice[i].noempleado = registros[i].enrollment;
                indice[i].indice = i;
                agregar(registros, i); // agregar al binario
                i++;
            }
            ord = 0;
            break;
        case 2: // eliminar
            eliminar(registros, indice, i, ord);
            break;
        case 3: // buscar
            buscar(indice, registros, i, ord);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
    return 0;
}

/************************* Desarrollo de funciones  *******************************/
int mnsj(void)
{
    int op;
    system("CLS");
    printf("   ---- MENU ----\n");
    printf("1- Agregar\n");
    printf("2- Eliminar\n");
    printf("3- Buscar\n");
    printf("4- Ordenar\n");
    printf("5- Imprimir registros archivo original\n");
    printf("6- Imrimir registros archivo ordenado\n");
    printf("7- Generar archivo texto\n");
    printf("8- Empaquetar\n");
    printf("0-  SALIR\n");
    op = validar("Ingresa una opcion numerica: ", 0, 8);
    system("CLS");
    return op;
}

Tdatos gen_per(void)
{
    Tdatos per;
    per.status = 1;
    per.enrollment = numAleatorio(300000, 399999);
    gen_nom(per.name, per.sex, per.LastName1, per.LastName2);
    per.age = numAleatorio(18, 40);
    per.cellPhone = numAleatorio(1000000000, 1410065407);
    estado(per.state);
    job(per.JobPstion);
    return per;
}

/**** funciones archivo binario ****/
int cont_reg(char nomArchivo[])
{
    int cont;
    char cmd[50];

    system("mingw32-gcc-6.3.0.exe cont_reg.c -o cont_reg");
    system("PAUSE");
    sprintf(cmd, "cont_reg.exe %s ", nomArchivo);
    cont = system(cmd);

    return cont;
}

int crg_bin(Tdatos registro[], Tindice index[], int *i, int N)
{
    FILE *fa;
    Tdatos temp;
    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        while (fread(&temp, sizeof(Tdatos), 1, fa))
        {
            if ((*i) <= N)
            {
                registro[(*i)] = temp;
                if (registro[*i].status == 1)
                {
                    index[(*i)].noempleado = registro[(*i)].enrollment;
                    index[(*i)].indice = (*i);
                }
                (*i)++;
            }
        }
        fclose(fa);
        return 1;
    }
    else
    {
        printf("Error al abrir archivo\n");
    }

    return 0;
}

void agregar(Tdatos registro[], int i)
{
    FILE *fa;
    fa = fopen("datos.dat", "ab");
    if (fa)
    {
        fseek(fa, i * sizeof(Tdatos), SEEK_END);
        fwrite(&registro, sizeof(Tdatos), 1, fa);
        fclose(fa);
    }
    else
    {
        printf("Error al agregar datos al archivo\n");
    }
}

void eliminar(Tdatos registros[], Tindice index[], int i, int ord)
{
    int mat, enc, op = 0;
    FILE *fa;
    mat = validar("Matricula a buscar para eliminar: ", 300000, 399999);
    enc = busq_opt(index, i, mat, ord);
    if (enc != -1)
    {
        printf("Nombre: %s\n Apellidos: %s %s\nEdad: %d\nSexo: %s\nEstado: %s\nPuesto: %s\nMatricula: %d\nCelular: %d\n", registros[enc].name, registros[enc].LastName1, registros[enc].LastName2, registros[enc].age, registros[enc].sex, registros[enc].state, registros[enc].JobPstion, registros[enc].enrollment, registros[enc].cellPhone);
        op = validar("Desea eliminar el registro?\n1-Si\n2-No\nIngrese una opcion: ", 1, 2);
        system("CLS");
        if (op == 1)
        {
            fa = fopen("datos.dat", "r+b");
            if (fa)
            {
                fseek(fa, sizeof(Tdatos) * index[enc].indice, SEEK_SET);
                fread(&registros, sizeof(Tdatos), 1, fa);
                registros[enc].status = 0;
                fseek(fa, sizeof(Tdatos) * index[enc].indice, SEEK_SET);
                fwrite(&registros, sizeof(Tdatos), 1, fa);
                printf("Registro eliminado\n");
                fclose(fa);
            }
            else
            {
                printf("Problemas para abrir el archivo\n");
            }
        }
        else
        {
            printf("El registro no se elimino\n");
        }
    }
    else
    {
        printf("Matricula de empleado no encontrado\n");
    }
}

void buscar(Tindice index[], Tdatos registros[], int i, int ord)
{
    int mat, enc;
    FILE *fa;
    mat = validar("Matricula a buscar para mostrar: ", 300000, 399999);
    enc = busq_opt(index, i, mat, ord);
    if (enc != -1)
    {
        fa = fopen("datos.dat", "rb");
        fseek(fa, sizeof(Tdatos) * index[enc].indice, SEEK_SET);
        fread(&registros, sizeof(Tdatos), 1, fa);
        if (registros[enc].status == 1)
        {
            printf("Nombre: %s\n Apellidos: %s %s\nEdad: %d\nSexo: %s\nEstado: %s\nPuesto: %s\nMatricula: %d\nCelular: %d\n", registros[enc].name, registros[enc].LastName1, registros[enc].LastName2, registros[enc].age, registros[enc].sex, registros[enc].state, registros[enc].JobPstion, registros[enc].enrollment, registros[enc].cellPhone);
        }
    }
    else
    {
        printf("Empleado no encontrado\n");
    }
}

int ordenar(Tindice index[], int i, int ord)
{

    if (ord == 1) // ya esta ordenado
    {
        // meterle otro metodo de ordenamiento
    }
    else
    {
        ord = burbuja(index, i);
    }
}

void print_ord(Tindice index[], Tdatos registros[], int i)
{
    FILE *fa;
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No.  | MATRICULA |     NOMBRE     |   APELLIDO P.   |     APELLIDO MAT.     |  EDAD  |   SEXO   |      PUESTO      |      ESTADO      |   CELULAR   \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        for (int j = 0; j < i; j++)
        {
            if (registros[j].status == 1)
            {
                rewind(fa);
                fseek(fa, index[j].indice * sizeof(Tdatos), SEEK_SET);
                fread(&registros, sizeof(Tdatos), 1, fa);
                printf("%d  %d  %s  %s  %s  %d  %s  %s  %s  %d", j + 1, registros[j].enrollment, registros[j].name, registros[j].LastName1, registros[j].LastName2, registros[j].age, registros[j].sex, registros[j].JobPstion, registros[j].state, registros[j].cellPhone); // agregarle otros campos
            }
        }
        fclose(fa);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
}

// funcion de ordenamiento
int burbuja(Tindice registro[], int n)
{
    int i, j;
    Tindice temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (registro[j].noempleado < registro[i].noempleado)
            {
                temp = registro[i];
                registro[i] = registro[j];
                registro[j] = temp;
            }
        }
    }
    return 1;
}

// funciones de busqueda

int busq_seq(Tindice index[], int n, int num) // registro no ordenado
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (index[i].noempleado == num)
        {
            return i;
        }
    }
    // no encontrado
    return -1;
}

int busq_binaria(Tindice index[], int rf, int key)
{
    int ri = 0;
    while (ri <= rf)
    {
        int medium = ri + (rf - ri) / 2;

        // Checa si el numero se encuentra en medio
        if (index[medium].noempleado == key)
        {
            return medium;
        }

        if (index[medium].noempleado < key) // si el numero es mayor ignora el lado izquierdo
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

int busq_opt(Tindice index[], int n, int key, int flag)
{
    int i;

    if (flag)
    {
        i = busq_binaria(index, n, key);
    }
    else
    {
        i = busq_seq(index, n, key);
    }

    return i;
}
