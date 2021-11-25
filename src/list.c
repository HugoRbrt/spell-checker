#include "list.h"

list newList(){
  list NewList=calloc(1,sizeof(struct maillon_));
  NewList->next=NULL;
  NewList->string="";
  //struct list_ newlist=calloc(1,sizeof(struct list_));
  //Newlist=&newlist;
  return NewList;
}

void list_add(char* newstring,list* ptr_liste){

  //struct list_ newlist=calloc(1,sizeof(struct list_));
  //new=&newlist;

  if(list_is_empty(*ptr_liste)){
    (*ptr_liste)->next=NULL;
    (*ptr_liste)->string=strdup(newstring);
  }
  list new=newList();
  new->string=strdup(newstring);

  new->next=*(ptr_liste);
  *ptr_liste=new;
  //printf("le nouveau premier maillon est : %s\n",(*liste)->string);
}

int list_contains(char* searchStr,list liste){
  list list_parc=NULL;
  list_parc=liste;
  while(list_parc!=NULL){
    if(strcmp(searchStr,list_parc->string)==0){return 1;}
    list_parc=list_parc->next;
  } return 0;
}

int list_is_empty(list liste){
  return liste==NULL;
}

void list_print(list liste){

  int i=0;
  list list_temp= NULL;
  list_temp=liste;
  if(list_is_empty(liste)){printf("liste vide\n");return;}
  if(list_is_empty(liste->next)){printf("element 0 : %s\n",list_temp->string);return;}
  while(list_temp->next!=NULL){
    printf("element %d : %s\n",i,list_temp->string);
    list_temp=list_temp->next;
    i++;
  }
}
void list_free(list* liste){
  //free(liste);
  list list_parc=NULL;
  list list_temp=NULL;
  list_parc=*liste;
  //if(list_is_empty(*liste)){return;}
  while(*liste!=NULL){
    list_parc=list_parc->next; //on sauvegarde le maillon suivant avant de supprimer son prédécesseur
    //free((*liste)->string);
    free(*liste);
    *liste=list_parc;
  }
}

list creation_listDict(FILE* f){
  list listDic=newList();
  char buffer[30];
  while((fscanf(f,"%s",buffer))!=EOF){
      list_add(buffer,&listDic);
    }
    printf("affichage du dictionnaire\n");
  list_print(listDic);
    printf("fin du dictionnaire\n");

  fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
  return listDict;

}

list creation_listDict_borne(FILE* f,int borne){
  list listDic=newList();
  int cpt=0;
  char buffer[30];
  while(cpt<borne && ((fscanf(f,"%s",buffer))!=EOF)){
      list_add(buffer,&listDic);
    }
    printf("affichage du dictionnaire\n");
    list_print(listDic);
    printf("fin du dictionnaire\n");

  fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
  return listDict;
}
