/*
    Danna Sandez Islas 373080
    13 de noviembre de 2023
    Actividad 13
    SD_ACT13
*/

#include "junior.h"

typedef long Tkey;
typedef struct _datos
{
    Tkey key;
    int status;
    char ap_pat[40];
    char ap_mat[40];
    char nom[40];
    int edad;
    char sexo[20];
} Tdatos;

/*** Prototipo de funciones ***/
int mnsj(void);
Tdatos gen_per(void);
void buscar(Tdatos registro[], int i, int flag);
void eliminar(Tdatos registro[], int i, int flag, char nom_arch[20]);
void editar(Tdatos registro[], int i, int flag, char nom_bin[]);
void cambiar(int op, Tdatos registro[], int i, int flag);

int busq_binaria(Tdatos registro[], int rf, int mat);
int busq_seq(Tdatos registro[], int n, int num);
int busq_opt(Tdatos refistro[], int n, int mat, int flag);

int burbuja(Tdatos registro[], int n);
int quickSort(Tdatos vect[], int n);
void qs(Tdatos vect[], int limite_izq, int limite_der);
int ordOpt(Tdatos registro[], int n);

void gen_nom_arch(char nom_arch[]);
void gen_arch(char nomArchivo[], Tdatos vect[], int n);
void imprimir(Tdatos vect[], int n, int status);
int carg_arch(char nomArchivo[], Tdatos registro[], int *n);
void mostrar_arch(Tdatos vect[], int n, char nom_arch[]);

int gen_arch_bin(Tdatos registro[], int n, char nom_bin[]);
void respaldo(char nom[]);
int cargar_bin(Tdatos registro[], int *i, int max, char nom[]);
void act_arch(Tdatos registro[], int i, char nom_arch[]);

#define N 5000

/*** Funcion principal ***/
int main()
{
    Tdatos registro[N], empleado;
    int op;
    int i = 0, ord = 0, carg = 0;
    char nom_arch[20], nom_bin[20];
    srand(time(NULL));
    do
    {
        system("CLS");
        op = mnsj();
        switch (op)
        {
        case 1: /* agregar empleados al registro */
            if ((i + 100) <= N)
            {
                for (int j = 0; j < 100; j++)
                {
                    empleado = gen_per();
                    while (busq_opt(registro, i, empleado.key, ord) != -1)
                    {
                        empleado.key = numAleatorio(300000, 399999);
                    }
                    registro[i++] = empleado;
                }
                printf("100 empleados agregados exitosamente!\n");
            }
            else
            {
                printf("Registro lleno\n");
            }
            ord = 0;
            break;
        case 2: /* editar el registro de empleados  */
            editar(registro, i, ord, nom_bin);
            break;
        case 3: /* eliminar empleado del registro */
            eliminar(registro, i, ord, nom_bin);
            break;
        case 4: /* buscar empleado */
            buscar(registro, i, ord);
            break;
        case 5: /* ordenar registros */
            if (ord == 1)
            {
                printf("El registro ya se encuentra ordenado\n");
            }
            else
            {
                ord = ordOpt(registro, i);
                printf("Ordenado\n");
                system("PAUSE");
                system("CLS");
                act_arch(registro, i, nom_bin);
            }
            break;
        case 6: /* imprimir registros  */
            imprimir(registro, i, 1);
            break;
        case 7: /* generar archivo de texto */
            gen_nom_arch(nom_arch);
            gen_arch(nom_arch, registro, i); // empleados activos
            printf("Tarea realizada exitosamente!\n");
            break;
        case 8: /* mostrar archivo de texto */
            mostrar_arch(registro, i, nom_arch);
            break;
        case 9: /* crear archivo binario */
            gen_nom_arch(nom_bin);
            gen_arch_bin(registro, i, nom_bin);
            respaldo(nom_bin);
            printf("Tarea realizada exitosamente!\n");
            break;
        case 10: /* cargar archivo binario */
            if (carg)
            {
                printf("El archivo ya se encuentra cargado\n");
            }
            else
            {
                carg = cargar_bin(registro, &i, N, nom_bin);
            }
            break;
        case 11: /*mostrar borrados */
            imprimir(registro, i, 0);
            break;
        }
        system("PAUSE");
    } while (op != 0);
    system("CLS");
    printf("Gracias por usar el programa. Hasta luego!\n");

    return 0;
}

