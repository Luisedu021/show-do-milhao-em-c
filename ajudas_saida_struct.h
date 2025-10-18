#ifndef AJUDAS
#define AJUDAS

#include <stdio.h>

typedef struct{
    char nivel;
    char descricao[200];
    char alt[4][30];
    char alt_correta;
}perguntas;


void saidas(perguntas pergunta_desejada, int* ajudas);

void ajuda_plateia(perguntas pergunta);

int pula_pergunta(int nivel, int* vet_questao, int* ajudas, FILE *arq);

#endif