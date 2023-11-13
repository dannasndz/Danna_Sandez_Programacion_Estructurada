/*
    Danna Sandez Islas 373080
    10 de noviembre  de 2023
    Actividad 12
    SD_ACT12
*/
#include "vivo.h"

typedef struct _datos
{
    int status;
    int mat;
    char ap_pat[40];
    char ap_mat[40];
    char nom[40];
    int edad;
    char sexo[20];
} Tdatos;

/* Prototipo de funciones */
Tdatos gen_per(void);
int busq_binaria(Tdatos registro[], int rf, int mat);
int busq_seq(Tdatos registro[], int n, int num);
int busq_opt(Tdatos refistro[], int n, int mat, int flag);
int burbuja(Tdatos registro[], int n);
int quickSort(Tdatos vect[], int n);
void qs(Tdatos vect[], int limite_izq, int limite_der);
int ordOpt(Tdatos registro[], int n);
void nom(char nom_arch[]);
int carg_arch(char nomArchivo[], Tdatos registro[], int *n);
void escr_arch(char nomArchivo[], Tdatos vect[], int n, int arch);
void imprimir(Tdatos vect[], int n, int status);
int cont_reg(char nomArchivo[], int status);
void gen_arch(Tdatos registro[], int i);
void eliminar(Tdatos registro[], int i, int ord);

/* Funcion principal */
int main()
{
    srand(time(NULL));
    Tdatos persona, registro[1500];
    int op, num, st;
    int ord = 0, i = 0, k = 0, carg = 0, l = 0;
    char nom_arch[20];
    do
    {
        system("CLS");
        printf("   ---- MENU ----\n");
        printf("1- Cargar archivo\n");
        printf("2- Agregar\n");
        printf("3- Eliminar\n");
        printf("4- Buscar\n");
        printf("5- Ordenar\n");
        printf("6- Mostrar todo\n");
        printf("7- Generar archivo\n");
        printf("8- Cantidad de registros en Archivo\n");
        printf("9- Mostrar eliminados\n");
        printf("0- SALIR\n");
        op = validar("Ingresa una opcion numerica: ", 0, 9);
        system("CLS");

        switch (op)
        {
        case 1: // cargar registros desde el arch de tecto
            if (!carg)
            {
                gen_arch(registro, i);
            }
            else
            {
                printf("Los registros ya se han cargado]n");
            }
            system("PAUSE");
            break;
        case 2: // agregar registros al arreglo y al arch de txt
            if (i < 1500)
            {
                for (int j = 0; j < 10; j++)
                {
                    persona = gen_per();
                    while (busq_seq(registro, i, persona.mat) != -1)
                    {
                        persona.mat = numAleatorio(300000, 399999);
                    }
                    registro[l++] = persona;
                    i++;
                }
                ord = 0;
                printf("10 personas agregadas exitosamente!\n");
            }
            else
            {
                printf("El registro a llegado a su capacidad maxima!\n");
            }

            if (carg)
            {
                escr_arch(nom_arch, registro, i, 0);
                escr_arch(nom_arch, registro, i, 1);
            }
            system("PAUSE");
            break;
        case 3: // eliminar
            eliminar(registro, i, ord);
            system("PAUSE");
            break;
        case 4: // buscar
            num = validar("Ingrese la matricula a buscar: ", 300000, 399999);
            system("CLS");
            k = busq_opt(registro, i, num, ord);
            if (k != -1)
            {
                printf("MATRICULA: %d\nNOMBRE: %s\nAPELLIDO PATERNO: %s\nAPELLIDO MATERNO: %s\nEDAD: %d\nSEXO: %s\n", registro[k].mat, registro[k].nom, registro[k].ap_pat, registro[k].ap_mat, registro[k].edad, registro[k].sexo);
            }
            else
            {
                printf("Matricula no encontrada\n");
            }
            system("PAUSE");
            break;
        case 5: // ordenar
            if (ord == 1)
            {
                printf("El registro ya se encuentra ordenado\n");
            }
            else
            {
                ord = ordOpt(registro, i);
                printf("Registro ordenado con exito1\n");
            }
            system("PAUSE");
            break;
        case 6: // mostrar registros
            imprimir(registro, i, 1);
            system("PAUSE");
            break;
        case 7: // generar archivo
            nom(nom_arch);
            escr_arch(nom_arch, registro, i, 0);
            escr_arch(nom_arch, registro, i, 1);
            printf("Tarea realizada exitosamente!\n");
            system("PAUSE");
            break;
        case 8: // retorno de cantidad de datos existentes en el archivo
            st = validar("Que registros desea ver?\n1-Activos\n2-Eliminados\nIngrese una opcion: ", 1, 2);
            nom(nom_arch);
            num = cont_reg(nom_arch, st);
            system("CLS");
            if (num == -1)
            {
                printf("El archivo no se ha encontrado\n");
            }
            else
            {
                printf("%d registros existentes en el archivo\n", num);
            }
            system("PAUSE");
            break;
        case 9: // mostrar registros eliminados
            imprimir(registro, i, 0);
            system("PAUSE");
            break;
        }
    } while (op != 0);
    printf("Gracias por usar el programa. Hasta luego!\n");
    return 0;
}

