#include <iostream>
#include <mysql.h>
#include <time.h>
#include <math.h>

#include "fonction.h"

using namespace std;


// Ceci est un test !
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
	cout << "La connexion a fonctionné !";
	system("PAUSE");
	return true;
	/*
	if (mysql_real_connect(&mysql, "localhost", "root", "root", "saintheque", 3306, NULL, 0))
	{
		mysql_query(&mysql, "SHOW tables;");
		mysql_close(&mysql);
		cout << "La connexion a fonctionné !";
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

	if (mysql_query(connexionMySQL, "SELECT * FROM adhérant"))
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
		cout << "Bonjour " << groupe.role << " que souhaitez vous faire ?" << endl;
		cout << " (1) Faire une recherche par livre ou par auteur " << endl;
	}
	else if (groupe.role == "Bibliotecaire_Saintheque" || groupe.role == "Admin_Saintheque") {
		cout << " (2) Ajouter un emprunt" << endl;
		cout << " (3) Retourner un emprunt " << endl;
		cout << " (4) Ajouter un ouvrage " << endl;
		cout << " (5) Modifier l'état d'un ouvrage" << endl;
		cout << " (6) Modifier un utilisateur " << endl;

	}
	else if (groupe.role == "Admin_Saintheque") {
		cout << " (10) Faire des requêtes SQL " << endl;
		cout << " (66) Executer un adhérant " << endl;
	}
	else {
		cout << "Erreur de groupe non reconnu" << endl;
	}
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