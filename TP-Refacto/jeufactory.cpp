#include "jeufactory.h"
#include "jeumorpion.h"
#include "jeuothello.h"
#include "jeupuissance4.h"
#include "jeudames.h"
#include "grillefactory.h"
#include <memory>

std::shared_ptr<IJeu> JeuFactory::CreerJeu(TypesJeu &typeDeJeu, std::shared_ptr<AJoueur> &joueur1, std::shared_ptr<AJoueur> &joueur2, std::shared_ptr<IAffichage> &modeAffichage) {

    std::shared_ptr<AGrille> grille = GrilleFactory::CreerGrille(typeDeJeu);

    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_shared<JeuMorpion>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Puissance4:
        return std::make_shared<JeuPuissance4>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Othello:
        return std::make_shared<JeuOthello>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Dames:
        return std::make_shared<JeuDames>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::COUNT:
        break;
    };

    return nullptr;
}
