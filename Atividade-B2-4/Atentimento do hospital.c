#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char motivo_consulta[100];
} Paciente;


typedef struct Node {
    Paciente paciente;
    struct Node* proximo;
} Node;


typedef struct {
    Node* inicio;
    Node* fim;
    int tamanho;
} Fila;


Fila* inicializarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}


bool filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}


void enfileirarPaciente(Fila* fila, Paciente paciente) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->paciente = paciente;
    novoNode->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNode;
    } else {
        fila->fim->proximo = novoNode;
    }

    fila->fim = novoNode;
    fila->tamanho++;
}

Paciente desenfileirarPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = fila->inicio;
    Paciente paciente = temp->paciente;

    fila->inicio = fila->inicio->proximo;
    free(temp);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    fila->tamanho--;

    return paciente;
}

Paciente proximoPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        exit(EXIT_FAILURE);
    }

    return fila->inicio->paciente;
}


void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    Node* atual = fila->inicio;
    printf("Fila de pacientes:\n");
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, Motivo da Consulta: %s\n", atual->paciente.nome, atual->paciente.idade, atual->paciente.motivo_consulta);
        atual = atual->proximo;
    }
}

int main() {
    Fila* filaNormal = inicializarFila();
    Fila* filaPrioritaria = inicializarFila();
    Fila* filaUrgente = inicializarFila();

    
    Paciente p1 = {"Joao", 30, "Dor de cabeça"};
    enfileirarPaciente(filaNormal, p1);
    Paciente p2 = {"Maria", 65, "Pressão alta"};
    enfileirarPaciente(filaPrioritaria, p2);
    Paciente p3 = {"Pedro", 75, "Dor no peito"};
    enfileirarPaciente(filaUrgente, p3);

    
    Paciente pacienteAtual;
    while (!filaVazia(filaUrgente)) {
        pacienteAtual = desenfileirarPaciente(filaUrgente);
        printf("Atendendo paciente urgente: %s\n", pacienteAtual.nome);
        
    }

    while (!filaVazia(filaPrioritaria)) {
        pacienteAtual = desenfileirarPaciente(filaPrioritaria);
        printf("Atendendo paciente prioritario: %s\n", pacienteAtual.nome);
        
    }

    int n = 3; 
    int contador = 0;
    while (!filaVazia(filaNormal)) {
        if (contador == n) {
            while (!filaVazia(filaPrioritaria)) {
                pacienteAtual = desenfileirarPaciente(filaPrioritaria);
                printf("Atendendo paciente prioritario: %s\n", pacienteAtual.nome);
               
            }
            contador = 0;
        }

        pacienteAtual = desenfileirarPaciente(filaNormal);
        printf("Atendendo paciente normal: %s\n", pacienteAtual.nome);
        
        contador++;
    }

    
    free(filaNormal);
    free(filaPrioritaria);
    free(filaUrgente);

    return 0;
}
