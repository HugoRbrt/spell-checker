#include "list.h"

list newList(){
  list NewList=malloc(sizeof(list));
  return NewList;
}

list list_add(char* newstring,list liste){
  list new=malloc(sizeof(list));
  new->string=newstring;
  new->next=liste;
  return new;
}

int list_contains(char* searchStr,list liste){
  list list_temp=liste;
  while(list_temp->next!=NULL){
    if(strcmp(searchStr,list_temp->string)==0){return 1;}
    list_temp=list_temp->next;
  } return 0;
}

int list_is_empty(list liste){
  return liste==NULL;
}

void list_print(list liste){
  printf("affichage de la liste :\n");
  int i=0;
  list list_temp= liste;
  while(list_temp->next!=NULL){
    printf("element %d : %s\n",i,list_temp->string);
    list_temp=list_temp->next;
    i++;
  }
}
void list_free(list* liste){ //liberation par recurrence de la liste

  if(list_is_empty((*(liste))->next)){
    free(liste);
    printf("ok");
    //printf("la liste est déjà vide\n");
    return;
  }
  list_free(&((*(liste))->next));
  // list list_temp=liste;
  // list nextlist=NULL;
  // while(list_temp->next!=NULL){
  //   nextlist=list_temp->next;
  //   free(list_temp);
  //   list_temp=nextlist;
  // }
  // free(list_temp);
  // free(liste);
}
