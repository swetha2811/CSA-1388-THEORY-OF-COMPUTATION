#include <stdio.h>
#include <string.h>
int isBelongToLanguageS(char *str, int start, int end) {
    if (start > end) {
        return 1;
    }
    if (str[start] == '0') {
        return isBelongToLanguageS(str, start + 1, end);
    }
    if (str[start] == '1') {
        return isBelongToLanguageS(str, start + 1, end);
    }
    return 0; 
}
int isBelongToLanguageA(char *str, int start, int end) {
    if (start > end) {
        return 1;
    }
    if (str[start] == '0' || str[start] == '1') {
        return isBelongToLanguageA(str, start + 1, end);
    }
    return 0;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
 int len = strlen(input); 
 if (len >= 5 && input[len - 4] == '1' && input[len - 3] == '0' && input[len - 2] == '1' && input[len - 1] == '1') {
        if (isBelongToLanguageA(input, 0, len - 5) && isBelongToLanguageA(input, len - 5, len - 5)) {
            printf("The string not belongs to the language defined by the CFG.\n");
        } else {
            printf("The string belong to the language defined by the CFG.\n");
        }
    } else {
        printf("The string belong to the language defined by the CFG.\n");
    }
    return 0;
}
