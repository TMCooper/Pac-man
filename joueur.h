#ifndef JOUEUR_H
#define JOUEUR_H

class Joueur {
public:
    int x, y;          // Position du joueur
    int taille;        // Taille du joueur
    char direction;    // Direction ('U' pour haut, 'D' pour bas, 'L' pour gauche, 'R' pour droite)

    // Constructeur
    Joueur(int posX, int posY, int tailleJoueur);

    // Méthode pour dessiner le joueur
    void dessiner();
};

void gererClavier(Joueur& joueur);

#endif
