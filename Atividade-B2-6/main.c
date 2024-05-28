#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4 // Tamanho do array

void insertInArray(int arr[], int size, int value, int position) {
    int i;
    // Deslocar elementos para abrir espaço para o novo valor
    for (i = size - 1; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // Inserir o novo valor na posição desejada
    arr[position] = value;
}

int main() {
    int arr[SIZE] = {10, 25, 40, 80};
    int value = 30;
    int position = SIZE / 2; // Inserir no meio do array
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    insertInArray(arr, SIZE, value, position);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Exibir o array atualizado
    printf("Array depois da inserção:\n");
    for (int i = 0; i < SIZE + 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Tempo de processamento: %f segundos\n", cpu_time_used);

    return 0;
}
