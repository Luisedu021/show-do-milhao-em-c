#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ajudas_saida_struct.h"
#include "zera_vetor.h"
#include "niveis.h"

int main(void){
    int checa, nivel, cursor, saldo_max, *vet_questao, ajudas[4] = {3, 3, 3, 3};;
    float saldo;
    char resposta;
    perguntas pergunta;

    FILE *arq;
   
    arq = fopen("perguntas.dat", "rb");
    if(arq == NULL){
        perror("Erro ao abrir arquivo!\n");
        exit(1);
    }

    srand(time(NULL));

    saldo = 0;

    vet_questao = zera_vetor(vet_questao);
    saldo_max = 5000;
    nivel = 1;
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq,pergunta);
    if(checa == 0){
        return 0;
    }

    saldo = 10000;

    vet_questao = zera_vetor(vet_questao);    
    saldo_max = 60000;
    nivel = 2;
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq,pergunta);
    if(checa == 0){
        return 0;
    }
    
    saldo = 100000;

    vet_questao = zera_vetor(vet_questao);    
    saldo_max = 600000;
    nivel = 3;
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq,pergunta);
    if(checa == 0){
        return 0;
    }

    
    vet_questao = zera_vetor(vet_questao); 
    saldo_max = 1000000;
    nivel = 4;
    checa = niveis(saldo, saldo_max, nivel, vet_questao,ajudas, arq,pergunta);
    if(checa == 0){
        return 0;
    }
    
    

    return 0;
}


