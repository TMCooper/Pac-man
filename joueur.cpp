#include "joueur.h"
#include <SDL2/SDL.h>
#include <xamgraph.h>

// Assurez-vous que vous avez une référence à l'instance de XamGraph
extern XamGraph graph;

Joueur::Joueur(int px, int py, int pTaille) 
    : x(px), y(py), taille(pTaille), dx(0), dy(0), direction('U') {}

void Joueur::dessiner() {
    graph.setColor(XAM_YELLOW);
    graph.filledCircle(x, y, taille);
}

void Joueur::deplacer() {
    // Mettre à jour la position en fonction de la direction
    x += dx * taille;
    y += dy * taille;

    // Gérer les bordures du jeu
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > 800 - taille) x = 800 - taille;
    if (y > 600 - taille) y = 600 - taille;
}

void gererClavier(Joueur& joueur) {
    SDL_Event event;

    // Vérifie si un événement clavier a été capturé
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    joueur.direction = 'U';
                    joueur.dy = -1; // Déplacer vers le haut
                    joueur.dx = 0;  // Pas de déplacement horizontal
                    break;
                case SDLK_DOWN:
                    joueur.direction = 'D';
                    joueur.dy = 1;  // Déplacer vers le bas
                    joueur.dx = 0;  // Pas de déplacement horizontal
                    break;
                case SDLK_LEFT:
                    joueur.direction = 'L';
                    joueur.dx = -1; // Déplacer vers la gauche
                    joueur.dy = 0;  // Pas de déplacement vertical
                    break;
                case SDLK_RIGHT:
                    joueur.direction = 'R';
                    joueur.dx = 1;  // Déplacer vers la droite
                    joueur.dy = 0;  // Pas de déplacement vertical
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            // Arrêter le déplacement quand la touche est relâchée
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                case SDLK_DOWN:
                    joueur.dy = 0; // Arrêter le mouvement vertical
                    break;
                case SDLK_LEFT:
                case SDLK_RIGHT:
                    joueur.dx = 0; // Arrêter le mouvement horizontal
                    break;
            }
        }
    }
}