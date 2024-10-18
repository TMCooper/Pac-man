#include "point.h"
#include "joueur.h" // Inclure le fichier d'en-tête pour accéder à la définition de Joueur
#include <xamgraph.h>

extern XamGraph graph; // Assurez-vous que cela est correct

bool points[HAUTEUR_GRILLE][LARGEUR_GRILLE];
int pointStates[HAUTEUR_GRILLE][LARGEUR_GRILLE]; // 0: disparu, 1: visible

void initPoints() {
    // Initialisation des points
    for (int i = 0; i < HAUTEUR_GRILLE; i++) {
        for (int j = 0; j < LARGEUR_GRILLE; j++) {
            points[i][j] = true; // Ou une autre logique d'initialisation
            pointStates[i][j] = 1; // 1: visible
        }
    }
}

void dessinerPoint(int largeur, int hauteur, int tailleCellule) {
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (pointStates[y][x] == 1) {
                graph.setColor(XAM_PINK); // Couleur des points
                graph.filledCircle(x * tailleCellule + tailleCellule / 2,
                                   y * tailleCellule + tailleCellule / 2,
                                   tailleCellule / 4); // Dessiner le point
            } else if (pointStates[y][x] == 0) {
                graph.setColor(XAM_BLUE); // Couleur des points disparus
                graph.filledCircle(x * tailleCellule + tailleCellule / 2,
                                   y * tailleCellule + tailleCellule / 2,
                                   tailleCellule / 4); // Dessiner le point comme disparu
            }
        }
    }
}

void verifierCollision(Joueur& joueur) {
    int caseX = joueur.x / (joueur.taille * 2); // Ajuster selon la taille du joueur
    int caseY = joueur.y / (joueur.taille * 2); // Ajuster selon la taille du joueur

    // Vérifier si le joueur touche un point
    if (caseX >= 0 && caseX < LARGEUR_GRILLE && caseY >= 0 && caseY < HAUTEUR_GRILLE) {
        if (pointStates[caseY][caseX] == 1) {
            pointStates[caseY][caseX] = 0; // Changer l'état du point à 0 (disparu)
        }
    }
}
