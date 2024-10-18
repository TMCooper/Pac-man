#include <xamgraph.h>
#include <SDL2/SDL.h>
#include "grille.h"
#include "point.h"
#include "joueur.h"
#include "config.h"

// Déclaration de la référence de l'instance de XamGraph
XamGraph graph(800, 600, "Pac-Man");

int main() {
    const int LARGEUR_GRILLE = 25;
    const int HAUTEUR_GRILLE = 20;
    const int TAILLE_CELLULE = 30;

    const int colonnes = 20;
    const int lignes = 25;

    initPoints(); // Initialise les points

    Joueur joueur(TAILLE_CELLULE / 2, TAILLE_CELLULE / 2, TAILLE_CELLULE / 2);
    dessinerGrille(HAUTEUR_GRILLE, LARGEUR_GRILLE, TAILLE_CELLULE);


    while (true) {
        // Gérer les entrées du clavier
        gererClavier(joueur);

        // Vérifier les collisions
        verifierCollision(joueur);

        // Dessiner la grille et les points
        dessinerPoint(LARGEUR_GRILLE, HAUTEUR_GRILLE, TAILLE_CELLULE);
        
        // Dessiner le joueur
        joueur.dessiner();

        // Mettre à jour l'écran
        graph.updateScreen();
    }

    return 0;
}