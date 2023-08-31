#include <stdio.h>
#include <stdbool.h>
int transition(int state, char input) {
    if (state == 0 && input == '0') return 1;
    if (state == 1 && input == '1') return 2;
    return -1;
}
bool simulateDFA(const char *input) {
    int currentState = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) {
            return false; // Invalid transition, input string not accepted
        }
    }
    return currentState == 2; // Check if the final state is reached
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulateDFA(input)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }
    return 0;
}
