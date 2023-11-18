#ifndef JEUFACTORY_H
#define JEUFACTORY_H

#include "IJeu.h"
#include "TypesJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>


class JeuFactory
{
public:
    static std::unique_ptr<IJeu> CreerJeu(TypesJeu typeDeJeu, IGrille& grille, IJoueur& joueur1, IJoueur& joueur2);
};

#endif // JEUFACTORY_H
