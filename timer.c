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
  // signal(SIGALRM, handler); // he handler automatically disables handling of future signals so we set it again here.
}

int main(int argc, char * argv[])
{
  /*
  idea: 
  get current time at beginning of main
  set counter for number of SIGALRM that has passed
  in handler for ctrl + c, get current time
  subtract to get the time
  */

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