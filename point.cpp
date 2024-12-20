#include "point.h"
#include "joueur.h"
#include <xamgraph.h>
#include "grille.h"
#include "global.h"

// Déclaration des points
bool points[HAUTEUR_GRILLE][LARGEUR_GRILLE];
int pointStates[HAUTEUR_GRILLE][LARGEUR_GRILLE];

// Fonction pour initialiser les points
void initPoints() {
    for (int i = 0; i < HAUTEUR_GRILLE; i++) {
        for (int j = 0; j < LARGEUR_GRILLE; j++) {
            points[i][j] = true;
            pointStates[i][j] = 1; // 1: visible
        }
    }
}

// Fonction pour dessiner les points
void dessinerPoint(int largeur, int hauteur, int tailleCellule) {
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (pointStates[y][x] == 1) {
                graph.setColor(XAM_PINK); // Couleur des points
                graph.filledCircle(x * tailleCellule + tailleCellule / 2,
                                   y * tailleCellule + tailleCellule / 2,
                                   tailleCellule / 4); // Dessiner le point
            }
        }
    }
}

// Fonction pour vérifier les collisions avec les points
void verifierCollision(Joueur& joueur, int tailleCellule) {
    int caseX = joueur.x / tailleCellule;
    int caseY = joueur.y / tailleCellule;

    if (caseX >= 0 && caseX < LARGEUR_GRILLE && caseY >= 0 && caseY < HAUTEUR_GRILLE) {
        if (pointStates[caseY][caseX] == 1) {
            pointStates[caseY][caseX] = 0; // Changer l'état du point à 0 (disparu)
            // Redessiner uniquement le point touché
            graph.setColor(XAM_BLUE); // Couleur du plateau de jeu
            graph.filledCircle(caseX * tailleCellule + tailleCellule / 2,
                               caseY * tailleCellule + tailleCellule / 2,
                               tailleCellule / 4); // Dessiner le point comme disparu
        }
    }
}
