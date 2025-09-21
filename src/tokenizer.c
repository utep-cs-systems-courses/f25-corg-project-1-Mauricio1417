#include "stdio.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
  }
  return 0;
}

int non_space_character(char c)
{
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1;
  }
  return 0;
}

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

char *token_terminator(char *token)
{
  if (non_space_character(*token) == 1) {
    token++;
    return token_terminator(token);
  }
  return token;
}

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

int main(char c)
{
  /*
  char str[] = "   hello ugly world";
  char *p = token_start(str);
  printf("%c\n", *p);
  printf("\n");

  char *x = token_terminator(p);
  printf("%c\n", *x);
  printf("\n");

  printf("%c\n", *++x);
  printf("\n");
  */

  char str[] = "          three  tokens       here";
  int x = count_tokens(str);
  printf("%d\n", x);
  printf("\n");
  
}


