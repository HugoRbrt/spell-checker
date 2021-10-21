#include "ArbrePrefixe.h"

int main(){
  arbrePrefixe A =NULL,B=NULL;
  A = creer_noeud('#');
  insererMot_ArbrePrefixe(A,"xiaomi");
  puts("ajout xiaomi : ");afficher_ArbrePrefixe(A);puts("");
  insererMot_ArbrePrefixe(A,"xtar");
  add_fils(A->fils,'t');
  puts("ajout xtar : ");afficher_ArbrePrefixe(A);puts("");
  insererMot_ArbrePrefixe(A,"beh");
  puts("ajout beh : ");afficher_ArbrePrefixe(A);puts("");
  puts("**********");
  printf("beh présent ? : %d\n",est_present_arbrePrefixe(A,"beh"));
  puts("**********");
  afficher_ArbrePrefixe(A);
  A = descendre_arbrePrefixe(A,'x');
  A = descendre_arbrePrefixe(A,'t');
  puts("");puts("NOUVEAU A");
  afficher_ArbrePrefixe(A);
  detruire_arbrePrefixe(&A);
  afficher_ArbrePrefixe(A);
  assert(A==NULL);
}
