#include<cs50.h>
#include<math.h>
#include<stdio.h>
int main()
{
    float f;
    int sum,quarter,dime,nickel,rem,total=0;
    do{
        printf("O hai! How much change is owed?\n");
        f=get_float();
        sum=round(f*100);
        quarter=sum/25;
        rem=sum%25;
        dime=rem/10;
        rem=rem%10;
        nickel=rem/5;
        rem=rem%5;
        total=quarter+dime+nickel+rem;
        printf("%d\n",total);
    }while(f<0);
    return 0;
}