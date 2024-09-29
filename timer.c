/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int print_message = 0;

void alarm_handler(int signum)
{ //signal alarm_handler
  printf("Hello World!\n");
  print_message = 1;
  // signal(SIGALRM, alarm_handler); // he alarm_handler automatically disables handling of future signals so we set it again here.
}

int main(int argc, char * argv[])
{
  /*
  idea: 
  get current time at beginning of main
  set counter for number of SIGALRM that has passed
  in alarm_handler for ctrl + c, get current time
  subtract to get the time
  */
  int alarms_delivered = 0;
  time_t seconds;
     
  start = time(NULL);

  signal(SIGALRM,alarm_handler); //register alarm_handler to handle SIGALRM
  alarm(5);
  while(1){
    
    if (print_message){
      
      printf("Turing was right!\n");
      print_message = 0;
      alarms_delivered ++;
      alarm(5);
    }
  
  
  }
  return 0; //never reached
}