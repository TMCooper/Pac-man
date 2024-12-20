#ifndef CARTE_H
#define CARTE_H

#include "config.h"

// Déclaration de la carte de jeu
extern int carte[HAUTEUR_GRILLE][LARGEUR_GRILLE];

// Fonction pour initialiser la carte
void initCarte();

// Fonction pour dessiner la carte
void dessinerCarte(int tailleCellule);

#endif // CARTE_H
