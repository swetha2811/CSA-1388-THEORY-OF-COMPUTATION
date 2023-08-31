

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Function to check if a string belongs to the CFG language
bool belongsToCFG(char *input, int start, int end) {
    // Base case: empty string
    if (start > end) {
        return true;
    }
    // Case 1: S -> 0S0
    if (input[start] == '0' && input[end] == '0') {
        for (int i = start + 1; i < end; i++) {
            if (belongsToCFG(input, start + 1, i - 1) && belongsToCFG(input, i + 1, end - 1)) {
                return true;
            }
        }
    }
    // Case 2: S -> 1S1
    if (input[start] == '1' && input[end] == '1') {
        for (int i = start + 1; i < end; i++) {
            if (belongsToCFG(input, start + 1, i - 1) && belongsToCFG(input, i + 1, end - 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char input_string[100];

    printf("Enter an input string: ");
    scanf("%s", input_string);

    int len = strlen(input_string);

    if (belongsToCFG(input_string, 0, len - 1)) {
        printf("String belongs to the CFG language.\n");
    } else {
        printf("String does not belong to the CFG language.\n");
    }

    return 0;
}
