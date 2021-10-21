#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "ArbrePrefixe"

//pas de fuite memoire

int main(int argc, char* argv[])
{
  FILE* f;
  int nb_space;
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  int mode;
  while(mode!=1){printf("entrez le graph voulu :\n1.ArbrePrefixe\n2.pas Fait...\n3.pasFait..."),scanf("%d",&mode)}
  if(mode=1){
    //creation du graph :
    arbrePrefixe a = creation_arbrePrefixe(f);
  }

  //choix algorithme est execution de l'algorithme
  int cout = choix_char_algo(g,&tab_station);
  tab_station = hashtable_delete(tab_station);
  g = graph_delete(g);


  puts("*fin*");
  fclose(f);
}
