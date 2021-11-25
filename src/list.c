#include "list.h"

list newList(){
  list NewList = NULL;
  return NewList;
}

void list_add(char* newstring,list* ptr_liste){
  list new=newList();
  new = malloc(sizeof(maillon));
  new->string=strdup(newstring);
  new->next=*(ptr_liste);
  *ptr_liste=new;

  //printf("le nouveau premier maillon est : %s\n",(*liste)->string);
}

int list_contains(char* searchStr,list liste){

//cas spéciaux de ponctuations, majuscule, mot vide...
  int k=0;
  int l = strlen(searchStr);if(l==0){return 1;}//un mot vide est dans l'arbre
  if(searchStr[0]==34 || searchStr[0]==40){return list_contains(searchStr+1,liste);}//si le mot commence par ( ou " on refait pareil sans ce caractère
  while(searchStr[l-1]==44 || searchStr[l-1]==46 || searchStr[l-1]==40 || searchStr[l-1]==41 || searchStr[l-1]==34 || searchStr[l-1]==45 ){
    searchStr[l-1]='\0';l--;
  }//on enlève tous les caractère , . (  " - à la fin du mot
  if(strlen(searchStr)==0){return 1;}//si les actions on vidé le mot, alors il est dans l'arbre (pour ne pas considérer les ponctuations isolés commes non francais)
  for(k=0;k<l;k++){
    if(searchStr[k]<97){return 1;}//cas ou il y a lattre majuscule ou chiffre ou ;:<>=?@_^[]\/'-    =>on part du principe qu'il est francais
  }
//cas général avec des mots en minusculesuniquement

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
    //printf("element %d : %s\n",i,list_temp->string);
    list_temp=list_temp->next;
    i++;
  }
}
void list_free(list* liste){

  list list_parc=NULL;
  list_parc=*liste;

  while(*liste!=NULL){
    list_parc=list_parc->next; //on sauvegarde le maillon suivant avant de supprimer son prédécesseur
    free((*liste)->string);
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
  return listDic;

}

list creation_listDict_borne(FILE* f,int borne){
  list listDic=newList();
  int cpt=0;
  char buffer[30];
  while(cpt<borne && ((fscanf(f,"%s",buffer))!=EOF)){
    cpt++;
      list_add(buffer,&listDic);
    }
    printf("affichage du dictionnaire\n");
    list_print(listDic);
    printf("fin du dictionnaire\n");
  return listDic;
}
