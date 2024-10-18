#include "joueur.h"
#include <SDL2/SDL.h>
#include <xamgraph.h>
#include "grille.h" // Assure-toi que ce fichier contient les définitions

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

Joueur::Joueur(int posX, int posY, int tailleJoueur)
    : x(posX), y(posY), taille(tailleJoueur) {}

void Joueur::dessiner() {
    graph.setColor(XAM_YELLOW);
    graph.filledCircle(x, y, taille);
}

void Joueur::deplacer(char direction) {
    int nouvelleX = x;
    int nouvelleY = y;

    // Déplacer uniquement si une direction est définie
    switch (direction) {
        case 'U': nouvelleY -= taille; break;
        case 'D': nouvelleY += taille; break;
        case 'L': nouvelleX -= taille; break;
        case 'R': nouvelleX += taille; break;
    }

    // Vérifier si le nouveau déplacement est à l'intérieur des limites
    if (nouvelleX >= 0 && nouvelleX < LARGEUR_GRILLE * taille &&
        nouvelleY >= 0 && nouvelleY < HAUTEUR_GRILLE * taille) {
        x = nouvelleX;
        y = nouvelleY;
    }
}



void gererClavier(Joueur& joueur) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:    joueur.y -= joueur.taille; break;
                case SDLK_DOWN:  joueur.y += joueur.taille; break;
                case SDLK_LEFT:  joueur.x -= joueur.taille; break;
                case SDLK_RIGHT: joueur.x += joueur.taille; break;
            }
        }
    }
}