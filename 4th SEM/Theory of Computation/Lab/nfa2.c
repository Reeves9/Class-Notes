//nfa for string endinging with 01
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

bool simulate_nfa(char *input_string) {
    int len = strlen(input_string);
    bool ends_with_01 = false;

    if (len >= 2 && input_string[len - 2] == '0' && input_string[len - 1] == '1') {
        ends_with_01 = true;
    }

    for (int i = 0; i < len - 2; i++) {
        char symbol = input_string[i];
        if (symbol != '0' && symbol != '1') {
            return false;  // Invalid symbol
        }
    }

    return ends_with_01;
}

int main() {
    char input_string[MAX_INPUT_LENGTH];

    printf("Enter a binary string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the input string
    input_string[strcspn(input_string, "\n")] = '\0';

    if (simulate_nfa(input_string)) {
        printf("The string is accepted.\n");
    } else {
        printf("The string is rejected.\n");
    }

    return 0;
}