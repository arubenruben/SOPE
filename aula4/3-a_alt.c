#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

//SIGUSR1 incrementa
//SIGUSR2 decrementa


int variavel=0;

void sigusr_handler(int signum){

    if(signum==SIGUSR1){
        variavel++;

    }else if(signum==SIGUSR2){
        variavel--;
    }

    return;    
}

void sigalarm_handler(int signum){

    printf("Entrei aqui\n");

    printf("%d\n",variavel);

    return;
}



int main(){



    signal(SIGALRM,sigalarm_handler);
    signal(SIGUSR1,sigusr_handler);
    signal(SIGUSR2,sigusr_handler);



    while(1){
        alarm(1);
        sleep(1);
    }



    return 0;
}