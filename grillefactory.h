#ifndef GRILLEFACTORY_H
#define GRILLEFACTORY_H

#include "TypesJeu.h"
#include "IGrille.h"
#include <memory>

class GrilleFactory {
public:
    static std::unique_ptr<IGrille> CreerGrille(TypesJeu typeDeJeu);
};

#endif // GRILLEFACTORY_H
