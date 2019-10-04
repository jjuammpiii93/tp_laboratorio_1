#include "ArrayEmployees.h"
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param arrayEmp[] sEmployees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(sEmployees arrayEmp[], int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        arrayEmp[i].isEmpty= 1;
        arrayEmp[i].id=i+1;
    }
    return 0;
}


int findFirstFreeId(sEmployees arrayEmp[],int len)
{
    int i;
    for(i=0; i < len; i++)
    {
        if(arrayEmp[i].isEmpty==1)
        {
            return i;
        }
    }
    return -1;
}
void getInformation(char auxName[],char auxLastName[],char auxSalary[],char auxSector[])
{
    getString("ENTER NAME: ",auxName);
    while(!esSoloLetras(auxName))
    {

        getString("ENTER NAME (ONLY LETTERS): ",auxName);
    }

    getString("ENTER LASTNAME: ",auxLastName);
    while(!esSoloLetras(auxLastName))
    {

        getString("ENTER LASTNAME (ONLY LETTERS): ",auxLastName);
    }


    getString("ENTER SALARY: ",auxSalary);
    while(!isFloat(auxSalary))
    {
        getString("INVALID VALUE, ENTER SALARY AGAIN: ",auxSalary);
    }

    getString("ENTER SECTOR: ",auxSector);
    while(!isNumber(auxSector))
    {
        getString("INVALID VALUE, ENTER SECTOR AGAIN: ",auxSector);
    }

}
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param arrayEmp[] sEmployees
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(sEmployees arrayEmp[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    strcpy(arrayEmp[id].name,name);
    strcpy(arrayEmp[id].lastName,lastName);
    arrayEmp[id].salary = salary;
    arrayEmp[id].sector = sector;
    arrayEmp[id].isEmpty = 0;
    return 1;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param arrayEmp[] sEmployees
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(sEmployees arrayEmp[], int len,int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(id==arrayEmp[i].id)
        {
            return i;
        }
    }
    return NULL;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param arrayEmp[] sEmployees
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(sEmployees arrayEmp[],int len,int id)
{
    int i;
    if(!arrayEmp[id].isEmpty)
    {
        arrayEmp[id].isEmpty=1;
    }
    else
    {
        printf("ERROR,NONEXISTENT EMPLOYEE ");
    }
    for(i=0; i<len; i++)
    {
        if(arrayEmp[i].isEmpty==0)
            return 1;
    }
    return 0;
}
/** \brief print the content of employees array
*
* \param arrayEmp[] sEmployees
* \param length int
* \return int
*
*/
void printEmployees(sEmployees arrayEmp[], int length)
{
    printf("------------- EMPLOYEES -------------\n\n");

    printf("%*s%*s%*s%*s%*s\n\n",3,"ID",18,"LASTNAME",18,"NAME",12,"SALARY",7,"SECTOR");

    for (int i=0; i<length; i++)
    {
        if (arrayEmp[i].isEmpty == 0)
        {
            printf("%*d",3,arrayEmp[i].id);
            printf("%*s",18,arrayEmp[i].lastName);
            printf("%*s",18,arrayEmp[i].name);
            printf("%*.2f",12,arrayEmp[i].salary);
            printf("%*d\n",7,arrayEmp[i].sector);
        }
    }
    printf("\n\n");

}
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param arrayEmp[] sEmployees
* \param len int
* \param order int [1] indicate UP - [2] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void sortEmployees(sEmployees arrayEmp[], int len, int order)
{
    sEmployees aux;
    int i,j;

    if(order==1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(arrayEmp[i].lastName,arrayEmp[j].lastName)>0)
                {
                    aux=arrayEmp[i];
                    arrayEmp[i]=arrayEmp[j];
                    arrayEmp[j]=aux;
                }
                else if(!strcmp(arrayEmp[i].lastName,arrayEmp[j].lastName) && arrayEmp[i].sector > arrayEmp[j].sector)
                {
                    aux=arrayEmp[i];
                    arrayEmp[i]=arrayEmp[j];
                    arrayEmp[j]=aux;
                }
            }
        }
    }
    if(order==2)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(arrayEmp[i].lastName,arrayEmp[j].lastName)<0)
                {
                    aux=arrayEmp[i];
                    arrayEmp[i]=arrayEmp[j];
                    arrayEmp[j]=aux;
                }
                else if(!strcmp(arrayEmp[i].lastName,arrayEmp[j].lastName) && arrayEmp[i].sector < arrayEmp[j].sector)
                {
                    aux=arrayEmp[i];
                    arrayEmp[i]=arrayEmp[j];
                    arrayEmp[j]=aux;
                }
            }
        }


    }
}



/** \brief calculate total and average salary
 *
 * \param arrayEmp[] sEmployees
 * \param len int
 * \return void
 *
 */
void calculate(sEmployees arrayEmp[],int len)
{
    float prom,total=0.0;
    int i,qty=0;

    for(i=0; i<len; i++)
    {
        if(arrayEmp[i].isEmpty==0)
        {
            qty++;
            total+=arrayEmp[i].salary;
        }
    }
    prom=total/qty;
    printf("TOTAL SALARY: %.2f\n",total);
    printf("AVERAGE SALARY: %.2f\n",prom);
    qty=0;
    for(i=0; i<len; i++)
    {
        if(arrayEmp[i].salary>prom)
        {
            qty++;
        }
    }
    printf("NUMBER OF EMPLOYEES THET EXCEED THE AVERAGE ARE: %d\n\n",qty);
}
