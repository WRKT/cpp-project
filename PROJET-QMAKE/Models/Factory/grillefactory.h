#ifndef GRILLEFACTORY_H
#define GRILLEFACTORY_H

#include "Models/Jeux/TypesJeu.h"
#include "Models/Interfaces/AGrille.h"
#include <memory>

class GrilleFactory {
public:
    static std::unique_ptr<AGrille> CreerGrille(const TypesJeu& typeDeJeu);
};

#endif // GRILLEFACTORY_H
