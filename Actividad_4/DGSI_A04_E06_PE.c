//Danna Sandez Islas 373080
// 03 de septiembre de 2023
// M3 con condiciones anidadas
// SD_ACT04_06
#include <stdio.h>

int main()
{

    float st = 0, iva = 0, total = 0;
    int m3;

    printf("Ingrese los M3 consumidos \n");
    scanf("%d", &m3);

    if (m3 >= 0 && m3 <= 4) // rango 1
    {
        st = 50;
    }
    else
    {
        if (m3 >= 5 && m3 <= 15) //rango 2
        {
            st = (((m3 - 4) * 8) + (50));
        }
        else
        {
            if (m3 >= 16 && m3 <= 50) //rango 3
            {
                st = ((50) + (11 * 8) + ((m3 - 15) * 10));
            }
            else
            {
                if (m3 >= 51) //rango 4
                {
                    st = ((50) + (11 * 8) + (35 * 10) + ((m3 - 50) * 11));
                }
            }
        }
    }

    iva = (st * 0.16);
    total = st + iva;

    printf("EL SUBTOTAL ES=%.2f \n", st);
    printf("EL IVA ES=%.2f \n", iva);
    printf("EL TOTAL ES=%.2f \n", total);

    return 0;
}