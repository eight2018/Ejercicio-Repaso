#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096
#define CADLEN 1000


void cleanMemory()
{
     fflush(stdin);


}



void cleanStage(){
    system("cls");

}

void  pause(){
    printf("\ntoque cualquier letra para seguir");

    cleanMemory();

    getchar();
}

/**
*\brief pide un number al usuario, lo valida y devuelve el nombre
*\param pName Puntero a la variable
*\param message es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param retry es la cantidad de retry para cargar el nombre
*\return Si se pudo cargar devuelve un 0. Caso contarrio un -1
*
*/
int gl_getValidName(  char* pName, int limit, char* message,
                    char* errorMessage, int retry){
    int retorno=-1;

    char AuxName[BUFFER_STR];

    if( pName != NULL && limit > 0 && message != NULL &&
        errorMessage != NULL && retry >= 0)
    {
        do
        {
            retry--;

            printf("%s",message);
            if(getString(AuxName,limit) == 0  &&  isValidNombre(AuxName,limit))
            {
                strncpy(pName,AuxName,limit);

                retorno = 0;

                break;
            }
            else
            {
                printf("%s",errorMessage);

            }

        }
        while ( retry >= 0);
    }

    return retorno;
}


/**
*\brief solicita un number al usuario,valida y lo guarda en el puntero recibido por parametro
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param minimo es el number minimo aceptado
*\param maximo e el number maximo aceptado
*\param retry es la cantidad de retry que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/


int gl_getValidNumber(int* pNumber,char message[],char errorMessage[],int  min,int  max,int  retry)
{

    int number;

    int oneLess = 0;
     int validated = 1;
    char enteredString[CADLEN];

    printf("%s",message);

     for( int i = 0;i<retry; i++ )
    {
        validated=1;
        cleanMemory();
        fgets(enteredString, CADLEN, stdin);

        for (int j=0; j<strlen(enteredString)-1; j++)
        {
            if (enteredString[j] < '0' || enteredString[j] > '9')
            {
                 if(j > 0 || enteredString[j] != 45)
                {
                    validated = 0;
                    printf("%s",errorMessage);
                    break;

                }
                oneLess = 1;
            }
        }
        if(oneLess == 1 && strlen(enteredString)-1 == 1)
        {
            validated = 0;

        }
        if (validated)
        {
            number = atoi(enteredString);

            if(number >= min && number <= max)
            {
                *pNumber = number;
                return 0;
            }
            if(number < min || number > max)

            {

                printf("%s",errorMessage);
            }
        }

    }

     return -1;
}

