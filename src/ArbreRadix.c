#include "ArbreRadix.h"

int COMPTEUR=0;

noeudRadix* creer_noeud_ArbreRadix(char* caractere){
  if (caractere==NULL){return NULL;}
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
int taille_prefixe_commun_ArbreRadix(char* p, char* s){
  if(s==NULL || p==NULL){return 0;}
  char caractere_p = p[0];
  char caractere_s = s[0];
  bool diff = 0;//prend 1 lorsque 2 caractères comparés sont différents
  int cpt_char_identique = 0;//compteur de lettre identique
  while(caractere_s!='\0' && caractere_p!='\0' && !diff){//tant qu'on est pas arrivé à la fin d'un des string et qu'ils n'ont pas différé
    if(caractere_s!=caractere_p){diff=1;}//si il diffère on arrête le while
    else{
      cpt_char_identique++;//si ils sont identioque on avance de 1 caractère et on augmente le compteur de caractère identique de 1
      caractere_p = p[cpt_char_identique];
      caractere_s = s[cpt_char_identique];
    }
  }
  return cpt_char_identique;
}
void add_fils_ArbreRadix(arbreRadix source , noeudRadix* noeud){
  if(source->fils==NULL){//si il n'y a pas de fils, on n'a qu'à la mettre comme 1er fils
    source->fils = noeud;
    noeud->fils = creer_noeud_ArbreRadix("#");//pour siognifier qu'il s'agit bien de la fin d'un mot
  }
  else{//si il existe au moins un fils
    noeudRadix* f = source->fils;
    while(f->frere!=NULL){//on se position au dernier élément de la liste des frères
      f = f->frere;
    }
    f->frere = noeud;//on ajoute le noeud en bout de liste des frères
  }
}

void recInsertion_ArbreRadix(arbreRadix a, char* c){
  if(c==NULL || strlen(c)<1){//si on veut ajouter un c null cela veut dire qu'on a consommé tout le mot donc il faut ajoute rla feuille "#"
    add_fils_ArbreRadix(a,creer_noeud_ArbreRadix("#"));
  }//si mot vide on ne l'ajoute pas
  if(!possede_fils_ArbreRadix(*a)){//si a n'a pas de fils, on ajoute un fils ayant le string c
   add_fils_ArbreRadix(a,creer_noeud_ArbreRadix(c));
  }
  else{//si a à au moins 1 fils
    int l;
    bool modif_faite=0,tous_frere_parcouru=0, dernier_frere=0;
    noeudRadix* f = a->fils;
    if(f->frere==NULL){dernier_frere=1;}

    while(0==tous_frere_parcouru && !modif_faite){//tant qu'on a pas parcouru tous les fraires et qu'on a fait aucune insertion :
      if(dernier_frere==1){tous_frere_parcouru=1;}//si on est au dernier frere, on signal que c'est la derniere fois qu'on parcours le while
      l = taille_prefixe_commun_ArbreRadix(f->valeur,c);

      if(l!=0){//si le noeud contient un prefixe de s
        char* c2 = Retire_l_caracteres(c,l,0);//c2 correspond à c sans le prefixe commun à f et c
        if(l == strlen(f->valeur)){//si ce prefixe correspond à tout le noeud, on insert c2 dans ce noeud
          recInsertion_ArbreRadix(f,c2);
        }
        else {
             /*si le prefixe ne correspond qu'à une partie du noeud, il faut : modifier le noeud actuel pour qu'il ne contienne
             que le prefixe et qu'ils pointent vers 2 fils : 1 correspondant au reste des lettres de c, et un correspondant
             au reste des lettres du noeud (en conservant ses fils d'origines)*/
          noeudRadix* feuille = creer_noeud_ArbreRadix("#");//noeud disant que la branche jusqu'à fils 1 correspond à 1 mot
          feuille->frere = NULL;
          feuille->fils  = NULL;
          noeudRadix* reste_c = creer_noeud_ArbreRadix(c2);//noeud contenant le reste des lettres de c
          if(reste_c!=NULL){
          reste_c->frere = NULL;
          reste_c->fils  = feuille;
          }
          char* c_reste_noeud = Retire_l_caracteres(f->valeur,l,0);
          noeudRadix* reste_noeud = creer_noeud_ArbreRadix(c_reste_noeud);//noeud contenant le reste des lettres
          free(c_reste_noeud);
          reste_noeud->frere = reste_c;                                                       //du noeud d'origine (et pointant vers
          reste_noeud->fils  = f->fils;                                                      //les fils d'origine et ayanbt pour frere le noeud précédent)
          char* prefixe = strndup(f->valeur,l);//le noeud n possède alors plus que le prefixe en commun
          free(f->valeur);
          f->valeur = prefixe;
          f->fils   = reste_noeud; //il pointe vers les deux fils en commun
        }
        free(c2);
        modif_faite= 1;
      }

      if(!modif_faite && 0==tous_frere_parcouru){//on passe au suivant si aucune modif n'est faite et qu'on a pas encore parcouru tous les frères
        f = f->frere;
        if(f->frere==NULL){dernier_frere=1;}//si on est au dernier élémént alors on va refaire la while pour la derniere fois
      }
    }
    if(!modif_faite){//si aucun frere n'a de prefixe commun avec c, on ajoute un frere
    f->frere = creer_noeud_ArbreRadix(c);
    if(f->frere!=NULL){f->frere->fils = creer_noeud_ArbreRadix("#");}
    }
  }
}

char* Retire_l_caracteres(char* c, int l, bool liberer){
  assert(l<=strlen(c));
  if(l==strlen(c)){
    if(liberer){free(c);
    }//avant de quitter la fonction on libère si c'est demandé
    return NULL;//on a retirer tous les caractères de c
  }
  char* c2 = malloc(strlen(c) - l+1 );//-l pour les l lettres retirés
  int l_c = strlen(c);
  int k;
  for(k=0;k<l_c-l;k++){
    c2[k] = c[l+k];
  }
  c2[strlen(c)-l]='\0';

  if(liberer){free(c);}
  return c2;
}


arbreRadix descendre_arbreRadix(arbreRadix a,char* c){
  arbreRadix p =a->fils;
  while(p!=NULL){//tant qu'on a pas fait tous les freres et qu'on a pas trouvé le bon noeud
    char* s = strndup(c,strlen(p->valeur));
    if(strcmp(p->valeur,s) == 0){free(s);return p;}
    free(s);
    if(p->valeur[0]==c[0]){return NULL;}//si il commencait par la même lettre mais ils sont différents alors aucun frere ne convidendra (car chaques frere commence par une lettre differente)
    p = p->frere;
  }
  return p;//on retourne soit le noeud trouvé soit NULL car on est en fin de liste de frere
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

bool est_present_arbreRadix(arbreRadix a, char* c){
  arbreRadix b = a;
  int k;
//cas spéciaux de ponctuations, majuscule, mot vide...
  int l = strlen(c);
  if(l==0){return true;}//un mot vide est dans l'arbre
  if(c[0]==34 || c[0]==40){return est_present_arbreRadix(a,c+1);}//si le mot commence par ( ou " on refait pareil sans ce caractère
  while(l>0 && (c[l-1]==44 || c[l-1]==46 || c[l-1]==40 || c[l-1]==41 || c[l-1]==34 || c[l-1]==45 )){c[l-1]='\0';l--;}//on enlève tous les caractère , . (  " - à la fin du mot
  if(strlen(c)==0){return true;}//si les actions on vidé le mot, alors il est dans l'arbre (pour ne pas considérer les ponctuations isolés commes non francais)
  for(k=0;k<l;k++){
    if(c[k]<97){return true;}//cas ou il y a lattre majuscule ou chiffre ou ;:<>=?@_^[]\/'-    =>on part du principe qu'il est francais
  }
//recherche dans le graph
  char* s2 = strdup(c);
  char *s = malloc(strlen(s2) + 1 + 1 );
  strcpy(s,s2);
  s[strlen(s2)]='#';
  s[strlen(s2)+1]='\0';
  free(s2);

  //strcat(s,"#");//on ajoute le # qui symbolise la fin du mot dans l'arbre
  int len_b=0;
  while(b!=NULL && s!=NULL){
    b = descendre_arbreRadix(b,s);
    if(b!=NULL){len_b = strlen(b->valeur);}
    else{len_b=0;}
    if(len_b<=strlen(s)){s = Retire_l_caracteres(s,len_b,1);}
  }
  bool est_present = s==NULL;
  free(s);
  return est_present;
}

arbreRadix creation_arbreRadix(FILE* f){
  arbreRadix a =creer_noeud_ArbreRadix("");
  char s[30];
  int cpt=0;
  while(fscanf(f,"%s",s)!=EOF){//lit le mot
    recInsertion_ArbreRadix(a,s);cpt++;
  }
  printf("nombre de mot dans le graphe : %d",cpt);
  return a;

}
arbreRadix creation_arbreRadix_borne(FILE* f,float borne){
  arbreRadix a =creer_noeud_ArbreRadix("");
  char s[30];
  int cpt=0;
  while(fscanf(f,"%s",s)!=EOF){//lit le mot
    if(rand()%10000<100*borne){recInsertion_ArbreRadix(a,s);cpt++;}
  }
  printf("compteur = %d",cpt);
  return a;

}

void detruire_arbreRadix(arbreRadix* a){
  //on détruit le fils
  if(possede_fils_ArbreRadix(**a)){detruire_arbreRadix(&((*a)->fils));}
  //on détruit son frère le plus proche
  if(possede_frere_ArbreRadix(**a)){detruire_arbreRadix(&((*a)->frere));}
  free((*a)->valeur);
  free(*a);
}
