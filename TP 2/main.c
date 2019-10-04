#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define QTY 1000

int main()
{
    int op,order;
    int id,index;
    int SectorInt;
    char auxSector[51];
    int emptyPosition;
    int flag,option;
    char auxName[51];
    char auxLastName[51];
    char auxSalary[51];
    float SalaryFloat;

    sEmployees arrayEmployees[QTY];

    flag = initEmployees(arrayEmployees, QTY);

     do
    {
        system("cls");
        option=getInt("\n1 - ADD EMPLOYEES\n2 - MODIFY\n3 - REMOVE EMPLOYEES\n4 - PRINT\n5 - EXIT\n\n\n");
        switch(option)
        {
        case 1:
        {
            system("cls");
            emptyPosition=findFirstFreeId(arrayEmployees,QTY);
            if(emptyPosition == -1)
            {
                printf("\n\nNO FREE PLACES!!!\n");
                break;
            }
            getInformation(auxName,auxLastName,auxSalary,auxSector);
            SalaryFloat=atof(auxSalary);
            SectorInt =atoi(auxSector);

            flag=addEmployee(arrayEmployees,QTY,emptyPosition,auxName,auxLastName,SalaryFloat,SectorInt);

            break;
        }
        case 2:
        {
            system("cls");
            if(flag)


            {
                printEmployees(arrayEmployees,QTY);
                printf("\n\n");
                id=getInt("ENTER ID OF THE EMPLOYEE YOU WANT TO MODIFY:");
                index=findEmployeeById(arrayEmployees,QTY,id);
                op=getInt("\n\n\n1 - MODIFY NAME\n2 - MODIFY LASTNAME\n3 - MODIFY SALARY\n4 - MODIFY SECTOR\n5 - EXIT\n\n\n");
                while(op!=5)
                {
                    switch(op)
                    {
                    case 1:
                        getString("ENTER NAME: ",auxName);
                        while(!esSoloLetras(auxName))
                        {

                            getString("ENTER NAME (ONLY LETTERS): ",auxName);
                        }
                        strcpy(arrayEmployees[index].name,auxName);
                        break;
                    case 2:
                        getString("ENTER LAST NAME: ",auxLastName);
                        while(!esSoloLetras(auxLastName))
                        {

                            getString("ENTER LAST NAME (ONLY LETTERS): ",auxLastName);
                        }
                        strcpy(arrayEmployees[index].lastName,auxLastName);
                        break;
                    case 3:
                        getString("ENTER SALARY: ",auxSalary);
                        while(!isFloat(auxSalary))
                        {
                            getString("INVALID VALUE, ENTER SALARY AGAIN: ",auxSalary);
                        }
                        SalaryFloat=atof(auxSalary);
                        arrayEmployees[id].salary = SalaryFloat;
                        break;
                    case 4:
                        getString("ENTER SECTOR: ",auxSector);
                        while(!isNumber(auxSector))
                        {
                            getString("INVALID VALUE, ENTER SECTOR AGAIN: ",auxSector);
                        }
                        SectorInt = atoi(auxSector);
                        arrayEmployees[id].sector = SectorInt;
                        break;
                    }
                    op=getInt("\n\n\n1 - MODIFY NAME\n2 - MODIFY LASTNAME\n3 - MODIFY SALARY\n4 - MODIFY SECTOR\n5 - EXIT\n\n\n");
                }

            }
            printf("THERE ARE NO EMPLOYEES\n");

            break;
        }
        case 3:
        {
            system("cls");
            if(flag)
            {
                printEmployees(arrayEmployees,QTY);
                printf("\n\n");
                id=getInt("ENTER EMPLOYEE ID YOU WANT TO LEAVE:");
                flag=removeEmployee(arrayEmployees,QTY,id-1);
                break;
            }
            printf("THERE ARE NO EMPLOYEES\n");

            break;
        }
        case 4:
            system("cls");
            if(flag)
            {
                op=getInt("\n\n\n1 - List of employees sorted alphabetically by Last Name and Sector.\n2 - Total and average wages, and how many employees exceed the average salary.\n\n\n");
                system("cls");
                switch(op)
                {
                case 1:

                    order=getInt("\n\n\n1 - Ascendente.\n2 - Descendente.\n\n\n");
                    sortEmployees(arrayEmployees,QTY,order);
                    printEmployees(arrayEmployees,QTY);

                    break;
                case 2:
                    calculate(arrayEmployees,QTY);

                    break;
                }

            }else
            {
                printf("THERE ARE NO EMPLOYEES\n");
            }


            break;

        }
    system("pause");
    }
    while(option!=5);

    return 0;
}

