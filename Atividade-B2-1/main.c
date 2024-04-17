#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100


typedef struct {
    double items[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return (s->top == -1);
}


int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}


void push(Stack *s, double value) {
    if (isFull(s)) {
        printf("Erro: Pilha cheia\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}


double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}


double calculateResult(double operand1, double operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Erro: Divisão por zero\n");
                exit(EXIT_FAILURE);
            }
            return operand1 / operand2;
        default:
            printf("Erro: Operador inválido\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Stack stack;
    initialize(&stack);

    char rpn[MAX_SIZE];
    printf("Digite a fórmula no formato RPN (use espaços entre os elementos): ");
    fgets(rpn, MAX_SIZE, stdin);

    int i = 0;
    while (rpn[i] != '\0') {
        if (rpn[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit(rpn[i])) {
            push(&stack, atof(&rpn[i]));
            while (isdigit(rpn[i]) || rpn[i] == '.') {
                i++;
            }
        } else {
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result = calculateResult(operand1, operand2, rpn[i]);
            push(&stack, result);
            i++;
        }
    }

    printf("Resultado da operação aritmética: %.2f\n", pop(&stack));

    
    printf("Fórmula algébrica equivalente: ");
    i = 0;
    while (rpn[i] != '\0') {
        if (isdigit(rpn[i]) || rpn[i] == '.') {
            printf("%c", rpn[i]);
            while (isdigit(rpn[i + 1]) || rpn[i + 1] == '.') {
                i++;
                printf("%c", rpn[i]);
            }
            printf(" ");
        } else if (rpn[i] == '+' || rpn[i] == '-' || rpn[i] == '*' || rpn[i] == '/') {
            printf("%c ", rpn[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
