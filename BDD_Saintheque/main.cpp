#include <mysql.h>
#include <iostream>
#include <cstdlib>
#include "fonction.h"

//static groupe grouptab[3][2] = { {"Admin_Saintheque","Admin"},{"Bibliothecaire_Saintheque","Bibliothecaire"},{"Client_Saintheque","Client"} };

using namespace std;


int main() {
	cout << "Bienvenu à la Médiatheque de Saint-Etienne ! " << endl; // prints Bienvenu à la Médiatheque de Saint-Etienne !
	printf("MySQL client version: %s\n", mysql_get_client_info());

	user user;
	user.id = "root";
	user.mdp = ".root123.";
	groupe droit = recuperationGroupe(user);
	action(droit);

	return 0;
}