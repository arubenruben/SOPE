#include <stdio.h>
#include <stdlib.h>

void handler_1(void){

    printf("handler 1\n");



    return;
}

void handler_2(void){

    printf("handler 2\n");

    return;
}


int main(){

    void (*func) ();
    func=handler_2;
    
    
    atexit(handler_1);
    
    atexit(func);
    
    return 0;











    return 0;
}