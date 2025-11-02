//modularizando tudo,para podermos organizar e nao nos perdemos nos codigos
//fiz algumas para funções complementares como niveis,randomizador e fiz uma grande para as ajudas e saidas
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
    int cont_pergunta;

    FILE *arq;
   
    arq = fopen("perguntas.dat", "rb");
    if(arq == NULL){
        perror("Erro ao abrir arquivo!\n");
        exit(1);
    }

    srand(time(NULL));

    //imprimindo a o nome do show do milhão
    int var = 43;
        for(int i = 0;i < var;i++){
            printf("=");
            if (i == var - 1){
                printf("\n");
            }
        }

        for(int i = 0;i < (var - 14);i++){
            printf(" ");
            if (i == (var - 15)/2){
                printf("SHOW DO MILHAO");
            }
        }
    printf("\n");
    
     for(int i = 0;i < var;i++){
            printf("=");
            if (i == var - 1){
                printf("\n");
            }
        }
//aplicando e fazendo algumas variaveis uteis para realizar o codigo,como zera o vetor para manipular as questões
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
    
    
//fechando os carquivos e dando free na memoria 

    fclose(arq);
    free(vet_questao);
    
    return 0;
}