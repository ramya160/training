#include <stdio.h>

#include <sys/types.h>

#include <unistd.h>

int main()

{

int pid=0;

pid = fork();
 
int fds[2];
int fds1[2];
int data;
int data1;
 if(pipe(fds)<0)
      {
   printf("pipe error");
      }
   if(pipe(fds1)<0)
      {
   printf("pipe error");
      } 
   if(pid<0)
      {
   printf("error");
      }
          

if(pid == 0){

printf("In Child");
  sleep(5);
  read(fds[0],data,5);
  write(fds1[1],"hai",5);
}

if(pid>0)
{     printf("In Parent process");
      write(fds[1],"hello",5);
       sleep(5);
       read(fds1[0],data1,5);
}


return 0;

}
