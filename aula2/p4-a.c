#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>



int main(){

    int fd_write;
    char caracter;

    fd_write=open("classificacoes.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);

    if(fd_write<1){

        perror("Erro");
        return -1;
    }
    printf("Introduza um nome e sua classificacao\n");
    while((read(STDIN_FILENO,&caracter,1))>0){

        write(fd_write,&caracter,1);
        
        if(caracter=='\n'){
            printf("Introduza um nome e sua classificacao\n");
        }

    }

    return 0;
}