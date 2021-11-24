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


arbrePrefixe add_fils(arbrePrefixe source , char c){
  if(arbre_est_vide(source->fils)){//si pas de fils : on  ajoute le fils et on le retourne
    source->fils=creer_noeud(c);
    return source->fils;
  }
  arbrePrefixe p = source->fils;//si il y a un fils :
  while(!arbre_est_vide(p->frere)){
    if(p->valeur == c){return p;}//si on rencontre un fils identique à celui qu'on veut ajouter, on retourne le maillon existante
    p=p->frere;
  }
  if(p->valeur!=c){//si on a parcouru toute la liste de frère sans trouvé le maillon c, on l'ajoute à la fin de la liste
    p->frere = creer_noeud(c);
    return p->frere;
  }
  return p;//retourne le nouveau noeud crée
}
arbrePrefixe descendre_arbrePrefixe(arbrePrefixe a,char c){
  arbrePrefixe p =a->fils;
  while(p!=NULL ){//on parcours tous les fils
    if(p->valeur == c){return p;}//si un des fils contient c, on le retourne
    p = p->frere;
  }
  return p;//pas trouvé donc return NULL
}

void afficher_ArbrePrefixe(arbrePrefixe a){
  if(!arbre_est_vide(a)){
    printf("->%c",a->valeur);//on affiche la racine
    arbrePrefixe b = a->fils;
    while(b!=NULL){//on affiche tous les fils de la racinen
      afficher_ArbrePrefixe(b);
      b = b->frere;
    }
  }
}

void insererMot_ArbrePrefixe(arbrePrefixe a, char* s){
  arbrePrefixe b = a;
  int k;
  for(k=0;k<strlen(s);k++){
    b = add_fils(b,s[k]);//on ajoute chaques caractère 1 à 1 en descendant dans le graph
  }
  b=add_fils(b,'\0');
}

bool est_present_arbrePrefixe(arbrePrefixe a, char* s){
  arbrePrefixe b = a;
  int k, compteur=0;
  int l = strlen(s);if(l==0){return true;}//un mùot vide est dans l'arbre
  if(s[0]==34 || s[0]==40){return est_present_arbrePrefixe(a,s+1);}//si le mot commence par ( ou " on refait pareil sans ce caractère
  while(s[l-1]==44 || s[l-1]==46 || s[l-1]==40 || s[l-1]==41 || s[l-1]==34 || s[l-1]==45 ){s[l-1]='\0';l--;}//on enlève tous les caractère , . (  " - à la fin du mot
  if(l==0){return true;}
  for(k=0;k<l;k++){
    if(s[k]<97){return true;}//cas ou il y a lattre majuscule ou chiffre ou ;:<>=?@_^[]\/'-    =>on part du principe qu'il est francais
  }
  for(k=0;k<l+1;k++){
    if((b = descendre_arbrePrefixe(b,s[k]))==NULL){return false;}//cas ou un lettre n'est pas dans l'arbre
  }
  return true;
}

void detruire_noeudarbrePrefixe(noeudPrefixe* n){
  free(n);
}

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
  char s[30];//on mot est de taille <30caractères normalement
  int cpt=0;
  while(fscanf(f,"%s",s)!=EOF){//lit le mot

      insererMot_ArbrePrefixe(a,s);cpt++;
  }
  printf("nombre de mot dans le graphe : %d",cpt);
  return a;

}

arbrePrefixe creation_arbrePrefixe_borne(FILE* f,int borne){
  arbrePrefixe a =creer_noeud('#');//noeud source, on a choisi ce caractère abritrairement
  char s[30];//on mot est de taille <30caractères normalement
  int cpt=0;
  while(cpt<borne && fscanf(f,"%s",s)!=EOF){//lit le mot

      insererMot_ArbrePrefixe(a,s);cpt++;
  }
  return a;

}
