// SudokuSolveur.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "FctAnnexes.h"

using namespace std; 

grilleSudoku grille;

int main()
{

    grille = lecture_grille("grille2.txt");
	afficher_grille(grille);
    cout << endl; cout << endl;
    solveur(grille, 0, 0);
    afficher_grille(grille);
    return 0;
}
