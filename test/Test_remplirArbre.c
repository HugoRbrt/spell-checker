#include "ArbrePrefixe.h"
#include "ArbreRadix.h"

//pas de fuite memoire

int main(int argc, char* argv[])
{
  //ouverture fichier dictionnaire
  FILE* f;
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  //recherche du mode à réaliser
  int mode=0;
  while(mode<1 || mode>2){printf("entrez le graph voulu :\n1.ArbrePrefixe\n2.pas Fait...\n3.pasFait...\n");scanf("%d",&mode);}
  if(mode==1){
    //creation du graph à partir du dictionnaire:
    arbrePrefixe a = creation_arbrePrefixe(f);
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur=0;
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbrePrefixe(a,s)==0){printf("%s   ",s);compteur++;}//affiche le mot si il est faux
    }
    printf("\nnombre de mot pas francais : %d\n",compteur);
    puts("*fin*");
    fclose(f2);
    //suppression graph
    detruire_arbrePrefixe(&a);
  }
  if(mode==2){
    //creation du graph à partir du dictionnaire:
    arbreRadix a = creation_arbreRadix(f);printf("FAIT\n");/*
    getchar();
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur =0;
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbreRadix(a,s)==0){printf("%s   ",s);compteur++;}//affiche le mot si il est faux
    }
    printf("\nnombre de mot pas francais : %d\n",compteur);
    puts("*fin*");
    fclose(f2);*/
    printf("amantes présent ? : %d\n",est_present_arbreRadix(a,"amantes"));
    //suppression graph
    //detruire_arbreRadix(&a);
  }
}
