#include <stdio.h>
#include <stdlib.h>
#include <termio.h>
#include <unistd.h>

int main(){


    struct termios old, configs;

    tcgetattr(STDIN_FILENO,&configs);
    
    old=configs;


    configs.c_lflag&= ~(ECHO | ECHOE | ECHOK |  ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &configs);


    printf("Introduza a password\n");

    char asterisco='*';

    while(1){

        char carac;
        
        read(STDIN_FILENO,&carac,1);
        
        if(carac!='\n'){
            write(STDOUT_FILENO,&asterisco,1);
        }else{
            break;
        }

    }




        printf("\n");

        printf("Obrigado. As suas informacoes estao agora guardadas no computador do Futebol Clube do Porto\n");

            tcsetattr(STDIN_FILENO, TCSAFLUSH, &old);



    return 0;
}
