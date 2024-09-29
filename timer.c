/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int print_message = 0;
int start;
int alarms_delivered;

void alarm_handler(int signum)
{ //signal alarm_handler
  printf("Hello World!\n");
  print_message = 1;
  // signal(SIGALRM, alarm_handler); // he alarm_handler automatically disables handling of future signals so we set it again here.
}

void int_handler(int signum)
{ //signal alarm_handler
  int current = time(NULL);
  int time_in_execution = current-start;
  printf("Number of alarms: %d\n", alarms_delivered);
  printf("Time in time_in_execution: %d secs\n", time_in_execution);
  exit(0);
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
  alarms_delivered = 0;
     
  start = time(NULL);

  signal(SIGALRM,alarm_handler); //register alarm_handler to handle SIGALRM
  signal(SIGINT,int_handler); //register alarm_handler to handle SIGALRM
  alarm(1);
  while(1){
    
    if (print_message){
      
      printf("Turing was right!\n");
      print_message = 0;
      alarms_delivered ++;
      alarm(1);
    }
  
  
  }
  return 0; //never reached
}