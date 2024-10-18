#include <xamgraph.h>
#include "point.h"

// Assurez-vous que vous avez une référence à l'instance de XamGraph
extern XamGraph graph;  // Déclaration de l'instance de XamGraph

void dessinerPoint(int lignes, int colonnes, int tailleCellule) {
    int x = colonnes * tailleCellule / 2;  
    int y = lignes * tailleCellule / 2;    
    int rayon = tailleCellule / 4;         

    graph.setColor(XAM_PINK);
    graph.filledCircle(x, y, rayon);
    graph.updateScreen();
}