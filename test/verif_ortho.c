#include "ArbrePrefixe.h"
#include "ArbreRadix.h"
#include "list.h"
int main(int argc, char* argv[])
{
  //ouverture fichier dictionnaire
  FILE* f;
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  //recherche du mode à réaliser
  int mode=0;
  while(mode<1 || mode>3){printf("entrez le graph voulu :\n1.ArbrePrefixe\n2.ArbreRadix\n3.Liste (très lent, environ 30 minutes !)\n");scanf("%d",&mode);}
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
      compteur++;
      if(est_present_arbrePrefixe(a,s)==0){
        printf("%s, ",s);
        }//affiche le mot si il est faux
    }
    printf("\nnombre de mot pas francais : %d\n",compteur);
    puts("*fin*");
    fclose(f2);
    //suppression graph
    detruire_arbrePrefixe(&a);
  }
  if(mode==2){
    //creation du graph à partir du dictionnaire:
    arbreRadix a = creation_arbreRadix(f);
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur =0;
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbreRadix(a,s)==0){
        printf("%s, ",s);
        compteur++;}//affiche le mot si il est faux
    }
    printf("\nnombre de mot pas francais : %d\n",compteur);
    puts("*fin*");
    fclose(f2);

    //suppression graph
    detruire_arbreRadix(&a);
  }
  if(mode==3){
    list listDic=creation_listDict(f);
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f2==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur=0;
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
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
}
