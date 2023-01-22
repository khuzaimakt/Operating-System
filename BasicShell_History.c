#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
  
void executerecent(char** parse,char* input)
{
  for (int i = 0; i < 100; i++)
         {
        	parse[i] = strsep(&input, " ");
  
        	if (parse[i] == NULL)
            		break;
        	if (strlen(parse[i]) == 0)
            		i--;
    	}
  if (strcmp(parse[0],"cd") == 0) 
 	 {
 	 	
 	    chdir(parse[1]);
            
         }
         
         
    else
         {
         	
            pid_t retVal=fork();
 	 	if (retVal == -1) 
 	 	{
        		printf("\nFailed");
        	} 
        	else if (retVal == 0) 
        	{
        		if (execvp(parse[0], parse) < 0)
        		{ 
            			printf("\nCommand Failed");
            		}	
        	
        		exit(0);
        	} 
        	
     		else if(retVal>0)
     		{
        		wait(NULL);
        		
        		
        	}
        }

}
int main()
{
 
 char* parse[100];
 char*h[100];
 int counter=0;
 int c=0;
 printf("\n\n\n\t****KT's SHELL****");
 printf("\n");
 
 int flag=1;
 while(flag==1)
 {
   if(c==10)
     {
     	c=0;
     }
    char cur_dir[1024];
    getcwd(cur_dir, sizeof(cur_dir));
    printf("\nDirectory: %s\n", cur_dir);
    
    char* input;
    
    
    h[counter++] = readline("\n>>> ");
    c++;
    input = malloc(strlen(h[counter - 1]));
	strcpy(input,h[counter-1]);
    
    if (strlen(input) == 0) 
    {
    	printf("Not valid input");
    	break;

    } 
    else
     {
        for (int i = 0; i < 100; i++)
         {
        	parse[i] = strsep(&input, " ");
  
        	if (parse[i] == NULL)
            		break;
        	if (strlen(parse[i]) == 0)
            		i--;
    	}
    
        
       
       
 	 if (strcmp(parse[0],"exit") == 0) 
 	 {
 	    
 	    printf("\nYou Exited!\n");
 	    flag=0;
 	   
         }
         else if (strcmp(parse[0],"history") == 0) 
 	 {
 	     counter--;
 	     c--;
 	    if(counter==0)
 	    {
 	    printf("No commands in history\n");
 	    
 	    }
 	   else{
 	   for(int i=1;i<=counter;i++)
 	   printf("\n %d: %s",counter-i,h[counter-i]);
 	   }
         }
         
        
         
         
    	else if (strcmp(parse[0],"!!") == 0) 
 	 {
 	   counter--;
 	   c--;
 	   if(counter==0)
 	   {
 	   
 	     printf("\nNo recent command");
 	     
 	   }
 	   else
 	   { 
 	    char* input;
 	    input=h[counter-1];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   
 	    }
         }
 	    
           else if (strcmp(parse[0],"!1") == 0) 
 	 {
 	   counter--;
 	   c--;
 	   if(counter<1)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   {
 	    char* input;
 	    input=h[(counter-c)+0];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	   
 	    
         }       
    	else if (strcmp(parse[0],"!1") == 0) 
 	 {
 	   counter--;
 	   c--;
 	   if(counter<2)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   {
 	    char* input;
 	    input=h[(counter-c)+1];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	   
 	    
         }
         
                  
    	else if (strcmp(parse[0],"!2") == 0) 
 	 {
 	   counter--;
 	   c--;
 	  if(counter<3)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   {
 	    char* input;
 	    input=h[(counter-c)+2];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	   
 	    
         }
         
         
                  
    	else if (strcmp(parse[0],"!3") == 0) 
 	 {
 	 counter--;
 	 c--;
 	 if(counter<4)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   { 
 	    char* input;
 	    input=h[counter-c+3];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   
 	    }
         }
         
         
                  
    	else if (strcmp(parse[0],"!4") == 0) 
 	 {
 	    counter--;
 	    c--;
 	   if(counter<5)
 	   {
 	    printf("\nNo such command in history");
 	   
 	    }
 	   else
 	   {
 	    char* input;
 	    input=h[counter-c+4];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
         
                  
    	else if (strcmp(parse[0],"!5") == 0) 
 	 {
 	  counter--;
 	  c--;
 	   if(counter<6)
 	   {
 	    printf("\nNo such command in history");
 	   
 	    }
 	    else
 	    {
 	    char* input;
 	    input=h[counter-c+5];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
         
         
                  
    	else if (strcmp(parse[0],"!6") == 0) 
 	 {
 	 
 	  counter--;
 	  c--;
 	  if(counter<7)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   { 
 	    char* input;
 	    input=h[counter-c+6];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
                  
    	else if (strcmp(parse[0],"!7") == 0) 
 	 {
 	  counter--;
 	  c--;
 	   if(counter<8)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	  else
 	  {  
 	    char* input;
 	    input=h[counter-c+7];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
         
                  
    	else if (strcmp(parse[0],"!8") == 0) 
 	 {
 	  counter--;
 	  c--;
 	  if(counter<9)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	  
 	  else
 	    {
 	    char* input;
 	    input=h[counter-c+8];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
         
                  
    	else if (strcmp(parse[0],"!9") == 0) 
 	 {
 	   counter--;
 	   c--;
 	   if(counter<10)
 	   {
 	    printf("\nNo such command in history");
 	    
 	    }
 	   else
 	   { 
 	    char* input;
 	    input=h[counter-c+9];
 	    h[counter++]=input;
 	    c++;
 	    char * temp[100];
 	   executerecent(temp,input);
 	   }
 	    
         }
         else if (strcmp(parse[0],"cd") == 0) 
 	 {
 	 	
 	    chdir(parse[1]);
            
         }
         
         else
         {
         	
            pid_t retVal=fork();
 	 	if (retVal == -1) 
 	 	{
        		printf("\nFailed");
        	} 
        	else if (retVal == 0) 
        	{
        		if (execvp(parse[0], parse) < 0)
        		{ 
            			printf("\nCommand Failed");
            		}	
        	
        		exit(0);
        	} 
        	
     		else if(retVal>0)
     		{
     			
        		wait(NULL);
        		free(input);
        		
        		
        	}
         }
         
     }
 
   	
}
exit(0);
return 0;
}


