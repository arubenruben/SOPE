// PROGRAMA p5b.c

#include <stdio.h> //a completar
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int fd;
  char *text1="CCCCC";
  char *text2="DDDDD";

  fd = open("f1.txt", O_WRONLY|O_SYNC,0600);

  if(fd<0){
    perror("Erro");
    return -1;
  }
  getchar();
  write(fd,text1,5);
  write(fd,text2,5);
  close(fd);
  return 0;
}

