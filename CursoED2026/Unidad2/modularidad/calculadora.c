#include <stdio.h>
#include <math.h>
#include "areas.h"
#include "volumenes.h"

float areaCirculo(float radio){
    return M_PI * radio * radio;
}

float areaCuadrado(float lado){
    return lado * lado;
}

float volumenEsfera(float radio){
    return (4.0/3.0) * M_PI * radio * radio * radio;
}

float volumenCubo(float lado){
    return lado * lado * lado;
}

int main(){

    float r = 3;
    float l = 4;

    printf("Area del circulo: %.2f\n", areaCirculo(r));
    printf("Area del cuadrado: %.2f\n", areaCuadrado(l));
    printf("Volumen de la esfera: %.2f\n", volumenEsfera(r));
    printf("Volumen del cubo: %.2f\n", volumenCubo(l));

    return 0;
}