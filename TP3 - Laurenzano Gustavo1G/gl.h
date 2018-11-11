#ifndef GL_H_INCLUDED
#define GL_H_INCLUDED

void cleanMemory();
void cleanStage();
void pause();
int utn_getNombre(  char* pNombre, int limite, char* msg,char* msgErr, int reintentos);
int utn_getDescription(  char* pDescription, int size, char* msg,char* msgErr, int reintentos);
int gl_getValidName(  char* pName, int limit, char* message,char* errorMessage, int retry);
int gl_getValidNumber(int* pNumber,char message[],char errorMessage[],int  min,int  max,int  retry);


#endif // GL_H_INCLUDED


