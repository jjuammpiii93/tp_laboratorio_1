#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "IngresarOperando.h"
#include "suma.h"
#include "resta.h"
#include "multiplicar.h"
#include "dividir.h"
#include "factorial.h"
#include "InformarResultados.h"
//en el main llamo cada una de las funciones que cree.
int main()
{
    int op,a,b,suma,resta,multiplicacion,factA,factB;
    float division;
    char divCero;
    do
    {
        op = menu();

    switch(op)
    {
    case 1:
        IngresarOperando(&a);
        break;
    case 2:
        IngresarOperando(&b);
        break;
    case 3:
        sumar(a,b,&suma);
        restar(a,b,&resta);
        multiplicar(a,b,&multiplicacion);
        dividir(a,b,&division,&divCero);
        factorial(a,&factA);
        factorial(b,&factB);
        break;
    case 4:
        InformarResultado(suma,resta,multiplicacion,division,factA,factB,divCero);
        break;

    }

    }while(op!=5);

    return 0;
}
