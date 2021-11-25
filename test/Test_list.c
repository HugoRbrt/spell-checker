#include "list.h"


int main(){

  list tnewlist=newList();
  list_add("toto",&tnewlist);
  list_add("taaa",&tnewlist);
  list_add("tara",&tnewlist);
  list_add("taea",&tnewlist);
  list_add("tui",&tnewlist);
  printf("notre dictionnaire de test :\n");
  puts("");

  list_print(tnewlist);
  printf("fin du dictionnaire \n");
  puts("");
  printf("la liste contient toto ? %d\n",list_contains("toto",tnewlist));
  printf("la liste contient tui ? %d\n",list_contains("tui",tnewlist));
  printf("la liste contient titi ? %d\n",list_contains("titi",tnewlist));
  printf("effacement de la liste\n");
  list_free(&tnewlist);
  printf("la liste est bien vide ? %d\n",list_is_empty(tnewlist));

}
