#ifndef LOGISTICA_H
#define LOGISTICA_H


typedef enum {
    EM_PROCESSAMENTO = 1,
    EM_TRANSITO,
    EM_ESPERA,
    ENTREGUE,
    EXTRAVIADO
} Status;


typedef struct Pacote {
    int id;
    char conteudo[100];
    char origem[50];
    char destino[50];
    Status situacao;
    struct Pacote *prox;
} Pacote;

void incluirPacote(Pacote **lista, char conteudo[], char origem[], char destino[]);
void alterarStatus(Pacote *lista, int id, Status novoStatus);
void rastrearPacote(Pacote *lista, int id);
void mostrarEntregas(Pacote *lista);

#endif