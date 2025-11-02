#ifndef AJUDAS
#define AJUDAS

#include <stdio.h>

typedef struct{
    char nivel;
    char descricao[200];
    char alt[4][30];
    char alt_correta;
}perguntas;


void saidas(perguntas pergunta_desejada, int* ajudas,int erradas_p_pular,float saldo,int num_pergunta);

void ajuda_plateia(perguntas pergunta,int *ajudas);

void ajuda_universitaria(perguntas pergunta,int *ajudas);

int ajuda_das_cartas(int *ajudas);

void desenhar_cartas();



#endif