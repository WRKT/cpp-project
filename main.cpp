#include <iostream>
#include "IGrille.h"
#include "grille.h"
#include "IJeu.h"
#include "TypesJeu.h"
#include "jeufactory.h"
#include "joueurfactory.h"

int main() {
    int choixJeu, modeJeu;
    std::cout << "Choisissez un jeu:\n1. Morpion\n2. Puissance 4\nVotre choix: ";
    std::cin >> choixJeu;

    std::cout << "Choisissez le mode de jeu:\n1. Joueur vs Joueur\n2. Joueur vs Ordinateur\nVotre choix: ";
    std::cin >> modeJeu;

    TypesJeu typeDeJeu = (choixJeu == 1) ? TypesJeu::Morpion : TypesJeu::Puissance4;

    auto joueur1 = JoueurFactory::CreerJoueurHumain("Alice", 'X');
    std::unique_ptr<IJoueur> joueur2;

    if (modeJeu == 1) {
        joueur2 = JoueurFactory::CreerJoueurHumain("Bertrand", 'O');
    } else {
        joueur2 = JoueurFactory::CreerJoueurOrdinateur('O');
    }

    int tailleGrilleMorpion = 3;
    int tailleGrillePuissance4 = 6;
    int nbColonnes = (typeDeJeu == TypesJeu::Morpion) ? tailleGrilleMorpion : tailleGrillePuissance4;
    int nbLignes = (typeDeJeu == TypesJeu::Morpion) ? tailleGrilleMorpion : tailleGrillePuissance4;

    auto grille = std::make_unique<Grille>(nbLignes, nbColonnes);

    auto jeu = JeuFactory::CreerJeu(typeDeJeu, *grille, *joueur1, *joueur2);

    jeu->jouer();

    return 0;
}
