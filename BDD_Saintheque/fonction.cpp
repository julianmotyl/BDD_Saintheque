#include <iostream>
#include <mysql.h>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream> 
#include <vector> 
#include "fonction.h"

using namespace std;

int qstate;


user* identification() {
	user *utilisateur = new user;
	char next;
	bool notok = true;
	string logid, logpwd;

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
		utilisateur->id = logid;
		cout << endl << "Veuillez saisir votre mot de passe :" << endl << "|-> ";
		cin >> logpwd;
		utilisateur->mdp = logpwd;
		cout << endl << "<...> Connexion a l'interface de l'utilisateur '" << logid << "' <...>" << endl;
		condition = connexionMySQL();
		if (!condition) {
			cout << "Echec de connexion � la base de donn�es, souhaitez vous r�essayer ? (o/n)" << endl;
			string retry;
			cin >> retry;
				if (retry == "o") {
					condition = false;
				}
				else {
				}
		}
		else {
			if (verifUtilisateur(utilisateur)) {

			}
			else {
				cout << "Identification echoue, mauvais couple mail / mot de passe" << endl;
				condition = false;
			}
		}
	}
	return utilisateur;
}

bool connexionMySQL() {

	connexion = mysql_init(0);
	connexion = mysql_real_connect(connexion, "localhost", "root", ".root123.", "saintheque", 3306, NULL, 0);
	if (connexion){
		cout << "La connexion a fonctionn� !" << endl;
		return true;
	}
	else {
		cout << "La connexion n'a pas fonctionn� !" << endl;
		return false;
	}
}

