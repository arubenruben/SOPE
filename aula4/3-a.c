#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

//SIGUSR1 incrementa
//SIGUSR2 decrementa


int variavel=0;

void sigusr_handler(int signum){

    printf("Entrei no handler\n");

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
    
    new.sa_handler=sigusr_handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags=0;

    if(sigaction(SIGUSR1,&new,NULL)<0){
        perror("Erro");
    }
    if(sigaction(SIGUSR2,&new,NULL)<0){

        perror("Erro");
    }

    aux.sa_handler=sigalarm_handler;
    sigemptyset(&aux.sa_mask);
    aux.sa_flags=0;

    if(sigaction(SIGALRM,&aux,NULL)<0){
        perror("Erro");
    }
    printf("Vou entrar no ciclo\n");
    
    while(1){
        
        alarm(1);
        sleep(1);

    }


    return 0;
}



