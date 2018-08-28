#include <stdio.h>
#include <stdlib.h>

int main()
{   float numero=0;
    int contadorPositivos=0;
    int contadorNegativos=0;
    int contadorCeros=0;
    int contadorPares=0;
    float promedioPositivos=0;
    float promedioNegativos=0;
    float difPositivos;
    float difNegativos;
    float sumaPositivos;
    float sumaNegativos;
    float maximo;
    float minimo;



    char letra='s';

       do {
            printf("ingrese un numero");
            scanf("%f",&numero);
            if (numero==0)
            {
              contadorCeros++;

            }
            if (numero >0);
                        {
              contadorPositivos++;
              sumaPositivos=sumaPositivos+numero;
            }
            if (numero <0);
                        {
              contadorNegativos++;
              sumaNegativos=sumaNegativos+numero;
            }





            printf("quiere  seguir?");
            fflush(stdin);
            scanf("%c",&letra);





   }while(letra=='s');
   {
   printf("1) La cantidad de positivos es: %d\n",contadorPositivos);
   printf("2) La cantidad de negativos es: %d\n",contadorNegativos);
   printf("3) La cantidad de ceros es: %d\n",contadorCeros);
  /* printf("4) La cantidad de pares es: %d",);
   printf("5) El promedio  de positivos es: %f",);
   printf("6) El promedio  de negativos es: %f",);
   printf("7) La diferencia entre negativos y postivos es: %d",);
   printf("8) La suma  de positivos es: %d",);
   printf("9) La suma de negativos  es: %d",);
   printf("10) La cantidad de positivos es: %d",);*/
   }

    return 0;
}
