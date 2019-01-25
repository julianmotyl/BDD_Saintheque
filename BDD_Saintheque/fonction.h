#pragma once
#include <string>
/**
Structures
**/

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
void executeOrder66(user*);
void importFile();
void seeTheLoans();
void empruntOuvrage(user*);

void searchSaintheque();
bool addDBRandomUser(unsigned int nb);
std::string majuscule(std::string &chaine);
std::string minuscule(std::string &chaine);
std::string gename(const unsigned int MIN, const unsigned int MAX);