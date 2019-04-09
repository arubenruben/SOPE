#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sigint_handler(int signo)
{
    printf("In SIGINT handler ...\n");
}
int main(void)
{
    sigset_t new;
    
    struct sigaction new_hand;

    sigfillset(&new);
    sigdelset(&new,SIGALRM);

    sigprocmask(SIG_SETMASK,&new,NULL);

    new_hand.sa_handler=sigint_handler;
    
    if (sigaction(SIGINT,&new_hand,NULL) < 0)
    {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }
    printf("Sleeping for 30 seconds ...\n");
    alarm(30);
    sleep(30);
    printf("Waking up ...\n");
    exit(0);
}