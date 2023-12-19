#ifndef GRILLEFACTORY_H
#define GRILLEFACTORY_H

#include "TypesJeu.h"
#include "AGrille.h"
#include <memory>

class GrilleFactory {
public:
    static std::unique_ptr<AGrille> CreerGrille(const TypesJeu& typeDeJeu);
};

#endif // GRILLEFACTORY_H
