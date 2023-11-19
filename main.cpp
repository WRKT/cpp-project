
#include <iostream>
#include "IGrille.h"
#include "grille.h"
#include "IJeu.h"
#include "TypesJeu.h"
#include "jeufactory.h"
#include "joueurfactory.h"
#include <map>
#include <limits>

std::map<TypesJeu, std::string> nomsDesJeux = {
    {TypesJeu::Morpion, "Morpion"},
    {TypesJeu::Puissance4, "Puissance 4"}
 };


int main() {
    std::cout << "=========================================\n";
    std::cout << " Bienvenue dans notre espace de jeux !\n";
    std::cout << "=========================================\n\n";

    std::cout << "Vous avez le choix entre " << static_cast<int>(TypesJeu::COUNT) - 1 << " jeux classiques :\n";

    int choixJeu, modeJeu;
    bool choixValide;

    do {
        std::cout << "\nChoisissez un jeu:\n";
        for (const auto& jeu : nomsDesJeux)
        {
            std::cout << static_cast<int>(jeu.first) << ". " << jeu.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choixJeu;

        choixValide = std::cin.good() && nomsDesJeux.find(static_cast<TypesJeu>(choixJeu)) != nomsDesJeux.end();

        if (!choixValide) {
            std::cout << "Choix invalide. Veuillez réessayer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!choixValide);

    TypesJeu typeDeJeu = static_cast<TypesJeu>(choixJeu);

    std::cout << "Vous avez choisi: " << nomsDesJeux[typeDeJeu] << std::endl;

    std::cout << "\nChoisissez le mode de jeu:\n1. Joueur vs Joueur\n2. Joueur vs Ordinateur\nVotre choix: ";
    std::cin >> modeJeu;


    int tailleGrilleMorpion = 3;
    int LigneGrillePuissance4 =7 ;
    int ColonneGrillePuissance4 = 4;

    int nbColonnes = (typeDeJeu == TypesJeu::Morpion) ? tailleGrilleMorpion : LigneGrillePuissance4;
    int nbLignes = (typeDeJeu == TypesJeu::Morpion) ? tailleGrilleMorpion : ColonneGrillePuissance4;

    std::unique_ptr<IGrille> grille = std::make_unique<Grille>(nbLignes, nbColonnes);
    std::shared_ptr<IJoueur> joueur1 = JoueurFactory::CreerJoueurHumain("Vader", Jeton::X);
    std::shared_ptr<IJoueur> joueur2 = (modeJeu == 1) ? JoueurFactory::CreerJoueurHumain("Obi-Wan", Jeton::O) : JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, *grille, joueur1, joueur2);

    jeu->Jouer();

    return 0;
}
