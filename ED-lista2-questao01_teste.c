/*
** Função : Aquivo de teste para verificar a execução do arquivo de interface de vetor de inteiros.
** Autor : Marlon Rufino do nascimento 2º período turma A 2024.1
** Data : 25/05/2024
** Observações: Este aquivo será utilizado para testar o arquivo ED-lista2-questao01.h para que realize suas funções previstas no enunciado das questôes: O nome ED-lista2-questao01_teste foi utilizado já para referenciar sua função.
                Dependendo de onde for executar é necessrio adicionar no terminal "gcc -o ED-lista2-questao01_teste ED-lista2-questao01.c ED-lista2-questao01_teste.c" para que a compilação seja bem sucedida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ED-lista2-questao01.h"

int main() {
    setlocale(LC_ALL, "portuguese"); 
    int opcao = -1;
    VETOR_INTEIROS *vetor = NULL;

    do {
        printf("\n----- Menu Teste -----\n");
        if (vetor == NULL) {
            printf("0. Criar vetor\n");
        }
        printf("1. Inserir valor no vetor\n");
        printf("2. Buscar valor na posição do vetor\n");
        printf("3. Buscar valor no vetor\n");
        printf("4. Remover valor no vetor\n");
        printf("5. Imprimir vetor\n");
        printf("6. Apagar vetor\n");
        printf("7. Sair do teste\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: {
                if (vetor == NULL) {
                    vetor = criar_vetor(2);
                    if (vetor != NULL) {
                        printf("\nVetor criado com sucesso!\n");
                    } else {
                        printf("\nErro na criação do vetor!\n");
                    }
                } else {
                      printf("\nOpção inválida! Tente novamente.\n");
                }
                break;
            }
            case 1: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                int valor;
                printf("\nDigite o valor que deseja inserir no vetor: ");
                scanf("%d", &valor);
                inserir_valor(vetor, valor);
                imprimir_vetor(vetor);
                break;
            }
             case 2: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                int posicao;
                printf("\nDigite a posição do vetor que deseja exibir o valor: ");
                scanf("%d", &posicao);
                int valor = consultar_posicao(vetor, posicao);
                if (valor == -1) {
                    printf("\nPosição indisponível no vetor!\n");
                } else {
                    printf("\nValor na posição %d: %d\n", posicao, valor);
                }
                break;
            }
            case 3: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                int valor;
                printf("\nDigite o valor que deseja descobrir a posição: ");
                scanf("%d", &valor);
                int posicao = buscar_valor(vetor, valor);
                if (posicao != -1) {
                    printf("\nValor %d encontrado na posição %d\n", valor, posicao);
                } else {
                    printf("\nValor %d não encontrado no vetor\n", valor);
                }
                break;
            }
            case 4: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                int valor;
                printf("\nDigite o valor que deseja remover do vetor: ");
                scanf("%d", &valor);
                remover_valor(vetor, valor);
                printf("\nValor removido com sucesso!\n");
                imprimir_vetor(vetor);
                break;
            }
            case 5: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                printf("\n");
                imprimir_vetor(vetor);
                break;
            }
            case 6: {
                if (vetor == NULL) {
                    printf("\nO vetor ainda não foi criado!\n");
                    break;
                }
                apagar_vetor(vetor);
                vetor = NULL;
                printf("\nVetor apagado com sucesso!\n");
                break;
            }
            case 7:
                printf("\nSaindo do teste...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 7);

    if (vetor != NULL) {
        apagar_vetor(vetor);
    }

    return 0;
}
