// PROGRAMA p7.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{   

    //compila, se der erro, é que executa printf e exit, devemos preencher com codigos de erro
    char prog[20];
    sprintf(prog, "%s.c", argv[1]);
    execlp("gcc", "gcc", prog, "-Wall", "-o", argv[1], NULL);
    printf("Houve erro\n");
    exit(-1);
}