#ifndef CARTE_H
#define CARTE_H

#include "config.h"

extern int carte[HAUTEUR_GRILLE][LARGEUR_GRILLE];

void initCarte();
void dessinerCarte(int tailleCellule);

#endif // CARTE_H
