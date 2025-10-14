#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ajudas_saidas.h"
#include "randomizador.h"


float niveis(float saldo, float saldo_max, int nivel, int* vet_questao, int* ajudas, FILE *arq);
void saidas(perguntas pergunta, int* ajudas);




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
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq);
    if(checa == 0){
        return 0;
    }

    saldo = 10000;

    vet_questao = zera_vetor(vet_questao);    
    saldo_max = 60000;
    nivel = 2;
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq);
    if(checa == 0){
        return 0;
    }
    
    saldo = 100000;

    vet_questao = zera_vetor(vet_questao);    
    saldo_max = 600000;
    nivel = 3;
    checa = niveis(saldo, saldo_max, nivel, vet_questao, ajudas, arq);
    if(checa == 0){
        return 0;
    }

    
    vet_questao = zera_vetor(vet_questao); 
    saldo_max = 1000000;
    nivel = 4;
    checa = niveis(saldo, saldo_max, nivel, vet_questao,ajudas, arq);
    if(checa == 0){
        return 0;
    }
    
    

    return 0;
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
             ajudas[0]--;
            printf("\nPulando para a próxima pergunta!!");
            //volta pro topo do loop
            continue;
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
            printf("\nCerta resposta!\n");
            printf("\nSaldo: R$ %.2f\n\n", saldo);

        }else if(resposta == '5' || resposta_aux == 5){
            printf("SALDO FINAL: R$ %.2f", saldo);
            return 0;
        }
        else if(resposta == '2'){
            printf("Ajuda da plateia!\n");
            ajuda_plateia(pergunta);
        }
        else{
            printf("RESPOSTA ERRADA!\nSaldo: R$ 0.00\n\nFIM DE JOGO!");
            return 0;
            }
        }
        return 1;
}



