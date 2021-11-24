#include "ArbreRadix.h"

int main(){
  arbreRadix A =NULL,B=NULL;
  A = creer_noeud_ArbreRadix("");


  recInsertion_ArbreRadix(A,"xiaomi");
  puts("ajout xiaomi : ");afficher_ArbreRadix(A);


  recInsertion_ArbreRadix(A,"xtar");
  recInsertion_ArbreRadix(A,"xtarda");
  add_fils_ArbreRadix(A->fils,creer_noeud_ArbreRadix("t"));
  puts("");puts("ajout xtar : ");afficher_ArbreRadix(A);puts("");


  recInsertion_ArbreRadix(A,"beh");
  puts("");puts("ajout beh : ");afficher_ArbreRadix(A);
  puts("");puts("**********");
  printf("xtar présent ? : %d\n",est_present_arbreRadix(A,"xtar"));


  puts("**********");
  afficher_ArbreRadix(A);
  //A = descendre_arbrePrefixe(A,'x');
  //A = descendre_arbrePrefixe(A,'t');
  puts("");puts("NOUVEAU A");
  afficher_ArbreRadix(A);
  detruire_arbreRadix(&A);
}
