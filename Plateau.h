// Plateau.h
#pragma once
#include "Direction.h"

class Plateau
{
public:
    Plateau(int taille);
    ~Plateau();

    void mouvement(Direction direction);
    bool estFusionnable(int i, int j, Direction direction);
    bool estDeplacable();
    void afficher();
    void nouvelleCase();
    int getScore();

private:
    int taille;
    int **plateau;
    int score;

    void deplacerCases(Direction direction);
    void fusionnerCases(Direction direction);
    bool estCaseVide(int i, int j);
};
