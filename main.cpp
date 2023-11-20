#include "Partie.h"
#include <iostream>
#include <cstdlib>

int main()
{
    // Initialisation de la partie avec une taille de plateau, on demande à l'utilisateur de saisir la taille
    std::cout << "Entrez la taille du plateau : ";
    int taille;
    std::cin >> taille;

    Partie partie(taille);

    char choix;
    do
    {
        // On efface la console
        system("cls");
        // Affiche l'état actuel de la partie
        partie.afficher();

        // Demande à l'utilisateur de saisir une direction
        std::cout << "Entrez la direction (d: droite, g: gauche, h: haut, b: bas, q: quitter) : ";
        std::cin >> choix;

        // Gestion de la saisie de l'utilisateur
        switch (choix)
        {
        case 'd':
            partie.mouvement(Direction::Droite);
            break;
        case 'g':
            partie.mouvement(Direction::Gauche);
            break;
        case 'h':
            partie.mouvement(Direction::Haut);
            break;
        case 'b':
            partie.mouvement(Direction::Bas);
            break;
        case 'q':
            std::cout << "Fin du jeu. Merci d'avoir joué !" << std::endl;
            return 0;
        default:
            std::cout << "Saisie invalide. Veuillez réessayer." << std::endl;
            break;
        }

        // Vérifie si la partie est perdue
        if (partie.aPerdu())
        {
            std::cout << "Partie terminée. Vous avez perdu." << std::endl;
            return 0;
        }

    } while (choix != 'q');

    return 0;
}
