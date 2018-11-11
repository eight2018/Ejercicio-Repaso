#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "gl.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int Vflag = 0;

    int opcion;


    do
    {
        printf  ("\nTP3 GUSTAVO LAURENZANO 1 G \n");
        printf  ("-------------------------------------------------------------------------\n");
        printf  ("MENU DE OPCIONES:\n");
        printf ("\n1) CARGAR LOS DATOS DE EMPLEADOS DESDE ARCHIVO data.csv (en modo texto)");
        printf ("\n2) CARGAR LOS DATOS DE EMPLEADOS DESDE ARCHIVO data.bin (en modo binario)");
        printf ("\n3) ALTA DE EMPLEADO");
        printf ("\n4) MODIFICAR DATOS DE UN EMPLEADO");
        printf ("\n5) BAJA DE EMPLEADO");
        printf ("\n6) LISTAR EMPLEADOS");
         printf("\n7) ORDENAR EMPLEADOS POR ORDEN ALFABETICO");
        printf ("\n8) CARGAR LOS DATOS DE EMPLEADOS EN EL  ARCHIVO data.csv (en modo texto)");
        printf ("\n9) CARGAR LOS DATOS DE EMPLEADOS EN EL  ARCHIVO data.bin (en modo binario)");
        printf("\n10)SALIR");
        printf  ("\n-------------------------------------------------------------------------\n");

        gl_getValidNumber( &opcion, "\n INGRESE UNA OPCION DEL MENU: ","ERROR. INGRESE UN NUMERO VALIDO DEL 1 AL 10",1,10,1);

        switch(opcion)
        {
        case 1:

            if(!controller_loadFromText( "data.csv", listaEmpleados))
            {
                Vflag = 1;
                printf("\nLOS DATOS FUERON CARGADOS CON EXITO\n");
            }
            printf("\nTAMANO DE LA LISTA: %d \n",ll_len(listaEmpleados));
            break;

        case 2:
               printf("\nEL TAMANO DEL LINKEDLIST ES: %d",ll_len(listaEmpleados));
                if(!controller_loadFromBinary( "data.bin", listaEmpleados))
            {
                Vflag = 1;
                printf("LOS DATOS FUERON CARGADOS CON EXITO\n");
            }
            printf("\nEL TAMANO DEL LINKEDLIST ES: %d",ll_len(listaEmpleados));
            break;

        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                Vflag = 1;
                printf("EL EMPLEADO FUE AGREGADO CON EXITO");
            }
            else
            {
                printf("NO PUDO AGREGARSE UN EMPLEADO");
            }
            break;

        case 4:
            controller_ListEmployee(listaEmpleados);
            if(Vflag)
            {
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("EL EMPLEADO FUE MODIFICADO CON EXITO");
                }
                else
                {
                    printf("NO PUDO MODIFICARSE EL EMPLEADO");
                }
            }
            else
            {
                printf("NO HAY EMPLEADOS PARA MODIFICAR");
            }
            break;

        case 5:
            if(Vflag)
            {
                controller_ListEmployee ( listaEmpleados );

                if(!controller_removeEmployee ( listaEmpleados ) )
                {
                    printf("EL EMPLEADO SE ELIMINO CON EXITO");
                }
                else
                {
                    printf("NO SE PUDO BORRAR EL EMPLEADO");
                }
            }
            else
            {
                printf("NO HAY EMPLEADOS PARA ELIMINAR");
            }
            break;

        case 6:
            if(Vflag)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("NO HAY EMPLEADOS PARA REALIZAR EL LISTADO");

            }
            break;

        case 7:

            if(Vflag)

            {
                printf("\nREALIZANDO ORDENAMIENTO ALFABETICO DE LA A LA Z, POR FAVOR AGUARDE");

                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("\nORDEN  REALIZADO CON EXITO");
                }
                else
                {
                    printf("NO SE PUDO REALIZAR EL ORDENAMIENTO");
                }
            }
            else
            {
                printf("NO HAY EMPLEADOS PARA ORDENAR");
            }

            break;

        case 8:
            if(Vflag)
            {
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nEL ARCHIVO FUE GUARDADO EXITOSAMENTE");
                }
                else
                {
                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO");
                }
            }
            else
            {
                printf("NO HAY DATOS CARGADOS");
            }
            break;

        case 9:
            if(Vflag)
            {
                if(!controller_saveAsBinary( "data.bin", listaEmpleados))
                {
                    printf("\nEL ARCHIVO FUE GUARDADO EXITOSAMENTE");
                }

                else

                {
                    printf("\nNO SE PUDO GUARDAR EL ARCHIVO");
                }
            }
            else
            {
                printf("NO HAY DATOS CARGADOS PARA GUARDAR");
            }
            break;
        }
        pause();
        cleanStage();
    }
    while(opcion!=10);
    return 0;
}
