#ifndef POINT_H
#define POINT_H

#include "config.h"
#include "joueur.h"

// Déclaration des points
extern bool points[HAUTEUR_GRILLE][LARGEUR_GRILLE];
extern int pointStates[HAUTEUR_GRILLE][LARGEUR_GRILLE];

// Fonction pour initialiser les points
void initPoints();

// Fonction pour dessiner les points
void dessinerPoint(int lignes, int colonnes, int tailleCellule);

// Fonction pour vérifier les collisions avec les points
void verifierCollision(Joueur& joueur);

#endif
