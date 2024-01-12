#include "jeufactory.h"
#include "Models/Jeux/jeumorpion.h"
#include "Models/Jeux/jeuothello.h"
#include "Models/Jeux/jeupuissance4.h"
#include "Models/Jeux/jeudames.h"
#include "Models/Affichage/affichageconsole.h"
#include "grillefactory.h"
#include <memory>

std::unique_ptr<IJeu> JeuFactory::CreerJeu(TypesJeu &typeDeJeu, std::shared_ptr<AJoueur> &joueur1, std::shared_ptr<AJoueur> &joueur2) {

    std::shared_ptr<AGrille> grille = GrilleFactory::CreerGrille(typeDeJeu);
    std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();

    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<JeuMorpion>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Puissance4:
        return std::make_unique<JeuPuissance4>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Othello:
        return std::make_unique<JeuOthello>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Dames:
        return std::make_unique<JeuDames>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::COUNT:
        break;
    };

    return nullptr;
}
