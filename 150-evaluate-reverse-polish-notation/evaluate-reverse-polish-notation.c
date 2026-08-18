#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int val) {
    stack->data[++stack->top] = val;
}

int pop(Stack* stack) {
    return stack->data[stack->top--];
}

bool isOperator(const char* token) {
    return (
        strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 || strcmp(token, "/") == 0
    );
}

int evalRPN(char** tokens, int tokensSize) {
    Stack* stack = createStack(tokensSize);
    for (int i = 0; i < tokensSize; ++i) {
        char* token = tokens[i];
        if (isOperator(token)) {
            int b = pop(stack);
            int a = pop(stack);
            int result;
            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else result = a / b;
            push(stack, result);
        } else {
            push(stack, atoi(token));
        }
    }
    int finalResult = pop(stack);
    free(stack->data);
    free(stack);
    return finalResult;
}