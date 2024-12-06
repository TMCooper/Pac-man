#include "config.h"
#include "joueur.h"
#include <SDL2/SDL.h>
#include <xamgraph.h>
#include "grille.h"

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

Joueur::Joueur(int posX, int posY, int tailleJoueur)
    : x(posX), y(posY), taille(tailleJoueur) {}

void Joueur::dessiner() {
    graph.setColor(XAM_YELLOW);
    graph.filledCircle(x, y, taille/2);
}


// void gererClavier(Joueur& joueur) {
//     SDL_Event event;
//     while (SDL_PollEvent(&event)) {
//         if (event.type == SDL_KEYDOWN) {
//             switch (event.key.keysym.sym) {
//                 case SDLK_UP:    joueur.y -= joueur.taille*2; break;
//                 case SDLK_DOWN:  joueur.y += joueur.taille*2; break;
//                 case SDLK_LEFT:  joueur.x -= joueur.taille*2; break;
//                 case SDLK_RIGHT: joueur.x += joueur.taille*2; break;
//             }
//         }
//     }
// }

void gererClavier(Joueur& joueur) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if (joueur.y - joueur.taille * 2 >= 0) {
                        joueur.y -= joueur.taille * 2;
                    }
                    break;
                case SDLK_DOWN:
                    if (joueur.y + joueur.taille * 2 < HAUTEUR_GRILLE * TAILLE_CELLULE) {
                        joueur.y += joueur.taille * 2;
                    }
                    break;
                case SDLK_LEFT:
                    if (joueur.x - joueur.taille * 2 >= 0) {
                        joueur.x -= joueur.taille * 2;
                    }
                    break;
                case SDLK_RIGHT:
                    if (joueur.x + joueur.taille * 2 < LARGEUR_GRILLE * TAILLE_CELLULE) {
                        joueur.x += joueur.taille * 2;
                    }
                    break;
            }
        }
    }
}
