#include <iostream>
#include <string>
#include <mysql.h>
#include <time.h>
#include <math.h>

#include "fonction.h"

using namespace std;

int qstate;


void identification() {
	char next;
	bool notok = true;
	char logid[55], logpwd[55];

	cout << "................................................" << endl;
	cout << "       _________" << endl;
	cout << "       ---------" << endl;
	cout << "    //" << endl;
	cout << " (|" << endl;
	cout << "   \\" << endl;
	cout << "     \\" << endl;
	cout << "       |)" << endl;
	cout << "     //" << endl;
	cout << "======   AINTHEQUE - DATABASE ACCESS" << endl;
	cout << "................................................" << endl;

	getchar();

	while (notok) {
		cout << "Bienvenu-e-s, une identification est necessaire, voulez-vous continuer ?(O/n) -> ";
		cin >> next;
		if (next == 'O') {
			notok = false;
		}
		else {
			if (next == 'n') {
				notok = false;
			}
		}

	}
	cout << endl << "Veuillez saisir votre @mail :" << endl << "|-> ";
	cin >> logid;
	cout << endl << "Veuillez saisir votre mot de passe :" << endl << "|-> ";
	cin >> logpwd;
	cout << endl << "<...> Connexion a l'interface de l'utilisateur '" << logid << "' <...>" << endl;
}
bool connexionMySQL(char * identifiant, char  * motdepasse) {

	MYSQL* connexion;// = new MYSQL;
	MYSQL_ROW row;
	MYSQL_RES *res;

	connexion = mysql_init(0);
	//	mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "");
	system("PAUSE");
	connexion = mysql_real_connect(connexion, "localhost", "test1", "test1", "sainteque", 3306, NULL, 0);
	string requete = "SHOW tables;";
	const char* r = new char[45];
	r = requete.c_str();

	mysql_query(connexion, r);
	mysql_close(connexion);
	cout << "La connexion a fonctionn� !";
	system("PAUSE");
	return true;
	/*
	if (mysql_real_connect(&mysql, "localhost", "root", "root", "saintheque", 3306, NULL, 0))
	{
		mysql_query(&mysql, "SHOW tables;");
		mysql_close(&mysql);
		cout << "La connexion a fonctionn� !";
		system("PAUSE");
		return true;
	}
	else
	{
		cout << "Une erreur s'est produite lors de la connexion a la BDD!" << endl;
		system("PAUSE");
		return false;
	}*/
}

