#include "jeufactory.h"
#include "jeumorpion.h"
#include "jeupuissance4.h"
#include "affichageconsole.h"
#include "grillefactory.h"

#include <memory>
// Inclure les autres fichiers de jeux si nécessaire

std::unique_ptr<IJeu> JeuFactory::CreerJeu(TypesJeu typeDeJeu, std::shared_ptr<IJoueur> joueur1, std::shared_ptr<IJoueur> joueur2) {
    std::shared_ptr<IGrille> grille = GrilleFactory::CreerGrille(typeDeJeu);
    std::shared_ptr<IAffichage> modeAffichage = std::make_shared<AffichageConsole>();

    switch (typeDeJeu) {
    case TypesJeu::Morpion:
        return std::make_unique<JeuMorpion>(grille, joueur1, joueur2, modeAffichage);
    case TypesJeu::Puissance4:
        return std::make_unique<JeuPuissance4>(grille, joueur1, joueur2);
    case TypesJeu::Othello:
        break;
    case TypesJeu::Dames:
        break;
    case TypesJeu::COUNT:
        break;
    };
    return nullptr;
}
