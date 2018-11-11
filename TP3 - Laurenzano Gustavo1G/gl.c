#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CADLEN 1000
#define BSTRING 4096
#include "gl.h"

void cleanMemory(){
     fflush(stdin);
}

void cleanStage(){
    system("cls");

}

void pause(){

    printf("\nPULSE ENTER PARA CONTINUAR");
    cleanMemory();
    getchar();

}

/**
* \brief  El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/
static int getString(char* pBuffer, int limite)
{
    int valorRetornado = -1;

    char bufferStr[BSTRING];

    int largo;
    if(pBuffer != NULL && limite > 0)
    {
        cleanMemory();
        fgets(bufferStr,limite,stdin);
        largo = strlen(bufferStr);

        if(largo != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[largo-1] = '\0';
        }
        valorRetornado = 0;

        strncpy(pBuffer,bufferStr,limite);
    }

    return valorRetornado;
}

/**
* \brief    Evalua si es un nombre, solo puede tener un espacio y cada nombre
*            debe empezar por mayuscula y el resto minusculas
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidNombre(char* pBuffer,int limite)
{
     int i;
    int valorRetornado = 0;


    if(pBuffer != NULL && limite > 0)
    {
        valorRetornado = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)

        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && pBuffer[i]!= ' ')
            {

                valorRetornado = 0;

                break;
            }
        }
    }
    return valorRetornado;
}


/**
*\brief valida que sea una descripcion valida
*\param pBuffer Puntero a la variable Description
*\param size es el tamaño del string
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

static int isValidDescription(char* pBuffer,int size)
{
        int i;
    int valorRetornado = 0;

    if(pBuffer != NULL && size > 0)
    {
        valorRetornado = 1;
        for(i=0;i < size && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && (pBuffer[i] < '0' || pBuffer[i] > '9') && pBuffer[i]!= ' ' )
            {
                valorRetornado=0;

                break;
            }
        }
    }
    return valorRetornado;
}


/**
*\brief solicita un nombre al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param retries es la cantidad de retries que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*/
int utn_getNombre(  char* pNombre, int limite, char* msg, char* msgErr, int retries)

{
    int valorRetornado=-1;
    char bufferNombre[BSTRING];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && retries >= 0)
    {
        do
        {
            retries--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                valorRetornado = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(retries >= 0);
    }
    return valorRetornado;
}


/**
*\brief solicita una descripcion al usuario,valida y devuelve el resultado
*\param pDescription Puntero a la variable Description
*\param msg es el mensaje a ser mostrado
*\param msgErr es el mensaje a ser mostrado en caso de error
*\param retries es la cantidad de retries que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*/
int utn_getDescription(  char* pDescription, int size, char* msg, char* msgErr, int retries)

{
    int valorRetornado=-1;

    char bufferDescription[BSTRING];

    if( pDescription != NULL && size > 0 && msg != NULL &&
        msgErr != NULL && retries >= 0)
    {
        do
        {
            retries--;
            printf("%s",msg);
            if( getString(bufferDescription,size) == 0 &&
                isValidDescription(bufferDescription,size))
            {
                strncpy(pDescription,bufferDescription,size);

                valorRetornado = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(retries >= 0);
    }
    return valorRetornado;
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
    int valorRetornado=-1;

    char AuxName[BSTRING];

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

                valorRetornado = 0;

                break;
            }
            else
            {
                printf("%s",errorMessage);

            }

        }
        while ( retry >= 0);
    }

    return valorRetornado;
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