void  afficheAdherents(char * table)
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0);

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
				printf("ID: %s, Nom: %s, Prenom: %s mail: %s, nbr_ouvrages_max: %s, adresse: %s score: %s, mdp: %s, role: %s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
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
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

groupe recuperationGroupe(user user) {

	MYSQL *connexionMySQL = mysql_init(NULL);
	mysql_options(connexionMySQL, MYSQL_READ_DEFAULT_GROUP, "");
	groupe userGroupe;

	if (connexionMySQL == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(connexionMySQL, "localhost", user.id, user.mdp,
		"saintheque", 0, NULL, 0) == NULL)
	{
		finish_with_error(connexionMySQL);
	}

	if (mysql_query(connexionMySQL, "SELECT * FROM adh�rent"))
	{
		finish_with_error(connexionMySQL);
	}

	MYSQL_RES *result = mysql_store_result(connexionMySQL);

	if (result == NULL)
	{
		finish_with_error(connexionMySQL);
	}

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;

	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(connexionMySQL);

	exit(0);
}


void action(groupe groupe) {
	if (groupe.role == "Client_Saintheque" || groupe.role == "Admin_Saintheque" || groupe.role == "Bibliotecaire_Saintheque") {
		cout << "Bonjour, " << groupe.role << " que souhaitez vous faire ?" << endl;
		cout << " (1) Faire une recherche par livre ou par auteur " << endl;
	}
	else if (groupe.role == "Bibliotecaire_Saintheque" || groupe.role == "Admin_Saintheque") {
		cout << " (2) Ajouter un emprunt" << endl;
		cout << " (3) Retourner un emprunt " << endl;
		cout << " (4) Ajouter un ouvrage " << endl;
		cout << " (5) Modifier l'�tat d'un ouvrage" << endl;
		cout << " (6) Modifier un utilisateur " << endl;

	}
	else if (groupe.role == "Admin_Saintheque") {
		cout << " (10) Faire des requ�tes SQL " << endl;
		cout << " (66) Executer un adh�rant " << endl;
	}
	else {
		cout << "Erreur de groupe non reconnu" << endl;
	}
}

void search_saintheque() {
	unsigned int choix;
	string search;
	bool notok = true;

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);

	//conn = mysql_real_connect(conn, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0); //DB Julian
	conn = mysql_real_connect(conn, "localhost", "root", ".root123", "saintheque", 3307, NULL, 0); //DB Kent


	if (conn) {
		puts("Successful connection to database!");
		string query;
		while (notok) {
			cout << "Veuillez rentrer le nom du livre ou de l'auteur � rechercher ? " << endl << ": ";
			getline (cin, search);
			cout << "Souhaitez-vous rechercher un livre (1) ou un auteur (2) ? " << endl << ": ";
			cin >> choix;
			if (choix == 1) {
				notok = false;
				query = "SELECT * FROM ouvrage WHERE titre SOUNDS LIKE "+ search;
			}
			else {
				if (choix == 2) {
					notok = false;
					string query_nom = "SELECT * FROM auteur WHERE nom SOUNDS LIKE " + search.substr(search.find(' ') + 1, 999999);
					string query_prenom = " AND WHERE prenom SOUNDS LIKE " + search.substr(1, search.find(' ') - 1);
					query = query_nom + query_prenom;
				}
			}
		}
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				if (choix == 1) {
					printf("ID: %s, Titre: %s, Genre: %s Auteur: %s, Date de parution: %s, Dur�e: %s, Type: %s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
				}
				if (choix == 2) {
					printf("ID: %s, Nom: %s, Prenom: %s, Date de naissance: %s, Date de d�c�s: %s, Biographie: %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
				}
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

}




bool estVide(list l) {
	return l == NULL;
}

void afficher(list l) {
	while (!estVide(l)) {
		cout << l->valeur << ",";
		l = l->suivant;
	}
}

int count = 0;
list supprime_pos_rec(list l, int pos) {
	if (estVide(l)) {
		return l;
	}
	if (::count == pos) {
		maillon *m = l->suivant;
		free(l);
		return m;
	}
	else {
		::count++;
		l->suivant = supprime_pos_rec(l->suivant, pos);
		return l;
	}
}

list initList() {
	return NULL;
}

list insert(list l, int val) {

	if (estVide(l)) {
		maillon*m = new maillon;
		m->valeur = val;
		m->suivant = NULL;
		return m;
	}
	if (l->suivant->valeur >= val) {
		maillon*m = new maillon;
		m->valeur = val;
		m->suivant = l->suivant;
		l->suivant = m;
		return l;
	}
	if (l->valeur >= val) {
		maillon*m = new maillon;
		m->valeur = val;
		m->suivant = l;
		return m;
	}
	else {
		l->suivant = insert(l->suivant, val);
		return l;
	}
}

list supprime(int val, list l) {
	list result = l;
	bool supprime = false;
	if (l->valeur == val) {
		result = l->suivant;
		free(l);
		supprime = true;
	}
	while (!estVide(l->suivant) && !supprime) {

		if (l->suivant->valeur == val) {
			maillon * m = l->suivant->suivant;
			free(l->suivant);
			l->suivant = m;
			supprime = true;
		}
		else {
			l = l->suivant;
		}
	}
	return result;
}

list supprime_rec(int val, list l) {

	if (!estVide(l)) {
		return l;
	}
	if (l->valeur == val) {
		maillon *m = l->suivant;
		free(l);
		return m;
	}
	else {
		l->suivant = supprime_rec(val, l->suivant);
		return l;
	}
}

int factorielle(int n) {

	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorielle(n - 1);
	}

}

int ** matrixInt(const int ROW = 5, const int COL = 5, const int MIN = 0, const int MAX = 100)
{
	int **pt = new int *[ROW];
	for (int u = 0; u < ROW; u++)
		*(pt + u) = new int[COL];
	cout << sizeof(pt) << endl;
	cout << sizeof(pt[0]) << endl;
	cout << sizeof(int) << endl;
	cout << ROW << endl;
	cout << COL << endl;
	srand(time(NULL));


	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int ran = rand() % (MAX - MIN + 1) + MIN;
			cout << "l" << i + 1 << "/" << ROW << " ; c" << j + 1 << "/" << COL << endl;
			cout << "r" << i << ", c" << j << endl;
			pt[i][j] = ran;
			cout << pt[i][j] << endl;
			cout << &pt[i][j] << endl;
		}

	}
	return pt;

}

void disMatrixInt(int ** pt)
{
	//const int ROW = sizeof(pt)/sizeof(int); NOT WORKING
	//const int COL = sizeof(*pt)/sizeof(int);
	const int ROW = 6;
	const int COL = 5;

	cout << endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << pt[i][j] << " ; ";
		}
		cout << endl;

	}
}