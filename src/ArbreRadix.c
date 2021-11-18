#include "ArbreRadix.h"

//TESTÉ



//FAIT
noeudRadix* creer_noeud_ArbreRadix(char* caractere){
  noeudRadix* n = malloc(sizeof(noeudRadix));
  n->valeur = strdup(caractere);
  n->fils=NULL;//gauche=fils
  n->frere=NULL;//droite=frere
  return n;
}
bool arbre_est_vide_ArbreRadix(arbreRadix a){
  return a==NULL;
}
bool possede_frere_ArbreRadix(noeudRadix p){
  return p.frere!=NULL;
}
bool possede_fils_ArbreRadix(noeudRadix p){
  return p.fils!=NULL;
}
void insererMot_ArbreRadix(arbreRadix a, char* s){
  if(!est_present_arbreRadix(a,s)){//si le mot n'est pas présent dans l'arbre on l'ajoute
    recInsertion_ArbreRadix(a,s);
  }
}

void recInsertion_ArbreRadix(arbreRadix a, char* c){
  if(!possede_fils_ArbreRadix(*a)){//si a n'a pas de fils, on ajoute un fils ayant le string c
   add_fils_ArbreRadix(a,creer_noeud_ArbreRadix(c));
  }
  else{
    int l;
    bool fin_while=0;
    noeudRadix* f = a->fils;
    while(f->frere!=NULL && !fin_while){
//deb
      l = contient_prefixe_ArbreRadix(*f,c);
      if(l!=0){//si le noeud contient un prefixe de s
        char* c2 = Retire_l_caracteres(c,l,0);//c2 correspond à c sans le prefixe commun à f et c
        if(l == strlen(f->valeur)){//si ce prefixe correspond à tout le noeud, on insert c2 dans ce noeud
          recInsertion_ArbreRadix(f,c2);
        }
        else{//si le prefixe ne correspond qu'à une partie du noeud, il faut : modifié le noeud actuel pour qu'il ne contienne
             //que le prefixe et qu'ils pointent vers 2 fils : 1 correspondant au reste des lettres de c, et un correspondant
             //au reste des lettres du noeud (en conservant les fils d'origines)
          noeudRadix* fils0 = creer_noeud_ArbreRadix("#");//noeud disant que la branche jusqu'à fils 1 correspond à 1 mot
          fils0->frere = NULL;
          fils0->fils  = NULL;
          noeudRadix* fils1 = creer_noeud_ArbreRadix(c2);//noeud contenant le reste des lettres de c
          fils1->frere = NULL;
          fils1->fils  = fils0;
          noeudRadix* fils2 = creer_noeud_ArbreRadix(Retire_l_caracteres(f->valeur,l,0));//noeud contenant le reste des lettres
          fils2->frere = fils1;                                                       //du noeud d'origine (et pointant vers
          fils2->fils  = f->fils;                                                      //les fils d'origine et ayanbt pour frere le noeud précédent)
          char* c3 = strndup(f->valeur,l);//le noeud n possède alors plus que le prefixe en commun
          f->valeur = c3;
          f->fils   = fils2; //il pointe vers les deux fils en commun
        }
        fin_while= 1;
      }
      else{fin_while= 0;}
//fi
      if(!fin_while){f = f->frere;}
    }
    if(f->frere==NULL){//on refait sur le dernire frere si on a toujours pas trouvé de préfixe commun


//deb
      int l = contient_prefixe_ArbreRadix(*f,c);
      if(l!=0){//si le noeud contient un prefixe de s
        char* c2 = Retire_l_caracteres(c,l,0);//c2 correspond à c sans le prefixe commun à f et c
        if(l == strlen(f->valeur)){//si ce prefixe correspond à tout le noeud, on insert c2 dans ce noeud
          recInsertion_ArbreRadix(f,c2);
        }
        else{//si le prefixe ne correspond qu'à une partie du noeud, il faut : modifié le noeud actuel pour qu'il ne contienne
             //que le prefixe et qu'ils pointent vers 2 fils : 1 correspondant au reste des lettres de c, et un correspondant
             //au reste des lettres du noeud (en conservant les fils d'origines)
          noeudRadix* fils0 = creer_noeud_ArbreRadix("#");//noeud disant que la branche jusqu'à fils 1 correspond à 1 mot
          fils0->frere = NULL;
          fils0->fils  = NULL;
          noeudRadix* fils1 = creer_noeud_ArbreRadix(c2);//noeud contenant le reste des lettres de c
          fils1->frere = NULL;
          fils1->fils  = fils0;
          noeudRadix* fils2 = creer_noeud_ArbreRadix(Retire_l_caracteres(f->valeur,l,0));//noeud contenant le reste des lettres
          fils2->frere = fils1;                                                       //du noeud d'origine (et pointant vers
          fils2->fils  = f->fils;                                                      //les fils d'origine et ayanbt pour frere le noeud précédent)
          char* c3 = strndup(f->valeur,l);//le noeud n possède alors plus que le prefixe en commun
          f->valeur = c3;
          f->fils   = fils2; //il pointe vers les deux fils en commun
        }
        fin_while= 1;
      }
      else{fin_while= 0;}
//fi
      if(!fin_while){//si aucun frere n'a de prefixe commun avec c, on ajoute un frere

      f->frere = creer_noeud_ArbreRadix(c);
      f->frere->fils = creer_noeud_ArbreRadix("#");

      }
    }
  }
}

