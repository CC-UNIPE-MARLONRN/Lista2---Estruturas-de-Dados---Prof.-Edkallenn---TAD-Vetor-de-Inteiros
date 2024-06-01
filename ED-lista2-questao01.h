/*
** Função : Aquivo de interface (cabeçalho) para definir um vetor de inteiros.
** Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
** Data : 25/05/2024
** Observações: Este aquivo será utilizado junto a sua implementação no arquivo ED-lista2-questao01.c para que realize suas funções previstas no enunciado das questôes.
*/

#ifndef ED_LISTA2_QUESTAO01_H
#define ED_LISTA2_QUESTAO01_H

typedef struct {
    int *valor;
    int tamanho;
    int capacidade;
} VETOR_INTEIROS;

//Funções para manipulação do vetor 
VETOR_INTEIROS *criar_vetor(int capacidade);
void inserir_valor(VETOR_INTEIROS *vetor, int valor);
void remover_valor(VETOR_INTEIROS *vetor, int elemento);
int consultar_posicao(VETOR_INTEIROS *vetor, int posicao);
int buscar_valor(VETOR_INTEIROS *vetor, int posicao);
void imprimir_vetor(VETOR_INTEIROS *vetor);
void apagar_vetor(VETOR_INTEIROS *vetor);

#endif

