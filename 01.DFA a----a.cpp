#include <stdio.h>
// DFA transition function
int transition(int state, char input) {
    if (state == 0 && input == 'a') return 1;  // Move to state 1 on input 'a'
    if (state == 1 && input == 'a') return 1;  // Stay in state 1 on input 'a'
    return 0;  // Any other input leads to a non-accepting state
}
int main() {
    int current_state = 0;
    char input_string[100];
    printf("Enter an input string: ");
    scanf("%s", input_string);
    for (int i = 0; input_string[i] != '\0'; i++) {
        current_state = transition(current_state, input_string[i]);
    }
    if (current_state == 1) {
        printf("String accepted\n");
    } else {
        printf("String not accepted\n");
    }
    return 0;
}
