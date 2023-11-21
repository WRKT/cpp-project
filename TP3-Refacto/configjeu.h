#ifndef CONFIGJEU_H
#define CONFIGJEU_H

#include <utility>
#include "TypesJeu.h"

class ConfigJeu
{
public:
    std::pair<int, int> getDimensionsGrille(TypesJeu typeDeJeu);
};

#endif // CONFIGJEU_H
