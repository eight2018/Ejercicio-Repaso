#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "gl.h"
/** \brief  Da de alta un empleado
  * \param pArrayListEmployee es el LinkedList donde  se agrega un nuevo empleado
 * \return Si se pudo dar de alta un nuevo empleado devuelve un 0. Caso contrario devuelve -1
  */
int controller_addEmployee(LinkedList* pArrayListEmployee){

    char nombre[32];
    int horasTrabajadas;
    int sueldo;
    int valorRetorno = -1;

    if( !gl_getValidName(nombre,32,"\nINGRAR EL NOMBRE: ","ERROR.INGRESAR NOMBRE CORRECTAMENTE: ",5 )&&
        !gl_getValidNumber(&horasTrabajadas,"\nINGRESAR LAS  HORAS TRABAJADAS: ","ERROR.INGRESAR HORAS TRABAJADAS: ",0,3000,5)&&
       !gl_getValidNumber(&sueldo,"INGRESAR EL SUELDO: ","ERROR.INGRESAR SUELDO: ",0,300000,5))


    {
        Employee* empleado=Employee_new_Tec(nombre,horasTrabajadas,sueldo);

        if( empleado!=NULL )
        {
            valorRetorno=ll_add(pArrayListEmployee,empleado);
        }

    }
    return valorRetorno;
}









/** \brief Guarda los datos de  los empleados en el  archivo  data.csv modo texto.
  * \param path es el camino donde se guarda el archivo en moo texto
 * \param pArrayListEmployee es la LinkedList con los datos que se van a guardar
 * \return Si se pudo guardar devuelve un 0. Caso contarrio devuelve -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){

     int valorRetorno=-1;


    FILE* pFile = fopen(path,"w");



    if( pFile != NULL && !parser_SaveToText( pFile, pArrayListEmployee ))
      {

          valorRetorno = 0;
       }

    fclose(pFile);

    return valorRetorno;
}




/** \brief Guarda los datos de  los empleados en el  archivo  data.bin modo binario
  * \param path es el camino donde se guarda el archivo en moo texto
  * \param pArrayListEmployee es la LinkedList con los datos que se van a guardar
 * \return Si se pudo guardar devuelve un 0. Caso contarrio devuelve -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
      int valorRetorno = -1;

     FILE* pFile = fopen(path,"wb");

    if(pFile != NULL && !parser_SaveToBinary(pFile,pArrayListEmployee))
    {
        valorRetorno = 0;
    }
    fclose(pFile);


    return valorRetorno;
}




/** \brief Carga datos de empleados desde el archivo data.csv en modo texto
 * \param path es el camino del archivo a leer
 * \param pArrayListEmployee es el LinkedList donde se cargan los datos
 * \return Si el array es distinto de NULL y si el archivo existe se devuelve un 0. Caso contrario devuelve -1
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile;
    pFile=fopen( path, "r" );
     int valorRetorno= -1;
    if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
    {
    valorRetorno = 0;
    }

    fclose(pFile);

    return valorRetorno;
}

/** \brief Carga datos de empleados desde el archivo data.bin en modo binario
  * \param path es el camino del archivo a leer
 * \param   pArrayListEmployee es el LinkedList donde se cargan los datos
 * \return  Si el array es distinto de NULL y si el archivo existe se devuelve un 0. Caso contrario devuelve -1
  */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    FILE* pFile;
        pFile=fopen( path, "rb" );
    int valorRetorno=-1;


    if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
    {
    printf("\nEL ARCHIVO SE CARGO CORRECTAMENTE");

    valorRetorno=0;
    }
    fclose(pFile);

    return valorRetorno;

}


/** \brief  Modifica LoS  datos de un empleado
  * \param  pArrayListEmployee es el LinkedList desde donde se edita un empleado
 * \return  Si logra modificarlo devuelve 0. Caso contrario devuelve -1
*/
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int valorRetorno = -1;
    int AuxiliarID;
    int id;

    Employee* empleado;

     char nombre[32];
int horasTrabajadas;

    int sueldo;


     if( pArrayListEmployee!= NULL)
    {
        if(!gl_getValidNumber(&id,"\n\nINGRESE EL ID A MODIFICAR: ","ERROR. INGRESE NUMERO  VALIDO",0,99999,5))
        {

            for(i = 0; i< ll_len(pArrayListEmployee); i++)
            {
                empleado = ll_get( pArrayListEmployee,i);

                Employee_getId(empleado,&AuxiliarID);

                if(AuxiliarID==id)
                {

                             if( !gl_getValidName(nombre,32,"\nINGRAR EL NOMBRE: ","ERROR.INGRESAR NOMBRE CORRECTAMENTE: ",5 )&&
           !gl_getValidNumber(&horasTrabajadas,"\nINGRESAR LAS  HORAS TRABAJADAS: ","ERROR.INGRESAR HORAS TRABAJADAS: ",0,3000,5)&&
              !gl_getValidNumber(&sueldo,"INGRESAR EL SUELDO: ","ERROR.INGRESAR SUELDO: ",0,300000,5))
                    {

                        if(!Employee_setNombre(empleado, nombre)&&!Employee_setHorasTrabajadas(empleado, horasTrabajadas)&&
                                !Employee_setSueldo(empleado, sueldo)                                )
                        {
                            valorRetorno=0;

                            break;
                        }

                    }
                    else
                    {

                        break;
                    }
                }
            }
        }

    }
    return valorRetorno;
}

/** \brief Baja de empleado
  * \param pArrayListEmployee Es la LinkedList de empleados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int AuxiliarID;
    int valorRetorno = -1;
    int i;
    int id;

    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        if(!gl_getValidNumber(&id,"Ingrese el ID del empleado a borrar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);

               Employee_getId(empleado,&AuxiliarID);

               if(AuxiliarID == id)

               {
                    Employee_delete(empleado);

                    ll_remove(pArrayListEmployee,i);

                    valorRetorno = 0;

                    break;
               }

            }
        }

    }
    return valorRetorno;
}

/** \brief Lista los empleados
  * \param pArrayListEmployee Es la LinkedList del cual se listan los empleados
 * \return Si el LinkedList es distinto de NULL devuelve un 0 . Caso contarrio devuelve un -1
  */
/** \brief Ordena a los empleados segun el criterio pedido
  * \param pArrayListEmployee es el LinkedList que se va a ordenar
 * \return Si se ordeno devuelve un 0 . Caso contrario devuelve un -1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int valorRetorno=-1;
    if(pArrayListEmployee != NULL)

    {
        if(!ll_sort (pArrayListEmployee, Employee_criterioSortNombre, 1))
        {
            valorRetorno=0;
        }

    }

          return valorRetorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int valorRetorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* AuxiliarPemployee;

    if(pArrayListEmployee != NULL)
    {
        valorRetorno = 0;

        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            AuxiliarPemployee = ll_get(pArrayListEmployee,i);
            Employee_getNombre(AuxiliarPemployee,nombre);
            Employee_getId(AuxiliarPemployee,&id);
            Employee_getSueldo(AuxiliarPemployee,&sueldo);
            Employee_getHorasTrabajadas(AuxiliarPemployee,&horasTrabajadas);



            printf("\nNOMBRE:%10s   ID:%6d   HORAS:%6d   SUELDO: $%10d",nombre,id,horasTrabajadas,sueldo );



        }
    }
    return valorRetorno;
}

