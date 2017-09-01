#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int h,i,j,k;
    
    
    do
    {
        printf("Height: ");
        h=get_int();

            for(i=1;i<=h;i++)
            {
                for(j=i;j<h;j++)
                printf(" ");
                for(k=1;k<2+i;k++)
                printf("#");
                printf("\n");
            }
        
    }while(h<0||h>23);
}