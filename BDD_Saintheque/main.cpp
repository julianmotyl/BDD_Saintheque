#include <mysql.h>
#include <iostream>
#include <cstdlib>
#include "fonction.h"

//static groupe grouptab[3][2] = { {"Admin_Saintheque","Admin"},{"Bibliothecaire_Saintheque","Bibliothecaire"},{"Client_Saintheque","Client"} };

using namespace std;


int main() {
	cout << "Bienvenu � la M�diatheque de Saint-Etienne ! " << endl; // prints Bienvenu � la M�diatheque de Saint-Etienne !

	identification();

	return 0;
}