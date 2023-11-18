#include "jeufactory.h"
#include "jeumorpion.h"
#include "jeupuissance4.h"
// Inclure les autres fichiers de jeux si nécessaire

std::unique_ptr<IJeu> JeuFactory::CreerJeu(TypesJeu typeDeJeu, IGrille& grille, IJoueur& joueur1, IJoueur& joueur2) {
    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<JeuMorpion>(grille, joueur1, joueur2);
    case TypesJeu::Puissance4:
        return std::make_unique<JeuPuissance4>(grille, joueur1, joueur2);
        // Ajoutez d'autres cas ici
    }
    // Retourner un pointeur nul ou lever une exception si le type de jeu est inconnu
}
