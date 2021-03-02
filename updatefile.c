#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
struct employee
{
    int empid;
    char empname[20];
}obj1[10];
int main()
{   int i;int id;
    FILE *fp;
    fp=fopen("employeedb","r+b");
    printf("enter the id to update");
    scanf("%d",&id);
    while((fread(&obj1[i],sizeof(obj1),1,fp)==1))
    { 
        for(i=1;i<3;i++)
        {
             if(obj1[i].empid==id)
               {    
                   printf("enter new data");
                   scanf("%d %s",&obj1[i].empid,&obj1[i].empname);
                   fseek(fp,sizeof(obj1[i])*i,SEEK_SET);
                   fwrite(&obj1[i],sizeof(obj1),1,fp);
               }
        }   
    }
 fclose(fp);
}

