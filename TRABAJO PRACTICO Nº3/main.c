#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            if(!(controller_loadFromText("data.csv",listaEmpleados)))
            {
                printf("\nNO SE PUDO CARGAR EL ARCHIVO data.csv\n\n");
                system("pause");
            }
            else
            {
                printf("\nARCHIVO CARGADO...\n\n");
                system("pause");
            }
            break;
        case 2:
            if(!(controller_loadFromBinary("data.bin",listaEmpleados)))
            {
                printf("\nNO SE PUDO CARGAR EL ARCHIVO data.bin\n\n");
                system("pause");
            }
            else
            {
                printf("\nARCHIVO CARGADO...\n\n");
                system("pause");
            }

            break;
        case 3:
            if(controller_addEmployee(listaEmpleados))
            {
                printf("\nSE AGREGO EMPLEADO EXITOSAMENTE...\n");
                system("pause");
            }
            else
            {
                printf("\nERROR,NO SE PUDO AGREGAR EMPLEADO...\n");
                system("pause");
            }
            break;
        case 4:
            system("cls");
            if(controller_editEmployee(listaEmpleados))
            {
                printf("SE EDITO EMPLEADO EXITOSAMENTE...\n");
                system("pause");
            }
            else
            {
                printf("EMPLEADO INEXISTENTE...\n");
                system("pause");
            }

            break;
        case 5:
            system("cls");
            if(controller_removeEmployee(listaEmpleados))
            {
                printf("SE ELIMINO EMPLEADO EXITOSAMENTE...\n");
                system("pause");
            }
            else
            {
                printf("EMPLEADO INEXISTENTE...\n");
                system("pause");
            }
            break;
        case 6:
            system("cls");
            if(!(controller_ListEmployee(listaEmpleados)))
            {
                printf("NO SE CARGO NINGUN ARCHIVO\n\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(controller_sortEmployee(listaEmpleados))
            {
                printf("\nLISTA ORDENADA....\n");
                system("pause");
            }

            break;
        case 8:
            if(controller_saveAsText("data1.csv",listaEmpleados))
            {
                printf("\nARCHIVO GUARDADO EXITOSAMENTE...\n");
                system("pause");
            }
            else
            {
                printf("\nERROR, NO SE PUDO GUARDAR EL ARCHIVO...\n");
                system("pause");
            }
            break;
        case 9:
            if(controller_saveAsBinary("data1.bin",listaEmpleados))
            {
                printf("\nARCHIVO GUARDADO EXITOSAMENTE...\n");
                system("pause");
            }
            else
            {
                printf("\nERROR, NO SE PUDO GUARDAR EL ARCHIVO...\n");
                system("pause");
            }
            break;

        }
    }
    while(option != 10);

    return 0;
}
