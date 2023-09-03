// Danna Sandez Islas 373080
// numero par o impar
//22/08/23
// SD_ACT01_02

 #include <stdio.h>

int main (){
    int num;

    printf ("NUMERO PAR O IMPAR \n");
    printf("Ingrese un numero entero: \n");
    scanf("%d",&num);

    if (num%2==0)
    printf("El numero %d es PAR \n",num);
    
    else 
    printf ("El numero %d es IMPAR \n",num);
    
    return 0;
}