#include "Employee.h"


int menu()
{
    int opcion;
    printf("/*********************************************************\n\n");
    printf("Menu:\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");
    printf("***********************************************************/");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\n\nERROR las opciones son numericas del 1 al 10: ",1,10);
    return opcion;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* employee=employee_new();
    int flag=0;
    if(employee_setId(employee,atoi(idStr)))
    {
        if(employee_setNombre(employee,nombreStr))
        {
            if(employee_setHorasTrabajadas(employee,atoi(horasTrabajadasStr)))
            {
                if(employee_setSueldo(employee,atoi(sueldoStr)))
                    flag=1;
            }
        }
    }
    if(flag==0)
    {
        employee = NULL;
    }
    return employee;
}

Employee* employee_new()
{
    Employee* employee=(Employee*) malloc(sizeof(Employee));

    if(employee == NULL)
    {
        printf("MEMORIA LLENA...");
        system("Pause");
    }
    return employee;
}
int employee_setId(Employee* this,int id)
{
    if(this!=NULL&&id>0)
    {
        this->id=id;
        return 1;
    }
    return 0;
}
int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    return 0;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL&&horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        return 1;
    }
    return 0;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL&&sueldo>0)
    {
        this->sueldo=sueldo;
        return 1;
    }
    return 0;
}
void employee_mostrarEmployees(LinkedList* lista)
{
    int i;
    Employee* employee;
    for(i=0; i < ll_len(lista); i++)
    {
        employee = (Employee*)ll_get(lista, i);
        employee_mostrarEmployee(employee);
    }
}
void employee_mostrarEmployee(Employee* employee)
{
    int id,sueldo,horasTrabajadas;
    char nombre[128];
    if(employee!=NULL)
    {
        employee_getId(employee,&id);
        employee_getHorasTrabajadas(employee,&horasTrabajadas);
        employee_getSueldo(employee,&sueldo);
        employee_getNombre(employee,nombre);
        printf("%*d %*s %*d %*d\n",6,id,15,nombre,6,horasTrabajadas,8,sueldo);

    }
}
int employee_getId(Employee* this,int* id)
{
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        return 1;
    }
    return 0;
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        return 1;
    }
    return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        return 1;
    }
    return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        return 1;
    }
    return 0;
}

int menu2(int* orden)
{
    int opcion;
    printf("***Ordenamiento***\n");
    printf("\n1) Ordenar por id");
    printf("\n2) Ordenar por nombre");
    printf("\n3) Ordenar por horas trabajadas");
    printf("\n4) Ordenar por sueldo");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","ERROR Las opciones son de 1 a 4: ",1,4);
    printf("\nColoque 0 para que sea Desendente");
    printf("\nColoque 1 para que sea Ascendente");
    utn_getEntero(orden,"\n\nDe que manera lo quiere ordenar: ","ENTRE 0 Y 1: ",0,1);
    return opcion;
}


int employee_nombre(void* employeeA, void* employeeB)
{
    char nombre[2][128];
    if(employeeA!=NULL&&employeeA!=NULL)
    {
        employee_getNombre(((Employee*)employeeA),nombre[0]);
        employee_getNombre(((Employee*)employeeB),nombre[1]);
    }
    return strcmp(nombre[0],nombre[1]);
}

int employee_horasTrabajadas(void* employeeA, void* employeeB)
{
    int horasAux1,horasAux2;
    if(employeeA!=NULL&&employeeB!=NULL)
    {
        employee_getHorasTrabajadas(((Employee*)employeeA),&horasAux1);
        employee_getHorasTrabajadas(((Employee*)employeeB),&horasAux2);
        if(horasAux1>horasAux2)
        {
            return 1;
        }
        else if(horasAux1<horasAux2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
int employee_sueldo(void* employeeA,void* employeeB)
{
    int sueldoAux1,sueldoAux2;
    if(employeeA!=NULL&&employeeB!=NULL)
    {
        employee_getSueldo(((Employee*)employeeA),&sueldoAux1);
        employee_getSueldo(((Employee*)employeeB),&sueldoAux2);
        if(sueldoAux1>sueldoAux2)
        {
            return 1;
        }
        else if(sueldoAux1<sueldoAux2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int employee_id(void* employeeA, void* employeeB)
{
    int idAux1,idAux2;
    if(employeeA!=NULL&&employeeA!=NULL)
    {
        employee_getId(((Employee*)employeeA),&idAux1);
        employee_getId(((Employee*)employeeB),&idAux2);
        if(idAux1>idAux2)
        {
            return 1;
        }
        else if(idAux1<idAux2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

