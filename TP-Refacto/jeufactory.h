#ifndef JEUFACTORY_H
#define JEUFACTORY_H

#include "IAffichage.h"
#include "IJeu.h"
#include "TypesJeu.h"
#include "AJoueur.h"
#include <memory>


class JeuFactory
{
public:
    static std::shared_ptr<IJeu> CreerJeu(TypesJeu &typeDeJeu, std::shared_ptr<AJoueur> &joueur1, std::shared_ptr<AJoueur> &joueur2, std::shared_ptr<IAffichage> &modeAffichage);
};

#endif // JEUFACTORY_H
