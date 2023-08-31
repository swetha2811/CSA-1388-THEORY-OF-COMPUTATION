#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 50
#define MAX_TRANSITIONS 50

typedef struct {
    int transitions[MAX_TRANSITIONS];
    int transitionCount;
} State;

State nfa[MAX_STATES];
bool visited[MAX_STATES];

void epsilonClosure(int state) {
    if (visited[state]) return;
    
    visited[state] = true;
    printf("%d ", state);
    
    for (int i = 0; i < nfa[state].transitionCount; i++) {
        int nextState = nfa[state].transitions[i];
        epsilonClosure(nextState);
    }
}
int main() {
    int numStates, numSymbols;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);

    printf("Enter the number of symbols (excluding e): ");
    scanf("%d", &numSymbols);

    for (int i = 0; i < numStates; i++) {
        nfa[i].transitionCount = 0;

        printf("Enter the number of transitions for state %d: ", i);
        int numTransitions;
        scanf("%d", &numTransitions);

        printf("Enter the transitions (state indices) for state %d: ", i);
        for (int j = 0; j < numTransitions; j++) {
            scanf("%d", &nfa[i].transitions[j]);
            nfa[i].transitionCount++;
        }
    }

    for (int i = 0; i < numStates; i++) {
        printf("e-closure(%d): ", i);
        for (int j = 0; j < MAX_STATES; j++) {
            visited[j] = false;
        }
        epsilonClosure(i);
        printf("\n");
    }

    return 0;
}
