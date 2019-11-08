#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int menu();
int menu2(int* orden);
void employee_mostrarEmployees(LinkedList* lista);
void employee_mostrarEmployee(Employee* emp);


int employee_nombre(void* employeeA, void* employeeB);
int employee_horasTrabajadas(void* employeeA, void* employeeB);
int employee_sueldo(void* employeeA,void* employeeB);
int employee_id(void* employeeA, void* employeeB);
#endif // employee_H_INCLUDED