/*** Desarrollo de funciones ***/
int mnsj(void)
{
    int op;
    system("CLS");
    printf("     ---- MENU ----\n");
    printf("1- Agregar\n");
    printf("2- Editar registro\n");
    printf("3- Eliminar registro\n");
    printf("4- Buscar\n");
    printf("5- Ordenar\n");
    printf("6- Mostrar todo\n");
    printf("7- Generar archivo texto\n");
    printf("8- Mostrar archivo de texto\n");
    printf("9- Crear archivo binario\n");
    printf("10- Cargar archivo binario\n");
    printf("11- Mostrar eliminados\n");
    printf("0-  SALIR\n");
    op = validar("Ingresa una opcion numerica: ", 0, 11);
    system("CLS");

    return op;
}

Tdatos gen_per(void)
{
    Tdatos per;
    per.status = 1;
    per.key = numAleatorio(300000, 399999);
    gen_nom(per.nom, per.sexo, per.ap_pat, per.ap_mat);
    per.edad = numAleatorio(18, 40);

    return per;
}

void buscar(Tdatos registro[], int i, int flag)
{
    int op, mat;
    mat = validar("Ingrese la matricula del empleado a buscar: ", 300000, 399999);
    system("CLS");
    op = busq_opt(registro, i, mat, flag);
    if (op != -1)
    {
        printf("MATRICULA: %ld\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nEDAD: %d\nSEXO: %s\n", registro[op].key, registro[op].nom, registro[op].ap_pat, registro[op].ap_mat, registro[op].edad, registro[op].sexo);
    }
    else
    {
        printf("Empleado no encontrado\n");
    }
}

void eliminar(Tdatos registro[], int i, int flag, char nom_arch[20])
{
    int mat, enc, op;
    mat = validar("Matricula a buscar: ", 300000, 399999);
    system("CLS");
    enc = busq_opt(registro, i, mat, flag);
    if (enc != -1)
    {
        if (registro[enc].status == 1)
        {
            printf("Desea eliminar a %ld?\n1-Si\n2-No\n", registro[enc].key);
            op = validar("Ingrese una opcion: ", 1, 2);
            system("CLS");
            if (op == 1)
            {
                registro[enc].status = 0;
                printf("Matricula eliminada exitosamente!\n");
                system("CLS");
                act_arch(registro, i, nom_arch);
            }
            else
            {
                printf("Matricula no eliminada\n");
            }
        }
        else
        {
            printf("Matricula inactiva\n");
        }
    }
    else
    {
        printf("La matricula que ingreso no existe\n");
    }
}

void editar(Tdatos registro[], int i, int flag, char nom_bin[])
{
    int mat, op, op2;
    mat = validar("Ingrese la matricula a editar: ", 300000, 399999);
    op = busq_opt(registro, i, mat, flag);
    system("CLS");
    if (op != -1)
    {
        do
        {
            printf("1-MATRICULA: %ld\n2-NOMBRE: %s\n3-APELLIDO PATERNO: %s\n4-APELLIDO MATERNO: %s\n5-EDAD: %d\n6-SEXO: %s\n0-SALIR\n", registro[op].key, registro[op].nom, registro[op].ap_pat, registro[op].ap_mat, registro[op].edad, registro[op].sexo);
            op2 = validar("Que campo desea editar: ", 0, 6);
            system("CLS");
            cambiar(op2, registro, op, flag);
            system("CLS");
        } while (op2 != 0);
        act_arch(registro, i, nom_bin);
    }
    else
    {
        printf("Matricula no encontrada\n");
    }
}

