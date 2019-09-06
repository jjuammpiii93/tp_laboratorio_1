#include "InformarResultados.h"
//muestro el resultado de casa funcion que hago.
void InformarResultado(int s,int r,int m,float d,int fa,int fb,char z)
{
    printf("EL RESULTADO DE A+B = %d\n",s);
    printf("EL RESULTADO DE A-B = %d\n",r);
    printf("EL RESULTADO DE AxB = %d\n",m);
    if(z=='v')
    {
        printf("EL RESULTADO DE A/B = %f\n",d);
    }
    if(z=='f')
    {
        printf("NO ES POSIBLE DIVIDIR POR CERO\n");
    }

    printf("EL FACTORIAL DE A ES: %d Y EL FACTORIAL DE B ES: %d\n",fa,fb);
    printf("\n");



}
