#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/*
void limpiarMemoria();
void limpiarPantalla();
void pause();*/

/*int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);*/

/*int utn_getDescription(  char* pDescription, int size, char* msg,
                    char* msgErr, int reintentos);*/


/*int utn_getNumero(int* pResultado,
                 char mensaje[],
                 char mensajeError[],
                 int  minimo,
                 int  maximo,
                 int  reintentos);*/


/*int utn_getNumeroConComa(float* pResultado,
                char mensaje[],
                char mensajeError[],
                float  minimo,
                float  maximo,
                int  reintentos);*/







int gl_getValidName(  char* pName, int limit, char* message,char* errorMessage, int retry);

int gl_getValidNumber(int* pNumber,char message[],char errorMessage[],int  min,int  max,int  retry);



void  pause();

void cleanMemory();

void cleanStage();



#endif // UTN_H_INCLUDED
