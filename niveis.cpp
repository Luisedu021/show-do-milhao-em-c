#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "niveis.h"
#include "randomizador.h"



float niveis(float saldo, float saldo_max, int nivel, int* vet_questao, int* ajudas, FILE *arq,perguntas pergunta){
    int i, cursor;
    char resposta;
    int cont_pergunta = 1;
    
    

    while(saldo < saldo_max ){
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
        int cont = 0;
        int ver_cartas;
        

        while(1){
        
        if (cont == 0){
            
            saidas(pergunta, ajudas,0,saldo,cont_pergunta);
            cont++;
            
        }
        else{
            cont_pergunta++;
            saidas(pergunta, ajudas,ver_cartas,saldo,cont_pergunta);
        }
        scanf("%c", &resposta);
        fflush(stdin);
        if(resposta == 'a' || resposta == 'b' || resposta == 'c' || resposta =='d'){

            if(resposta == pergunta.alt_correta){
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
            printf("\nCerta resposta!");
            printf("\nSaldo: R$ %.2f\n\n", saldo);
            cont_pergunta++;
            ver_cartas = 0;
            break;
                }
            else{
                printf("\nResposta errada!");
                printf("\nFim de jogo!");
                return 0;
            }
            
        }
        

        else if(resposta == '1'){
            if(ajudas[0] > 0){
                ajudas[0]--;
                ver_cartas = 0;
                cont_pergunta++;
                break;
            }
            else{
                printf("\nNao eh possivel mais pular a pergunta!");
                ver_cartas = 0;
                cont_pergunta--;
            }
            
        }

        else if(resposta == '2'){
            if(ajudas[1] > 0){
                ajuda_plateia(pergunta,ajudas);
                
            }
            else{
                printf("Ajudas da plateia ja usadas");
                
            }
            ver_cartas = 0;
            cont_pergunta--;
        }  
        else if(resposta == '3'){
            if (ajudas[2] > 0){
                printf("Voce escolheu a ajudas dos universitarios!\n");

                ajuda_universitaria(pergunta,ajudas);
                ver_cartas = 0;
                
            }
            else{
                printf("Ajuda dos universitarios ja usadas!\n");
                
            }
            cont_pergunta--;

        }
        else if(resposta == '4'){
            if (ajudas[3] > 0){
                printf("\nVoce escolheu a ajuda das cartas!\n");
                ver_cartas = ajuda_das_cartas(ajudas);
                cont_pergunta--;

            }
            else{
                printf("Ajuda das cartas ja usadas!\n");
            }
            
        }
        
        else if(resposta == '5' ){
            printf("\nCerta resposta!\n");
            printf("Fim de jogo :( ");
            printf("SALDO FINAL: R$ %.2f", saldo);
            ver_cartas = 0;
            return 0;
        }

        else{
            printf("\nCaracter invalido!Digite novamente a resposta!\n");
            ver_cartas = 0;
            cont_pergunta--;
        }

        }

        
        }
        return 1;
}