#include <mysql.h>
#include <iostream>
#include <cstdlib>
#include "fonction.h"
#include <fstream>
#include <vector>

//static groupe grouptab[3][2] = { {"Admin_Saintheque","Admin"},{"Bibliothecaire_Saintheque","Bibliothecaire"},{"Client_Saintheque","Client"} };

using namespace std;


int main() {
	cout << "Bienvenu à la Médiatheque de Saint-Etienne ! " << endl; // prints Bienvenu à la Médiatheque de Saint-Etienne !
	colonne table[4];
	table[0].nom = "id adherents";
	table[0].numColone = 0;
	table[1].nom = "nom";
	table[1].numColone = 1;
	table[2].nom = "mail";
	table[2].numColone = 3;
	table[3].nom = "score";
	table[3].numColone = 6;
	//identification();
	//action();
	int nombreColones = sizeof(table) / sizeof(colonne);
	user *utilisateur= new user;
	char id[6] = "test1";
	utilisateur->id = id;
	utilisateur->mdp = id;
	utilisateur->role = "admin_saintheque";
	connexionMySQL();
	//utilisateur = identification();
	//verifUtilisateur(utilisateur);
	action(utilisateur);
	//const char * query = "select * from adherents";

	//customQuery();
	return 0;
}