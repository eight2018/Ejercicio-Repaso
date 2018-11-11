#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/

int Employee_setId(Employee* this,int id)
{
    int valorRetorno=-1;

    static int nextId=-1;

    if(this!=NULL && id==-1)
    {
        nextId++;
        this->id=nextId;
        valorRetorno=0;
    }
    else if(id>nextId)
    {
        nextId=id;
        this->id=nextId;
        valorRetorno=0;
    }
    return valorRetorno;
}

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/

int Employee_getId(Employee* this,int* id)
{
    int valorRetorno = -1;
    if(this==NULL)
    {
        return valorRetorno;

    }

    *id=this->id;
        valorRetorno=0;

    return valorRetorno;
}

/**
*\brief Reservar espacio en la memoria para un elemento
*\param no recibe parametros
*\return En Caso de reservar memoria devuelve el elemento . Caso contrario devuelve NULL
*/
Employee* Employee_new()
{
    Employee* this ;

    this = malloc(sizeof(Employee));

    if(this== NULL)
    {
        return NULL;
    }

    else
    {
        return this;
    }

}

/**
*\brief Libera espacio en memoria ocupado por elemento
*\param tihs Es el elemento
*\return Retorna 0 si logra liberar sino retorna -1
*/

int Employee_delete(Employee* this)
{
    int valorRetorno = -1;

    if(this== NULL)
    {
        return valorRetorno;

    }
        free(this );

        valorRetorno = 0;
        return valorRetorno;

}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmployee Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Employee* Employee_newParam(char* id,char* nombre,char* horasTrabajadas,char* sueldo)//lee desde el archivo
{
    Employee* this;
    this = Employee_new();

    int idCustomer=atoi(id);
    int horasTrabajadasCus = atoi(horasTrabajadas);
    int sueldoCus=atoi(sueldo);

    if(
    !Employee_setId(this,idCustomer)&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,horasTrabajadasCus)&&
    !Employee_setSueldo(this,sueldoCus))
        return this;

    Employee_delete(this);
    return NULL;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmployee Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Employee* Employee_new_Tec(char* nombre,int horasTrabajadas,int sueldo)//este no lee de un archivo
{
    Employee* this;
    this = Employee_new();

    if(
    !Employee_setId(this,-1)&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,horasTrabajadas)&&
    !Employee_setSueldo(this,sueldo))
        return this;

    Employee_delete(this);
    return NULL;
}
/**
*\brief Set del  nombre del elemento
*\param this es el elemento
*\param nombre es el nombre  para setear
*\return Si setea el elemento devuelve un cero caso contrario -1
*/

int Employee_setNombre(Employee* this,char* nombre)
{
    int valorRetorno=-1;

    if(this==NULL && nombre!=NULL)
    {
         return valorRetorno;

        }
       strcpy(this->nombre,nombre );
        valorRetorno=0;
    return valorRetorno;
}

/**
*\brief consigue el nombre del elemento
*\param this es el elemento
*\param nombre es el nombre obtenido
*\return Si lo obtiene devuelve 0 caso contrario un -1
*/

int Employee_getNombre(Employee* this,char* nombre)
{
    int valorRetorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);

        valorRetorno=0;
    }
    return  valorRetorno;
}

/**
*\brief setea las horas trabajadas de un elemento
*\param this es el elemento
*\param horasTrabajadas es la cantidad de horas a setear
*\return Si pudo setear las horas devuelve 0 caso contrario devuelve un -1
*/

int Employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int valorRetorno = -1;

    if(this == NULL)
    {
        return valorRetorno;
    }
     Employee_getNombre(this,nombre);
        Employee_getHorasTrabajadas(this,horas);
        Employee_getSueldo(this,sueldo);
        Employee_getId(this,id);

        valorRetorno = 0;


    return valorRetorno;
}








int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int valorRetorno=-1;
    if(this==NULL)
    {
      return valorRetorno;
    }
    this->horasTrabajadas=horasTrabajadas;
        valorRetorno=0;
    return valorRetorno;
}

/**
*\brief Se obtienen las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int valorRetorno=-1;
    if(this==NULL)
    {
       return valorRetorno;
    }
    *horasTrabajadas=this->horasTrabajadas;
        valorRetorno=0;
    return valorRetorno;
}

/**
*\brief  setea el sueldo del elemento
*\param  this es el elemento
*\param  sueldo es el sueldo a setear
*\return  Si setea devuelve 0 caso contrario devuelve -1
*/
int Employee_setSueldo(Employee* this,int sueldo)
{
    int valorRetorno=-1;
    if(this==NULL)
    {
        return valorRetorno;

    }
    this->sueldo=sueldo;
        valorRetorno=0;
    return valorRetorno;
}

/**
*\brief obtiene el sueldo del elemento
*\param this es el elemento
*\param sueldo es el sueldo que se obtiene
*\return Si lo obtiene devuelve un 0. Caso contrario devuelve un -1
*/
int Employee_getSueldo(Employee* this,int* sueldo){
    int valorRetorno=-1;

    if(this==NULL)
    {

         return valorRetorno;

    }
       *sueldo = this->sueldo;
        valorRetorno = 0;
        return valorRetorno;
}

/**
*\brief compara nombres  de dos elementos
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return devuelve 1 si el primer elemento es mayor al segundo,
*\       devuelve -1 si el, Si son iguales un devuelve un 0
*/

int Employee_criterioSortNombre(void* thisA,void* thisB)
{
    int valorRetorno = 0;

    char nameB[50];
    char nameA[50];


       Employee_getNombre(thisA,nameA);
      Employee_getNombre(thisB,nameB);
   if(strcmp(nameA,nameB)>0)
   {
    valorRetorno = 1;
   }
   else if(strcmp(nameA,nameB)< 0)
   {

    valorRetorno = -1;
   }

    return valorRetorno;
}


