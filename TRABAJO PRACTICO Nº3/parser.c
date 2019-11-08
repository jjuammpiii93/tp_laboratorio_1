#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char buffer[4][50];
    int cant;
    Employee* auxEmployee;
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
    do
    {
        cant =fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        if(cant == 4)
        {
            auxEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(auxEmployee==NULL)
            {
                return 0;
                break;
            }
            if(ll_add(pArrayListEmployee, auxEmployee))
            {
                return 0;
                break;
            }
        }
        else
        {
            return 0;
            break;
        }
    }
    while(!feof(pFile));
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* this;
    int status;
    while(!feof(pFile))
    {
        this = employee_new();
        status = fread(this, sizeof(Employee), 1, pFile);

        if(status == 1 && this != NULL)
            ll_add(pArrayListEmployee, this);

        else if(status != 1)
        {
            if(!feof(pFile))
            {
                printf("\tError al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("\tEmpleados Cargados\n\n");
                return 1;
            }
        }
    }
    fclose(pFile);
    return 0;

}
