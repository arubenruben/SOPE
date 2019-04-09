#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>

typedef struct{

    int number1,number2;
}numbers_packet;



int main(){


    pid_t fork_return_value;
    int fd_pipe[2];

    pipe(fd_pipe);

    fork_return_value=fork();

    if(fork_return_value>0){

        numbers_packet sender;
        
        close(fd_pipe[0]);

        printf("Introduzir 2 numero\n");

        scanf("%d%d",&sender.number1,&sender.number2);


        if(write(fd_pipe[1],&sender,sizeof(numbers_packet))<0){
            perror("Erro");
        }
    
        wait(NULL);

    }else if(fork_return_value==0){
        
        numbers_packet receiver;

        close(fd_pipe[1]);
    
        read(fd_pipe[0],&receiver,sizeof(numbers_packet));

        printf("A soma de %d + %d e: %d\n",receiver.number1,receiver.number2,receiver.number1+receiver.number2);

        exit(0);
    }

    return 0;
}