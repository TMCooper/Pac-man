#include <xamgraph.h>
#include <boutton.h>

// Déclaration d'une instance globale de XamGraph
extern XamGraph graph;

// Constantes pour la taille et la position du bouton
const int TAILLE_HAUTEUR = 40;
const int TAILLE_LARGEUR = 125;
const int RECT_X = 625;
const int RECT_Y = 605;

bool isMouseOverButton(int mouseX, int mouseY) {
    // Vérifier si la souris est dans le rectangle du bouton
    return (mouseX >= RECT_X && mouseX <= RECT_X + TAILLE_LARGEUR &&
            mouseY >= RECT_Y && mouseY <= RECT_Y + TAILLE_HAUTEUR);
}

// Fonction pour dessiner le bouton "Exit"
void draw_exit_boutton() {
    // Définir la couleur du bouton (bleu ici)
    graph.setColor(XAM_BLUE);

    // Dessiner un rectangle rempli à la position (625, 605)
    graph.filledRectangle(RECT_X, RECT_Y, TAILLE_LARGEUR, TAILLE_HAUTEUR);

    // Définir la couleur du texte (blanc ici)
    graph.setColor(XAM_WHITE);

    // Texte à afficher sur le bouton
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

// Fonction pour gérer les clics de souris
void handle_mouse_click(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);  // Obtenir la position actuelle de la souris
        printf("Mouse X: %d, Mouse Y: %d\n", mouseX, mouseY);
        // Vérifier si la souris est dans la zone du bouton Exit
        if (isMouseOverButton(mouseX, mouseY) && event.button.button == SDL_BUTTON_LEFT) {
            printf("Le bouton Exit a été cliqué. Quitter le programme...\n");
            exit(0);  // Quitter le programme
        }
    }
}