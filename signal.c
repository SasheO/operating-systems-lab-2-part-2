/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  signal(SIGALRM, handler); // he handler automatically disables handling of future signals so we set it again here.
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  
  while(1){
    alarm(5); //Schedule a SIGALRM for 1 second
    printf("Turing was right!\n");
  }; //busy wait for signal to be delivered
  return 0; //never reached
}