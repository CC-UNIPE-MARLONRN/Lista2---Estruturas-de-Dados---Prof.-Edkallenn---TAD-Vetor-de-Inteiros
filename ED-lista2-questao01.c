/*
** Função : Aquivo de implementação para definir um vetor de inteiros.
** Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
** Data : 25/05/2024
** Observações: Este aquivo será utilizado junto a sua interface (cabeçalho) no arquivo ED-lista2-questao01.h para que realize suas funções previstas no enunciado das questôes.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ED-lista2-questao01.h"

VETOR_INTEIROS *criar_vetor(int capacidade) {
    VETOR_INTEIROS *vetor = (VETOR_INTEIROS *)malloc(sizeof(VETOR_INTEIROS));
    if(vetor == NULL){
     return NULL; //Sem espaço para alocação
    }
    vetor->valor = (int *)malloc(capacidade * sizeof(int));
    if(vetor->valor == NULL){
        free(vetor);
        return NULL; //Sem espaço para alocação
    }
    vetor->tamanho = 0;
    vetor->capacidade = capacidade;
    return vetor;
}

void inserir_valor(VETOR_INTEIROS *vetor, int valor) {
    if (vetor == NULL) {
        printf("\nVetor inexistente!\n");
        exit(-1);
    }

    if (vetor->tamanho == vetor->capacidade) {
        vetor->capacidade *= 2;
        vetor->valor = (int*)realloc(vetor->valor, vetor->capacidade * sizeof(int));
        if (vetor->valor == NULL) {
            printf("\nErro ao realocar memória!\n");
            exit(-1);
        }
    }
    vetor->valor[vetor->tamanho++] = valor;
    printf("\nValor inserido no vetor!\n");
}


void remover_valor(VETOR_INTEIROS *vetor, int valor){
    int i;
    if(vetor == NULL){
        printf("Vetor inexistente!");
        exit(-1);
    }

    for(i = 0; i < vetor->tamanho; i++){
        if(vetor->valor[i] == valor){
            break;
        }
    }
    if(i < vetor->tamanho){
        for(int j = i; j < vetor->tamanho - 1; j++){
            vetor->valor[j] = vetor->valor[j+1];
        }
        vetor->tamanho--;
    }
}

int consultar_posicao(VETOR_INTEIROS *vetor, int posicao) {
    if (vetor == NULL) {
        printf("Vetor inexistente!\n");
        return -1;
    }
    
    if (posicao >= 0 && posicao < vetor->tamanho) {
        return vetor->valor[posicao];
    } else {
        printf("Erro: posição inválida!\n");
        return -1;
    }
}

int buscar_valor(VETOR_INTEIROS *vetor, int valor) {
      if (vetor == NULL) {
        printf("Vetor inexistente!\n");
        return -1;
    }

    for (int i = 0; i < vetor->tamanho; i++) {
        if (vetor->valor[i] == valor) {
            return i;
        }
    }
    return -1; // Valor não encontrado
}

void imprimir_vetor(VETOR_INTEIROS *vetor) {
      if (vetor == NULL) {
        printf("Vetor inexistente!\n");
        return;
    }

  printf("Vetor Inteiros: { ");
    for (int i = 0; i < vetor->tamanho; i++) {
        printf("%d", vetor->valor[i]);
        if (i < vetor->tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void apagar_vetor(VETOR_INTEIROS *vetor){
      if (vetor == NULL) {
        printf("Vetor inexistente!\n");
        return;
    }
    free (vetor->valor);
    free(vetor);
}