#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000



void *thrfunc(void *arg)
{
    int i;
    fprintf(stderr, "Starting thread %s\n", (char *)arg);
    for (i = 1; i <= NUMITER; i++)
        write(STDERR, (char*)arg, sizeof(int));
    return NULL;
}


//No a) se nao interpretar o apontador como inteiro fazendo o cast para int, no caso int, ele vai imprimir byte a byte. tinha de alterar o tamanho do byte a ler


int main()
{
    pthread_t ta, tb;
    int var1=1;
    int var2=2;
    pthread_create(&ta, NULL, thrfunc, &var1);
    pthread_create(&tb, NULL, thrfunc, &var2);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0;
}