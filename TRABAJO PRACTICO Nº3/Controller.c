#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "r");
    if(pFile!=NULL&&path!=NULL)
    {
        if(!(parser_EmployeeFromText(pFile,pArrayListEmployee)))
            return 0;
    }
    fclose(pFile);
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile!=NULL&&path!=NULL)
    {
        if(!(parser_EmployeeFromBinary(pFile,pArrayListEmployee)))
            return 0;
    }
    fclose(pFile);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int idAux,sueldoAux,horasAux,i,idComprobacion;
    char nombre[128],buffer[3][20];
    if(pArrayListEmployee!=NULL)
    {
        printf("***ALTA***\n\n");
        do
        {
            utn_getEntero(&idAux,"Ingrese el id del empleado: ","Error coloque un id del 1 al 10000: ",1,10000);
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(auxEmployee,&idComprobacion);
                if(idComprobacion==idAux)
                {
                    utn_getEntero(&idAux,"ID ya usado coloque otro: ","Error coloque un id del 1 al 10000:",1,10000);
                    i=0;
                }
            }
        }
        while(i!=ll_len(pArrayListEmployee));
        itoa(idAux,buffer[0],10);
        getStringLetras("Ingrese nombre del empleado: ","Error solo debe llevar letras: ",nombre);
        utn_getEntero(&horasAux,"Horas trabajdas del empleado: ","Horas entre 40 y 500: ",40,500);
        itoa(horasAux,buffer[1],10);
        utn_getEntero(&sueldoAux,"Sueldo del empleado: ","Sueldo entre 6000 y 250000: ",6000,250000);
        itoa(sueldoAux,buffer[2],10);
        auxEmployee=employee_newParametros(buffer[0],nombre,buffer[1],buffer[2]);
        if(auxEmployee != NULL)
        {
            ll_add(pArrayListEmployee,auxEmployee);
            return 1;
        }
    }
    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char nombre[128];
    int idAux,idAuxRemove,i,sueldoAux,horasAux,index;
    Employee* auxEmployee=employee_new();
    if(pArrayListEmployee != NULL&&auxEmployee!=NULL)
    {
        employee_mostrarEmployees(pArrayListEmployee);
        utn_getEntero(&idAuxRemove,"Ingrese el ID del empleado que desea modificar: ","ERROR los id van de 1 a 10000: ",1,10000);
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(auxEmployee,&idAux))
            {
                if(idAux==idAuxRemove)
                {
                    index=ll_indexOf(pArrayListEmployee,auxEmployee);
                    printf("ID: %d\n",idAux);
                    getStringLetras("Ingrese nuevo nombre del empleado: ","Error solo debe llevar letras: ",nombre);
                    employee_setNombre(auxEmployee,nombre);
                    utn_getEntero(&horasAux,"Horas trabajdas del empleado: ","Horas entre 40 y 500: ",40,500);
                    employee_setHorasTrabajadas(auxEmployee,horasAux);
                    utn_getEntero(&sueldoAux,"Sueldo del empleado: ","Sueldo entre 6000 y 250000:",6000,250000);
                    employee_setSueldo(auxEmployee,sueldoAux);
                    ll_set(pArrayListEmployee,index,auxEmployee);
                    return 1;
                    break;
                }
            }
        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idAux,idAuxRemove,i;
    Employee* auxEmployee=employee_new();
    if(pArrayListEmployee != NULL&&auxEmployee!=NULL)
    {
        employee_mostrarEmployees(pArrayListEmployee);
        utn_getEntero(&idAuxRemove,"Ingrese el ID del empleado: ","ERROR los id van de 1 a 10000:",1,10000);
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(employee_getId(auxEmployee,&idAux))
            {
                if(idAux==idAuxRemove)
                {
                    return 1;
                    ll_remove(pArrayListEmployee,i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("ERROR volver a intentar \n");
    }
    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(ll_len(pArrayListEmployee)==0)
    {
        return 0;
    }
    else
    {
        printf("%s %15s %s %s\n","id","nombre","horas","sueldo");
        employee_mostrarEmployees(pArrayListEmployee);
        return 1;
    }
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion,orden;
    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        opcion=menu2(&orden);
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,employee_id,orden);
            return 1;
            break;
        case 2:
            ll_sort(pArrayListEmployee,employee_nombre,orden);
            return 1;
            break;
        case 3:
            ll_sort(pArrayListEmployee,employee_horasTrabajadas,orden);
            return 1;
            break;
        case 4:
            ll_sort(pArrayListEmployee,employee_sueldo,orden);
            return 1;
            break;
        }
    }
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "w");
    Employee* p;
    int i;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
        }
        if(i==ll_len(pArrayListEmployee))
        {
            return 1;
        }
    }
    fclose(pFile);
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path, "wb");
    Employee* p;
    int i;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            p = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(p, sizeof(Employee), 1, pFile);
        }
        if(i==ll_len(pArrayListEmployee))
        {
            return 1;
        }
    }
    fclose(pFile);
    return 0;
}

