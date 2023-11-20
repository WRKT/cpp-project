
#include <iostream>
#include <map>
#include <memory>
#include <limits>

#include "TypesJeu.h"
#include "InterfaceUtilisateur.h"
#include "configjeu.h"
#include "IGrille.h"
#include "IJeu.h"
#include "IJoueur.h"
#include "joueurfactory.h"
#include "jeufactory.h"
#include "grille.h"

int main() {
    std::cout << "=========================================\n";
    std::cout << " Bienvenue dans notre espace de jeux !\n";
    std::cout << "=========================================\n\n";
    InterfaceUtilisateur ui;
    bool rejouer;

    do {
            TypesJeu typeDeJeu = ui.demanderTypeDeJeu();
            int modeJeu = ui.demanderModeDeJeu();

            ConfigJeu config;
            auto dimensionsGrille = config.getDimensionsGrille(typeDeJeu);

            std::unique_ptr<IGrille> grille = std::make_unique<Grille>(dimensionsGrille.first, dimensionsGrille.second);

            std::string prenomJoueur1 = ui.demanderPrenomJoueur("Entrez le prénom du premier joueur : ");
            std::shared_ptr<IJoueur> joueur1 = JoueurFactory::CreerJoueurHumain(prenomJoueur1, Jeton::X);
            std::shared_ptr<IJoueur> joueur2;
            if (modeJeu == 1) {
                std::string prenomJoueur2 = ui.demanderPrenomJoueur("Entrez le prénom du second joueur : ");
                joueur2 = JoueurFactory::CreerJoueurHumain(prenomJoueur2, Jeton::O);
            } else {
                joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
            }
            std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, *grille, joueur1, joueur2);
            jeu->Jouer();
            rejouer = ui.demanderRejouer();
    } while (rejouer);
    return 0;
}

