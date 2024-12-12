#include "Rocha.h"
#include <stdio.h>


Rocha InicializaRocha(Rocha* rocha, int valor, int peso, int posicao){
    Setpeso(rocha,peso);
    Setposicao(rocha,posicao);
    Setvalor(rocha,valor);

    return*rocha;
}

void Setvalor(Rocha *rocha, int valor){
    rocha->valor=valor;
}
void Setpeso(Rocha *rocha, int peso){
    rocha->peso=peso;
}
void Setposicao(Rocha *rocha, int posicao){
    rocha->posicao=posicao;
}

int Getvalor(Rocha* rocha){
    return(rocha->valor);
}
int Getpeso(Rocha* rocha){
    return(rocha->peso);
}
int Getposicao(Rocha* rocha){
    return(rocha->posicao);
}
