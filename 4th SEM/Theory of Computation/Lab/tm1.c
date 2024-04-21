#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define NUM_STATES 5

typedef enum {
    q0, q1, q2, q3, q4
} State;

typedef enum {
    LEFT, RIGHT, STAY
} Direction;

typedef struct {
    State currentState;
    int head;
    char tape[MAX_INPUT_LENGTH + 2];
} TuringMachine;

void initTuringMachine(TuringMachine *tm, char *input_string) {
    tm->currentState = q0;
    tm->head = 0;
    strcpy(tm->tape + 1, input_string);
    tm->tape[0] = '?';  // Left marker
    tm->tape[strlen(input_string) + 1] = '!';  // Right marker
}

bool stepTuringMachine(TuringMachine *tm) {
    char currentSymbol = tm->tape[tm->head];

    switch (tm->currentState) {
        case q0:
            if (currentSymbol == '0') {
                tm->currentState = q1;
                return true;
            } else {
                return false;  // Reject if the first symbol is not '0'
            }
        case q1:
            if (currentSymbol == '0') {
                tm->head++;
                return true;
            } else if (currentSymbol == '1') {
                tm->currentState = q2;
                tm->head++;
                return true;
            } else {
                return false;  // Invalid input
            }
        case q2:
            if (currentSymbol == '1') {
                tm->head++;
                return true;
            } else if (currentSymbol == '!') {
                tm->currentState = q4;
                return true;
            } else {
                return false;  // Invalid input
            }
        case q3:
            return false;  // q3 is not used in this implementation
        case q4:
            return true;  // Accept state
        default:
            return false;  // Invalid state
    }
}

bool simulateTuringMachine(char *input_string) {
    TuringMachine tm;
    initTuringMachine(&tm, input_string);

    while (true) {
        bool shouldContinue = stepTuringMachine(&tm);
        if (!shouldContinue) {
            return false;  // Reject
        }
        if (tm.currentState == q4) {
            return true;  // Accept
        }
    }
}

int main() {
    char input_string[MAX_INPUT_LENGTH];

    printf("Enter a binary string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input_string[strcspn(input_string, "\n")] = '\0';

    if (simulateTuringMachine(input_string)) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is rejected.\n");
    }

    return 0;
}