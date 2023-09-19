// Danna Sandez Islas 373080
//  18 de septiembre de 2023
//  Actividad 06
//  SD_ACT06

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//  PARTE 1 PROTOTIPO DE FUNCIONES
void menu(void);
void fibWhile(void);
void fibFor(void);
void fibDoWhile(void);
void factFor(void);
void factWhile(void);
void factDoWhile(void);
void digFor(void);
void digWhile(void);
void digDoWhile(void);

// PARTE 2 PROTOTIPO DE FUNCIONES
void menu2(void);
void tablas(void);
int validar(char mensj[], int ri, int rf);
void calif(void);
void numeros(void);
void pasajeros(void);
void asignatura(void);

// FUNCION PRINCIPAL
int main()
{
    int op;
    printf("A que parte de la practica deseas ingresar? \n");
    printf("1- Parte 1\n");
    printf("2- Parte 2\n");
    printf("3- Salir\n");
    scanf("%d", &op);
    system("CLS");

    switch (op)
    {
    case 1: // usuario eligio parte 1
        menu();
        break;
    case 2: // usuario eligio parte 2
        menu2();
        break;
    case 3: // usuario eligio salir
        printf("Gracias, nos vemos pronto!");
        break;

    default: // mensaje en caso de error
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        getch();
        system("CLS");
        main(); // envia al usuario a la funcion main
        break;
    }

    return 0;
}

// PARTE 1 DESARROLLO DE FUNCIONES

void menu(void) // funcion menu para la PARTE 1 de la actividad
{
    //variable local
    int op;
    system("CLS");
    printf("Bienvenido a la Parte 1 de la practica!\n");
    printf("\n");
    printf(" Seleccione una opcion NUMERICA \n");
    printf(" 1- Fibonacci \n");
    printf(" 2- Factorial \n");
    printf(" 3- Cantidad de digitos \n");
    printf(" 4- Salir\n");
    printf(" Ingrese la opcion NUMERICA que desea: ");
    scanf("%d", &op);

    system("CLS"); //limpia pantalla
  
    switch (op)
    {
        int op;
    case 1: // usuario eligio fibonacci
        printf("Que fibonacci desea utiliza? \n");
        printf("\n");
        printf("1- Fibonacci Ciclo FOR \n");
        printf("2- Fibonacci Ciclo WHILE \n");
        printf("3- Fibonacci ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1: // usuario eligio ciclo for
            fibFor();
            break;
        case 2: // usuario eligio ciclo while
            fibWhile();
            break;
        case 3: // usuario eligio ciclo do while
            fibDoWhile();
            break;
        default: // mensaje en caso de error
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS"); // limpia pantalla
            main();        // envia al usuario a la funcion main
            break;
        }
        break;
    case 2: // usuario eligio factorial
        printf("Que Factorial desea utiliza? \n");
        printf("\n");
        printf("1- Factorial Ciclo FOR \n");
        printf("2- Factorial Ciclo WHILE \n");
        printf("3- Factorial ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1: // usuario eligio ciclo for
            factFor();
            break;
        case 2: // usuario eligio ciclo while
            factWhile();
            break;
        case 3: // usuario eligio ciclo do while
            factDoWhile();
            break;

        default: // mensaje en caso de error
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS");
            main(); // envia al usuario a la funcion main
            break;
        }
        break;
    case 3: // usuario eligio digitos
        printf("Que Contador de Digitos desea utiliza? \n");
        printf("\n");
        printf("1- Contador Ciclo FOR \n");
        printf("2- Contador Ciclo WHILE \n");
        printf("3- Contador ciclo DO WHILE \n");
        printf("Ingresa una opcion numerica por favor: \n");
        scanf("%d", &op);
        system("CLS");

        switch (op)
        {
        case 1: // usuario eligio ciclo for
            digFor();
            break;
        case 2: // usuario eligio ciclo whiles
            digWhile();
            break;
        case 3: // usuario eligio ciclo do while
            digDoWhile();
            break;
        default: // mensaje en caso de error
            printf("La opcion que ingresaste es incorrecta. Por favor ingresa una opcion correcta! \n");
            getch();
            system("CLS");
            main(); // envia al usuario a la funcion main
            break;
        }
        break;
    case 4: // usuario eligio salir del menu
        printf("Gracias, nos vemos");
        getch();
        system("CLS");
        main(); // envia al usuario a la funcion main
        break;
    default: // mensaje en caso de error
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        getch();
        system("CLS");
        menu(); // envia al usuario a la funcion menu
        break;
    }
}

