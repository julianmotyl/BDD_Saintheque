#pragma once
#include <string>
#include <fstream> 
#include <vector> 

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

std::string today();
user* identification();
bool connexionMySQL();
bool verifUtilisateur(user* user);
void action(user* user);
void finish_with_error(MYSQL* mysql);
MYSQL_ROW mysqlQuery(const char *, colonne[], int);
bool recupRole(user* user);
void customQuery();
void executeOrder66(user * user);
//void importFile();
void seeTheLoans();
void empruntOuvrage(user* user);
bool rendOuvrage(user * user);
void searchSaintheque();
bool addDBRandomUser(unsigned int nb);
std::string majuscule(std::string chaine);
std::string minuscule(std::string chaine);
std::string gename(const unsigned int MIN, const unsigned int MAX);
std::vector <std::string> lectureFile(std::string name);
std::vector<std::string> split(const std::string &str, const std::string &separator);
bool insertFile(std::string file, std::string table);
