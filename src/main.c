#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"

int main() {

  // Linked List
  List *list = init_history();
  
  while (1) {
    printf("> ");
    
    // User input
    char *str = malloc(100);
    fgets(str, 100, stdin);

    if (*str != '!') add_history(list, str);
    
    // Tokenize string
    char **tokens = tokenize(str);

    // User enters a command
    if ((tokens[0] != NULL && tokens[1] == NULL) && *tokens[0] == '!') {
      char *x = tokens[0];
      x++;
      if (*x == 'h') {
	print_history(list);
	continue;
      }
      char *p = tokens[0];
      p++;
      int id = atoi(p);

      char *historyString = get_history(list, id);
      char **tokensArr = tokenize(historyString);
      print_tokens(tokensArr);
      continue;
    }
    
    print_tokens(tokens);
  }
}
