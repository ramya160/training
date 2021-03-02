
#include <stdio.h>




struct employee


{


   int empID;


   char empname[20];


   char company[20];


}obj1[10];


struct employee obj2[10];


int main()


{    int id;int i;


   FILE *fp;


   fp=fopen("employeedb","r+b");


   printf("enter employee id to update");


   scanf("%d",&id);


   while((fread(&obj2[i],sizeof(obj2),1,fp) ==1))


   {


       for(i=0;i<=3;i++)


       {


           if (obj2[i].empID == id)


           {


               printf("Enter the new data ");


               scanf("%d %s %s", &obj2[i].empID,&obj2[i].empname,&obj2[i].company);


               fseek(fp,sizeof(obj2[i])*i,SEEK_SET);


               fwrite(&obj2[i], sizeof(obj2), 1, fp);


           }


       }


   }


   fclose(fp);


   printf("\nRecord updated.");


}

