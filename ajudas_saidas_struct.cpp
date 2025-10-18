#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomizador.h"
#include "ajudas_saida_struct.h"

//aqui temos a declarao das ajudas e do struct que vamos utilizar no codigo

void ajuda_plateia(perguntas pergunta){

srand(time(NULL));
int prob_correta= 40;
int prob_restante = 20;
//(ela vai ser usado 3 vezes)

char alt_correta;  
alt_correta = pergunta.alt_correta;
int prob_a,prob_b,prob_c,prob_d;

//analisando qual a alternativa correta e quais o resto

if(alt_correta == 'a'){
        
        prob_a = prob_correta;
        prob_b = prob_restante;
        prob_c = prob_restante;
        prob_d = prob_restante;

}
else if(alt_correta == 'b'){
        prob_b = prob_correta;
        prob_a = prob_restante;
        prob_c = prob_restante;
        prob_d = prob_restante;

}
else if(alt_correta == 'c'){
        prob_c = prob_correta;
        prob_b = prob_restante;
        prob_a = prob_restante;
        prob_d = prob_restante;
}
else{
        prob_d = prob_correta;
        prob_b = prob_restante;
        prob_c = prob_restante;
        prob_a = prob_restante;
}
int cont_a = 0,cont_b = 0,cont_c = 0,cont_d = 0;
int total_respostas = 30;

for(int i = 0;i < total_respostas;i++){
        int nume_aleat = rand() % 100; // gera um num de 0 a 99
        if(nume_aleat < prob_a){
                cont_a++;
        }
        else if(nume_aleat < prob_a + prob_b){
                cont_b++;
        }
        else if(nume_aleat < prob_a + prob_b + prob_c){
                cont_c++;
        }
        else{
                cont_d++;
        }
        //terminar de implementar a ajudar e reestruturar o codigo
}

 
}

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
                return 1;
                break;
                
            }
        }
 }

 void saidas(perguntas pergunta_desejada, int* ajudas){

    printf("\nNIVEL %d\n\n", pergunta_desejada.nivel);
    printf("%s\n", pergunta_desejada.descricao);
    printf("\na)%s", pergunta_desejada.alt[0]);
    printf("\nb)%s", pergunta_desejada.alt[1]);
    printf("\nc)%s", pergunta_desejada.alt[2]);
    printf("\nd)%s", pergunta_desejada.alt[3]);
    printf("\n\nAJUDAS:");
    printf("\n[1] Pular pergunta (%dx)", ajudas[0]);
    printf("\n[2] Pedir ajuda a plateia (%dx)", ajudas[1]);
    printf("\n[3] Pedir ajuda aos universitarios (%dx)", ajudas[2]);
    printf("\n[4] Pedir ajuda as cartas (%dx)", ajudas[3]);
    printf("\n[5] Parar");
    printf("\n\nResposta: ");
}
