#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "ArbrePrefixe.h"

//pas de fuite memoire

int main(int argc, char* argv[])
{
  //fichier dictionnaire
  FILE* f;
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  //recherche du mode à réaliser
  int mode;
  while(mode!=1){printf("entrez le graph voulu :\n1.ArbrePrefixe\n2.pas Fait...\n3.pasFait...\n");scanf("%d",&mode);}
  if(mode==1){
    //creation du graph :
    arbrePrefixe a = creation_arbrePrefixe(f);
    fclose(f);
    //fichier a corriger
    FILE* f2;
    f2=fopen(argv[2],"r");
    if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    //test
    char s[30];
    while(fscanf(f2,"%s",s)!=EOF){//lit le mot
      if(est_present_arbrePrefixe(a,s)==0){printf("%s   ",s);}
    }
    puts("*fin*");
    fclose(f2);
    //suppression graph
    detruire_arbrePrefixe(&a);
  }
}
