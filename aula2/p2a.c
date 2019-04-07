#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){

    FILE* source,*dest;

    char str[500];

    if(argc<2){
        printf("Argc sem ter source e dest\n");
        return -1;
    }


    source=fopen(argv[1],"r");
    if(source==NULL){
        perror("Erro");
        return -1;
    }

    dest=fopen(argv[2],"w");


    while(fread(str,1,1,source)!=0){

        fwrite(str,1,1,dest);
    }

    return 0;
}