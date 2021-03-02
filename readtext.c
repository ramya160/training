#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
struct employee
{
    int empid;
    char empname[20];
}obj1[10];
struct employee obj2[10];
int main()
{   int i;
    FILE *fp;
    fp=fopen("employeedb","rb");
    for(i=0;i<2;i++)
    {
    fread(&obj2[i],sizeof(obj2),1,fp);
    }
    for(i=0;i<2;i++)
    {
        printf("%d %s",obj2[i].empid,obj2[i].empname);
    }
    printf("read successfully");
}

