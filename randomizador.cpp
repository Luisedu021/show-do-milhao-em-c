#include "randomizador.h"
#include <stdlib.h>
#include <time.h>

int randomizador(int* vet_questao, int a, int b){
    int cursor = (rand() % a) + 20*b;

    for(int i=0; i<8; i++){
        if(cursor == vet_questao[i]){
            cursor = (rand() % a) + 20*b;
            i = -1;
        }
    }

    return cursor;
}

void zera_vetor(int* vet_questao){

    for(int i = 0; i < 8; i++){
        vet_questao[i] = -1;
    }
}