int contient_prefixe_ArbreRadix(noeudRadix p, char* s){
  char c_p = p.valeur[0];
  char c_s = s[0];
  bool diff = 0;//prend 1 lorsque 2 caractères comparés sont différents
  int cpt = 0;//compteur de lettre identique
  while(c_s!='\0' && c_p!='\0' && !diff){
    if(c_s!=c_p){diff=1;}
    else{
      cpt++;
      c_p = p.valeur[cpt];
      c_s = s[cpt];
    }
  }
  return cpt;
}

char* Retire_l_caracteres(char* c, int l, bool liberer){
  assert(l<=strlen(c));
  if(l>strlen(c)){return NULL;}
  if(l==strlen(c)){return NULL;}
  char* c2 = malloc(strlen(c) - l );//-l pour les l lettres retirés
  int s = strlen(c);
  for(int k=0;k<s-l;k++){
    c2[k] = c[l+k];
  }

  if(liberer){free(c);}
  return c2;
}

void add_fils_ArbreRadix(arbreRadix source , noeudRadix* noeud){
  if(source->fils==NULL){//si il n'y a pas de fils, on n'a qu'à la mettre comme 1er fils
    source->fils = noeud;
    noeud->fils = creer_noeud_ArbreRadix("#");
  }
  else{//si il existe au moins un fils
    noeudRadix* f = source->fils;
    while(f->frere!=NULL){//on se position au dernier élément de la liste des frères
      f = f->frere;
    }
    f->frere = noeud;//on ajoute le noeud en bout de liste des frères
  }
}

arbreRadix descendre_arbreRadix(arbreRadix a,char* c){
  arbreRadix p =a->fils;
  while(p!=NULL ){
    char* s = strndup(c,strlen(p->valeur));
    if(strcmp(p->valeur,s) == 0){free(s);return p;}
    free(s);
    if(p->valeur[0]==c[0]){return NULL;}//si il commencait par la même lettre mais ils sont différents alors aucun frere ne convidendra (car chaques frere commence par une lettre differente)
    p = p->frere;
  }
  return p;//pas trouvé donc return NULL
}

bool est_present_arbreRadix(arbreRadix a, char* c){
  char* s = strdup(c);
  strcat(s,"#");
  arbreRadix b = a;
  int len_b=0;

  while(b!=NULL && s!=NULL){
    b = descendre_arbreRadix(b,s);
    if(b!=NULL){len_b = strlen(b->valeur);}
    if(len_b<=strlen(s)){s = Retire_l_caracteres(s,len_b,1);}
  }
  return s==NULL;
}

void afficher_ArbreRadix(arbreRadix a){
  if(!arbre_est_vide_ArbreRadix(a)){
    printf("->%s",a->valeur);
    arbreRadix b = a->fils;
    while(b!=NULL){//on refait pareil pour chaque sous graph
      afficher_ArbreRadix(b);
      b = b->frere;
    }
  }
}

arbreRadix creation_arbreRadix(FILE* f){
  arbreRadix a =creer_noeud_ArbreRadix("");
  char s[30];
  int compteur=0;
  while(fscanf(f,"%s",s)!=EOF){//lit le mot
    //printf("%s\n",s);//affiche le mot lu
    insererMot_ArbreRadix(a,s);compteur++;printf("%s\n",s);
    //afficher_ArbreRadix(a);
  }
  printf("graph rempli\n");
  return a;

}
//A FAIRE






/*
void detruire_arbre(arbreRadix* a){
  if(!arbre_est_vide_ArbreRadix(*a)){
    detruire_arbre(&((*a)->fils));
    detruire_arbre(&((*a)->frere));
    free(*a);
    *a=NULL;
  }
}

void detruire_noeudarbreRadix(noeudRadix* n){
  free(n);
}

void detruire_arbreRadix(arbreRadix* n){
  //cas arbre vide
  if(n==NULL){return ;}
  //cas arbre sans fils
  noeudRadix* q = *n;
  noeudRadix* p1 = q->fils;
  if(p1==NULL){detruire_noeudarbreRadix(q);return;}
  //cas arbre avec fils
  noeudRadix* p2 = p1->frere;
  while(!arbre_est_vide_ArbreRadix(p2)){//on détruit les arbres commencant par les fils (sauf le dernier)
    detruire_arbreRadix(&(p1));
    p1=p2;
    p2=p2->frere;
  }
  detruire_arbreRadix(&p1);//on détruit le dernier fils
  detruire_noeudarbreRadix(q);//on détruit enfin la racine
  *n=NULL;//on met a jour la nouvelle valeur de a
}
*/
