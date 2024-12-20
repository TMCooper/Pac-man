#include <xamgraph.h>
#include <SDL2/SDL.h>
#include "joueur.h"
#include "config.h"

// Déclaration de la référence de l'instance de XamGraph
extern XamGraph graph;

// Constructeur de la classe Joueur
Joueur::Joueur(int posX, int posY, int tailleJoueur)
    : x(posX), y(posY), taille(tailleJoueur) {}

// Méthode pour dessiner le joueur
void Joueur::dessiner() {
    // Définir la couleur du joueur (jaune ici)
    graph.setColor(XAM_YELLOW);
    // Dessiner un cercle rempli à la position du joueur
    graph.filledCircle(x, y, taille / 2);
}

// Fonction pour gérer les entrées du clavier
void gererClavier(Joueur& joueur, SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:
                // Déplacer le joueur vers le haut si la position est valide
                if (joueur.y - joueur.taille * 2 >= 0) {
                    joueur.y -= joueur.taille * 2;
                }
                break;
            case SDLK_DOWN:
                // Déplacer le joueur vers le bas si la position est valide
                if (joueur.y + joueur.taille * 2 < HAUTEUR_GRILLE * TAILLE_CELLULE) {
                    joueur.y += joueur.taille * 2;
                }
                break;
            case SDLK_LEFT:
                // Déplacer le joueur vers la gauche si la position est valide
                if (joueur.x - joueur.taille * 2 >= 0) {
                    joueur.x -= joueur.taille * 2;
                }
                break;
            case SDLK_RIGHT:
                // Déplacer le joueur vers la droite si la position est valide
                if (joueur.x + joueur.taille * 2 < LARGEUR_GRILLE * TAILLE_CELLULE) {
                    joueur.x += joueur.taille * 2;
                }
                break;
        }
    }
}
