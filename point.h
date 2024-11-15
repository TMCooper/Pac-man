#ifndef POINT_H
#define POINT_H

#include "config.h"
#include "joueur.h" // Inclure le fichier d'en-tête de Joueur

extern bool points[HAUTEUR_GRILLE][LARGEUR_GRILLE];
extern int pointStates[HAUTEUR_GRILLE][LARGEUR_GRILLE]; // 0: disparu, 1: visible

// Déclaration des fonctions
void initPoints();
void dessinerPoint(int lignes, int colonnes, int tailleCellule);
void verifierCollision(Joueur& joueur);

#endif // POINT_H
