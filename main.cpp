#include "Partie.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

#ifdef _WIN32
    #define CLEAR_CONSOLE "cls"
#else
    #define CLEAR_CONSOLE "clear"
#endif

const int ARROW_UP = 72;
const int ARROW_DOWN = 80;
const int ARROW_LEFT = 75;
const int ARROW_RIGHT = 77;

int main()
{
    // Initialisation de la partie avec une taille de plateau, on demande à l'utilisateur de saisir la taille
    system(CLEAR_CONSOLE);
    std::cout << "Entrez la taille du plateau : ";
    int taille;
    std::cin >> taille;

    Partie partie(taille);

    char choix;

    // Tableau constant des valeurs des touches des flèches directionnelles
    const int arrowKeys[] = {ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT};

    do
    {
        // Affiche l'état actuel de la partie
        partie.afficher();

        // Demande à l'utilisateur de saisir une direction
        std::cout << "Entrez la direction (utilisez les touches des fleches, q: quitter) : ";

        // Utilisation de _getch() pour obtenir la touche sans nécessiter d'appuyer sur Enter
        choix = _getch();

        // Si la touche est '3', quitte le programme
        if (choix == 3)
        {
            std::cout << "Fin du programme." << std::endl;
            return 0;
        }

        // On efface la console
        //system(CLEAR_CONSOLE);

        // Gestion de la saisie de l'utilisateur
        switch (choix)
        {
        case ARROW_RIGHT:
            partie.mouvement(Direction::Droite);
            break;
        case ARROW_LEFT:
            partie.mouvement(Direction::Gauche);
            break;
        case ARROW_UP:
            partie.mouvement(Direction::Haut);
            break;
        case ARROW_DOWN:
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
