#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

//SIGUSR1 incrementa
//SIGUSR2 decrementa


int variavel=0;
int n_vezes=0;

void sigusr_handler(int signum){

    if(signum==SIGUSR1){
        variavel++;

    }else if(signum==SIGUSR2){
        variavel--;
    }

    return;    
}

void sigalarm_handler(int signum){

    printf("%d\n",variavel);

    return;
}

int main(){
    
    struct sigaction new;
    struct sigaction aux;
    
    sigset_t mask_config;
    sigemptyset(&mask_config);

    sigprocmask(SIG_SETMASK,&mask_config,NULL); 
    
    
    
    pid_t fork_return=fork();


    if(fork_return==0){
        
        new.sa_handler = sigusr_handler;
        sigemptyset(&new.sa_mask);
        new.sa_flags = 0;

        if (sigaction(SIGUSR1, &new, NULL) < 0)
        {
            perror("Erro");
        }
        if (sigaction(SIGUSR2, &new, NULL) < 0)
        {
            perror("Erro");
        }

        aux.sa_handler = sigalarm_handler;
        sigemptyset(&aux.sa_mask);
        aux.sa_flags = 0;

        if (sigaction(SIGALRM, &aux, NULL) < 0)
        {
            perror("Erro");
        }

        while (n_vezes<50)
        {
            alarm(1);
            sleep(2);
        }

        return 0;

    }else if(fork_return>0){

        while(n_vezes<50){

            sleep(1);

            kill(fork_return,SIGUSR1);

            n_vezes++;

        }
    
    }
    


    return 0;
}



