#include<cs50.h>
#include<stdio.h>
int main()
{
    int min=0,bot=0;
    printf("Minutes: ");
    min=get_int();
    if(min>=0)
    {
        bot=12*min;
        printf("Bottles: %d\n",bot);
    }
    return 0;
    
}