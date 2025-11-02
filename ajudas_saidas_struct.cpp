#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomizador.h"
#include "ajudas_saida_struct.h"

#ifdef _WIN32
    // Se estiver compilando no Windows
    #include <windows.h>
    void pausar_execucao_ms(int milissegundos) {
        Sleep(milissegundos);
    }
#else
    // Para outros sistemas(mac ou linux)
    #include <unistd.h> // Para a função usleep
    void pausar_execucao_ms(int milissegundos) {
        usleep(milissegundos * 1000); 
    }
#endif

//aqui temos a declarao das ajudas e do struct que vamos utilizar no codigo

void ajuda_plateia(perguntas pergunta,int *ajudas){

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
        
}

printf("A plateia votou:\n");
printf("Alternativa A: %02d votos\n", cont_a);
printf("Alternativa B: %02d votos\n", cont_b);
printf("Alternativa C: %02d votos\n", cont_c);
printf("Alternativa D: %02d votos\n", cont_d);

ajudas[1]--;
 
}


void saidas(perguntas pergunta_desejada, int* ajudas,int erradas_p_pular,float saldo,int num_pergunta){
char alt[] = {'a','b','c','d'};
int erradas_ja_puladas = 0;
        perguntas ver[1000];

    int tempo_pausa_ms = 700; 
    printf("\n==NIVEL %d\n", pergunta_desejada.nivel);
    printf("==Pergunta %d\n",num_pergunta);
    printf("==Voce possui um total acumulado de R$ %.2f\n\n",saldo);
    printf("%s\n", pergunta_desejada.descricao);

    //deixando o código mais bonitinho na parte de saida
    //fazendo aquele efeito de retardar as saidas,dando uma sensação de jogo mesmo
    fflush(stdout); 
    pausar_execucao_ms(1000); 

//aqui fiz uma estrutura caso o usuario quisesse as ajudas das cartas,assim,com um verificador
//ele veria o tanto de alternativas que teria que imprimir ao certo
for(int i = 0;i < 4;i++){
        if(alt[i] == pergunta_desejada.alt_correta){
        printf("\n%c)%s", alt[i], pergunta_desejada.alt[i]);
            fflush(stdout); 
            pausar_execucao_ms(tempo_pausa_ms); 
        }
        else {
                if(erradas_ja_puladas < erradas_p_pular){
                        erradas_ja_puladas++;
                }
                else{
                printf("\n%c)%s", alt[i], pergunta_desejada.alt[i]);
                fflush(stdout); 
                pausar_execucao_ms(tempo_pausa_ms);

                }
        }
}
    
  
    fflush(stdout); 
    pausar_execucao_ms(tempo_pausa_ms); 
    printf("\n\nAJUDAS:");
    printf("\n[1] Pular pergunta (%dx)", ajudas[0]);
    printf("\n[2] Pedir ajuda a plateia (%dx)", ajudas[1]);
    printf("\n[3] Pedir ajuda aos universitarios (%dx)", ajudas[2]);
    printf("\n[4] Pedir ajuda as cartas (%dx)", ajudas[3]);
    
    printf("\n[5] Parar");
    
    printf("\n\nResposta: ");
}



void ajuda_universitaria(perguntas pergunta,int *ajudas){
char estudantes[3];
srand(time(NULL));
int prob_correta= 70;
int prob_restante = 10;
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
int total_respostas = 3;

for(int i = 0;i < total_respostas;i++){
        int nume_aleat = rand() % 100; // gera um num de 0 a 99
        if(nume_aleat < prob_a){
                estudantes[i] = 'a';
        }
        else if(nume_aleat < prob_a + prob_b){
                estudantes[i] = 'b';
        }
        else if(nume_aleat < prob_a + prob_b + prob_c){
                estudantes[i] = 'c';
        }
        else{
                estudantes[i] = 'd';
        }
}


printf("Os universitarios votaram:\n");

for (int i = 0;i<3;i++){
printf("o universitario %d votou:%c\n",i+ 1,estudantes[i]);
}
ajudas[2]--;
}

int ajuda_das_cartas(int *ajudas){
srand(time(NULL));
desenhar_cartas();
ajudas[3]--;
int ver;
int prob = 25;


int nume_aleat = rand() % 100; // gera um num de 0 a 99
        if(nume_aleat < prob){
                ver = 0;
        }
        else if(nume_aleat < prob *2){
                ver = 1;
        }
        else if(nume_aleat < prob *3){
                ver = 2;
        }
        else{
                ver = 3;
        }

if(ver == 0){
        printf("\nQue pena,essa carta nao exclui nenhuma alternativa :(\n");
        //aqui eu chamo niveis
}
else if(ver == 1){
        printf("\n1 opcao foi excluida!\n");
}
else if(ver == 2){
        printf("\n2 opcoes foram excluidas!\n");
}
else{
        printf("\nQue sorte!!\n");
        printf("\nTres opcoes foram exluidas!\n");
}

return ver;
}

void desenhar_cartas(){
int cont = 0;
for(int j = 0;j<4;j++){
        pausar_execucao_ms(100);
        printf("+-------+   ");
        
      }
      printf("\n");
for(int k = 0;k<5;k++){
        if(k == 2){
        for(int h = 0;h<4;h++){
                pausar_execucao_ms(100);
                if(h == 3){
                        
                        printf("|   %d   |\n",cont);
                }
                else{
                        printf("|   %d   |   ",cont);
                }
                cont++;
        }
}
        else{

        for(int j = 0;j<4;j++){
                pausar_execucao_ms(100);
        printf("|       |   ");
        
      }
      printf("\n");

        }
        

}
for(int j = 0;j<4;j++){
        printf("|_______|   ");
        
      }
}