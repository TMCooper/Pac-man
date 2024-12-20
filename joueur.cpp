#include <xamgraph.h>
#include <SDL2/SDL.h>
#include "joueur.h"
#include "config.h"

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

// Constructeur de la classe Joueur
Joueur::Joueur(int posX, int posY, int tailleJoueur, int deplacementJoueur)
    : x(posX), y(posY), taille(tailleJoueur), direction('R'), deplacement(deplacementJoueur), oldX(posX), oldY(posY) {}

// Méthode pour dessiner le joueur
void Joueur::dessiner() {
    // Redessiner l'ancienne position du joueur avec la couleur du fond
    graph.setColor(XAM_BLUE);
    graph.filledCircle(oldX, oldY, taille / 2);

    // Dessiner le joueur à sa nouvelle position
    graph.setColor(XAM_YELLOW);
    graph.filledCircle(x, y, taille / 2);

    // Mettre à jour l'ancienne position
    oldX = x;
    oldY = y;
}

// Méthode pour mettre à jour la position du joueur
void Joueur::updatePosition() {
    switch (direction) {
        case 'U':
            if (y - deplacement >= 0) {
                y -= deplacement;
            }
            break;
        case 'D':
            if (y + deplacement < HAUTEUR_GRILLE * TAILLE_CELLULE) {
                y += deplacement;
            }
            break;
        case 'L':
            if (x - deplacement >= 0) {
                x -= deplacement;
            }
            break;
        case 'R':
            if (x + deplacement < LARGEUR_GRILLE * TAILLE_CELLULE) {
                x += deplacement;
            }
            break;
    }
}

// Méthode pour changer la valeur de déplacement
void Joueur::setDeplacement(int nouveauDeplacement) {
    deplacement = nouveauDeplacement;
}

// Fonction pour gérer les entrées du clavier
void gererClavier(Joueur& joueur, SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                joueur.direction = 'U';
                break;
            case SDLK_DOWN:
                joueur.direction = 'D';
                break;
            case SDLK_LEFT:
                joueur.direction = 'L';
                break;
            case SDLK_RIGHT:
                joueur.direction = 'R';
                break;
        }
    }
}
