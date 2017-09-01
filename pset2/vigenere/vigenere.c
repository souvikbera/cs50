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
    string k=argv[1];
    //char* k=strupr(z);
    int len=strlen(k);
    for(int i=0;i<len;i++)
    {
        if(k[i]>=97 && k[i]<=122)
        k[i]=toupper(k[i]);//converting all letters to uppercase
    }
    //printf("%s",k);
    printf("plaintext:");
    string c=get_string();
    printf("ciphertext:");
    int l=strlen(c);
    int j=0;
    for(int i=0;i<l;i++)
    {
        if(c[i]>=65&&c[i]<=90&&k[j]>=65&&k[j]<=90)
        {
            if(c[i]+k[j]-65>90)
            c[i]=c[i]+k[j]-91;//26+65=91
            else
            c[i]=c[i]+k[j]-65;
            j++;
        }
        else if(c[i]>=97&&c[i]<=122&&k[j]>=65&&k[j]<=90)
        {
            if(c[i]+k[j]-65>122)
            c[i]=c[i]+k[j]-91;//26+65=91
            else
            c[i]=c[i]+k[j]-65;
            j++;
        }
        printf("%c",c[i]);
        //printf("%d",j);
        if(j==len)
        j=0;
    }
    printf("\n");
    return 0;
}