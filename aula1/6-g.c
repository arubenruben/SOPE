// PROGRAMA p6a.c
#include <stdio.h>
#include <stdlib.h>
#define BUF_LENGTH 256
#define MAX 256

int main(int argc,char * argv[],char * envp[])
{
    FILE *src, *dst;
    char buf[BUF_LENGTH];

    if(argc<2){
        printf("usage: %s file1 file2\n",argv[0]);
        return -1;
    }

    if ((src = fopen(argv[1], "r")) == NULL)
    {   
        perror("Erro");
        exit(1);
    }
    if ((dst = fopen(argv[2], "w")) == NULL)
    {
        perror("Erro");

            
        exit(2);
    }

    while ((fgets(buf, MAX, src)) != NULL)
    {
        fputs(buf, dst);
    }
    fclose(src);
    fclose(dst);
    exit(0); // zero é geralmente indicativo de "sucesso"
}
