#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;
    if (argc != 2)
    {
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0)
        printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
    else if (pid == 0)
    {
        
        
        
        char aux[50];
        char **arg=(char**)malloc(sizeof(char**)*4);
        arg[0]=(char*)malloc(sizeof(char)*strlen("ls"));
        strcpy(arg[0],"ls");
        arg[1]=(char*)malloc(sizeof(char)*strlen("-laR"));
        strcpy(arg[1],"-laR");
        arg[2]=(char*)malloc(sizeof(char)*strlen(argv[1]+1));
        strcpy(arg[2],argv[1]);
        arg[3]=NULL;

        printf("%s\n%s\n%s\n",arg[0],arg[1],arg[2]);
        
        
        execvp("ls",arg);
        printf("Command not executed !\n");
        exit(1);
    }
    exit(0);
}