void cambiar(int op, Tdatos registro[], int i, int flag)
{
    int mat, edad, sex;
    char nom[40], paterno[40], materno[40];
    switch (op)
    {
    case 1: // cambiar matricula
        do
        {
            mat = validar("Ingrese una matricula nueva: ", 300000, 399999);
            system("CLS");
        } while (busq_opt(registro, i, mat, flag) != -1);
        registro[i].key = mat;
        break;
    case 2: // cambiar nombre
        do
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nom);
            system("CLS");
        } while (alfabetico(nom) == -1);
        mayus(nom);
        strcpy(registro[i].nom, nom);
        break;
    case 3: // cambiar ap paterno
        do
        {
            printf("Ingrese apellido paterno: ");
            fflush(stdin);
            gets(paterno);
            system("CLS");
        } while (alfabetico(paterno) == -1);
        mayus(paterno);
        strcpy(registro[i].ap_pat, paterno);
        break;
    case 4: // cambiar ap materno
        do
        {
            printf("Ingrese apellido materno: ");
            fflush(stdin);
            gets(materno);
            system("CLS");
        } while (alfabetico(materno) == -1);
        mayus(materno);
        strcpy(registro[i].ap_mat, materno);
        break;
    case 5: // cambiar edad
        edad = validar("Ingrese edad ", 18, 40);
        registro[i].edad = edad;
        break;
    case 6: // cambiar sexo
        sex = validar("1-Mujer\n2-Hombre\nIngrese una opcion numerica: ", 1, 2);
        if (sex == 1)
        {
            strcpy(registro[i].sexo, "MUJER");
        }
        else
        {
            strcpy(registro[i].sexo, "HOMBRE");
        }
        break;
    }
}

// funciones de busqueda

int busq_seq(Tdatos registro[], int n, int num) // registro no ordenado
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (registro[i].key == num)
        {
            return i;
        }
    }
    // no encontrado
    return -1;
}

int busq_binaria(Tdatos registro[], int rf, int key)
{
    int ri = 0;
    while (ri <= rf)
    {
        int medium = ri + (rf - ri) / 2;

        // Checa si el numero se encuentra en medio
        if (registro[medium].key == key)
        {
            return medium;
        }

        if (registro[medium].key < key) // si el numero es mayor ignora el lado izquierdo
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

int busq_opt(Tdatos refistro[], int n, int key, int flag)
{
    int i;

    if (flag)
    {
        i = busq_binaria(refistro, n, key);
    }
    else
    {
        i = busq_seq(refistro, n, key);
    }

    return i;
}

// funciones de ordenamiento

int burbuja(Tdatos registro[], int n)
{
    int i, j;
    Tdatos temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (registro[j].key < registro[i].key)
            {
                temp = registro[i];
                registro[i] = registro[j];
                registro[j] = temp;
            }
        }
    }
    return 1;
}

int quickSort(Tdatos vect[], int n)
{
    qs(vect, 0, n - 1);

    return 1;
}

void qs(Tdatos vect[], int limite_izq, int limite_der)
{
    int izq, der, pivote;
    Tdatos temp;

    izq = limite_izq;
    der = limite_der;
    pivote = vect[(izq + der) / 2].key;

    do
    {
        while (vect[izq].key < pivote && izq < limite_der)
        {
            izq++;
        }

        while (pivote < vect[der].key && der > limite_izq)
        {
            der--;
        }

        if (izq <= der)
        {
            temp = vect[izq];
            vect[izq] = vect[der];
            vect[der] = temp;
            izq++;
            der--;
        }
    } while (izq <= der);

    if (limite_izq < der)
    {
        qs(vect, limite_izq, der);
    }

    if (limite_der > izq)
    {
        qs(vect, izq, limite_der);
    }
}

int ordOpt(Tdatos registro[], int n)
{
    if (n <= 200)
    {
        burbuja(registro, n);
    }
    else
    {
        quickSort(registro, n);
    }

    return 1;
}

// Funciones para archivo de texto

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

