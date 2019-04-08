// PROGRAMA p2.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("1");
    
    if (fork() > 0)
    {//pai
        printf("2");
        printf("3");
    }
    else
    {//filho
        printf("4");
        printf("5");
    }
    printf("\n");
    return 0;
}