/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int print_message = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  print_message = 1;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5);
  while(1){
    
    if (print_message){
      
      printf("Turing was right!\n");
      print_message = 0;
      alarm(5);
    }
  
  
  }
  return 0; //never reached
}