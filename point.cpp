#include "point.h"
#include "joueur.h"
#include <xamgraph.h>
#include "grille.h"

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

// Déclaration des points
bool points[HAUTEUR_GRILLE][LARGEUR_GRILLE];
int pointStates[HAUTEUR_GRILLE][LARGEUR_GRILLE];

// Fonction pour initialiser les points
void initPoints() {
    for (int i = 0; i < HAUTEUR_GRILLE; i++) {
        for (int j = 0; j < LARGEUR_GRILLE; j++) {
            points[i][j] = true;
            pointStates[i][j] = 1;
        }
    }
}

// Fonction pour dessiner les points
void dessinerPoint(int largeur, int hauteur, int tailleCellule) {
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            if (pointStates[y][x] == 1) {
                graph.setColor(XAM_PINK);
                graph.filledCircle(x * tailleCellule + tailleCellule / 2,
                                   y * tailleCellule + tailleCellule / 2,
                                   tailleCellule / 4);
            } else if (pointStates[y][x] == 0) {
                graph.setColor(XAM_BLUE);
                graph.filledCircle(x * tailleCellule + tailleCellule / 2,
                                   y * tailleCellule + tailleCellule / 2,
                                   tailleCellule / 4);
            }
        }
    }
}

// Fonction pour vérifier les collisions avec les points
void verifierCollision(Joueur& joueur) {
    int caseX = joueur.x / (joueur.taille * 2);
    int caseY = joueur.y / (joueur.taille * 2);

    if (caseX >= 0 && caseX < LARGEUR_GRILLE && caseY >= 0 && caseY < HAUTEUR_GRILLE) {
        if (pointStates[caseY][caseX] == 1) {
            pointStates[caseY][caseX] = 0;
        }
    }
}
