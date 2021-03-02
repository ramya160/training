#include <stdio.h>

#include <sys/types.h>

#include <unistd.h>

int main()

{

int pid=0;
int fds[2];
int fds1[2];
char data[10];
char data1[10];
 if(pipe(fds)<0)
      {
   printf("pipe error");
      }
   if(pipe(fds1)<0)
      {
   printf("pipe error");
      } 
   if((pid = fork())<0)
      {
   printf("error");
      }
          

if(pid == 0)
{

  sleep(5);
  read(fds[0],data,5);
  printf("%s",data);
  write(fds1[1],"hai",5);
}

if(pid>0)
{
       write(fds[1],"hello",5);
       sleep(5);
       read(fds1[0],data1,5);
       printf("%s",data1);
}

}
