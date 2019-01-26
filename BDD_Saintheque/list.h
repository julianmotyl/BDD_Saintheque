#include <string>
#include <fstream> 
#include <vector> 

//TD des Listes

typedef struct maillon {

	char  valeur;
	maillon * suivant;

} maillon;

typedef maillon *list;


int factorielle(int n);
int ** matrixInt(const int ROW, const int COL, const int MIN, const int MAX);
void disMatrixInt(int ** pt);
list initList();
bool estVide(list l);
void afficher(list l);
list insert(list l, int val);
list supprime_rec(int val, list l);