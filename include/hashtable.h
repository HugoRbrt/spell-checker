#include "list.h"


typedef struct _hashtable{
  list * tab_list;
  int nb_mots;
}* hashtable;

void free_hashtable(hashtable* hashtab);

void remplir_dico( FILE* f,hashtable hashtab);

void add_to_hashtab(char* string,hashtable hashtab);

int hashtab_contains(char* string, hashtable hashtab);

int hashcode(char* string);

hashtable newHashTable();
