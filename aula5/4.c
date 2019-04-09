#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char * argv[]){


    if(argc<3){
        printf("Falta args\n");       
        return -1;
    }

    int fd_pipe[2];

    pipe(fd_pipe);


    __pid_t fork_return_value;

    fork_return_value=fork();



    if(fork_return_value==0){
        //meio

        close(fd_pipe[0]);
        int pipe_intermedio[2];

        pipe(pipe_intermedio);


        __pid_t fork_medio;
        
        fork_medio=fork();

        if(fork_medio>0){
            
            close(pipe_intermedio[1]);

            wait(NULL);
            dup2(pipe_intermedio[0],STDIN_FILENO);

            dup2(fd_pipe[1],STDOUT_FILENO);

            printf("Executei\n");
            
            execlp("grep","grep",argv[2],NULL);
            
            printf("Erro\n");            
            
            exit(0);



        }else if(fork_medio==0){
            
            //Neto
            close(pipe_intermedio[0]);

            dup2(pipe_intermedio[1],STDOUT_FILENO);
            execlp("ls","ls",argv[1],"-laR",NULL);
            exit(0);

        }


    }else if(fork_return_value>0){

        wait(NULL);
        printf("Entrei no sort\n");
        close(fd_pipe[1]);
        dup2(fd_pipe[0],STDIN_FILENO);

        //pai
        execlp("sort", "sort",NULL);
        printf("Erro\n");


    }








    return 0;
}