bool verifUtilisateur(user *utilisateur) {
	MYSQL_ROW row;
	MYSQL_RES *res;

	string debutQuery = "SELECT mdp FROM adherents where mail = \"";
	char * dbtQuery = new char[debutQuery.length() + 1];
	strcpy(dbtQuery, debutQuery.c_str());

	std::string id = utilisateur->id;
	const char * identifiant = id.c_str();

	const char * motDePasse = utilisateur->mdp.c_str();
	string interQuery = strcat(dbtQuery, utilisateur->id.c_str());
	const char* intermedQuery = nullptr;
	if (connexion) {
		string query = debutQuery + utilisateur->id + "\"";
		const char* q = query.c_str();
		qstate = mysql_query(connexion, q);
		if (!qstate)
		{
			res = mysql_store_result(connexion);
			row = mysql_fetch_row(res);
			if (utilisateur->mdp == row[0]) {
				return recupRole(utilisateur);
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
	return false;
}

bool recupRole(user *utilisateur) {
	MYSQL_ROW row;
	MYSQL_RES *res;

	string debutQuery = "SELECT role FROM adherents where mail = \"";
	char * dbtQuery = new char[debutQuery.length() + 1];
	strcpy(dbtQuery, debutQuery.c_str());

	std::string id = utilisateur->id;
	const char * identifiant = id.c_str();

	const char * motDePasse = utilisateur->mdp.c_str();
	string interQuery = strcat(dbtQuery, utilisateur->id.c_str());
	const char* intermedQuery = nullptr;
	if (connexion) {
		string query = debutQuery + utilisateur->id + "\"";
		const char* q = query.c_str();
		qstate = mysql_query(connexion, q);
		if (!qstate)
		{
			res = mysql_store_result(connexion);
			row = mysql_fetch_row(res);
			utilisateur->role = row[0];
			return true;
		}
		else
		{
			cout << "La requete a echoue : " << mysql_error(connexion) << endl;
		}
	}
	else {
		finish_with_error(connexion);
	}
	return false;
}

MYSQL_ROW  mysqlQuery(const char * query, colonne table[], int nbrColonnes)
{
	MYSQL_ROW row = nullptr;
	MYSQL_RES *res;


	if (connexion) {
		qstate = mysql_query(connexion, query);
		if (!qstate)
		{
			res = mysql_store_result(connexion);
			while (row = mysql_fetch_row(res))
			{	
				int i = 0;
				while ( i < nbrColonnes) {
					printf(table[i].nom.c_str());
					printf(" : ");
					printf( " %s, " , row[table[i].numColone]);
					i++;
				}
				printf("\n");
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

	return row;
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

string gename(const unsigned int MIN, const unsigned int MAX) {
	/*std::*/string acceptes = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string consonnes = "bcdfghjklmnpqrstvwxz";
	string voyelles = "aeiouy";
	bool alt = true;
	/*std::*/string filename = "";
	size_t taille = (rand() % (MAX - MIN) + 1) + MIN;
	size_t pos = rand() % 26;//j'ai 26 caract�res majuscules dans acceptes
	filename += acceptes[pos];
	for (size_t i = 0; i < taille - 1; i++)
	{
		if (alt) {
			pos = rand() % 5;//j'ai 6 voyelles
			filename += voyelles[pos];
			alt = false;
		}
		else {
			pos = rand() % 20;//j'ai 20 consonnes
			filename += consonnes[pos];
			alt = true;
		}
	}
	//char *cstr = new char[filename.length() + 1];
	//strcpy(cstr, filename.c_str());
	return filename;
}

string minuscule(string chaine)
{
	for (int i = 0; i < chaine.size(); i++)
	{
		chaine[i] = tolower(chaine[i]);
	}
	return chaine;
}

string majuscule(string chaine)
{
	for (int i = 0; i < chaine.size(); i++)
	{
		chaine[i] = toupper(chaine[i]);
	}
	return chaine;
}

bool addDBRandomUser(unsigned int nb) {

	bool retour = 1;
	MYSQL* conn;
	MYSQL_ROW row = nullptr;
	MYSQL_RES *res;
	conn = mysql_init(0);

	//conn = mysql_real_connect(conn, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0); //DB Julian
	conn = mysql_real_connect(conn, "localhost", "root", ".root123", "saintheque", 3307, NULL, 0); //DB Kent


	if (conn) {
		puts("\nSuccessful connection to database!\n");
		for (unsigned int i = 0; i < nb; i++) {
			string nom = gename(3, 8);
			string rue = gename(2, 5);
			unsigned int nb_ouvrage = (rand() % (5 - 0) + 1) + 0;
			unsigned int num_rue = (rand() % (99 - 1) + 1) + 1;
			unsigned int groupe = rand() % 4;
			unsigned int score = 100;//(rand() % (500 - 0) + 1) + 0;
			string prenom = gename(3, 6);
			const char * grouptab[4][2] = { {"admin_saintheque","admin"},{"client_saintheque","client"},{"bibliothecaire_saintheque","bibliothecaire"},{"client_saintheque","client"} };
			string query = "INSERT INTO `saintheque`.`adherents` (`nom`, `prenom`, `mail`, `mdp`, `role`, `nbr_ouvrages_max`, `adresse`, `score`) VALUES('" + nom + "', '" + prenom + "', '" + minuscule(prenom) + "." + minuscule(nom) + "@mail.fr', '" + majuscule(nom).substr(0, 1) + majuscule(prenom).substr(0, 2) + majuscule(nom).substr(majuscule(nom).size() - 1, majuscule(nom).size()) + "', '" + grouptab[groupe][0] + "', '" + to_string(nb_ouvrage) + "', '" + to_string(num_rue) + " rue de " + rue + ", 42000 Saint-Etienne, France', '" + to_string(score) + "');";
			cout << query <<endl;
			//INSERT INTO `saintheque`.`adherents` (`nom`, `prenom`, `mail`, `mdp`, `adresse`, `score`) VALUES('Gonga', 'J�r�me', 'jerome.gonga@mail.fr', 'GJEA', '2 avenue Duroy, 42000 Saint-Etienne, France', '200');

			const char* q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << "|->+ ADDED\n"<<endl;
				retour = 0;
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
				retour = 1;
			}
		}
	}
	else {
		puts("Connection to database has failed!");
	}
	system("PAUSE");

	return retour;
}

vector<string> split(const string &str, const string &separator)
{
	vector<string> strVect; // pour la valeur retour
	if (str.empty())
		return strVect; // vecteur vide

	int pos = 0;
	size_t size;
	do
	{
		size = str.find(separator, pos);
		if (size != string::npos)
		{
			strVect.push_back(str.substr(pos, size - pos));
			pos = size + 1;
		}
		else
			strVect.push_back(str.substr(pos, str.size()));
	} while (size != string::npos);

	return strVect;
}

bool insertFile(string file, string table) {
	//le fichier doit comprendre le m�me nombre de colonne que la table de la base de donn�es (s�par�es par des tabulations)
	bool retour = 0;
	MYSQL* conn;
	MYSQL_ROW row = nullptr;
	MYSQL_RES *res;
	conn = mysql_init(0);

	//Choisir sa base de donn�es !!
	//conn = mysql_real_connect(conn, "localhost", "root", ".root123.", "sainteque", 3306, NULL, 0); //DB Julian
	conn = mysql_real_connect(conn, "localhost", "root", ".root123", "saintheque", 3307, NULL, 0); //DB Kent


	if (conn) {
		puts("\nSuccessful connection to database!\n");
		vector <string> monTableau = lectureFile(file);
		cout << "[i] Ajout du contenu du fichier '" + file + ".txt' dans la table '" + table + "' [i]" << endl;
		for (unsigned int i = 0; i < monTableau.size(); i++)
		{
			vector <string> tempRow = split(monTableau[i], "\t");
			string query = "INSERT INTO `saintheque`.`" + table + "` VALUES(";
			for (unsigned int j = 0; j < tempRow.size()-1; j++) {
				if (tempRow[j].empty() or tempRow[j] == "NULL" or tempRow[j] == "null")
					query += "NULL,";
				else
					query += "'" + tempRow[j] + "',";
			}
			if (tempRow[tempRow.size() - 1].empty() or tempRow[tempRow.size() - 1] == "NULL" or tempRow[tempRow.size() - 1] == "null")
				query += "NULL);";
			else
				query += "'" + tempRow[tempRow.size() - 1] + "');";
			cout << query << endl;
			const char* q = query.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				cout << "|->+ ADDED\n" << endl;
				retour = 0 xor retour;
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl << endl;
				retour = 1;
			}
		}
	}
	else {
		puts("Connection to database has failed!");
		retour = 1;
	}
	system("PAUSE");

	return retour;
}

void searchSaintheque() {
	unsigned int choix;
	string search;
	bool notok = true;

	colonne table[6];
	int nombreColones = sizeof(table) / sizeof(colonne);
	string query;
	while (notok) {
		cout << "Souhaitez-vous rechercher un ouvrage..." << endl;
		cout << "(1) ...par son titre ? [titre]"<< endl;
		cout << "(2) ...par son auteur ? [prenom nom]" << endl;
		cout << "(3) ...par sa date de parution ? [yyyy-mm-dd]" << endl;
		cout << "(0) QUITTER" << endl;
		cin >> choix;
		cout << "Veuillez rentrer le(s) mot(s) cl�(s) pour la recherche ? " << endl << ": ";
		getline(cin, search);
		//afficher les mediatheques et nombre d'exemplaires
		switch (choix)
		{
		case 1:
			query = "SELECT ouvrage.titre,auteur.prenom,auteur.nom,ouvrage.date_parution,ouvrage.resume,genre.intitule,type_media.intitule,ouvrage.duree,COUNT(exemplaires.id_ouvrage), COUNT(DISTINCT mediatheques.id_mediatheques) FROM ouvrage INNER JOIN auteur ON ouvrage.id_auteur = auteur.id_auteur INNER JOIN type_media ON ouvrage.id_type_media = type_media.id_type_media INNER JOIN genre ON ouvrage.id_genre = genre.id_genre INNER JOIN exemplaires ON ouvrage.id_ouvrage = exemplaires.id_ouvrage INNER JOIN mediatheques ON exemplaires.id_mediatheque = mediatheques.id_mediatheques WHERE ouvrage.titre SOUNDS LIKE '" + search +"';";
			//SELECT ouvrage.*,auteur.prenom,auteur.nom,ouvrage.date_parution,ouvrage.resume,genre.intitule,type_media.intitule,ouvrage.duree,COUNT(exemplaires.id_ouvrage), COUNT(DISTINCT mediatheques.id_mediatheques) FROM ouvrage INNER JOIN auteur ON ouvrage.id_auteur = auteur.id_auteur INNER JOIN type_media ON ouvrage.id_type_media = type_media.id_type_media INNER JOIN genre ON ouvrage.id_genre = genre.id_genre INNER JOIN exemplaires ON ouvrage.id_ouvrage = exemplaires.id_ouvrage INNER JOIN mediatheques ON exemplaires.id_mediatheque = mediatheques.id_mediatheques WHERE ouvrage.titre SOUNDS LIKE 'les justes';
			//SELECT COUNT(exemplaires.id_exemplaire) FROM exemplaires INNER JOIN emprunts ON emprunts.id_exemplaire = exemplaires.id_exemplaire WHERE rendu = 1 OR exemplaires.id_exemplaire != emprunts.id_exemplaire;			
			break;
		case 2:
			query = "SELECT * FROM ouvrage INNER JOIN auteur ON ouvrage.id_auteur = auteur.id_auteur WHERE auteur.nom SOUNDS LIKE '" + search.substr(search.find(' ') + 1, 999999) + "' AND auteur.prenom SOUNDS LIKE '" + search.substr(1, search.find(' ') - 1) + "';";
			/*table[0].nom = "NOM";
			table[0].numColone = 1;
			table[1].nom = "PRENOM";
			table[1].numColone = 2;
			table[2].nom = "GENRE";
			table[2].numColone = 3;
			table[3].nom = "DATE DE NAISSANCE";
			table[3].numColone = 4;
			table[4].nom = "DATE DE DECES";
			table[4].numColone = 5;
			table[5].nom = "BIOGRAPHIE";
			table[5].numColone = 6;*/
			break;
		case 3:
			query = "SELECT * FROM ouvrage WHERE date_parution='" + search +"';";
			break;
		case 0:
			notok = false;
			break;
		default:
			cout << "/!\ Erreur de choix : non reconnu /!\\" << endl;
		}
		table[0].nom = "TITRE";
		table[0].numColone = 1;
		table[1].nom = "GENRE";
		table[1].numColone = 2;
		table[2].nom = "AUTEUR";
		table[2].numColone = 3;
		table[3].nom = "DATE DE PARUTION";
		table[3].numColone = 4;
		table[4].nom = "DUREE";
		table[4].numColone = 5;
		table[5].nom = "TYPE";
		table[5].numColone = 6;
		char * chQuery = new char[query.length() + 1];
		strcpy(chQuery, query.c_str());
		mysqlQuery(chQuery, table, nombreColones);
		system("PAUSE");
	}

}

void action(user *utilisateur) {
	int choix;
	cout << "Bonjour " << utilisateur->id << " que souhaitez vous faire ?" << endl;
	cout << " (1) Rechercher un ouvrage par titre, par auteur ou par date" << endl;
	cout << " (2) Emprunter un ouvrage" << endl;
	cout << " (3) Retourner un ouvrage " << endl;
	if (utilisateur->role == "Bibliotecaire_Saintheque" || utilisateur->role == "Admin_Saintheque") {
		cout << " (4) Afficher les ouvrages empruntees par un adherent" << endl;
		cout << " (5) Ajouter les ouvrages depuis un fichier externe" << endl;
	}
	if (utilisateur->role == "Admin_Saintheque") {
		cout << " (10) Faire des requ�tes SQL " << endl;
		cout << " (66) Executer un adh�rant " << endl;
	}
	//cout << "(99) Quitter" << endl;
	cin >> choix;
	switch (choix)
	{
	case 1: 
		break;
	case 2: 
		break;
	case 3: 
		break;
	case 4: if (utilisateur->role == "Bibliotecaire_Saintheque" || utilisateur->role == "Admin_Saintheque") {
		seeTheLoans();
	}
		break;
	case 5: if (utilisateur->role == "Bibliotecaire_Saintheque" || utilisateur->role == "Admin_Saintheque") {
		importFile();
	}
		break;

	case 10: if (utilisateur->role == "Admin_Saintheque") {
		customQuery();
	}
		break; 
	case 66: if (utilisateur->role == "Admin_Saintheque") {
		executeOrder66(utilisateur);
	}
		break;
	case 99:
		break;
	default: cout << "Erreur de choix non reconnu" << endl;
		break;
	}
	if (choix != 99) {
		action(utilisateur);
	}
}

vector <string> lectureFile(string name) {
	fstream fichier(name+".txt");
	vector <string> monTableau;
	if (!fichier)
		cout << name + ".txt : fichier inexistant /!\\";
	else {
		bool continuer = true;
		while (!fichier.eof())
		{
			monTableau.push_back("");//creation d'une ligne vide 
			getline(fichier, monTableau.back());//lecture d'une ligne du fichier 
			int ligne = monTableau.size() - 1;//je recupere la taille du tableau (-1 pour la ligne 0) 
			if (monTableau[ligne].empty())//si la ligne est vide
				monTableau.pop_back();//on la retire du tableau 
		}
		cout << "Nombre de lignes du fichier '"+name+".txt' : " << monTableau.size() << endl;//j'affiche le nombre de lignes pour test 
	}
	return monTableau;
}

void customQuery() {/*
	string query;
	cout << "Quel est votre requete ?" << endl;
	cin >> query;
	mysql_query(connexion, query.c_str());
	//D�claration des objets
	MYSQL_RES *result = NULL;
	MYSQL_ROW row;
	int i = 1;

	//On met le jeu de r�sultat dans le pointeur result
	result = mysql_use_result(connexion);
	if (result) {
		while ((row = mysql_fetch_row(result)))
		{
			printf("Resultat %ld\n", i);
			i++;
		}
	}
	else {
		cout << "La requete a echoue : " << mysql_error(connexion) << endl;
	}
	//Tant qu'il y a encore un r�sultat ...

	//Lib�ration du jeu de r�sultat
	mysql_free_result(result);
}

void executeOrder66(user * utilisateur) {
	MYSQL_ROW row;
	MYSQL_RES *res;

	string debutQuery = "DELETE FROM adherents where mail = \"";
	char * dbtQuery = new char[debutQuery.length() + 1];
	strcpy(dbtQuery, debutQuery.c_str());

	std::string id;
	cin >> id;
	const char * identifiant = id.c_str();
	if (connexion) {
		string query = debutQuery + id + "\"";
		const char* q = query.c_str();
		qstate = mysql_query(connexion, q);
		if (!qstate)
		{
			cout << "Ce sera fait mon Seigneur !" << endl;
		}
		else
		{
			cout << "La requete a echoue : " << mysql_error(connexion) << endl;
		}
	}
	else {
		finish_with_error(connexion);
	}
}

void importFile() {
	string debutQuery = "load data local infile '";
	string nomFichier;
	cout << "Quel est le nom du fichier (incluez bien l'extension)";
	cin >> nomFichier;
	string milieuQuery = "' into table ouvrages fields terminated by '";
	string separateurDeChamps;
	cout << "Quel est le s�parateur de champ ?";
	cin >> separateurDeChamps;
	string finQuery = "lines terminated by '\n' (id_ouvrage, titre, id_genre, id_auteur, date_parution, duree, id_type_media, resume)";
	if (connexion) {
		string query = debutQuery + nomFichier + milieuQuery + separateurDeChamps + finQuery;
		const char* q = query.c_str();
		qstate = mysql_query(connexion, q);
		if (!qstate)
		{
			cout << "Le fichier � bien �t� importe" << endl;
		}
		else
		{
			cout << "La requete a echoue : " << mysql_error(connexion) << endl;
		}
	}
	else {
		finish_with_error(connexion);
	}
}

void seeTheLoans() {
	string debutQuery = "SELECT ouvrage.titre, ouvrage.resume, genre.intitule FROM ouvrage INNER JOIN genre INNER JOIN adherents INNER JOIN emprunts WHERE adherents.mail = '";
	string nomAdherent;
	cout << "De quel adherent voulez vous voir les emprunts ?" << endl;
	cin >> nomAdherent;
	string finQuery = "' AND adherents.id_adherents = emprunts.id_adherent AND emprunts.id_ouvrage = ouvrage.id_ouvrage AND ouvrage.id_genre = genre.id_genre;";
	string intermedQuery = debutQuery + nomAdherent + finQuery;
	colonne table[3];
	table[0].nom = "TITRE";
	table[0].numColone = 1;
	table[1].nom = "DESCRIPTION";
	table[1].numColone = 2;
	table[2].nom = "GENRE";
	table[2].numColone = 3;
	mysqlQuery(intermedQuery.c_str(), table, 3);
}

void empruntOuvrage(user * utilisateur) {
	string query = "SELECT score FROM adherents WHERE mail ='" + utilisateur->id + "';";
	const char * q = query.c_str();
	MYSQL_ROW row = mysqlQuery(q, NULL, 0 );
	int userScore = (int) row[0];
	if (userScore != 0) {
		string query2 = "SELECT nbr_ouvrages_max FROM adherents WHERE mail ='" + utilisateur->id + "';";
		const char * q2 = query.c_str();
		MYSQL_ROW row = mysqlQuery(q2, NULL, 0);
		int userMaxOuvrage = (int)row[0];
		if (userMaxOuvrage != 0) {

		}
		else {
			cout << "Vous avez déjà trop d'emprunts en cours" << endl;
		}
	}
	else {
		cout << "Votre score est trop mauvais, vous en respectez pas la ligne du parti" << endl;
	}
}