#include <stdio.h>
#include <string.h>
#include "lista.h"


int main(){
	char ordem[5];


	while(1){
		imprime_menu();
		printf("Opcao: ");
		scanf("%s", ordem);



		if(strcmp(ordem,"-d")==0){
			ordena_crescente();
			printf("D\n");
		}
		else if(strcmp(ordem,"-r")==0){
			ordena_decrescente();
			printf("R\n");
		}else{
			printf("Opcao invalida!\n");
		}

	}

	return 0;
}
