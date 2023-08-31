#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Number of states in the NFA
#define NUM_STATES 3
// Transition function for the NFA
int transitions[NUM_STATES][2][2] = {
    {{0, 1}, {-1, -1}}, // State 0
    {{-1, -1}, {2, -1}}, // State 1
    {{-1, -1}, {-1, -1}} // State 2 (accepting state)
};
// Function to simulate NFA for the given input string
bool simulateNFA(const char *input) {
    int currentState = 0;
    int inputLength = strlen(input);
    for (int i = 0; i < inputLength; i++) {
        char c = input[i];
        int inputIndex = (c == 'b') ? 0 : ((c == 'a') ? 1 : -1);
        if (inputIndex == -1) {
            // Invalid input character
            return false;
        }
        int nextState1 = transitions[currentState][inputIndex][0];
        int nextState2 = transitions[currentState][inputIndex][1];
        if (nextState1 == -1 && nextState2 == -1) {
            // No valid transitions for this input character
            return false;
        }
        currentState = nextState1;
        if (nextState2 != -1) {
            currentState = nextState2;
        }
    }
    return currentState == 2; // Check if the final state is the accepting state
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
