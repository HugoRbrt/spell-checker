#include "ArbrePrefixe.h"

noeudPrefixe* creer_noeud(char caractere){
  noeudPrefixe* n = malloc(sizeof(noeudPrefixe));
  n->valeur = caractere;//chaque noeud comporte un caractère
  n->fils=NULL;//gauche=fils
  n->frere=NULL;//droite=frere
  return n;
}
bool arbre_est_vide(arbrePrefixe a){
  return a==NULL;
}
void detruire_arbre(arbrePrefixe* a){
  if(!arbre_est_vide(*a)){
    detruire_arbre(&((*a)->fils));
    detruire_arbre(&((*a)->frere));
    free(*a);
    *a=NULL;
  }
}

bool possede_frere(noeudPrefixe p){
  return p.frere!=NULL;
}
bool possede_fils(noeudPrefixe p){
  return p.fils!=NULL;
}

arbrePrefixe add_fils(arbrePrefixe source , char c){
  if(arbre_est_vide(source->fils)){source->fils=creer_noeud(c);return source->fils;}//cas ou il n'y a pas de fils
  arbrePrefixe p = source->fils;
  while(!arbre_est_vide(p->frere)){
    if(p->valeur == c){return p;}
    p=p->frere;
  }
  if(p->valeur!=c){
    p->frere = creer_noeud(c);
    return p->frere;
  }
  return p;//retourne le nouveau noeud crée
}
arbrePrefixe descendre_arbrePrefixe(arbrePrefixe a,char c){
  arbrePrefixe p =a->fils;
  while(p!=NULL ){
    if(p->valeur == c){return p;}
    p = p->frere;
  }
  return p;//pas trouvé donc return NULL
}

void afficher_ArbrePrefixe(arbrePrefixe a){
  if(!arbre_est_vide(a)){
    printf("->%c",a->valeur);
    arbrePrefixe b = a->fils;
    while(b!=NULL){//on refait pareil pour chaque sous graph
      afficher_ArbrePrefixe(b);
      b = b->frere;
    }
  }
}

void insererMot_ArbrePrefixe(arbrePrefixe a, char* s){
  arbrePrefixe b = a;
  int k;
  for(k=0;k<strlen(s);k++){
    b = add_fils(b,s[k]);
  }
  b=add_fils(b,'\0');
}

bool est_present_arbrePrefixe(arbrePrefixe a, char* s){
  arbrePrefixe b = a;
  int k;
  for(k=0;k<strlen(s);k++){
    if(s[k]>122 || s[k]<97){return true;}//cas ou il y a une majuscule ou une ponctuation=>on part du principe qu'il est francais
    if((b = descendre_arbrePrefixe(b,s[k]))==NULL){return false;}//cas ou un lettre n'est pas dans l'arbre
  }
  if((b = descendre_arbrePrefixe(b,s[strlen(s)]))==NULL){
    return false;
  }
  return true;
}

void detruire_noeudarbrePrefixe(noeudPrefixe* n){
  free(n);
}
/*
void detruire_listearbrePrefixe(noeudPrefixe* n){
  if(n==NULL){return ;}//cas liste vide
  noeudPrefixe* p = n->frere;
  noeudPrefixe* q = n;
  while(!arbre_est_vide(p)){//on les detruit tous sauf le dernier
    detruire_noeudarbrePrefixe(*q);
    q = p;
    p=p->frere;
  }
  detruire_noeudarbrePrefixe(q);//on détruit le dernier
  n=NULL;
}*/

void detruire_arbrePrefixe(arbrePrefixe* n){
  //cas arbre vide
  if(n==NULL){return ;}
  //cas arbre sans fils
  noeudPrefixe* q = *n;
  noeudPrefixe* p1 = q->fils;
  if(p1==NULL){detruire_noeudarbrePrefixe(q);return;}
  //cas arbre avec fils
  noeudPrefixe* p2 = p1->frere;
  while(!arbre_est_vide(p2)){//on détruit les arbres commencant par les fils (sauf le dernier)
    detruire_arbrePrefixe(&(p1));
    p1=p2;
    p2=p2->frere;
  }
  detruire_arbrePrefixe(&p1);//on détruit le dernier fils
  detruire_noeudarbrePrefixe(q);//on détruit enfin la racine
  *n=NULL;//on met a jour la nouvelle valeur de a
}

arbrePrefixe creation_arbrePrefixe(FILE* f){
  arbrePrefixe a =creer_noeud('#');//noeud source, on a choisi ce caractère abritrairement
  char s[30];
  while(fscanf(f,"%s",s)!=EOF){//lit le mot
    //printf("%s\n",s);//affiche le mot lu
    insererMot_ArbrePrefixe(a,s);
    //afficher_ArbrePrefixe(a);
  }
  printf("graph rempli\n");
  return a;

}
