#include <xamgraph.h>
#include "grille.h"

// Assurez-vous que vous avez une référence à l'instance de XamGraph
extern XamGraph graph;  // Déclaration de l'instance de XamGraph

void dessinerGrille(int lignes, int colonnes, int tailleCellule) {
    // Couleur de fond
    graph.setColor(XAM_BLUE);
    graph.filledRectangle(0, 0, colonnes * tailleCellule, lignes * tailleCellule);

    // Dessiner la grille
    graph.setColor(XAM_WHITE);
    for (int i = 0; i <= lignes; i++) {
        graph.line(0, i * tailleCellule, colonnes * tailleCellule, i * tailleCellule);  // Lignes horizontales
    }
    for (int j = 0; j <= colonnes; j++) {
        graph.line(j * tailleCellule, 0, j * tailleCellule, lignes * tailleCellule);  // Lignes verticales
    }
    
    // Actualiser l'affichage
    graph.updateScreen();
}