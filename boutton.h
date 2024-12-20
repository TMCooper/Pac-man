#ifndef BOUTTON_H
#define BOUTTON_H

#include <SDL2/SDL.h>

// Déclaration de la fonction de dessin du bouton
void draw_exit_boutton();

// Déclaration de la fonction de gestion des clics de souris
void handle_mouse_click(SDL_Event& event);

// Déclaration des constantes pour la taille du bouton
extern const int TAILLE_HAUTEUR;
extern const int TAILLE_LARGEUR;

#endif // BOUTTON_H