void gen_arch(char nomArchivo[], Tdatos vect[], int n)
{
    int i, cont = 0;
    char temp[30];
    FILE *fa;

    strcpy(temp, nomArchivo);
    strcat(temp, "_activos.txt");

    fa = fopen(temp, "w");

    if (fa)
    {
        fprintf(fa, "------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
        fprintf(fa, "------------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++)
        {
            if (vect[i].status == 1)
            {
                fprintf(fa, "%4d.-  %6ld      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].key, vect[i].nom, vect[i].ap_pat, vect[i].ap_mat, vect[i].edad, vect[i].sexo);
                fprintf(fa, "\n");
                cont++;
            }
        }
    }
    else
    {
        printf("Al parecer ha ocurrido un error al generar el archivo\n");
    }
    fclose(fa);
}

void imprimir(Tdatos vect[], int n, int status)
{
    int activos, i;

    printf("------------------------------------------------------------------------------------------\n");
    printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    printf("------------------------------------------------------------------------------------------\n");
    for (i = 0, activos = 0; i < n; i++)
    {
        if (vect[i].status == status)
        {
            printf("%4d.-  %6ld      %-10s      %-10s      %-10s          %2d      %-7s\n", activos + 1, vect[i].key, vect[i].nom, vect[i].ap_pat, vect[i].ap_mat, vect[i].edad, vect[i].sexo);
            activos++;
        }
    }
}

void mostrar_arch(Tdatos vect[], int n, char nom_arch[])
{
    char temp[20];
    int cont = 0;
    gen_nom_arch(temp);
    strcat(temp, "_activos.txt");
    if (strcmp(temp, nom_arch))
    {
        printf("------------------------------------------------------------------------------------------\n");
        printf("  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
        printf("------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < n; i++)
        {
            if (vect[i].status == 1)
            {
                printf("%4d.-  %6ld      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].key, vect[i].nom, vect[i].ap_pat, vect[i].ap_mat, vect[i].edad, vect[i].sexo);
                printf("\n");

                cont++;
            }
        }
    }
    else
    {
        printf("El archivo que buscas no existe\n");
    }
}

// Funciones archivo binario

int gen_arch_bin(Tdatos registro[], int n, char nom[])
{
    Tdatos reg;
    FILE *fa;
    int i;
    char temp[20];
    strcpy(temp, nom);
    strcat(temp, ".dll");
    fa = fopen(temp, "ab");
    if (fa == NULL)
    {
        printf("No hay registros por guardar\n");
        return 0;
    }
    else
    {
        if (fa)
        {
            for (i = 0; i < n; i++)
            {
                reg = registro[i];
                fwrite(&reg, sizeof(Tdatos), 1, fa);
            }
            fclose(fa);
        }
    }

    return 1;
}

void respaldo(char nom[])
{
    FILE *fa;
    FILE *resp;
    Tdatos reg;
    char nom2[20];
    strcpy(nom2, nom);
    strcat(nom2, ".dll");
    fa = fopen(nom2, "rb");
    if (fa)
    {
        strcat(nom, ".tmp");
        resp = fopen(nom, "wb");
        while (fread(&reg, sizeof(Tdatos), 1, fa))
        {
            fwrite(&reg, sizeof(Tdatos), 1, resp);
        }
        fclose(fa);
        fclose(resp);
    }
}

int cargar_bin(Tdatos registro[], int *i, int max, char nom[])
{
    Tdatos reg;
    FILE *fa;
    FILE *crg;
    char nom2[20];
    fa = fopen(nom, "rb");
    if (fa)
    {
        strcpy(nom2, "datos.dll");
        crg = fopen(nom2, "wb");
        while (fread(&reg, sizeof(Tdatos), 1, crg))
        {
            if ((*i) <= max)
            {
                registro[(*i)++] = reg;
            }
        }
        fclose(fa);
        fclose(crg);
        printf("Archivo cargado exitosamente\n");
        return 1;
    }
    else
    {
        printf("Al parecer ha ocurrido un error\n");
        return 0;
    }
}

void act_arch(Tdatos registro[], int i, char nom_arch[])
{
    int op;
    printf("Quieres actualizar el archivo?\n1-Si\n2-No\n");
    op = validar("Ingresa una opcion numerica: ", 1, 2);
    system("CLS");
    if (op == 1)
    {
        gen_arch_bin(registro, i, nom_arch);
        printf("Archivo actualizado\n");
    }
}
