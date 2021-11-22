#include "hashtable.h"
#define SIZE 20;


hashtable newHashTable(){
  hashtable hashtab=malloc(sizeof(hashtab));
  hashtab->nb_mots=0;
  return hashtab;
}

int hashcode(char* string){
  ptr_parc=string;
  int hash=0;
  while(ptr_parc!=NULL){
    hash+=char;
    ptr_parc+=1;
  }
  return hash%SIZE;
}

int hashtab_contains(char* string, hashtable hashtab){
  int code=hashcode(string);
  list goodlist=(hashtab->tab_list)[code];
  if(list_contains(string,goodlist)){
      return 1;
  }
  return 0;
}

void add_to_hashtab(char* string,hashtable hashtab){
  int code=hashcode(string);
  int goodlist=(hashtab->tab)[hashcode]; //correspond à la liste à l'indice hashcode de la table de hachage
  if(goodlist==NULL){ //si la liste correspondant au hashcode de la chaine n'existe pas, on crée une nouvelle liste
    goodlist=malloc(sizeof(list));
    list_add(string,goodlist);
    (hashtab->nb_mots)++;
  }
  else if(!list_contains(string,goodlist){ // si la liste située à l'indice hashcode ne contient pas la chaine de carac, on l'y ajoute
    list_add(string,goodlist);
    (hashtab->nb_mots)++;
  }
}

void free_hashtable(hashtable* hashtab){
  free(*(hashtab)->tab_list);
  free(*hashtab);
}
void remplir_dico( FILE* f,hashtable hashtab){
  char buffer[30];
  hashtable hashtab=newHashTable();
  while(fscanf(f,"%s",buffer)!=EOF){
    add_to_hashtab(buffer,hashtab);
  }
  printf("graphe rempli\n");
  printf("nb mot ajoutes : %d",hashtab->nb_mots);getchar();getchar();
  return hashtab;
}
