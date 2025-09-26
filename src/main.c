#include "stdio.h"
#include "tokenizer.h"

int main() {
  char *str = "I love Paola";
  
  char **tokens = tokenize(str);
  print_tokens(tokens);
}