void fibFor(void) // funcion fibonacci con el ciclo FOR
{
    // variables locales
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);
    // desarrollo de funcion
    for (int i = 0; i < n; i++)
    {
        res = a + s;
        printf("%d", res); // valores que imprime
        a = s;
        s = res;
    }
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void fibWhile(void) // funcion fibonacci con el ciclo WHILE
{
    // variables locales
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);
    // desarrollo de funcion
    int i = 0;
    while (i < n)
    {
        res = a + s;
        printf("%d", res); // valores que imprime
        a = s;
        s = res;
        i++;
    }
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void fibDoWhile(void) // funcion fibonacci con ciclo DO WHILE
{
    // variables locales
    int n, a = -1, s = 1, res;

    printf(" Cuantas veces desea que se realice el programa Fibonacci? \n");
    scanf("%d", &n);

    // desarrollo de funcion
    int i = 0;
    do
    {
        i++;
        res = a + s;
        printf("%d", res); // valores que imprime
        a = s;
        s = res;
    } while (i < n);
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void factFor(void) // funcion factorial con el ciclo FOR
{
    // variables locales

    int num, a, s;
    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    // desarrollo de funcion
    a = num * (num - 1);
    for (int i = 2; i < num; i++)
    {
        s = a * (num - i);
        a = s;
    }
    printf("El factorial de %d es: %d", num, a); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void factWhile(void) // funcion factorial con el ciclo WHILE
{
    // variables locales
    int num, i, a, s;
    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);

    // desarrollo de funcion
    i = 2;
    a = num * (num - 1);
    while (i < num)
    {
        s = a * (num - i);
        a = s;

        i++;
    }
    printf("El factorial de %d es: %d", num, a); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void factDoWhile(void) // funcion factorial con el ciclo DO WHILE
{
    // variables locales
    int num, i, a, s;

    printf(" FACTORIAL ! \n");
    printf("Que numero deseas utilizar? \n");
    scanf("%d", &num);
    // desarrollo de funcion
    i = 2;
    a = num * (num - 1);
    do
    {
        s = a * (num - i);
        a = s;
        i++;
    } while (i < num);

    printf("El factorial de %d es: %d", num, a); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void digFor(void) // funcion contador de digitos con el ciclo FOR
{
    // variables locales
    int num, x = 1;
    int i;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);

    // desarrollo de funcion
    for (i = 0; num >= x; i++)
    {
        x = x * 10;
    }
    printf("La cantidad de digitos que tiene %d es: %d", num, i); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void digWhile(void) // funcion contador de digitos con el ciclo  WHILE
{
    // variables locales
    int num;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);
    // variables locales para el ciclo do whils
    int dig = 0, x = 1;
    // desarollo de funcion
    while (num >= x)
    {
        x = x * 10;
        dig++;
    }
    printf("La cantidad de digitos que tiene %d es: %d", num, dig); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

void digDoWhile(void) // funcion contador de digitos con el ciclo DO WHILE
{
    // variables locales
    int num;
    printf("Contador de digitos! \n");
    printf("Ingrese un numero por favor: ");
    scanf("%d", &num);
    // variables locales para el ciclo do while
    int dig = 0, x = 1;
    do
    {
        dig++;
        x = x * 10;
    } while (num >= x);
    printf("La cantidad de digitos que tiene %d es: %d", num, dig); // valor que imprime
    getch();
    system("CLS");
    menu(); // envia al usuario a la funcion menu
}

// PARTE DOS, DESARROLLO DE FUNCIONES

int validar(char mensj[], int ri, int rf) // funcion para validar argumentos dados por el usuario
{
    // variables locales
    int num;
    char cadena[1000]; // cadena que va a leer dependiendo el mensaje que ingrese el usuario
    // desarrollo de funcion
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);

    } while (num < ri || num > rf);

    return num; // retorna el valor que haya tomado num, entre los rangos dados por el usuario
}

void menu2(void) // funcion menu de PARTE 2 de la actividad
{
    int op;
    system("CLS");
    printf("Bienvenido a la Parte 2 de la practica!\n");
    printf("\n");
    printf("Que ejercicio te gustaria iniciar?\n");
    printf("\n");
    printf("1- Derecho a examen de nivelacion\n");
    printf("2- Tablas\n");
    printf("3- Media aritmetica\n");
    printf("4- Turistas\n");
    printf("5- Cursamiento de materia\n");
    printf("6- Salir\n");
    printf("Ingresa una opcion numerica por favor: ");
    scanf("%d", &op);
    system("CLS");

    switch (op)
    {
    case 1: // usuario eligio derecho a examen de nivelacion
        calif();
        break;
    case 2: // usuario eligio tablas
        tablas();
        break;
    case 3: // usuario eligio media aritmetica
        numeros();
        break;
    case 4: // usuario eligio turistas
        pasajeros();
        break;
    case 5: // usuario eligio cursamiento de materias
        asignatura();
        break;
    case 6: // usuario eligio salir del menu2
        printf("Gracias, nos vemos pronto!");
        getch();
        system("CLS");
        main(); // envia al usuario a la funcion main
        break;
    default: // mensaje en caso de error
        printf("La opcion que ingresaste es incorrecta. Ingresa una opcion correcta por favor \n");
        getch();
        system("CLS");
        menu2(); // envia al usuario a la funcion menu2
        break;
    }
}

void calif(void) // funcion que lee calificaciones e imprime cuantos no tienen derecho a examen
{
    // variables locales
    int cal;
    int sde = 0; // contador de alumno sin derecho a examen
    // desarrollo de funcion
    for (int i = 0; i < 40; i++)
    {
        printf("Hola alumno numero %d\n", i + 1); // imprime mensaje que indica el numero que alumno al que se le pedira la calificacion
        int suma = 0;
        for (int j = 0; j < 5; j++) // ciclo FOR para pedir 5 calificaciones
        {
            cal = validar("Ingresa tu calificacion:", 0, 100); // se manda a llamar a la funcion validar y le ingresamos sus parametros.
            suma += cal;                                       // las calificaciones se guardan en un acumulador para despues generar un promedio
        }
        int prom = (suma / 5); // promedio
        if (prom < 50)         // condicion para verificar si el alumno tendra o no derecho a examen
        {
            sde++; // si prom es menor a 50 no tiene derecho a examen, SE INCREMENTA sde
        }
        system("CLS");
    }
    printf("La cantidad de alumnos sin derecho a examen es: %d", sde); // imprime la cantidad de alumnos sin derecho a examen
    getch();
    menu2(); // manda al usuario a la funcion menu2
}

void tablas(void) // funcion que genera las tablas de multiplicar del 1-10
{
    // variables locales
    int num = 1;
    // desarrollo de funcion
    while (num < 11) // ciclo que incrementara el numero de la tabla que sera
    {
        printf("Tabla del %d \n", num); // mensaje que indica el numero de tabla que es
        for (int i = 1; i < 11; i++) // ciclo que genera tablas de 1 al 10
        {
            printf(" %d x %d = %d\n", num, i, (i * num));
        }
        getch();
        system("CLS"); // limpia pantalla
        num++; // incrementa numero 
    }
    getch();
    menu2(); // envia al usuario a la funcion menu2
}

void numeros(void) // funcion que lee n numeros dados por el usuario, los suma y desplega su media aritmetica
{
    // variables locales
    int n, ri, rf;
    int num, media;
    int suma = 0;

    printf("Cuantos numeros deseas ingresar? \n");
    scanf("%d", &n);
    printf("Cual es el rango menor que te gustaria usar?\n");
    scanf("%d", &ri);
    printf("Cual es el rango superior que te gustaria usar?\n");
    scanf("%d", &rf);
    system("CLS");

    // desarrollo de funcion
    for (int i = 0; i < n; i++) // ciclo que generara n cantidad de numeros
    {
        num = validar("Ingresa un numero: ", ri, rf); // el numero se manda a la funcion validar donde checa si cumple con los rangos dados
        suma += num; // acumulador donde se guardan los numeros generados para proximamente realizar la media
        getch();
        system("CLS"); // limpia pantalla
    }
    media = suma / n; // media aritmetica
    printf("La suma de los %d numeros es: %d\n", n, suma); // imprime la suma
    printf("La media aritmetica de los %d numeros es: %d", n, media); // imprime la media
    getch();
    menu2(); // envia al usuario a la funcion menu2
}

void pasajeros(void) // funcion que lee el peso de los pasajeros, imprime el promedio de peso y si se cumplio con la condicion de 10 pasajeros o peso maximo
{
    // variables locales
    int peso = 0;
    int prom = 0;
    int per;
    int sobrep = 700 + (700 * .15); // sobrepeso maximo capaz en el barco

    for (per = 0; per < 10; per++) // ciclo para contar el numero de pasajeron que van entrando
    {
        int pasaj;

        pasaj = validar("Ingresa tu peso: ", 0, 300); // variable pasajero guarda el peso del pasajero y valida si cumple con los rangos
        peso += pasaj; // acumulador de peso de pasajero
        getch();
        system("CLS"); // limpia pantalla

        if (peso == sobrep) // condicion para saber si se cumplio con el peso maximo
        {
            printf("El peso maximo de los turistas ha llegado al limite!\n"); // imprime bandera
            break; // termina el ciclo
        }
        if (per == 9) // capacidad maxima de turistas en el barco
        {
            printf("La capacidad maxima de turistas ha llegado al limite!\n"); // imprime bandera
        }
    }
    prom = peso / per; // genera promedio de los pesos
    printf("El promedio de peso de los pasajeros es: %d", prom); // imprime el promedio de los pesos
    getch();
    menu2(); // envia al usuario a la funcion menu2
}

void asignatura(void) // funcion que lee calificaciones de un alumno y genera su promedio para saber si aprobo, recursa materia o baja temporal
{
    // vairables locales
    float prom = 0;
    for (int mat = 0; mat < 3; mat++) // ciclo que cuanta las veces que ha cursado la materia
    {
        printf("Cantidad de veces que ha cursado la materia: %d\n", mat + 1); // mensaje que imprime las veces que ha cursado la materia
        int ac = 0; // acumulador de calificaciones para el promedio
        for (int i = 0; i < 3; i++) // ciclo para generar 3 calificacions
        {
            int cal; 
            cal = validar("Ingresa tu calificacion del parcial: ", 0, 100); // variable cal guarda la calificacion del alumno, con la funcion validar, checa si entra dentro de los rangos dados
            ac += cal; // acumula la calificacion
        }
        prom = ac / 3; // genera promedio 
        printf("Tu promedio es: %.2f\n", prom); // imprime promedio
        if (mat == 2) // condicion para saber si es baja temporal
        {
            printf("Has alcanzado el numero maximo de intentos\n");
            printf("BAJA TEMPORAL\n");
            break; // fin del ciclo
        }
        if (prom < 60) // condicion para saber si repite materia
        {
            printf("REPETIR MATERIA\n");
            getch();
            system("CLS"); // limpia pantalla
        }
        else // no cumple con la condicion anterior significa que aprobo
        {
            printf("APROBADO\n");
            break; // fin del ciclo
        }
    }
    getch();
    menu2(); // envia al usuario a la funcion menu2
}
