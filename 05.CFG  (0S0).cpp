#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Function to check if a string belongs to the CFG language
bool belongsToCFG(char *str) {
    if (*str == '\0') {
        return true;  // A -> e
    }
    if (*str == '0' && str[strlen(str) - 1] == '0') {
        return belongsToCFG(str + 1) && belongsToCFG(str + 1);  // S -> 0S0
    }
    if (*str == '1') {
        return belongsToCFG(str + 1);  // A -> 1A
    }
    return false;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (belongsToCFG(str)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
