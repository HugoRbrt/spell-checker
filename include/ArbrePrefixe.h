#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <float.h>
#include <math.h>

typedef struct noeud_p{
  char valeur;
  struct noeud_p *fils;
  struct noeud_p *frere;
}noeudPrefixe,* arbrePrefixe;//arbePrefixe

//creer un noeud avec un caractere sans frere ni fils
noeudPrefixe* creer_noeud(char caractere);
//retourne 1 si a vide, 0 sinon
bool arbre_est_vide(arbrePrefixe a);
//detruit l'arbre et le retourne NULL
void detruire_arbre(arbrePrefixe* a);
//ajoute un fils à un noeud source deja existant en s'assurant qu'il n'existe aucun fils possedant deja le caractere c
//retourne le pointeur sur le noeud correspond au fils de a ayant pour caractere c
arbrePrefixe add_fils(arbrePrefixe source, char c);
//renvoie a->fils tel que le a->fils->valeur == c (retourne NULL si il n'y a pas)
arbrePrefixe descendre_arbrePrefixe(arbrePrefixe a,char c);

//affiche l'arbre prefix dans l'ordre : racine, fils, frere
void afficher_ArbrePrefixe(arbrePrefixe );

//insere la chaine s dans a (en ajoutant les noeud si il faut)
void insererMot_ArbrePrefixe(arbrePrefixe a, char* s);
//renvoie 1 si le mot est présent, 0 sinon
bool est_present_arbrePrefixe(arbrePrefixe a, char* s);


//suppression d'un arbre
void detruire_noeudarbrePrefixe(noeudPrefixe* n);
void detruire_arbrePrefixe(arbrePrefixe* a);

//creation d'un graph a partir d'un fichier
arbrePrefixe creation_arbrePrefixe(FILE* f);
//pareil mais avec seulement les borne 1er mot (pour mesure performances)
arbrePrefixe creation_arbrePrefixe_borne(FILE* f, int borne);
