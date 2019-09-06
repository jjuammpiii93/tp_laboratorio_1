#include "dividir.h"
//hago una funcion divir y aclaro que cuando me da cero que muestre un mensaje error.
void dividir(int x,int y,float *d,char *z)
{

    if(y!=0)
    {

        *d = (float) x /(float) y ;
        *z='v';
    }
    else
    {
        *z='f';
    }


}
