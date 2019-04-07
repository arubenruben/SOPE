#include <stdio.h>
#include <stdlib.h>

int main(int arg, char * argv[])
{

	char *nome=argv[1];
	
	int n_vezes=atoi(argv[2]);
	
	


	for(int i=0;i<n_vezes;i++){
	 printf("Hello %s !\n",nome);
 	}
	
	return 0;
}
