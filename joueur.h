#ifndef JOUEUR_H
#define JOUEUR_H

#include <SDL2/SDL.h>

// Classe représentant le joueur
class Joueur {
public:
    int x, y;  // Position du joueur
    int taille;  // Taille du joueur
    char direction;  // Direction ('U' pour haut, 'D' pour bas, 'L' pour gauche, 'R' pour droite)

    // Constructeur
    Joueur(int posX, int posY, int tailleJoueur);

    // Méthode pour dessiner le joueur
    void dessiner();
};

// Fonction pour gérer les entrées du clavier
void gererClavier(Joueur& joueur, SDL_Event& event);

#endif
