#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomizador.h"
#include "ajudas_saidas.h"
int pula_pergunta(int nivel, int* vet_questao, int* ajudas, FILE *arq){
        int i, cursor;
        char resposta, resposta_aux = 0;
        perguntas pergunta;

        ajudas[0] = ajudas[0] - 1;

        if(nivel < 4){
            cursor = randomizador(vet_questao, 20, nivel - 1);
        }else{
            cursor = randomizador(vet_questao, 10, nivel - 1);
        }

        for(i=0; i<8; i++){
            if(vet_questao[i] == -1){
                vet_questao[i] = cursor;
                break;
            }
        }
    }


float niveis(float saldo, float saldo_max, int nivel, int* vet_questao, int* ajudas, FILE *arq){
    int i, cursor, resposta_aux = 0;
    char resposta;
    perguntas pergunta;

    while(saldo < saldo_max){
        if(nivel < 4){
            cursor = randomizador(vet_questao, 20, nivel - 1);
        }else{
            cursor = randomizador(vet_questao, 10, nivel - 1);
        }
        
        for(i=0; i<8; i++){
            if(vet_questao[i] == -1){
                vet_questao[i] = cursor;
                break;
            }
        }
        fseek(arq, cursor * sizeof(perguntas), SEEK_SET);
        fread(&pergunta, sizeof(perguntas), 1, arq);

        saidas(pergunta, ajudas);
        scanf("%c", &resposta);
        fflush(stdin);

        if(resposta == '1' && ajudas[0] > 0){
            resposta_aux = pula_pergunta(nivel, vet_questao, ajudas, arq);
        }

        if(resposta == pergunta.alt_correta || resposta_aux == 1){
            if(nivel == 1){
                saldo += 1000;
            }else if(nivel == 2){
                saldo += 10000;
            }else if(nivel == 3){
                saldo += 100000;
            }else{
                saldo = 1000000;
            }

            if(saldo == 5000){
                saldo = 10000;
            }else if(saldo == 60000){
                saldo = 100000;
            }
            printf("\nSaldo: R$ %.2f\n\n", saldo);

        }else if(resposta == 5 || resposta_aux == 5){
            printf("SALDO FINAL: R$ %.2f", saldo);
            return 0;

        }else{
            printf("RESPOSTA ERRADA!\nSaldo: R$ 0.00\n\nFIM DE JOGO!");
            return 0;
            }
        }
        return 1;
}
