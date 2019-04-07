#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    int fd_source, fd_dest;
    char carater;

    if(argc<1){
        printf("O argv nao tem 2 argumentos\n");
        return -1;
    }

    
    fd_source=open(argv[1],O_RDONLY);
    

    if(fd_source==-1){
        perror("Erro");
        return -1;
    }


    while((read(fd_source,&carater,1))>0){
        write(STDOUT_FILENO,&carater,1);
    }
    printf("\nAgora apague-se tudo\n");

    sleep(5);

    system("clear");

    return 0;
}



