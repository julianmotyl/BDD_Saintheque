#include <iostream>
#include <mysql.h>
#include <string>
#include <time.h>
#include <math.h>
#include <fstream> 
#include <vector> 
#include "fonction.h"

using namespace std;

int qstater;


int wmain(){

	srand(time(NULL));
	MYSQL* conn;
	MYSQL_ROW row = nullptr;
	MYSQL_RES *res;
	conn = mysql_init(0);

	//conn = mysql_real_connect(conn, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0); //DB Julian
	conn = mysql_real_connect(conn, "localhost", "root", ".root123", "saintheque", 3307, NULL, 0); //DB Kent

	if (conn) {
		cout << "Bienvenu à la Médiatheque de Saint-Etienne ! " << endl; // prints Bienvenu à la Médiatheque de Saint-Etienne !
		puts("Successful connection to database!");

		string query = "SELECT * FROM adherents";
		const char* q = query.c_str();
		qstater = mysql_query(conn, q);
		if (!qstater)
		{
			res = mysql_store_result(conn);
 			while (row = mysql_fetch_row(res))
			{
				printf("\nID: %s -|- NOM : %s -|- PRENOM : %s -|- @MAIL : %s -|- ROLE : %s -|- LIMITE DE NOMBRE D'OUVRAGES : %s -|- ADRESSE : %s -|- SCORE : %s |-\n", row[0], row[1], row[2], row[3], row[5], row[6], row[7], row[8]);
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else {
		puts("Connection to database has failed!");
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	addDBRandomUser(1);



	vector <string> myTab = lectureFile("test");
	for(unsigned int i = 0;i< myTab.size();i++)
		cout << myTab[i]<<endl;

	searchSaintheque();

	//cout << endl << insertFile("test", "ouvrage")<<endl;

	system("PAUSE");

return 0;
}