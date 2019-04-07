#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[],char* envp[]){


	char *user;
	
	
	
	user=getenv("USER");
	
	
	
	printf("Hello %s !\n",user);


	return 0;
}
