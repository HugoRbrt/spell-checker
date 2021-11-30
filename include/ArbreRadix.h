#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <float.h>
#include <math.h>

/*par convetion l'arbre possède des cellules de string et le mot n'est présent
que si il existe un chemin de la source (commencant par #) vers une feuille contenant #*/

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
//retourne la taille d eprefixe commun entre p et s
int taille_prefixe_commun_ArbreRadix(char* p, char* s);
//ajoute un noeud fils à source
void add_fils_ArbreRadix(arbreRadix source , noeudRadix* noeud);
//insertion récursive du mot pour la fonction précédente
void recInsertion_ArbreRadix(arbreRadix a, char* c);
//retire les l premiers caractères de c dans une nouvelle chaine retourné (libère c si libérer ==1)
char* Retire_l_caracteres(char* c, int l, bool liberer);
//renvoie le noeud fils de a contenant c
arbreRadix descendre_arbreRadix(arbreRadix a,char* c);
//renvoie 1 si c présent dans a
bool est_present_arbreRadix(arbreRadix a, char* c);
//affiche l'arbre a
void afficher_ArbreRadix(arbreRadix a);
//renvoie un nouvel arbre en fonction du contenu de f
arbreRadix creation_arbreRadix(FILE* f);
//pareil mais avec seulement les bornes 1er mots (pour mesure performance)
arbreRadix creation_arbreRadix_borne(FILE* f,float borne);
//liberation de tout l'arbreradix
void detruire_arbreRadix(arbreRadix* a);
