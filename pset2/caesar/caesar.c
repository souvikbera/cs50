#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>
int main(int argc,string argv[])
{
    if(argc!=2)
    {
        printf("error");
    return 1;
    }
    int k=atoi(argv[1]);
    k=k%26;
    printf("plaintext:");
    string c=get_string();
    printf("ciphertext:");
    int l=strlen(c);
    for(int i=0;i<l;i++)
    {
        if(c[i]>=65&&c[i]<=90)
        {
            if(c[i]+k>90)
            c[i]=c[i]+k-26;
            else
            c[i]=c[i]+k;
        }
        else if(c[i]>=97&&c[i]<=122)
        {
            if(c[i]+k>122)
            c[i]=c[i]+k-26;
            else
            c[i]=c[i]+k;
        }
        printf("%c",c[i]);
    }
    printf("\n");
    return 0;
}