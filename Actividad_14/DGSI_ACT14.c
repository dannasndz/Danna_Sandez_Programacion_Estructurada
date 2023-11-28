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
void agregar(Tdatos registro[], int i);
void imprimir(Tdatos registros[], Tindice index[], int i);
void eliminar(Tdatos registros[], Tindice index[], int i, int ord);
void buscar(Tindice index[], Tdatos registros[], int i, int ord);
int ordenar(Tindice index[], int i, int ord);
void archivo_txt(Tindice index[], Tdatos reg[], int i);
void empaquetar(Tdatos registro[], int i);

int crg_bin(Tdatos registro[], Tindice index[], int *i, int N);
int cont_reg(char nomArchivo[]);
void print_ord(Tindice index[], Tdatos registros[], int i);
void print_norm(Tdatos reg[], int i);
void gen_nom_arch(char nom_arch[]);
void gen_arch_ord(char nom[], Tindice index[], Tdatos reg[], int i);
void gen_arch_norm(char nom[], Tdatos reg[], int i);

void merge(Tindice arr[], int l, int m, int r);
int mergeSort(Tindice arr[], int l, int r);
int burbuja(Tindice registro[], int n);

int busq_seq(Tindice index[], int n, int num);
int busq_binaria(Tindice index[], int rf, int key);
int busq_opt(Tindice index[], int n, int key, int flag);

/*********************** Funcion principal **********************/
int main()
{
    srand(time(NULL));
    int op;
    /* datos pal arch */
    int N = cont_reg("datos.dat");
    int i = 0;
    N *= 1.25;
    Tindice indice[N];
    Tdatos registros[N], temp;
    /* cargar archivo BINARIO */
    crg_bin(registros, indice, &i, N);
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
            printf("Persona agregada exitosamente!\n");
            ord = 0;
            break;
        case 2: // eliminar
            eliminar(registros, indice, i, ord);
            break;
        case 3: // buscar
            buscar(indice, registros, i, ord);
            break;
        case 4: // ordenar
            ord = ordenar(indice, i, ord);
            break;
        case 5: // mostrar datos
            imprimir(registros, indice, i);
            break;
        case 6:
            imprimir(registros, indice, i);
            break;
        case 7: // generar archivo de texto
            archivo_txt(indice, registros, i);
            break;
        case 8: // empaquetar
            empaquetar(registros, i);
            break;
        }
        system("PAUSE");
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!");
    return 0;
}

/**************************************** DESARROLLO DE FUNCIONES  ********************************************/
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
    per.cellPhone = numAleatorio(1000000, 1410065);
    estado(per.state);
    job(per.JobPstion);
    return per;
}

void imprimir(Tdatos registros[], Tindice index[], int i)
{
    int op;
    op = validar("1-Ordenado\n2-Normal\nSelecciona una opcion: ", 1, 2);
    system("CLS");
    if (op == 1)
    {
        print_ord(index, registros, i);
    }
    else
    {
        print_norm(registros, i);
    }
}

void archivo_txt(Tindice index[], Tdatos reg[], int i)
{
    char nom[20];
    gen_nom_arch(nom);
    strcat(nom, ".txt");
    int op;
    op = validar("1-Ordenado\n2-Normal\nSelecciona una opcion: ", 1, 2);
    system("CLS");
    if (op == 1)
    {
        strcat(nom, "_ord");
        gen_arch_ord(nom, index, reg, i);
    }
    else
    {
        gen_arch_norm(nom, reg, i);
    }
}

