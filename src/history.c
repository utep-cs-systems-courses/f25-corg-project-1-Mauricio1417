#include "stdio.h"
#include "stdlib.h"
#include "history.h"

List *init_history()
{
  List *list = malloc(sizeof(list));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  Item *newItem = malloc(sizeof(Item));
  newItem->str = str;
  newItem->next = NULL;

  // Adding the first item
  if (list->root == NULL) {
    newItem->id = 0;
    list->root = newItem;
    return;
  }

  Item *curr = list->root;

  int count = 1;
  while (curr->next != NULL) {
    curr = curr->next;
    count++;
  }

  newItem->id = count++;
  curr->next = newItem;
}

char *get_history(List *list, int id)
{
  if (list == NULL || list->root == NULL) {
    return NULL;
  }

  Item *curr = list->root;
  
  while (curr != NULL) {
    if (curr->id == id) {
      return curr->str;
    }
    curr = curr->next;
  }
  return NULL;
}

void print_history(List *list)
{
  Item *curr = list->root;

  while (curr != NULL) {
    printf("%d: %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}

void free_history(List *list)
{
  Item *curr = list->root;
  Item *prev = list->root;

  while (curr->next != NULL) {
    // Free Strings
    if (curr->str != NULL) free(curr->str);

    prev = curr;
    curr = curr->next;

    free(prev);
    free(list);
  }
}
