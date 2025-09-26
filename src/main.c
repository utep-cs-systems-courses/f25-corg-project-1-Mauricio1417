#include "stdio.h"
#include "tokenizer.h"

int main() {
  char *str = "        Hello    world               this is           a  string";
  
  char **tokens = tokenize(str);
  print_tokens(tokens);
}
