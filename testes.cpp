#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char nivel;
    char descricao[200];
    char alt[4][30];
    char alt_correta;
}perguntas;

int main() {

srand(time(NULL));
int prob_correta= 40;
int prob_restante = 20;
perguntas pergunta;

//(ela vai ser usado 3 vezes)
pergunta.alt_correta = 'a';
pergunta.nivel = '1';

strcpy(pergunta.alt[0],"Letra a");
strcpy(pergunta.alt[1],"Letra b");
strcpy(pergunta.alt[2],"Letra c");
strcpy(pergunta.alt[3],"Letra d");



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
}

// Bloco de 16 linhas substituído por 4 linhas:

printf("A plateia votou:\n");
printf("Alternativa A: %02d votos\n", cont_a);
printf("Alternativa B: %02d votos\n", cont_b);
printf("Alternativa C: %02d votos\n", cont_c);
printf("Alternativa D: %02d votos\n", cont_d);

}