// Plateau.cpp
#include "Plateau.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Plateau::Plateau(int taille)
{
    this->taille = taille;
    score = 0;

    // Allocation de mémoire pour le plateau
    plateau = new int *[taille];
    for (int i = 0; i < taille; ++i)
    {
        plateau[i] = new int[taille];
    }

    // Initialisation du plateau à zéro
    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille; ++j)
        {
            plateau[i][j] = 0;
        }
    }

    // Ajout de deux nouvelles cases au début du jeu
    nouvelleCase();
    nouvelleCase();
}

Plateau::~Plateau()
{
    // Libération de la mémoire allouée pour le plateau
    for (int i = 0; i < taille; ++i)
    {
        delete[] plateau[i];
    }
    delete[] plateau;
}

void Plateau::mouvement(Direction direction)
{
    deplacerCases(direction);
    fusionnerCases(direction);
    deplacerCases(direction);
    nouvelleCase();
}

bool Plateau::estFusionnable(int i, int j, Direction direction)
{
    // Vérifie si une case peut fusionner avec sa voisine en fonction de la direction

    switch (direction)
    {
    case Direction::Droite:
        // Vérifie si la case peut fusionner avec sa voisine à droite
        return (j + 1 < taille) && (plateau[i][j] == plateau[i][j + 1]);
    case Direction::Gauche:
        // Vérifie si la case peut fusionner avec sa voisine à gauche
        return (j - 1 >= 0) && (plateau[i][j] == plateau[i][j - 1]);
    case Direction::Haut:
        // Vérifie si la case peut fusionner avec sa voisine en haut
        return (i - 1 >= 0) && (plateau[i][j] == plateau[i - 1][j]);
    case Direction::Bas:
        // Vérifie si la case peut fusionner avec sa voisine en bas
        return (i + 1 < taille) && (plateau[i][j] == plateau[i + 1][j]);
    }

    // Retourne false par défaut (ne devrait pas atteindre cette ligne normalement)
    return false;
}

bool Plateau::estDeplacable()
{
    // Vérifie si au moins une case peut être déplacée

    // Parcourez le plateau et vérifiez si au moins une case peut être déplacée dans n'importe quelle direction.
    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille; ++j)
        {
            if (estCaseVide(i, j))
            {
                return true; // S'il y a au moins une case vide, un déplacement est possible
            }

            // Vérifiez si la case peut être fusionnée avec une case adjacente dans n'importe quelle direction
            if (j + 1 < taille && plateau[i][j] == plateau[i][j + 1])
            {
                return true;
            }

            if (i + 1 < taille && plateau[i][j] == plateau[i + 1][j])
            {
                return true;
            }
        }
    }

    return false; // Aucun déplacement possible
}

void Plateau::afficher()
{
    for (int i = 0; i < taille; ++i)
    {
        std::cout << "+---";
    }
    std::cout << "+" << std::endl;

    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille; ++j)
        {
            std::cout << "| " << plateau[i][j] << " ";
        }
        std::cout << "|" << std::endl;

        for (int j = 0; j < taille; ++j)
        {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
}

void Plateau::nouvelleCase()
{
    // Ajoute une nouvelle case aléatoirement sur le plateau
    // La valeur de la case est 2 ou 4 (avec une probabilité de 90% pour 2 et 10% pour 4)

    // Initialisation du générateur de nombres aléatoires avec le temps actuel
    std::srand(std::time(0));

    // Choix aléatoire de la valeur (90% pour 2, 10% pour 4)
    int nouvelleValeur = (rand() % 10 == 0) ? 4 : 2;

    // Sélection aléatoire d'une position vide pour la nouvelle case
    int i, j;
    do
    {
        i = rand() % taille;
        j = rand() % taille;
    } while (!estCaseVide(i, j));

    // Attribution de la nouvelle valeur à la case
    plateau[i][j] = nouvelleValeur;
}

void Plateau::deplacerCases(Direction direction)
{
    // Déplace toutes les cases vers la direction spécifiée

    // Parcourez le plateau en fonction de la direction spécifiée
    // et déplacez les cases vers la direction souhaitée.

    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille; ++j)
        {
            if (!estCaseVide(i, j))
            {
                int nouvelleI = i;
                int nouvelleJ = j;

                // Déterminez les nouvelles coordonnées en fonction de la direction si la case peut être fusionnée avec une case adjacente
                switch (direction)
                {
                case Direction::Droite:
                    while (nouvelleJ + 1 < taille && plateau[nouvelleI][nouvelleJ + 1] == 0)
                    {
                        ++nouvelleJ;
                    }
                    break;
                case Direction::Gauche:
                    while (nouvelleJ - 1 >= 0 && plateau[nouvelleI][nouvelleJ - 1] == 0)
                    {
                        --nouvelleJ;
                    }
                    break;
                case Direction::Haut:
                    while (nouvelleI - 1 >= 0 && plateau[nouvelleI - 1][nouvelleJ] == 0)
                    {
                        --nouvelleI;
                    }
                    break;
                case Direction::Bas:
                    while (nouvelleI + 1 < taille && plateau[nouvelleI + 1][nouvelleJ] == 0)
                    {
                        ++nouvelleI;
                    }
                    break;
                }

                // Déplacez la case uniquement si ses coordonnées ont changé
                if (nouvelleI != i || nouvelleJ != j)
                {
                    plateau[nouvelleI][nouvelleJ] = plateau[i][j];
                    plateau[i][j] = 0;
                }

                // Ajoutez ici des mécanismes pour mettre à jour le score si nécessaire
                // (par exemple, en fonction de la valeur déplacée)

                // Avancez le pointeur j pour éviter de déplacer plusieurs fois la même case
                j = nouvelleJ;

                // Avancez le pointeur i pour éviter de déplacer plusieurs fois la même case
                i = nouvelleI;

                // Si la case a été déplacée, il est inutile de vérifier si elle peut fusionner avec une case adjacente
                break;
            }
        }
    }
}

void Plateau::fusionnerCases(Direction direction)
{
    // Fusionne les cases adjacentes dans la direction spécifiée

    // Parcourez le plateau et fusionnez les cases adjacentes en fonction de la direction.
    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille - 1; ++j)
        {
            int valeurCourante = plateau[i][j];

            if (valeurCourante != 0)
            {
                int k = j + 1;
                while (k < taille && plateau[i][k] == 0)
                {
                    ++k;
                }

                if (k < taille && estFusionnable(i, j, direction))
                {
                    // Fusionne les cases adjacentes
                    plateau[i][j] = 2 * valeurCourante;
                    plateau[i][k] = 0;

                    // Ajoutez ici des mécanismes pour mettre à jour le score si nécessaire
                    // (par exemple, en fonction de la valeur fusionnée)
                    score += 2 * valeurCourante;

                    // Avancez le pointeur j pour éviter de fusionner plusieurs fois la même paire
                    j = k;
                }
            }
        }
    }
}

bool Plateau::estCaseVide(int i, int j)
{
    // Vérifie si la case à la position (i, j) est vide
    return plateau[i][j] == 0;
}

int Plateau::getScore()
{
    return score;
}