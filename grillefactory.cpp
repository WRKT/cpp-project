#include "grillefactory.h"
#include "grille.h"

std::unique_ptr<IGrille> GrilleFactory::CreerGrille(TypesJeu typeDeJeu) {
    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<Grille>(3, 3);
    case TypesJeu::Puissance4:
        return std::make_unique<Grille>(4, 7);
    default:
        return nullptr;
    }
}
