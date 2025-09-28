#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

int main() {
  /*
  while (1) {
    printf("> ");

    // User input
    char *str = malloc(100);
    str[99] = '\0';
    fgets(str, sizeof(str), stdin);

    // Tokenize string
    char **tokens = tokenize(str);
    print_tokens(tokens);
   
  }
  */

   printf("> ");

    // User input
    char *str = malloc(100);
    str[99] = '\0';
    fgets(str, sizeof(str), stdin);

    // Tokenize string
    char **tokens = tokenize(str);
    print_tokens(tokens);
}
