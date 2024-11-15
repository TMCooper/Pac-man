#include <xamgraph.h>
#include <boutton.h>

// Déclaration d'une instance globale de XamGraph
extern XamGraph graph;

const int TAILLE_HAUTEUR = 40;
const int TAILLE_LARGEUR = 125;
const int RECT_X = 625;
const int RECT_Y = 605;

void exit_boutton() {
    // Définir la couleur du bouton (bleu ici)
    graph.setColor(XAM_BLUE);
    
    // Dessiner un bouton à la position (625, 605)
    graph.filledRectangle(RECT_X, RECT_Y, TAILLE_LARGEUR, TAILLE_HAUTEUR);

    // Définir la couleur du texte (blanc ici)
    graph.setColor(XAM_WHITE);
    
    const char* texte = "Exit";

    // Calculer la largeur et la hauteur du texte
    int textWidth = graph.textWidth(texte);
    int textHeight = graph.textHeight();

    // Calculer la position du texte pour le centrer dans le rectangle
    int textX = RECT_X + (TAILLE_LARGEUR - textWidth) / 2;
    int textY = RECT_Y + (TAILLE_HAUTEUR - textHeight) / 2;

    // Afficher le texte centré
    graph.textOut(textX, textY, texte);
}