void empaquetar(Tdatos registro[], int i)
{
    FILE *fa;
    char nom[11] = "datos.bak";
    fa = fopen(nom, "wb");
    if (fa)
    {
        for (int j = 0; j < i; j++)
        {
            fwrite(registro, sizeof(Tdatos), 1, fa);
        }

        fclose(fa);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
}

/**************************************** Funciones archivo binario *****************************************/
int cont_reg(char nomArchivo[])
{
    int cont;
    char cmd[50];

    system("mingw32-gcc-6.3.0.exe cont_reg.c -o cont_reg");
    sprintf(cmd, "cont_reg.exe %s ", nomArchivo);
    cont = system(cmd);

    return cont;
}

int crg_bin(Tdatos registro[], Tindice index[], int *i, int N)
{
    FILE *fa;
    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        while (fread(&registro[(*i)], sizeof(Tdatos), 1, fa))
        {
            if ((*i) <= N)
            {
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
        fwrite(&registro[i], sizeof(Tdatos), 1, fa);
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
        printf("Nombre: %s\nApellidos: %s %s\nEdad: %d\nSexo: %s\nEstado: %s\nPuesto: %s\nMatricula: %d\nCelular: %d\n\n", registros[enc].name, registros[enc].LastName1, registros[enc].LastName2, registros[enc].age, registros[enc].sex, registros[enc].state, registros[enc].JobPstion, registros[enc].enrollment, registros[enc].cellPhone);
        op = validar("Desea eliminar el registro?\n1-Si\n2-No\nIngrese una opcion: ", 1, 2);
        system("CLS");
        if (op == 1)
        {
            fa = fopen("datos.dat", "r+b");
            if (fa)
            {
                rewind(fa);
                fseek(fa, sizeof(Tdatos) * index[enc].indice, SEEK_SET);
                fread(&registros[index[enc].indice], sizeof(Tdatos), 1, fa);
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
            printf("Nombre: %s\n Apellidos: %s %s\nEdad: %d\nSexo: %s\nEstado: %s\nPuesto: %s\nMatricula: %d\nCelular: %d\n", registros[index[enc].indice].name, registros[index[enc].indice].LastName1, registros[index[enc].indice].LastName2, registros[index[enc].indice].age, registros[index[enc].indice].sex, registros[index[enc].indice].state, registros[index[enc].indice].JobPstion, registros[index[enc].indice].enrollment, registros[index[enc].indice].cellPhone);
        }
        fclose(fa);
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
        ord= mergeSort(index, 0, i - 1);
    }
    else
    {
        ord = burbuja(index, i);
    }
    return ord;
}

void print_ord(Tindice index[], Tdatos reg[], int i)
{
    FILE *fa;
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No.  | MATRICULA |     NOMBRE     |   APELLIDO P.   |     APELLIDO MAT.     |  EDAD  |   SEXO   |      PUESTO      |      ESTADO      |   CELULAR   \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fa = fopen("datos.dat", "r+b");
    if (fa)
    {
        for (int j = 0; j < i; j++)
        {
            if (reg[j].status == 1)
            {
                rewind(fa);
                fseek(fa, index[j].indice * sizeof(Tdatos), SEEK_SET);
                fread(&reg[index[j].indice], sizeof(Tdatos), 1, fa);
                printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j + 1, reg[j].enrollment, reg[j].name, reg[j].LastName1, reg[j].LastName2, reg[j].age, reg[j].sex, reg[j].JobPstion, reg[j].state, reg[j].cellPhone);
            }
        }
        fclose(fa);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
}

void print_norm(Tdatos reg[], int i)
{
    FILE *fa;
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  No.  | MATRICULA |     NOMBRE     |   APELLIDO P.   |     APELLIDO MAT.     |  EDAD  |   SEXO   |      PUESTO      |      ESTADO      |   CELULAR   \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fa = fopen("datos.dat", "r+b");
    if (fa)
    {
        for (int j = 0; j < i; j++)
        {
            if (reg[j].status == 1)
            {
                fseek(fa, i * sizeof(Tdatos), SEEK_SET);
                fread(&reg[j], i * sizeof(Tdatos), 1, fa);
                printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j + 1, reg[j].enrollment, reg[j].name, reg[j].LastName1, reg[j].LastName2, reg[j].age, reg[j].sex, reg[j].JobPstion, reg[j].state, reg[j].cellPhone);
            }
        }

        fclose(fa);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void gen_nom_arch(char nom_arch[])
{
    do
    {
        system("CLS");
        printf("Nombre del archivo: ");
        fflush(stdin);
        gets(nom_arch);
    } while (strcmp(nom_arch, "\n") == 0);
}

void gen_arch_ord(char nom[], Tindice index[], Tdatos reg[], int i)
{
    FILE *fa;
    fa = fopen(nom, "w");
    if (fa)
    {
        fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No.  | MATRICULA |     NOMBRE     |   APELLIDO P.   |     APELLIDO MAT.     |  EDAD  |   SEXO   |      PUESTO      |      ESTADO      |   CELULAR   \n");
        fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int j = 0; j < i; j++)
        {
            if (reg[j].status == 1)
            {
                fprintf(fa, "%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j + 1, reg[index[j].indice].enrollment, reg[index[j].indice].name, reg[index[j].indice].LastName1, reg[index[j].indice].LastName2, reg[index[j].indice].age, reg[index[j].indice].sex, reg[index[j].indice].JobPstion, reg[index[j].indice].state, reg[index[j].indice].cellPhone);
            }
        }
        printf("Archivo generado con exito\n");
        fclose(fa);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
}

void gen_arch_norm(char nom[], Tdatos reg[], int i)
{
    FILE *fa;

    fa = fopen(nom, "w");

    if (fa)
    {
        fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No.  | MATRICULA |     NOMBRE     |   APELLIDO P.   |     APELLIDO MAT.     |  EDAD  |   SEXO   |      PUESTO      |      ESTADO      |   CELULAR   \n");
        fprintf(fa, "------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int j = 0; j < i; j++)
        {
            if (reg[j].status == 1)
            {
                fprintf(fa, "%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j + 1, reg[j].enrollment, reg[j].name, reg[j].LastName1, reg[j].LastName2, reg[j].age, reg[j].sex, reg[j].JobPstion, reg[j].state, reg[j].cellPhone);
            }
        }
        printf("Archivo generado con exito\n");
        fclose(fa);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
}

/****************************************  Funciones de ordenamiento   ********************************************/

void merge(Tindice arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i].noempleado;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j].noempleado;

    // Fusionar los arreglos temporales de vuelta en arr[l..r]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = l; // Índice inicial del arreglo fusionado
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k].noempleado = L[i];
            i++;
        }
        else
        {
            arr[k].noempleado = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1)
    {
        arr[k].llave = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2)
    {
        arr[k].llave = R[j];
        j++;
        k++;
    }
}

// Función recursiva que implementa el algoritmo Merge Sort
int mergeSort(Tindice arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // Encuentra el punto medio

        // Ordena la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusiona las mitades ordenadas
        merge(arr, l, m, r);
    }
    return 1;
}

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

/****************************************  Funciones de busqueda   *********************************************/

int busq_seq(Tindice index[], int n, int num) 
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