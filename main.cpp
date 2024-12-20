#include <xamgraph.h>
#include <SDL2/SDL.h>
#include "grille.h"
#include "point.h"
#include "joueur.h"
#include "config.h"
#include "carte.h"
#include "boutton.h"
#include "global.h"
#include <chrono>
#include <thread>

// Déclaration de la référence de l'instance de XamGraph
XamGraph graph(755, 650, "Pac-Man");

int main() {
    // Initialiser les points
    initPoints();

    // Créer un joueur avec une valeur de déplacement initiale
    Joueur joueur(TAILLE_CELLULE / 2, TAILLE_CELLULE / 2, TAILLE_CELLULE / 2, TAILLE_CELLULE);

    // Initialiser la carte
    initCarte();

    // Redessiner la grille pour éviter les traces
    dessinerGrille(HAUTEUR_GRILLE, LARGEUR_GRILLE, TAILLE_CELLULE);

    // Dessiner les points
    dessinerPoint(LARGEUR_GRILLE, HAUTEUR_GRILLE, TAILLE_CELLULE);

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

        // Mettre à jour la position du joueur
        joueur.updatePosition();

        // Vérifier les collisions
        verifierCollision(joueur, TAILLE_CELLULE);

        // Dessiner le joueur
        joueur.dessiner();

        // Mettre à jour l'écran
        graph.updateScreen();

        // Ajouter un délai pour ralentir le mouvement
        std::this_thread::sleep_for(std::chrono::milliseconds(175));
    }

    return 0;
}
