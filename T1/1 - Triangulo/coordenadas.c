#include <stdio.h>
#include "coordenadas.h"


int main(){
	double x1, x2, x3;
	double y1, y2, y3;
	int opcao, opcao_distancia;
	double comprimento;
	bool existe;

	printf("Insira as coordenadas. \n");
	printf("Ponto 1: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Ponto 2: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Ponto 3: ");
	scanf("%lf %lf", &x3, &y3);
	while(1){
		printf("Escolha uma opcão: \n");
		imprime_menu();
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("Digite 1 para calcular da distancia do ponto 1 para 2\n");
				printf("Digite 2 para calcular da distancia do ponto 2 para 3\n");
				printf("Digite 3 para calcular da distancia do ponto 3 para 1\n");

				scanf("%d", &opcao_distancia);

				if(opcao_distancia == 1){
					comprimento = comprimento_dos_lados(x1, y1, x2, y2);

				}

				else if(opcao_distancia == 2){
					comprimento = comprimento_dos_lados(x2, y2, x3, y3);
				}

				else if(opcao_distancia == 3){
					comprimento = comprimento_dos_lados(x3, y3, x1, y1);
				}

				printf("Comprimento: %.2f\n", comprimento);
				break;

			case 2:

				existe = calculo_condicao_de_existencia(x1, y1, x2, y2, x3, y3);
				if(existe == true){
					printf("Esse triangulo existe!\n");
				}else{
					printf("Esse triangulo nao existe!\n");
				}
				break;
		};
	}


	return 0;
}
