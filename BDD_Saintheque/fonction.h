#pragma once
#include <string>

typedef struct user {
	const char * id;
	const char * mdp;
}user;

typedef struct groupe {
	const char * role;
	const char * mdp;
}groupe;

void identification();
bool connexionMySQL(char *, char *);
groupe  recuperationGroupe(user);
void action(groupe);
void search_saintheque();
bool addDB_random_adherents(unsigned int nb);
string majuscule(string &chaine);
string minuscule(string &chaine);
string gename(const unsigned int MIN, const unsigned int MAX);






typedef struct maillon {

	char  valeur;
	maillon * suivant;

} maillon;

typedef maillon *list;

int factorielle(int n);
int ** matrixInt(const int ROW, const int COL, const int MIN, const int MAX);
void disMatrixInt(int ** pt);
list initList();
bool estVide(list l);
void afficher(list l);
list insert(list l, int val);
list supprime_rec(int val, list l);