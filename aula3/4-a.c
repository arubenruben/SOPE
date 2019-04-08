#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>


int main(){

    pid_t fork_ret;



    fork_ret=fork();


    if(fork_ret<0){
        perror("Erro");
        return -1;
    }else if(fork_ret>0){
        //pai
        wait(NULL);
        char str[50]="world !\n";
        write(STDOUT_FILENO,&str,sizeof(str));
    }else{

        char str[50]="Hello ";
        write(STDOUT_FILENO,&str,sizeof(str));
    }

    return 0;
}