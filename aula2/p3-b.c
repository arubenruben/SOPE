#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd_source, fd_dest;
    char carater;

    if(argc<2){
        printf("O argv nao tem 2 argumentos\n");
        return -1;
    }

    
    fd_source=open(argv[1],O_RDONLY);
    fd_dest=open(argv[2],O_WRONLY);

    if(fd_source==-1||fd_dest==-1){
        perror("Erro");
        return -1;
    }

    dup2(fd_dest,STDOUT_FILENO);

    while((read(fd_source,&carater,1))>0){
        write(STDOUT_FILENO,&carater,1);
    }

    return 0;
}



