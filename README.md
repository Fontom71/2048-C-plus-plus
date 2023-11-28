# 2048 en C++

Ce dépôt contient une implémentation du jeu 2048 en C++, développée dans le cadre des études à l'ESIREM.

## Structure du Projet

Le projet est organisé comme suit :

- **CMakeLists.txt**: Fichier de configuration CMake pour la construction du projet.
- **Direction.h**: Fichier contenant l'énumération des directions utilisées dans le jeu.
- **Makefile**: Fichier Makefile pour la compilation du projet.
- **Partie.cpp et Partie.h**: Implémentation de la classe `Partie`, qui gère le déroulement du jeu.
- **Plateau.cpp et Plateau.h**: Implémentation de la classe `Plateau`, qui représente le plateau de jeu.
- **main.cpp**: Fichier principal contenant la fonction `main` et l'initialisation du jeu.

## Compilation et Exécution

Pour compiler le projet, vous pouvez utiliser le fichier Makefile en exécutant la commande suivante dans le terminal :

```bash
make
```

Une fois compilé, lancez le jeu avec la commande :

```bash
./2048
```

## Instructions de Jeu

- Utilisez les touches directionnelles (haut, bas, gauche, droite) pour déplacer les tuiles sur le plateau.
- L'objectif est de fusionner les tuiles de même valeur pour atteindre la valeur 2048 sur une tuile.

## Dépendances

Le projet ne nécessite aucune dépendance externe autre que le compilateur C++ et Make.

## Auteur

Ce projet a été développé par @Fontom71 dans le cadre des études à l'ESIREM.

## Licence

Aucune ! C'est cadeau pour voir comment j'ai fait ce petit exercice d'entrainement.
