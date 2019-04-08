#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
    int fd_write_ls=-1;
    
    if(argc==3){
        char caracter;

        fd_write_ls=open(argv[2],(O_CREAT|O_TRUNC|O_WRONLY),0777);
        
        if(fd_write_ls<0){
            perror("Erro");
            return -1;
        }

    }

    pid_t pid;


    if (argc < 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){
        int return_value;
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        wait(&return_value);
    }
    else if (pid == 0)
    {

        dup2(fd_write_ls,STDOUT_FILENO);

        execlp("ls","ls","-laR",argv[1],NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}