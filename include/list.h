#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct list_{
  char* string;
  struct list_* next;
}* list;

list newList();
void list_add(char* newstring,list liste);

int list_contains(char* searchStr,list liste);

int list_is_empty(list liste);

void list_print(list liste);

void list_free(list liste);
