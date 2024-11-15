#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
public:
    int x, y;          // Position du joueur
    int taille;        // Taille du joueur
    int dx, dy;        // Changement de position (delta)
    char direction;    // Direction ('U' pour haut, 'D' pour bas, 'L' pour gauche, 'R' pour droite)

    // Constructeur
    Joueur(int posX, int posY, int tailleJoueur);

    // Méthode pour déplacer le joueur
    void deplacer();

    // Méthode pour dessiner le joueur
    void dessiner();
};

// Déclaration de la fonction pour gérer le clavier
void gererClavier(Joueur& joueur);

#endif

