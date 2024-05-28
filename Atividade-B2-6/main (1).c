#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertInLinkedList(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void printLinkedList(Node *head) {
    printf("Lista ligada depois da inserção:\n");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    insertInLinkedList(&head, 10);
    insertInLinkedList(&head, 25);
    insertInLinkedList(&head, 40);
    insertInLinkedList(&head, 80);

    int value = 30;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    insertInLinkedList(&head, value);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printLinkedList(head);

    printf("Tempo de processamento: %f segundos\n", cpu_time_used);

    return 0;
}
