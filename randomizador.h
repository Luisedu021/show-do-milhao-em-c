#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizador(int* vet_questao, int a, int b){
    int cursor = (rand() % 20) + 20*b;

    for(int i=0; i<8; i++){
        if(cursor == vet_questao[i]){
            cursor = (rand() % a) + 20*b;
            i = 0;
        }
    }

    return cursor;
}