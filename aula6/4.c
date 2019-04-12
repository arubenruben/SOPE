#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <wait.h>
#include <unistd.h>



void* func_thread(void *arg){


    pthread_t num_tid=pthread_self();
    
    sleep(1);

    printf("O meu tid e: %ld\n",num_tid);

    return arg;
}




int main(){

    int n;


    

    printf("Numero de threads a criar\n");
    scanf("%d",&n);

    int *vec=(int*)malloc(sizeof(int)*n);
    int **num_return=(int**)malloc(sizeof(int*)*n);

    pthread_t *threads=(pthread_t*)malloc(sizeof(pthread_t)*n);

    for(int i=0;i<n;i++){

        vec[i]=i;

        pthread_create( &threads[i],NULL,func_thread,&vec[i]);

        pthread_join(threads[i],(void**)&num_return[i]);

    }

    for(int i=0;i<n;i++){

        printf("%d\n",*num_return[i]);

    }

    int return_value=0;

    pthread_exit((void*)&return_value);
}