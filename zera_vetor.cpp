#include <stdio.h>
#include <stdlib.h>
#include "zera_vetor.h"

int* zera_vetor(int* vet_questao){
    vet_questao = (int *) malloc(sizeof(int) * 8);
    for(int i = 0; i<8; i++){
        vet_questao[i] = -1;
    }
    return vet_questao;
}