#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main()
{
    string str=get_string();
    int l=strlen(str);
    printf("%c",toupper(str[0]));
    for(int i=0;i<l;i++)
    {
        if(str[i]==' ')
        printf("%c",toupper(str[i+1]));
        
    }
    printf("\n");
    return 0;
}