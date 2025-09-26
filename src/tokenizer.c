#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"

// True if c is a tab or space
int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
  }
  return 0;
}

// True if c is not a tab or space
int non_space_character(char c)
{
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1;
  }
  return 0;
}

// Returns pointer to start of the next token
char *token_start(char *str)
{
  while (*str != '\0') {
    if (non_space_character(*str) == 1) {
      return str;
    }
    else {
      str++;
    }
  }
  return 0;
}

// Returns pointer to char after the last character of the token
char *token_terminator(char *token)
{
  if (non_space_character(*token) == 1) {
    token++;
    return token_terminator(token);
  }
  return token;
}

// Returns the number of tokens in a string
int count_tokens(char *str)
{
  if (*str == '\0') {
    return 0;
  }

  char *start = token_start(str);
  if (start != NULL) {
    return 1 + count_tokens(token_terminator(start));
  }
  
  return 0;
}

// Returns copy of string len characters long
char *copy_str(char *inStr, short len)
{
  if (inStr == NULL || len <= 0) {
    return NULL;
  }

  char *result = malloc(len+1);
  char *iter = result;
  
  for (int i = 0; i < len; i++) {
    *iter = *inStr;
    iter++;
    inStr++;
  }
  
  *iter = '\0';
  return result;
}

// Tokenize string
char **tokenize(char *s)
{
  int num_tokens = count_tokens(s);
  char **tokens = malloc((num_tokens + 1) * sizeof(char *));
  tokens[num_tokens] = NULL;
  
  for (int i = 0; i < num_tokens; i++) {
    char *start = token_start(s);
    char *end = token_terminator(start);
    tokens[i] = copy_str(start, end - start);
    s = end;
  }
  return tokens;
}

// Print Tokens
void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("%s\n", tokens[i]);
    printf("\n");
  }
}

// free tokens from memory
void free_tokens(char **tokens)
{
  printf("Hello");
}
