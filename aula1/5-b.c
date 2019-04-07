#include <stdio.h>
#include <string.h>


int main(int argc, char * argv[],char* envp[]){


	int i=1;
	char *aux;
	char user[100];
	
	aux=envp[0];
	
	
	while(aux!=NULL){
	
		if(strstr(aux,"USER")!=NULL){
			
			aux=strstr(aux,"=");
			aux++;
			
			strcpy(user,aux);
			
			break;
		}
	
		aux=envp[i];
		i++;
	}
	
	
	
	printf("Hello %s !\n",user);


	return 0;
}
