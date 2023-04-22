#include <stdio.h>
#include <stdlib.h>
#define MEDIA 7

//PROTOTIPAGEM
void le_valida_nota(float nota[], int qtd_nota);
float calcula_media(float nota[], int qtd_nota);
float maior_nota(float nota[],int qtd_nota);
float menor_nota(float nota[], int qtd_nota);
int qtd_reprovados(float nota[],int qtd_nota);
int qtd_aprovados(float nota[],int qtd_nota);
int recebe_nmr_notas();
void cabecalho();
void rodape();
char refazer();




int main(){
    char retornar;
    int qtd_notas=0;
    float media_notas, highest_grade, minimum_grade, nmr_reprovados, nmr_aprovados;

    do{
        cabecalho();
        qtd_notas = recebe_nmr_notas();

        float vnotas[qtd_notas];

        le_valida_nota(vnotas,qtd_notas); // chamada
        media_notas = calcula_media(vnotas,qtd_notas);
        highest_grade = maior_nota(vnotas,qtd_notas);
        minimum_grade = menor_nota(vnotas,qtd_notas);
        nmr_reprovados = qtd_reprovados(vnotas,qtd_notas);
        nmr_aprovados = qtd_aprovados(vnotas,qtd_notas);

        rodape();

        retornar = refazer();
    }while(retornar=='S' || retornar=='s');

    return 0;
}

//DECLARACAO
void le_valida_nota(float nota[], int qtd_nota){ // passagem de vetor por paramentro
    int i;

    for(i=0;i<qtd_nota;i++){
        do{
            printf("Informe %da nota:",i+1);
            scanf("%f",&nota[i]);
        }while(nota[i]<0 || nota[i]>10);
    }
}

float calcula_media(float nota[], int qtd_nota){
    cabecalho(); // questao de organizacao no terminal
    float m, soma=0;
    int i;

    for(i=0;i<qtd_nota;i++){
        soma+= nota[i];
    }

    m = soma/qtd_nota;

    printf("Media da Turma:%.2f\n",m);
    return m;
}

float maior_nota(float nota[],int qtd_nota){
    float maior = nota[0];
    int i;

    for(i=0;i<qtd_nota;i++){
        if(nota[i]>maior){
            maior = nota[i];
        }
    }

    printf("Maior nota:%.2f\n",maior);
    return maior;
}

float menor_nota(float nota[], int qtd_nota){
    float menor= nota[0];
    int i;

    for(i=0;i<qtd_nota;i++){
        if(nota[i]<menor){
            menor = nota[i];
        }
    }

    printf("Menor nota:%.2f\n",menor);
    return menor;
}

int qtd_reprovados(float nota[],int qtd_nota){

    int reprov=0,i;

    for(i=0;i<qtd_nota;i++){
        if(nota[i]<MEDIA){
            reprov++;
        }
    }

    printf("Numero de reprovados:%d\n",reprov);
    return reprov;
}

int qtd_aprovados(float nota[],int qtd_nota){
    int aprov=0, i;

    for(i=0;i<qtd_nota;i++){
        if(nota[i]>=MEDIA){
            aprov++;
        }
    }

    printf("Numero de aprovados:%d\n",aprov);
    return aprov;
}

int recebe_nmr_notas(){

    int nmr_notas=0;
    do{
        printf("|      Informe o numero de      |\n");
        printf("|      provas realizadas:       |\n|             "); // prova = nota ... 1 pra 1
        scanf("%d",&nmr_notas);
        printf("+-------------------------------+\n");
        if(nmr_notas==0){
            printf("Nenhuma prova foi realizada!\n");
            exit(EXIT_SUCCESS); // EXIT_SUCCESS = 0 
        }
    }while(nmr_notas>25);
    
    return nmr_notas;
}

void cabecalho(){
        system("cls");
    printf("+-------------------------------+\n");
    printf("|      RELATORIO DA TURMA       |\n");
    printf("+-------------------------------+\n");
}

void rodape(){
    printf("+-------------------------------+\n");
    printf("|          BSB-2023             |\n");
    printf("+-------------------------------+\n");
}

char refazer(){
    char refaz;

    printf("|      Deseja refazer o         |\n");
    printf("|     procedimento? (S/N)       |\n|            ");
    scanf(" %c",&refaz); // para criterio de funcionamento foi dado um espaçamento antes de '%c'
    printf("+-------------------------------+\n");
    return refaz;
}