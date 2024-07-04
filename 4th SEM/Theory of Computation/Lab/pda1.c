//pda to have equal number of 1s and 0s
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_STACK_SIZE 100

typedef enum { q0, q1, q2, q3, q4 } State;

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
    State state = q0;

    for (int i = 0; i < len; i++) {
        char symbol = input_string[i];

        switch (state) {
            case q0:
                if (symbol == '0') {
                    push(&stack, '0');
                    state = q3;
                } else if (symbol == '1') {
                    push(&stack, '1');
                    state = q1;
                } else {
                    return false;  // Invalid symbol
                }
                break;
            case q1:
                if (symbol == '0') {
                    state = q2;
                } else if (symbol == '1') {
                    state = q1;
                } else {
                    return false;  // Invalid symbol
                }
                break;
            case q2:
                if (symbol == '0') {
                    if (!isEmpty(&stack) && stack.stack[stack.top] == '1') {
                        pop(&stack);
                        state = q4;
                    } else {
                        return false;  // Invalid transition
                    }
                } else if (symbol == '1') {
                    if (!isEmpty(&stack) && stack.stack[stack.top] == '0') {
                        pop(&stack);
                        state = q4;
                    } else {
                        return false;  // Invalid transition
                    }
                } else {
                    return false;  // Invalid symbol
                }
                break;
            case q3:
                if (symbol == '0') {
                    push(&stack, '0');
                    state = q3;
                } else if (symbol == '1') {
                    state = q1;
                } else {
                    return false;  // Invalid symbol
                }
                break;
            case q4:
                if (symbol == '0') {
                    push(&stack, '0');
                    state = q3;
                } else if (symbol == '1') {
                    push(&stack, '1');
                    state = q1;
                } else {
                    return false;  // Invalid symbol
                }
                break;
        }
    }

    return state == q4 && isEmpty(&stack);
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