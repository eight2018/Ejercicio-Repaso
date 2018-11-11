#ifndef Employee_H_INCLUDED
#define Employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

}Employee;

Employee* Employee_new();
int Employee_delete();



Employee* Employee_newParam(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
Employee* Employee_new_Tec(char* nombre,int horasTrabajadas,int sueldo);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);


int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);


int Employee_criterioSortNombre(void* thisA,void* thisB);
int Employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);




#endif // Employee_H_INCLUDED
