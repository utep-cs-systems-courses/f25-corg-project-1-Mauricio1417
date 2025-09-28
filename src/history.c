#include "stdio.h"
#include "history.h"

typedef struct s_item {
  int id;
  char *str;
  struct s_item *next;
} Item;

typedef struct s_list {
  Item *root;
} List;

List *init_history()
{
  List *list = malloc(sizeof(s_list));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  // If list does not have a root yet (first item)
  if (list->root == NULL) {
    s_list *newItem = malloc(sizeof(s_list));
    newItem->id = 0;
    newItem->str = str;
    newItem->next = NULL;
    return;
  }
  
  s_list *curr = list->root;

  // Get last node and id of last node
  int count = 0;
  while (curr.next != NULL) {
    curr = curr->next;
    count++;
  }
  
  s_list *newItem = malloc(sizeof(s_list));
  newItem->id = count + 1;
  newItem->str = str;
  newItem->next = NULL;
  
  curr->next = newItem;
}

char *get_history(List *list, int id)
{
  if (list->root == NULL) {
    printf("%s\n", "List is empty");
    return;
  }

  s_list *curr = list->root;
  
  while (curr->id != id) {
    curr = curr->next;
  }

  return curr->str;
}

void print_history(List *list) {

  s_list *curr = list->root;
  
  while (curr.next != NULL) {
    printf("%s\n", *curr->str);
    curr = curr->next;
  }
  printf("%s\n", curr->str);
}

void free_history(List *list)
{
  s_list *curr = list->root;
  
  // Free char *str
  while (curr->next != NULL) {
    free(curr->str);
    curr++;
  }
  free(curr->str);

  // Free nodes
  
}






