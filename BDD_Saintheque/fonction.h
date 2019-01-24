#pragma once
#include <string>

typedef struct user {
	std::string id;
	std::string mdp;
	std::string role;
}user;

typedef struct groupe {
	std::string role;
	std::string mdp;
}groupe;

typedef struct colonne {
	std::string nom;
	int numColone;
}colonne;

static MYSQL* connexion; //On conserve la même connexion pendant toute la durée du programme
static user utilisateur; //On conserve aussi le mmême urilisateur

void identification();
bool connexionMySQL();
bool verifUtilisateur(user*);
void action(user*);
void finish_with_error(MYSQL*);
void mysqlQuery(const char *, colonne[], int);
void recupRole();
void customQuery();
void executeOrder66();



//TD des Listes

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