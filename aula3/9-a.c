#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    if (argc != 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){
        int return_value;
        printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);
        wait(&return_value);
        
        printf("%d",WIFEXITED(return_value));

        printf("return do filho: %d\n",return_value);
    }
    else if (pid == 0)
    {
        execlp("ls","ls","-laR",argv[1],NULL);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}