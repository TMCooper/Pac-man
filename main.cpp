#include <xamgraph.h>
#include <SDL2/SDL.h>
#include "grille.h"
#include "point.h"
#include "joueur.h"
#include "config.h"
#include "carte.h"
#include "boutton.h"

// Déclaration de la référence de l'instance de XamGraph
XamGraph graph(755, 650, "Pac-Man");

int main() {
    // Initialiser les points
    initPoints();

    // Créer un joueur
    Joueur joueur(TAILLE_CELLULE / 2, TAILLE_CELLULE / 2, TAILLE_CELLULE / 2);

    // Dessiner la grille
    dessinerGrille(HAUTEUR_GRILLE, LARGEUR_GRILLE, TAILLE_CELLULE);

    // Initialiser la carte
    initCarte();

    // Dessiner le bouton "Exit"
    draw_exit_boutton();

    // Variable pour contrôler la boucle principale
    bool running = true;

    // Boucle principale du jeu
    while (running) {
        SDL_Event event;

        // Gérer les événements SDL
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;  // Quitter la boucle principale si l'événement est SDL_QUIT
            }
            handle_mouse_click(event);  // Gérer les clics de souris
            gererClavier(joueur, event);  // Gérer les entrées du clavier
        }

        // Vérifier les collisions
        verifierCollision(joueur);

        // Dessiner les points
        dessinerPoint(LARGEUR_GRILLE, HAUTEUR_GRILLE, TAILLE_CELLULE);

        // Dessiner le joueur
        joueur.dessiner();

        // Mettre à jour l'écran
        graph.updateScreen();
    }

    return 0;
}
