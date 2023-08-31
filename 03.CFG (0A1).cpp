#include <stdio.h>
#include <string.h>
int is_valid(char *string) {
  int i, j;
  char stack[100];
  for (i = 0; i < 100; i++) {
    stack[i] = '\0';
  }
  stack[0] = 'S';
  for (i = 0; string[i] != '\0'; i++) {
    // If the current character is a 0, then push an S onto the stack.
    if (string[i] == '0') {
      stack[i + 1] = 'S';
    }
    // If the current character is a 1, then pop an A from the stack.
    else if (string[i] == '1') {
      if (stack[i] != 'A') {
        return 0;
      }
      stack[i] = '\0';
    }
  }
  return stack[0] == '\0';
}
int main() {
  char string[100];
  printf("Enter the string: ");
  scanf("%s", string);
  if (is_valid(string)) {
    printf("String is valid.\n");
  } else {
    printf("String is not valid.\n");
  }
  return 0;
}