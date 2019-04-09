#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void alarm_handler(int signo)
{
    printf("Alarm received ...\n");
    //alarmflag = 1; <--- NOT NEEDED WITH 'sigsuspend'
}

int main(void)
{
    struct sigaction action;
    sigset_t sigmask;
    // install SIGALRM handler
    
    action.sa_handler = alarm_handler;
    sigemptyset(&action.sa_mask); //all signals are delivered
    action.sa_flags = 0;
    sigaction(SIGALRM, &action, NULL);
    
    // prepare mask for 'sigsuspend'
    sigfillset(&sigmask);         //all signals blocked ...
    sigdelset(&sigmask, SIGALRM); //...except SIGALRM
    alarm(5);
    printf("Pausing ...\n");
    
    //while (!alarmflag) pause(); //REPLACED BY 'sigsuspend'
    sigsuspend(&sigmask);
    printf("Ending ...\n");
    exit(0);
}