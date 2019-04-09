#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>


int main(int argc, char * argv[]){

    if(argc<2){
        printf("Inserir o ficheiro\n");
        return -1;
    }

    int fd_pipe[2];
    int fd_read;

    pipe(fd_pipe);
    
    fd_read=open(argv[1],O_RDONLY);
    
    if(fd_read<0){
        perror("Erro");
        return -1;
    }
    
    

    
    pid_t fork_return_value;


    fork_return_value=fork();

    if(fork_return_value>0){

        char caracter;

        close(fd_pipe[0]);

        dup2(fd_pipe[1],STDOUT_FILENO);

        execlp("cat","cat",argv[1],NULL);
        
        wait(NULL);

    }else if(fork_return_value==0){
                
        char caracter;

        close(fd_pipe[1]);
        printf("Retorno\n");
        

        dup2(fd_pipe[0],STDIN_FILENO);
        execlp("sort","sort",NULL);
        printf("erro\n");
        exit(0);
    }

    return 0;
}