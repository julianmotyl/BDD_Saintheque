#include <iostream>
#include <mysql.h>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream> 
#include <vector> 
#include "list.h"

using namespace std;

//------------------------------------TD Listes----------------------------------------------------------------//
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