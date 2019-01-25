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
//static user utilisateur; //On conserve aussi le mmême urilisateur

user* identification();
bool connexionMySQL();
bool verifUtilisateur(user*);
void action(user*);
void finish_with_error(MYSQL*);
MYSQL_ROW mysqlQuery(const char *, colonne[], int);
bool recupRole(user*);
void customQuery();
void executeOrder66();

void searchSaintheque();
bool addDBRandomUser(unsigned int nb);
std::string majuscule(std::string &chaine);
std::string minuscule(std::string &chaine);
std::string gename(const unsigned int MIN, const unsigned int MAX);


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