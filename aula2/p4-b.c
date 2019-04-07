#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

typedef struct{

    char nome[50];
    int nota;

}Info;


int main(){

    int fd_write;
    Info turma;

    fd_write=open("classificacoes.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);

    if(fd_write<1){

        perror("Erro");
        return -1;
    }
    while((read(STDIN_FILENO,&turma,sizeof(Info)))>0){

        printf("Introduza um nome e sua classificacao\n");
        
        write(fd_write,&turma,sizeof(Info));
        

    }

    return 0;
}