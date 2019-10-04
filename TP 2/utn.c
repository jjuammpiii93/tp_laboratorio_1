#include "utn.h"
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int isNumber(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0'||str[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isFloat(char str[])
{
    int i=0;
    int pointCounter=0;
    while(str[i]!='\0')
    {
        if((str[i]!='.')&&(str[i]<'0'|| str[i]>'9'))
            return 0;
        if(str[i]=='.')
            pointCounter++;
        i++;
    }
    if(pointCounter==1||pointCounter==0)
        if((str[0]!='.')&&(str[i-1]!='.'))
            {
                return 1;

            }
    return 0;
}
