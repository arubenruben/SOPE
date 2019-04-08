#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global = 1;
int main(void)
{
    int local = 2;
    if (fork() > 0)
    {   //pai
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global++;
        local--;
    }
    else
    {
        //filho
        printf("PID = %d; PPID = %d\n", getpid(), getppid());
        global--;
        local++;
    }
    printf("PID = %d - global = %d ; local = %d\n", getpid(), global, local);
    return 0;

}