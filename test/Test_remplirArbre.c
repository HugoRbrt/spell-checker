#include "ArbrePrefixe.h"
#include "ArbreRadix.h"
#include <time.h>

int NB_MOT_DICO=323925;//nombre de mot présent dans FR.txt

int main(int argc, char* argv[])
{
//Personnalisation du test a effectuer
    //demande du mode de graphe à réaliser
    int mode=2;
    //while(mode<1 || mode>2){printf("entrez le graph voulu :\n1.ArbrePrefixe\n2.ArbreRadix\n3.pasFait...\n");scanf("%d",&mode);}

    //quantité de mot à rechercher (si on en cherche)
    int pourcent_mot=0;
    //while(pourcent_mot<1 || pourcent_mot>100){printf("\nquel proportion du dico souhaitez vous lire ? (entre 1 et 100 compris) ");scanf("%d",&pourcent_mot);}
    int nb_recherche_max=NB_MOT_DICO*pourcent_mot/100;

    //mesure du temps d'execution
    int chrono=-1;
    while(chrono<0||chrono>4){printf("\nde quelle fonction souhaitez vous connaitre le temps d'execution ?\n0.ne pas mesurer de temps\n1.creation du graph\n2.recherche des mots dans le graphe\n3.destruction\n4.tout\n");scanf("%d",&chrono);}
    clock_t temps;

//realisation du test


  //ouverture fichier dictionnaire
  FILE* f;
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  if(mode==1){
    if(chrono==1 || chrono==4){temps=clock();}
    //creation du graph à partir du dictionnaire:
    arbrePrefixe a = creation_arbrePrefixe_borne(f,nb_recherche_max );
    if(chrono==1){temps=clock()-temps;}
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur=0;
    if(chrono==2){temps=clock();}
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbrePrefixe(a,s)==0){
        compteur++;}//affiche le mot si il est faux
    }
    if(chrono==2){temps=clock()-temps;}
    fclose(f2);
    //suppression graph
    if(chrono==3){temps=clock();}
    detruire_arbrePrefixe(&a);
    if(chrono==3 || chrono==4){temps=clock()-temps;}
  }
  if(mode==2){
    if(chrono==1 || chrono==4){temps=clock();}
    //creation du graph à partir du dictionnaire:
    arbreRadix a = creation_arbreRadix_borne(f,nb_recherche_max);
    if(chrono==1){temps=clock()-temps;}
    fclose(f);//fermeture du dictionnaire car il ne sert plus a rien
    //ouverture fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //recherche des mots faux
    char s[30];//car un mot de dépasse jamais plus de 30 caractères
    int compteur =0;
    if(chrono==2){temps=clock();}
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbreRadix(a,s)==0){
        compteur++;}//affiche le mot si il est faux
    }if(chrono==2){temps=clock()-temps;}
    fclose(f2);

    //suppression graph
    if(chrono==3){temps=clock();}
    detruire_arbreRadix(&a);
    if(chrono==3 || chrono==4){temps=clock()-temps;}
  }

      if(chrono!=0){printf("temps d'exécution mesuré: %lf",(double)temps/CLOCKS_PER_SEC);}
}
