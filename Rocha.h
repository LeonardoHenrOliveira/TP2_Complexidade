#ifndef ROCHA_H
#define ROCHA_H

typedef struct {
    int peso;
    int valor;
    int posicao;
    int usado;
}Rocha;

void Setvalor(Rocha *rocha, int valor);
void Setpeso(Rocha *rocha, int peso);
void Setposicao(Rocha *rocha, int posicao);

Rocha InicializaRocha(Rocha* rocha, int valor, int peso, int posicao);

int Getvalor(Rocha* rocha);
int Getpeso(Rocha* rocha);
int Getposicao(Rocha* rocha);


#endif