Tdatos gen_per(void)
{
    Tdatos per;
    per.status = 1;
    per.mat = numAleatorio(300000, 399999);
    strcpy(per.ap_pat, apellido[rand() % 30]);
    strcpy(per.ap_mat, apellido[rand() % 30]);

    int sex;
    sex = numAleatorio(1, 2);
    if (sex == 1)
    {
        strcpy(per.nom, nom_mujer[rand() % 19]);
        strcpy(per.sexo, "MUJER");
    }
    else
    {
        strcpy(per.nom, nom_hombre[rand() % 19]);
        strcpy(per.sexo, "HOMBRE");
    }

    per.edad = numAleatorio(18, 30);
    return per;
}

// funciones de busqueda

int busq_seq(Tdatos registro[], int n, int num) // registro no ordenado
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (registro[i].mat == num)
        {
            return i;
        }
    }
    // no encontrado
    return -1;
}

int busq_binaria(Tdatos registro[], int rf, int mat)
{
    int ri = 0;
    while (ri <= rf)
    {
        int medium = ri + (rf - ri) / 2;

        // Checa si el numero se encuentra en medio
        if (registro[medium].mat == mat)
        {
            return medium;
        }

        if (registro[medium].mat < mat) // si el numero es mayor ignora el lado izquierdo
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

int busq_opt(Tdatos refistro[], int n, int mat, int flag)
{
    int i;

    if (flag)
    {
        i = busq_binaria(refistro, n, mat);
    }
    else
    {
        i = busq_seq(refistro, n, mat);
    }

    return i;
}

/* funciones de ordenamiento */

int burbuja(Tdatos registro[], int n)
{
    int i, j;
    Tdatos temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (registro[j].mat < registro[i].mat)
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
    pivote = vect[(izq + der) / 2].mat;

    do
    {
        while (vect[izq].mat < pivote && izq < limite_der)
        {
            izq++;
        }

        while (pivote < vect[der].mat && der > limite_izq)
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

// funciones para el archivo .txt

void nom(char nom_arch[])
{
    do
    {
        system("CLS");
        printf("Ingresa el nombre del archivo: ");
        fflush(stdin);
        gets(nom_arch);
    } while (strcmp(nom_arch, "\n") == 0);
}

int carg_arch(char nomArchivo[], Tdatos registro[], int *n)
{
    FILE *fa;
    Tdatos reg;

    char temp[30];

    strcpy(temp, nomArchivo);
    strcat(temp, "_activos.txt");

    fa = fopen(temp, "r");

    if (fa)
    {
        while (!feof(fa))
        {
            if (((*n) + 1) <= 1500)
            {
                reg.status = 1;
                fscanf(fa, "%s %d %s %s %s %d %s", temp, &reg.mat, reg.nom, reg.ap_pat, reg.ap_mat, &reg.edad, reg.sexo);
                registro[(*n)++] = reg;
            }
            else
            {
                printf("Vector lleno\n");
            }
        }

        fclose(fa);
        return 1;
    }

    return 0;
}

void escr_arch(char nomArchivo[], Tdatos vect[], int n, int arch)
{
    int i, cont = 0;
    FILE *fa;

    char temp[30];
    strcpy(temp, nomArchivo);

    if (!arch)
    {
        strcat(temp, "_activos");
    }

    strcat(temp, ".txt");
    fa = fopen(temp, "w");

    if (arch)
    {
        fprintf(fa, "------------------------------------------------------------------------------------------\n");
        fprintf(fa, "  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
        fprintf(fa, "------------------------------------------------------------------------------------------\n");
    }

    for (i = 0; i < n; i++)
    {
        if (vect[i].status == 1)
        {
            fprintf(fa, "%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s", cont, vect[i].mat, vect[i].nom, vect[i].ap_pat, vect[i].ap_mat, vect[i].edad, vect[i].sexo);
            if (i < n - 1)
            {
                fprintf(fa, "\n");
            }
            cont++;
        }
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
            printf("%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s\n", activos + 1, vect[i].mat, vect[i].nom, vect[i].ap_pat, vect[i].ap_mat, vect[i].edad, vect[i].sexo);
            activos++;
        }
    }
}

int cont_reg(char nomArchivo[], int status)
{
    int cont;
    char cmd[50];

    system("mingw32-gcc-6.3.0.exe cont_reg.c -o cont_reg");
    system("PAUSE");
    sprintf(cmd, "cont_reg.exe %s %d", nomArchivo, status);
    cont = system(cmd);

    return cont;
}

/* funciones para el switch*/
void gen_arch(Tdatos registro[], int i)
{
    int carg = 0;
    char nom_arch[20];
    nom(nom_arch);
    carg = carg_arch(nom_arch, registro, &i);

    if (carg)
    {
        printf("Registros cargados al .txt con exito!\n");
    }
    else
    {
        printf("Parece que ha ocurrido un problema \n");
    }
}

void eliminar(Tdatos registro[], int i, int ord)
{
    int num, k = 0, op;
    num = validar("Ingrese el numero de matricula que desea eliminar: ", 300000, 399999);
    system("CLS");
    k = busq_opt(registro, i, num, ord);
    if (k != -1)
    {
        if (registro[k].status == 1)
        {
            printf("Desea eliminar a %d?\n1-Si\n2-No\n", registro[k].mat);
            op = validar("Ingrese una opcion: ", 1, 2);
            system("CLS");
            if (op == 1)
            {
                registro[k].status = 0;
                printf("La matricula eliminada exitosamente!\n");
            }
            else
            {
                printf("La matricula no se ha eliminado\n");
            }
        }
        else
        {
            printf("Matricula inactiva\n");
        }
    }
    else
    {
        printf("La matricula no es existente\n");
    }
}