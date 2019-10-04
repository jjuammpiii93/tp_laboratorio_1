#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;

    int sector;
    int isEmpty;
} sEmployees;

int findFirstFreeId(sEmployees[],int);
void getInformation(char[],char[],char[],char[]);
int addEmployee(sEmployees[], int, int, char [],char [],float,int);
int initEmployees(sEmployees[],int );
int findEmployeeById(sEmployees[],int,int);
int removeEmployee(sEmployees[],int,int);
void printEmployees(sEmployees [], int);
void sortEmployees(sEmployees [], int, int);
void calculate(sEmployees [],int);

