#include "InterfaceUtilisateur.h"
#include "saisieconsole.h"
#include <limits>
#include <map>
#include <regex>

TypesJeu InterfaceUtilisateur::demanderTypeDeJeu() {
    std::map<TypesJeu, std::string> nomsDesJeux = {
        {TypesJeu::Morpion, "Morpion"},
        {TypesJeu::Puissance4, "Puissance 4"},
        {TypesJeu::Othello, "Othello"}

    };
    // Besoin d'avis sur comment implémenter le mode de saisie -> Tips : static ne pourra pas etre pris en compte en raison de l'interface
    modeSaisie = std::make_unique<SaisieConsole>();

    int choixJeu;
    bool choixValide;

    do{
        std::cout << "Choisissez un jeu: " << std::endl;

        for (const auto& jeu : nomsDesJeux)
        {
            std::cout << static_cast<int>(jeu.first) << ". " << jeu.second << std::endl;
        }

        choixJeu = modeSaisie->getInt("Votre choix : ");

        choixValide = nomsDesJeux.find(static_cast<TypesJeu>(choixJeu)) != nomsDesJeux.end();

    } while(!choixValide);


    return static_cast<TypesJeu>(choixJeu);
}

int InterfaceUtilisateur::demanderModeDeJeu() {

    int modeJeu;
    bool choixValide;

    do {
        std::cout << std::endl;
        std::cout << "Choisissez le mode de jeu:\n1. Joueur vs Joueur\n2. Joueur vs Ordinateur\n\nVotre choix: ";

        modeJeu = modeSaisie->getInt("Choix mode de jeu : ");

        choixValide = (modeJeu == 1 || modeJeu == 2);

    } while (!choixValide);

    return modeJeu;
}

bool InterfaceUtilisateur::demanderRejouer() {

    char choix;
    bool choixValide;

    do {
        std::cout << std::endl;
        std::cout << "Voulez-vous rejouer? (o/n): ";
        std::cin >> choix;

        choixValide = (choix == 'o' || choix == 'O' || choix == 'n' || choix == 'N');

        if (!choixValide) {
            std::cout << "Réponse invalide. Veuillez répondre par 'o' (oui) ou 'n' (non).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!choixValide);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return choix == 'o' || choix == 'O';
}


std::string InterfaceUtilisateur::demanderPrenomJoueur(const std::string& prompt) {
    std::string prenom;
    std::regex regexPrenom("^[A-Za-z]{1,20}$");
    do {
        std::cout << prompt;
        std::cin >> prenom;
        if (!std::regex_match(prenom, regexPrenom)) {
            std::cout << "Prénom invalide. Utilisez uniquement des lettres et une longueur maximale de 20 caractères." << std::endl;
        }
    } while (!std::regex_match(prenom, regexPrenom));

    return prenom;
}
