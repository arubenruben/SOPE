#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>


int main(){


    pid_t fork_return_value;
    int fd_pipe_father_child[2];
    int fd_pipe_child_father[2];

    pipe(fd_pipe_father_child);
    pipe(fd_pipe_child_father);

    fork_return_value=fork();

    if(fork_return_value>0){

        close(fd_pipe_father_child[0]);
        close(fd_pipe_child_father[1]);

        int number1,number2;

        printf("Introduzir 2 numero\n");

        scanf("%d%d",&number1,&number2);


        if(write(fd_pipe_father_child[1],&number1,sizeof(number1))<0){
            perror("Erro");
        }
        
        if(write(fd_pipe_father_child[1],&number2,sizeof(number2))<0){
            perror("Erro");
        }

        int resultado;

        read(fd_pipe_child_father[0],&resultado,sizeof(resultado));

        printf("A soma de %d + %d e: %d\n",number1,number2,resultado);

        wait(NULL);

    }else if(fork_return_value==0){
        
        close(fd_pipe_father_child[1]);
        close(fd_pipe_child_father[0]);

        int number1, number2;

        read(fd_pipe_father_child[0],&number1,sizeof(number1));
        
        read(fd_pipe_father_child[0],&number2,sizeof(number2));

        number1=number1+number2;

        write(fd_pipe_child_father[1],&number1,sizeof(number1));

        exit(0);
    }

    return 0;
}