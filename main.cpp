#include <xamgraph.h>
#include "grille.h"
#include "point.h"
#include "joueur.h"

// Déclaration de l'instance de la classe XamGraph
XamGraph graph(800, 600, "Pac-Man");

int main() {
    int lignes = 20;
    int colonnes = 25;
    int tailleCellule = 30;

    // Création d'un joueur au centre de la grille
    Joueur joueur(tailleCellule / 2, tailleCellule / 2, tailleCellule / 4);

    while (true) {
        // Gérer les entrées du clavier
        gererClavier(joueur);  // Utilise l'instance joueur

        // Dessiner la grille et les points
        dessinerGrille(lignes, colonnes, tailleCellule);
        dessinerPoint(lignes, colonnes, tailleCellule);

        // Déplacer et dessiner le joueur
        joueur.deplacer();    // Utilise l'instance joueur
        joueur.dessiner();    // Utilise l'instance joueur

        // Actualiser l'affichage
        graph.updateScreen();
    }

    return 0;
}