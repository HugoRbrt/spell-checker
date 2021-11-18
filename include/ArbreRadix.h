#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <float.h>
#include <math.h>

typedef struct noeud_R{
  char* valeur;//chaque noeud comporte un String
  struct noeud_R *fils;
  struct noeud_R *frere;
}noeudRadix,* arbreRadix;//arbeRadix

//retourne ou nouveau noeud contenant le string caractere
noeudRadix* creer_noeud_ArbreRadix(char* caractere);
//retourne 1 si l'arbre est vide
bool arbre_est_vide_ArbreRadix(arbreRadix a);
//retourne 1 si l'le noeud possède un frere
bool possede_frere_ArbreRadix(noeudRadix p);
//retourne 1 si le noeud possède un fils
bool possede_fils_ArbreRadix(noeudRadix p);
//insère dans l'arbnre un mot qui n'etait pas déjà présent
void insererMot_ArbreRadix(arbreRadix a, char* s);
//insertion récursive du mot pour la fonction précédente
void recInsertion_ArbreRadix(arbreRadix a, char* c);
//retourne 1 si p contient s, 0 sinon
int contient_prefixe_ArbreRadix(noeudRadix p, char* s);
//retire les l premiers caractères de c dans une nouvelle chaine retourné (libère c si libérer ==1)
char* Retire_l_caracteres(char* c, int l, bool liberer);
//ajoute un noeud fils à source
void add_fils_ArbreRadix(arbreRadix source , noeudRadix* noeud);
//renvoie le noeud fils de a contenant c
arbreRadix descendre_arbreRadix(arbreRadix a,char* c);
//renvoie 1 si c présent dans a
bool est_present_arbreRadix(arbreRadix a, char* c);
//affiche l'arbre a
void afficher_ArbreRadix(arbreRadix a);
//renvoie un nouvel arbre en fonction du contenu de f
arbreRadix creation_arbreRadix(FILE* f);
