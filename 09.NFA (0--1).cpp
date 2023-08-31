#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Transition function for the NFA
int transition(int state, char symbol) {
    if (state == 0 && symbol == '0')
        return 1;
    else if (state == 1 && symbol == '1')
        return 2;
    return -1;  // Invalid transition
}

// NFA simulation function
bool simulateNFA(const char *input) {
    int currentState = 0;
    int inputLength = strlen(input);

    for (int i = 0; i < inputLength; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1)
            return false;
    }

    return currentState == 2;
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("Accepted: String follows the pattern.\n");
    } else {
        printf("Rejected: String does not follow the pattern.\n");
    }

    return 0;
}
