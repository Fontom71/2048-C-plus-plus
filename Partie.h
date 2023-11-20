// Partie.h
#pragma once
#include "Plateau.h"

class Partie
{
public:
    Partie(int taillePlateau);
    ~Partie();

    void afficher();
    bool aPerdu();
    void mouvement(Direction direction);

private:
    Plateau plateau;
    int score;
    int cptMouv;
};
