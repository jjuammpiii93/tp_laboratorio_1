#include "menu.h"
//muestro el menu y doy a elegir una opcion.
int menu()
{
    int opcion;

    printf("1. INGRESE PRIMER OPERANDO: \n");
    printf("2. INGRESE SEGUNDO OPERANDO:\n");
    printf("3. CALCULAR TODAS LAS OPERACIONES:\n");
    printf("4. INFORMAR RESULTADOS:\n");
    printf("5. SALIR \n\n");
    printf("INGRESE OPCION : ");
    do
    {
        scanf("%d",&opcion);

    }while(opcion<1||opcion>5);
    printf("\n");




    return opcion;





}

