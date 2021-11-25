#include "list.h"

int main(int argc, char* argv[])
{
  //ouverture fichier dictionnaire
  FILE* f;
  f=fopen("text/FR.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  //recherche du mode à réaliser

    //creation du graph à partir du dictionnaire:
    list listDic=newList();
    char buffer[30];
    while((fscanf(f,"%s",buffer))!=EOF){
        list_add(buffer,&listDic);
      }
      printf("affichage du dictionnaire\n");
    list_print(listDic);
      printf("fin du dictionnaire\n");

    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen("text/a_la_recherche_du_temps_perdu.txt","r");
    if (f2==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur=0;
    int cpt_temp=0;
    while(cpt_temp<20000 && fscanf(f2,"%s",s)!=EOF){//lit le mot
      cpt_temp++;
      if(!list_contains(s,listDic)){
        printf("%s\n",s);
          compteur++;
      }//affiche le mot si il est faux
    }
    printf("\nnombre de mot pas francais : %d\n",compteur);
    puts("*fin*");
    fclose(f2);
    //suppression graph
    list_free(&listDic);
  }
