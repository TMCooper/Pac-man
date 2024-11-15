#include <xamgraph.h>
#include "point.h"

// Assurez-vous que vous avez une référence à l'instance de XamGraph
extern XamGraph graph;  // Déclaration de l'instance de XamGraph

void dessinerPoint(int lignes, int colonnes, int tailleCellule) {
    // Parcourir chaque cellule de la grille
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            // Calculer les coordonnées du centre du cercle
            int x = j * tailleCellule + tailleCellule / 2;
            int y = i * tailleCellule + tailleCellule / 2;
            int rayon = tailleCellule / 4;  // Rayon du cercle (ajustable)

            // Dessiner un cercle rempli au centre de la cellule
            graph.setColor(XAM_PINK);       // Couleur du cercle
            graph.filledCircle(x, y, rayon);
        }
    }
    
    // Actualiser l'affichage
    graph.updateScreen();
}