#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define STDERR 2
#define NUMITER 10000


static int N=50000;

void * thrfunc(void * arg)
{
 //int i;

int *return_thread=(int*)malloc(sizeof(int));



 fprintf(stderr, "Starting thread %s\n", (char *) arg);

while(N>-1){
    
    write(STDERR,arg,1);
    N--;
    *return_thread=*return_thread+1;
}
 
 return return_thread;
}




int main()
{
 pthread_t ta, tb;

 int *escritas_1, *escritas_2;

 pthread_create(&ta, NULL, thrfunc, "1");
 pthread_create(&tb, NULL, thrfunc, "2");
 pthread_join(ta, (void**)&escritas_1);
 pthread_join(tb, (void**)&escritas_2);


 printf("\n %d \n %d\n",*escritas_1,*escritas_2);

 free(escritas_1);
 free(escritas_2);

 return 0;
} 