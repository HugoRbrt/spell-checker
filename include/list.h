#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct maillon_{
  char* string;
  struct maillon_* next;
}maillon, * list;


list newList();

void list_add(char* newstring,list* liste);

int list_contains(char* searchStr,list liste);

int list_is_empty(list liste);

void list_print(list liste);

void list_free(list* liste);

list creation_listDict(FILE* f);

list creation_listDict_borne(FILE* f,int borne);
