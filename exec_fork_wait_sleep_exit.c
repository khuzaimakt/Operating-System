#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>


int main(int argc,char* argv[])
{
   pid_t pid=fork();
   
   if(pid<0)
   {
   printf("Process Failed");
   }
   
   else if(pid==0)
   {
   printf("Child created");
   execlp("mkdir","mkdir","./myFolder_1","./myFolder_2",NULL);
   exit(0);
   }
   
   else
   {
    wait(NULL);
    pid_t pid=fork();
    if(pid<0)
    {
     printf("Process Failed");
    }
    
    else if(pid==0)
    {
     printf("Child created");
     execlp("mkdir","mkdir","./myFolder_1/mySubFolder",NULL);
     exit(0);
    }
    
    else
    {
     wait(NULL);
     pid_t pid=fork();
     if(pid<0)
    {
     printf("Process Failed");
    }
    
    else if(pid==0)
    {
     printf("Child created");
     execlp("ls","ls","-S",NULL);
     exit(0);
    }
    else
    {
     wait(NULL);
     printf("Task Completed");
    }
    
    }
    
   }
   
   return 0;
   
   }
  
    
     
 
