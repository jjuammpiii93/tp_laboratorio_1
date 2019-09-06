#include "IngresarOperando.h"
//hago una funcion que me pide que ingrese dos valores para realizar una operacion.
void IngresarOperando(int *x)
{

    int y;
    printf("INGRESE OPERANDO: ");
    scanf("%d",&y);
    *x=y;
    printf("EL VALOR INGRESADO ES %d\n",y);
    printf("\n");
}
