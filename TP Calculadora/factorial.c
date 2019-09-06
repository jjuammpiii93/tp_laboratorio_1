#include "factorial.h"
// hago una funcion factorial.
void factorial(int n,int *f)
{
    int  i;
    *f=1;
    for(i=1;i<=n;i++)
    {
        *f*=i;
    }

}
