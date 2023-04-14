#include <iostream>
#include <fstream>
#include <vector>
#include "FctAnnexes.h"

using namespace std;
int iteration;

grilleSudoku lecture_grille(string nomfichier) {
	grilleSudoku sudoku(9, vector<int>(9));
	ifstream fichier(nomfichier);
	if (fichier.fail()) cout << "pb lecture" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int temp;
			fichier >> temp;
			sudoku[i][j] = temp;
		}
	};
	//cout << "Reading done" << endl;
	return sudoku;
}

void afficher_grille(vector<vector<int>>& grille) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grille[i][j] << " ";;
		}
		cout << endl;
	};
}

bool grille_finie(const vector<vector<int>>& grille) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grille[i][j] == 0) return false;
		}
	};

	return true;
}

// La fonction renvoie true si toute le condition sont respecté
bool case_possible(const vector<vector<int>>& grille, int PosX, int PosY, int num) {
	//if (grille[PosX][PosY] == 0) return true;
	if (ligne_possible(grille, PosX, PosY, num) && colonne_possible(grille, PosX, PosY, num) && carre_possible(grille, PosX, PosY, num))
		return true;
	else return false;
}

bool ligne_possible(const  vector<vector<int>>& grille, int PosX, int PosY, int num) {
	for (int col = 0; col < 9; col++) {
			if (grille[col][PosX] ==num) return false;
	};
	return true;
}

bool colonne_possible(const  vector<vector<int>>& grille, int PosX, int PosY, int num) {
	
	for (int row = 0; row < 9; row++) {
		if (grille[PosY][row] == num) return false;
	};
	return true;
}

bool carre_possible(const  vector<vector<int>>& grille, int PosX, int PosY, int num) {
	int sectionRow = 3 * (PosX / 3);
	int sectionCol = 3 * (PosY / 3);
	//cout << "row : " << sectionRow <<  endl;
	//cout << "col : " << sectionCol << endl;

	for (int i = sectionRow; i < sectionRow + 3; i++) {
		for (int j = sectionCol; j < sectionCol + 3; j++) {
			//cout << grille[j][i] << " ";
			if (grille[j][i] == num) {
				return false;
			}
		}
		//cout << endl;
	}
	return true;
}

// Fonction qui va etre appelé sur chaque case
void solveur(std::vector<std::vector<int>>& grille, int PosX, int PosY) {
	cout << "iteration :" << iteration << endl;
	iteration++;
	//afficher_grille(grille);
	//cout << endl;
	// Cas de base : la grille est complétée
	if (grille_finie(grille)) {
		return;
	}

	// Vérifier si la case actuelle est déjà remplie
	if (grille[PosY][PosX] != 0) {
		// Passer à la case suivante
		int prochaine_colonne = (PosX + 1) % 9;
		int prochaine_ligne = PosY + (prochaine_colonne == 0 ? 1 : 0);
		solveur(grille, prochaine_colonne, prochaine_ligne);
		return;
	}

	// Essayer de remplir la case actuelle avec tous les chiffres possibles
	for (int num = 1; num <= 9; num++) {
		if (case_possible(grille, PosX, PosY, num)) {
			grille[PosY][PosX] = num;

			// Passer à la case suivante
			int prochaine_colonne = (PosX + 1) % 9;
			int prochaine_ligne = PosY + (prochaine_colonne == 0 ? 1 : 0);
			solveur(grille, prochaine_colonne, prochaine_ligne);

			// Si la grille est complétée, sortir de toutes les boucles
			if (grille_finie(grille)) {
				return;
			}
			// Annuler le chiffre ajouté pour essayer un autre chiffre
			grille[PosY][PosX] = 0;
		}
	}
}