#include <math.h>

#include <stdbool.h>

void imprime_menu(){
    printf("1 - Calcula comprimento dos lados\n");
    printf("2 - Calcula condicao de existencia\n");
    printf("3 - Calcula area do triangulo\n");
}

double comprimento_dos_lados(double x1, double y1, double x2, double y2){
    double comp = sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
    return comp;
}

bool calculo_condicao_de_existencia(double x1, double y1, double x2, double y2, double x3, double y3){
    double comp1, comp2, comp3;
    double condicao1;

    comp1 = comprimento_dos_lados(x1, y1, x2, y2);
    comp2 = comprimento_dos_lados(x2, y2, x3, y3);
    comp3 = comprimento_dos_lados(x3, y3, x1, y1);

    condicao1 = abs(comp2 - comp3);

    if((comp1 < comp2 + comp3) && comp1 > condicao1){
        return true;
    }else{
        return false;
    }

}

void calcula_perimetro(){


}

void calcula_area(){
	/*double altura = pow(b - (a/2.0) * (a/2.0) , 1/2.0);
	double area = (a * altura)/2.0;
    double area;
    return area;
	*/

}
