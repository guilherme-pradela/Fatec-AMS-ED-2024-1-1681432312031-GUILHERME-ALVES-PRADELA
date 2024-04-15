#include <stdio.h>
#include <stdlib.h>
#include "logistica.h"

void incluirPacote(Pacote **lista, char conteudo[], char origem[], char destino[]) {
    Pacote *novoPacote = (Pacote *)malloc(sizeof(Pacote));
    static int lastId = 1;

    if (novoPacote == NULL) {
        printf("Erro: memória insuficiente.\n");
        return;
    }

    novoPacote->id = lastId += 2;
    strcpy(novoPacote->conteudo, conteudo);
    strcpy(novoPacote->origem, origem);
    strcpy(novoPacote->destino, destino);
    novoPacote->situacao = EM_PROCESSAMENTO;
    novoPacote->prox = *lista;

    *lista = novoPacote;
}


void alterarStatus(Pacote *lista, int id, Status novoStatus) {
    while (lista != NULL) {
        if (lista->id == id) {
            lista->situacao = novoStatus;
            return;
        }
        lista = lista->prox;
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}


void rastrearPacote(Pacote *lista, int id) {
    while (lista != NULL) {
        if (lista->id == id) {
            printf("Conteúdo do pacote: %s\n", lista->conteudo);
            printf("Status do pacote: ");
            switch (lista->situacao) {
                case EM_PROCESSAMENTO:
                    printf("Em processamento\n");
                    break;
                case EM_TRANSITO:
                    printf("Em trânsito\n");
                    break;
                case EM_ESPERA:
                    printf("Em espera\n");
                    break;
                case ENTREGUE:
                    printf("Entregue\n");
                    break;
                case EXTRAVIADO:
                    printf("Extraviado\n");
                    break;
            }
            return;
        }
        lista = lista->prox;
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}


void mostrarEntregas(Pacote *lista) {
    printf("Situação atual das entregas:\n");
    while (lista != NULL) {
        printf("ID: %d, Conteúdo: %s, Status: ", lista->id, lista->conteudo);
        switch (lista->situacao) {
            case EM_PROCESSAMENTO:
                printf("Em processamento\n");
                break;
            case EM_TRANSITO:
                printf("Em trânsito\n");
                break;
            case EM_ESPERA:
                printf("Em espera\n");
                break;
            case ENTREGUE:
                printf("Entregue\n");
                break;
            case EXTRAVIADO:
                printf("Extraviado\n");
                break;
        }
        lista = lista->prox;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "logistica.h"

int main() {
    Pacote *lista = NULL;

   
    incluirPacote(&lista, "Livro", "São Paulo", "Rio de Janeiro");
    incluirPacote(&lista, "Eletrônicos", "Nova York", "Los Angeles");

    
    alterarStatus(lista, 3, EM_TRANSITO);

   
    rastrearPacote(lista, 3);

   
    mostrarEntregas(lista);

    return 0;
}