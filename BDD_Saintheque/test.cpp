#include <iostream>
#include <mysql.h>
#include <time.h>
#include <math.h>

#include "fonction.h"

using namespace std;

int qstate;


int main(){
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", ".root123", "saintheque", 3307, NULL, 0);

	if (conn) {
		puts("Successful connection to database!");

		string query = "SELECT * FROM adherents";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("ID: %s, Nom: %s, Prenom: %s, mail: %s, nbr_ouvrages_max: %s, adresse: %s, score: %s, mdp: %s, role: %s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
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
	system("PAUSE");

return 0;
}