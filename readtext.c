#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
struct employee
{
    int empid;
    char empname[20];
}obj1[10];
//struct employee obj2[10];
int main()
{   int i;
    FILE *fp;
    fp=fopen("employeedb","rb");
    for(i=1;i<3;i++)
    {
    fread(&obj1[i],sizeof(obj1),1,fp);
    }
    for(i=1;i<3;i++)
    {
        printf("%d %s",obj1[i].empid,obj1[i].empname);
    }
    fclose(fp);
}

