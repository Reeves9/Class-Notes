//pda1 but with empty stack check
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    char stack[MAX_STACK_SIZE];
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, char symbol) {
    if (!isFull(stack)) {
        stack->stack[++stack->top] = symbol;
    } else {
        printf("Stack overflow.\n");
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->stack[stack->top--];
    } else {
        printf("Stack underflow.\n");
        return '\0';
    }
}

bool simulatePDA(char *input_string) {
    int len = strlen(input_string);
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < len; i++) {
        char symbol = input_string[i];

        if (symbol == '0') {
            push(&stack, '0');
        } else if (symbol == '1') {
            if (!isEmpty(&stack) && stack.stack[stack.top] == '0') {
                pop(&stack);
            } else {
                push(&stack, '1');
            }
        } else {
            return false;  // Invalid symbol
        }
    }

    return isEmpty(&stack);
}

int main() {
    char input_string[MAX_INPUT_LENGTH];

    printf("Enter a binary string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input_string[strcspn(input_string, "\n")] = '\0';

    if (simulatePDA(input_string)) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is rejected.\n");
    }

    return 0;
}