#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
struct employee
{
    int empid;
    char empname[20];
}obj1[10];
int main()
{   int i;
    FILE *fp;
    fp=fopen("employeedb","wb");
    for(i=1;i<=3;i++)
    {
        scanf("%d %s",&obj1[i].empid,&obj1[i].empname);
    }
    for(i=1;i<3;i++)
    {
    fwrite(&obj1[i],sizeof(obj1),1,fp);
    }
    printf("written successfully");
}
