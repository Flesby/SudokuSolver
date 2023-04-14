#pragma once
#include <vector>

std::vector<std::vector<int>> lecture_grille(std::string nomfichier);

void afficher_grille(std::vector<std::vector<int>>& grille);
bool grille_finie(const std::vector<std::vector<int>>& grille);

//std::vector<std::vector<int>> solveur(const std::vector<std::vector<int>>& grille, int PosX, int PosY, int num);
// verification si un chiffre peut être mis
bool case_possible(const std::vector<std::vector<int>>& grille, int PosX, int PosY, int num);
bool ligne_possible(const std::vector<std::vector<int>>& grille, int PosX, int PosY, int num);
bool colonne_possible(const std::vector<std::vector<int>>& grille, int PosX, int PosY, int num);
bool carre_possible(const std::vector<std::vector<int>>& grille, int PosX, int PosY, int num);

void solveur(std::vector<std::vector<int>>& grille, int PosX, int PosY);

typedef std::vector<std::vector<int>> grilleSudoku;
