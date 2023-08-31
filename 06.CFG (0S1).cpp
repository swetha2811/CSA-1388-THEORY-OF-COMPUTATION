
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Function to check if the given string belongs to the language defined by the CFG
bool belongsToLanguage(const char *str, int start, int end) {
    if (start > end) {
        return true; // e production
    }
    if (str[start] == '0' && str[end] == '1') {
        for (int i = start + 1; i < end; i++) {
            if (belongsToLanguage(str, start + 1, i - 1) && belongsToLanguage(str, i + 1, end - 1)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = strlen(str);
    if (belongsToLanguage(str, 0, length - 1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
