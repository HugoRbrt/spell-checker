#include "ArbreRadix.h"

int main(){
  arbreRadix A =NULL,B=NULL;
  A = creer_noeud_ArbreRadix("");


  insererMot_ArbreRadix(A,"xiaomi");
  puts("ajout xiaomi : ");afficher_ArbreRadix(A);


  insererMot_ArbreRadix(A,"xtar");
//  add_fils_ArbreRadix(A->fils,creer_noeud_ArbreRadix("t"));
  puts("");puts("ajout xtar : ");afficher_ArbreRadix(A);puts("");


  insererMot_ArbreRadix(A,"beh");
  puts("");puts("ajout beh : ");afficher_ArbreRadix(A);
  puts("");puts("**********");
  printf("xtar présent ? : %d\n",est_present_arbreRadix(A,"xtar"));


  puts("**********");
  afficher_ArbreRadix(A);
  /*A = descendre_arbrePrefixe(A,'x');
  A = descendre_arbrePrefixe(A,'t');
  puts("");puts("NOUVEAU A");
  afficher_ArbrePrefixe(A);*/
  //detruire_arbrePrefixe(&A);
  //afficher_ArbrePrefixe(A);
  //assert(A==NULL);
}
