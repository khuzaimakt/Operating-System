#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<cstring>
#include<fstream>
using namespace std;

int main(int argc,char* argv[])
{
  int fd1[2];
  int fd2[2];
  char readBuffer[100];
  char message[100];
  int file;
  int out_file;
  int i;
  
  pid_t pid;
  
  if(pipe(fd1)==-1)
  {
   perror("Pipe Failed");
   return 1;
  }
  
  if(pipe(fd2)==-1)
  {
   perror("Pipe Failed");
   return 1;
  }
  
  pid=fork();
  
  if(pid<0)
  {
   perror("Fork");
   return 1;
  }
  
  else if(pid>0)
  { 
    file= open(argv[1],O_RDONLY);
    close(fd1[0]);
    read(file,message,100);
    cout<<message<<endl;
    write(fd1[1],message,100);
    close(fd1[1]);
    
    wait(NULL);
    close(fd2[1]);
    read(fd2[0],readBuffer,100);
     
    close(fd2[0]);
    out_file=open(argv[2],O_CREAT | O_WRONLY);
    write(out_file,readBuffer,strlen(readBuffer)+1);
    cout<<"Program completed"<<endl;
    
  }
  
  else if(pid==0)
  {
    close(fd1[1]);
    read(fd1[0],message,100);
    close(fd1[0]);
    
    for(i=0;message[i]!='\0';i++)
    { 
     if(!(message[i]>='a' && message[i]<='z') || (message[i]>='A' && message[i]<='Z') || (message[i]>='0' && message[i]<='9'))
     {
      message[i]=' ';
     }
     
    }
    cout<<message<<endl;
    close(fd2[0]);
    write(fd2[1],message,100);
    close(fd2[1]);
    exit(0);
   }
return 0;
}
