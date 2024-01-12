#ifndef JEUFACTORY_H
#define JEUFACTORY_H

#include "Models/Interfaces/IJeu.h"
#include "Models/Jeux/TypesJeu.h"
#include "Models/Interfaces/AJoueur.h"
#include <memory>


class JeuFactory
{
public:
    static std::unique_ptr<IJeu> CreerJeu(TypesJeu &typeDeJeu, std::shared_ptr<AJoueur> &joueur1, std::shared_ptr<AJoueur> &joueur2);
};

#endif // JEUFACTORY_H
