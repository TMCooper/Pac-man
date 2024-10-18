#include <stdio.h>
#include <xamgraph.h>
#include "grille.h"  // Inclusion du fichier grille.h

// Déclaration de l'instance de la classe XamGraph
XamGraph graph(800, 600, "Pac-Man");

int main() {
    // Paramètres de la grille (20x20 cellules, chaque cellule fait 30 pixels)
    int lignes = 20;
    int colonnes = 25;
    int tailleCellule = 30;

    // Dessiner la grille de base
    dessinerGrille(lignes, colonnes, tailleCellule);

    // Lancer la boucle d'événements
    graph.run();  // Appeler la méthode run() sur l'objet graph

    return 0;  // La méthode close() est automatiquement appelée lors de la sortie de main()
}
