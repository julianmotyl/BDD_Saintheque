#include <iostream>
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


	while (notok) {
		cout << "Bienvenu-e-s, une identification est necessaire, voulez-vous continuer ?(o/n) -> ";
		cin >> next;
		if (next == 'o') {
			notok = false;
		}
		else {
			if (next == 'n') {
				notok = false;
			}
		}

	}
	bool condition = false;
	while (!condition) {
		cout << endl << "Veuillez saisir votre @mail :" << endl << "|-> ";
		cin >> logid;
		utilisateur.id = logid;
		cout << endl << "Veuillez saisir votre mot de passe :" << endl << "|-> ";
		cin >> logpwd;
		utilisateur.mdp = logpwd;
		cout << endl << "<...> Connexion a l'interface de l'utilisateur '" << logid << "' <...>" << endl;
		condition = connexionMySQL(logid, logpwd);
		if (!condition) {
			cout << "Echec de connexion � la base de donn�es, souhaitez vous r�essayer ? (o/n)" << endl;
			char retry;
			cin >> retry;
				if (retry == 'o') {
					condition = false;
				}
				else {
					condition = true;
				}
		}
		else {
			system("PAUSE");
		}
	}
}

bool connexionMySQL(const char * identifiant, const char  * motdepasse) {

	MYSQL_ROW row;
	MYSQL_RES *res; 

	connexion = mysql_init(0);
	connexion = mysql_real_connect(connexion, "localhost", identifiant, motdepasse, "sainteque", 3306, NULL, 0);
	if (!connexion){
		string requete = "SHOW tables;";
		const char* r = new char[45];
		r = requete.c_str();

		mysql_query(connexion, r);
		cout << "La connexion a fonctionn� !" << endl;
		return true;
	}
	else {
		cout << "La connexion n'a pas fonctionn� !" << endl;
		return false;
	}
}

void  mysqlQuery(colonne table[])
{
	MYSQL_ROW row;
	MYSQL_RES *res;
	connexion = mysql_init(0);

	connexion = mysql_real_connect(connexion, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0);

	if (connexion) {
		puts("Successful connection to database!");

		string query = "SELECT * FROM adherents";
		const char* q = query.c_str();
		qstate = mysql_query(connexion, q);
		if (!qstate)
		{
			res = mysql_store_result(connexion);
			while (row = mysql_fetch_row(res))
			{
				printf("ID: %s, Nom: %s, Prenom: %s mail: %s, nbr_ouvrages_max: %s, adresse: %s score: %s, mdp: %s, role: %s\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
			}
		}
		else
		{
			cout << "La requete a echoue : " << mysql_error(connexion) << endl;
		}
	}
	else {
		finish_with_error(connexion);
	}
	system("PAUSE");
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}



void action(user utilisateur) {
	char choix;
	cout << "Bonjour " << utilisateur.role << " que souhaitez vous faire ?" << endl;
	cout << " (1) Faire une recherche par livre ou par auteur " << endl;
	if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {
		cout << " (2) Ajouter un emprunt" << endl;
		cout << " (3) Retourner un emprunt " << endl;
		cout << " (4) Ajouter un ouvrage " << endl;
		cout << " (5) Modifier l'�tat d'un ouvrage" << endl;
		cout << " (6) Modifier un utilisateur " << endl;

	}
	else if (utilisateur.role == "Admin_Saintheque") {
		cout << " (10) Faire des requ�tes SQL " << endl;
		cout << " (66) Executer un adh�rant " << endl;
	}
	cin >> choix;
	switch (choix)
	{
	case '1': 
		break;
	case '2': if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {

	}
		break;
	case '3': if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {

	}
		break;
	case '4': if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {

	}
		break;
	case '5': if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {

	}
		break;
	case '6': if (utilisateur.role == "Bibliotecaire_Saintheque" || utilisateur.role == "Admin_Saintheque") {

	}
		break;
	case '10': if (utilisateur.role == "Admin_Saintheque") {
		customQuery();
	}
		break; 
	case '66': if (utilisateur.role == "Admin_Saintheque") {
		executeOrder66();
	}
		break;
	default: cout << "Erreur de choix non reconnu" << endl;
		break;
	}
}

void customQuery() {
	char * query = new char;
	cout << "Quel est votre requete ?" << endl;
	cin >> query;
	mysql_query(connexion, query);
	//D�claration des objets
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	int i = 1;

	//On met le jeu de r�sultat dans le pointeur result
	result = mysql_use_result(connexion);
	//Tant qu'il y a encore un r�sultat ...
	while ((row = mysql_fetch_row(result)))
	{
		printf("Resultat %ld\n", i);
		i++;
	}
	//Lib�ration du jeu de r�sultat
	mysql_free_result(result);
}
void executeOrder66() {

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