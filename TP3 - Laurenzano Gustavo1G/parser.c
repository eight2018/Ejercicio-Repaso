#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Parsea los datos del linked list al archivo data.csv (modo texto).
  * \param pFile es el puntero a archivo para escribir los datos
 * \param pArrayListEmployee Es la LinkedList de donde se obtienen los datos
 * \return Devuelve 0 si existe el archivo y el LinkedList Caso contrario  devuelve -1
  */
int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    Employee* auxEmployee;


    char auxNombre[1000];
    int auxHorasTrabajadas;
    int auxSueldo;
    int largo;
    int i;
    int AuxId;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        largo = ll_len(pArrayListEmployee);

        for(i=0;i<largo;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i );
            Employee_getAll(auxEmployee,auxNombre,&auxHorasTrabajadas,&auxSueldo,&AuxId);
            fprintf(pFile,"%d ,%s ,%d ,%d \n",AuxId,auxNombre,auxHorasTrabajadas,auxSueldo);

            retorno = 0;
        }

    }
    return retorno;
}


/** \brief Parsea los datos del linkedlist al archivo data.bin (modo binario).
  * \param pFile es el puntero al archivo para escribir los datos
 * \param pArrayListEmployee es el LinkedList de donde se toman los datos
 * \return Devuelve un 0 si existe el archivo y el linkedlist caso contrario devuelve -1
  */
int parser_SaveToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int i = 0;
    int largo;
    int retorno = -1;

    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        largo = ll_len(pArrayListEmployee);
        while(i != largo)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            fwrite(auxEmployee,sizeof(Employee*),1,pFile);

            retorno = 0;

            i++;
        }
    }
    return retorno;
}



/** \brief  Parsea  los datos de los empleados desde el archivo data.csv (modo texto).
 * \param  FILE* pFile es puntero del tipo file al archivo para parsear
 * \param pArrayListEmployee LinkedList* es la lista donde se van a a guardar los empleados
 * \return Si pudo guardar los datos  devuelve  0 y en caso contrario devuelve -1
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    char auxSueldo[1024];
    int retorno = -1;
    int flagUnica = 1;

    char auxInt[1024];
    char auxNombre[1024];
    char auxHorasTrabajadas[1024];

    Employee* pEmpleado;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flagUnica)
            {
               flagUnica = 0;
               fscanf( pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxInt,auxNombre,auxHorasTrabajadas,auxSueldo);
            }

             fscanf( pFile, "%[^,],%[^,],%[^,],%[^\n]\n",auxInt,auxNombre,auxHorasTrabajadas,auxSueldo);

            pEmpleado = Employee_newParam( auxInt,auxNombre,auxHorasTrabajadas,auxSueldo);

            if(pEmpleado != NULL)
            {
                retorno = 0;

                ll_add(pArrayListEmployee, pEmpleado);
            }

        }
    }
    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data en modo binario.
 * \param FILE* pFile es el puntero del tipo file al archivo para parsear
 * \param pArrayListEmployee LinkedList* es la lista en donde se van a a guardar los empleados
 * \return Si puso parsear  devuelve un 0. Caso contrario devuelve un  -1
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    Employee* pEmpleado;

    if(pFile != NULL)
    {
        retorno = 0;

        while(!feof(pFile))
        {
            pEmpleado = Employee_new();

            fread(pEmpleado,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,pEmpleado);

        }

    }
    return retorno;
}

