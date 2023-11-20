// Partie.cpp
#include "Partie.h"
#include <iostream>

Partie::Partie(int taillePlateau) : plateau(taillePlateau), score(0), cptMouv(0) {}

Partie::~Partie() {}

void Partie::afficher()
{
    // Affiche l'état actuel de la partie
    std::cout << "Score : " << score << "\tMouvements : " << cptMouv << std::endl
              << std::endl;
    plateau.afficher();
    std::cout << std::endl;
}

bool Partie::aPerdu()
{
    // Vérifie si la partie est perdue

    // Si au moins une direction a des déplacements possibles, la partie n'est pas perdue
    if (plateau.estDeplacable())
    {
        return false;
    }

    return true;
}

void Partie::mouvement(Direction direction)
{
    // Applique le mouvement sur le plateau
    plateau.mouvement(direction);
    // Ajoutez ici des mécanismes pour mettre à jour le score si nécessaire
    // (par exemple, en fonction des cases fusionnées ou des nouvelles cases ajoutées)
    score += plateau.getScore();
    // Vous pouvez également ajouter d'autres mécanismes spécifiques à votre jeu.
    cptMouv++;
    // À compléter en fonction de votre logique de score.
}
