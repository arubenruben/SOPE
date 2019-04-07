#include <stdio.h>


int main(int argc, char * argv[],char* envp[]){


	int i=1;
	char *aux;
	
	aux=envp[0];
	
	
	while(aux!=NULL){
	
		printf("%s\n",aux);
	
	
	
	
	
		aux=envp[i];
		i++;
	}
	
	
	








	return 0;
}
