#include <xamgraph.h>
#include "grille.h"

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

// Fonction pour dessiner la grille
void dessinerGrille(int lignes, int colonnes, int tailleCellule) {
    // Dessiner le fond de la grille en bleu
    graph.setColor(XAM_BLUE);
    graph.filledRectangle(0, 0, colonnes * tailleCellule, lignes * tailleCellule);

    // Dessiner les lignes de la grille en blanc
    graph.setColor(XAM_WHITE);
    for (int i = 0; i <= lignes; i++) {
        graph.line(0, i * tailleCellule, colonnes * tailleCellule, i * tailleCellule); // Lignes horizontales
    }
    for (int j = 0; j <= colonnes; j++) {
        graph.line(j * tailleCellule, 0, j * tailleCellule, lignes * tailleCellule); // Lignes verticales
    }

    // Mettre à jour l'écran
    graph.updateScreen();
}
