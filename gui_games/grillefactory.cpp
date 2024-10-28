#include "grillefactory.h"
#include "grille.h"

std::unique_ptr<AGrille> GrilleFactory::CreerGrille(const TypesJeu &typeDeJeu) {
    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<Grille>(3, 3);
    case TypesJeu::Puissance4:
        return std::make_unique<Grille>(4, 7);
    case TypesJeu::Othello:
        return std::make_unique<Grille>(8, 8);
    case TypesJeu::Dames:
        return std::make_unique<Grille>(10, 10);
    default:
        return nullptr;
    }
}
