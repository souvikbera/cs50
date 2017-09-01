#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
int main(int argc,char* argv[])
{
    FILE* fp=fopen(argv[1],"r");
    //if input file cannot be opened exit with error msg
    if(argc!=2)
    {
        fprintf(stderr,"error in arguments");
        return 1;
    }
    if(fp==NULL)
    {
        fprintf(stderr,"unable to open the file");
        return 1;
    }
    FILE *out=NULL;//ouput file
    //int open=0;
    int count=0;//counts no.of jpeg
    char picname[8];
    uint8_t buffer[512];
    while(fread(buffer,sizeof(buffer),1,fp)>0)//not end of file
    {
        
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff &&(buffer[3]>=0xe0&&buffer[3]<=0xef))//check for start
        {
            if(out!=NULL) 
            fclose(out);
        
        sprintf(picname,"%03d.jpg",count);
        count++;
        out=fopen(picname,"w");//open file for writing
        fwrite(buffer,sizeof(buffer),1,out);
        }
        else if(count>0)
        {
            fwrite(buffer,sizeof(buffer),1,out);//writibg buffer
            
        }
   
    }
    if(count>0)
    fclose(out);
    fclose(fp);
    return 0;

}