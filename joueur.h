#ifndef JOUEUR_H
#define JOUEUR_H

#include <SDL2/SDL.h>

// Classe représentant le joueur
class Joueur {
public:
    int x, y;  // Position du joueur
    int taille;  // Taille du joueur
    char direction;  // Direction ('U' pour haut, 'D' pour bas, 'L' pour gauche, 'R' pour droite)
    int deplacement;  // Valeur de déplacement
    int oldX, oldY;  // Ancienne position du joueur

    // Constructeur
    Joueur(int posX, int posY, int tailleJoueur, int deplacementJoueur);

    // Méthode pour dessiner le joueur
    void dessiner();

    // Méthode pour mettre à jour la position du joueur
    void updatePosition();

    // Méthode pour changer la valeur de déplacement
    void setDeplacement(int nouveauDeplacement);
};

// Fonction pour gérer les entrées du clavier
void gererClavier(Joueur& joueur, SDL_Event& event);

#endif
