#include "carte.h"
#include <xamgraph.h>

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

// Définir la carte de jeu
int carte[HAUTEUR_GRILLE][LARGEUR_GRILLE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Fonction pour initialiser la carte (si nécessaire)
void initCarte() {
    // Initialisation de la carte (si nécessaire)
}

// Fonction pour dessiner la carte
void dessinerCarte(int tailleCellule) {
    for (int y = 0; y < HAUTEUR_GRILLE; y++) {
        for (int x = 0; x < LARGEUR_GRILLE; x++) {
            if (carte[y][x] == 1) {
                graph.setColor(XAM_BLUE); // Couleur des murs
                graph.filledRectangle(x * tailleCellule, y * tailleCellule, tailleCellule, tailleCellule);
            } else {
                graph.setColor(XAM_BLACK); // Couleur des chemins
                graph.filledRectangle(x * tailleCellule, y * tailleCellule, tailleCellule, tailleCellule);
            }
        }
    }
}
