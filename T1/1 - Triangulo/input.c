#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "geometric_calculus.h"
#include "menu.h"

void start_program(){
    int option = 0;
    int distance_option = 0;
    bool exist = false;
    double length = 0;
    double result_area = 0;
    double result_perimeter = 0;
    Coordinates coordinates;

    printf("Insira as Coordenadas x e y dos pontos\n");
    printf("Ponto 1: ");
    scanf("%lf %lf", &coordinates.x1, &coordinates.y1);
    printf("Ponto 2: ");
    scanf("%lf %lf", &coordinates.x2, &coordinates.y2);
    printf("Ponto 3: ");
    scanf("%lf %lf", &coordinates.x3, &coordinates.y3);

    while(1)
    {
        printf("\nEscolha uma opcão: \n");
        print_menu();
        scanf("%d", &option);

        switch(option)
        {
            case 0:

                exist = calculation_condition_existence(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                if(exist == true){
                    printf("Esse triangulo existe!\n\n");

                    length = side_length(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2);
                    printf("Comprimento lado 1: %.2f\n", length);
                    length = side_length(coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                    printf("Comprimento lado 2: %.2f\n", length);
                    length = side_length(coordinates.x3, coordinates.y3, coordinates.x1, coordinates.y1);
                    printf("Comprimento lado 3: %.2f\n\n", length);
                    result_perimeter = calculates_perimeter(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                    printf("O perímetro do triangulo é %.2f\n\n", result_perimeter);
                    result_area = calculates_area(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                    printf("A área do triangulo é %.2f\n\n", result_area);
                }
                else{
                    printf("Esse triangulo nao existe!\n");
                }

                break;

            case 1:
                printf("Digite 1 para calcular da distancia do ponto 1 para 2\n");
                printf("Digite 2 para calcular da distancia do ponto 2 para 3\n");
                printf("Digite 3 para calcular da distancia do ponto 3 para 1\n");

                scanf("%d", &distance_option);

                if(distance_option == 1){
                    length = side_length(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2);

                }

                else if(distance_option == 2){
                    length = side_length(coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                }

                else if(distance_option == 3){
                    length = side_length(coordinates.x3, coordinates.y3, coordinates.x1, coordinates.y1);
                }

                printf("Comprimento: %.2f\n", length);
                break;

            case 2:
                exist = calculation_condition_existence(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                if(exist == true){
                    printf("Esse triangulo existe!\n");
                }else{
                    printf("Esse triangulo nao existe!\n");
                }
                break;

            case 3:
                result_perimeter = calculates_perimeter(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                printf("O perímetro do triangulo é %.2f\n", result_perimeter);
                break;

            case 4:
                result_area = calculates_area(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
                printf("A área do triangulo é %.2f\n", result_area);
                break;

            default:
                printf("Opção inválida, digite um número de 0 a 4!");
                break;

        };
    }

}
