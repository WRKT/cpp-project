#include "jeufactory.h"
#include "jeumorpion.h"
#include "jeupuissance4.h"
#include <memory>
// Inclure les autres fichiers de jeux si nécessaire

std::unique_ptr<IJeu> JeuFactory::CreerJeu(TypesJeu typeDeJeu, IGrille& grille, std::shared_ptr<IJoueur> joueur1, std::shared_ptr<IJoueur> joueur2) {
    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<JeuMorpion>(grille, joueur1, joueur2);
    case TypesJeu::Puissance4:
        return std::make_unique<JeuPuissance4>(grille, joueur1, joueur2);
    case TypesJeu::COUNT:
        break;
    };
    return nullptr;
}
