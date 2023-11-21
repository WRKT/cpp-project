#include "configjeu.h"

std::pair<int, int> ConfigJeu::getDimensionsGrille(TypesJeu typeDeJeu) {
    if (typeDeJeu == TypesJeu::Morpion) {
        return {3, 3};
    } else if (typeDeJeu == TypesJeu::Puissance4) {
        return {4, 7};
    }
    return {0, 0};
}
