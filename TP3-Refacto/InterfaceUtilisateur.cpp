#include "InterfaceUtilisateur.h"
#include <limits>
#include <map>
#include <regex>

TypesJeu InterfaceUtilisateur::demanderTypeDeJeu() {
    std::map<TypesJeu, std::string> nomsDesJeux = {
        {TypesJeu::Morpion, "Morpion"},
        {TypesJeu::Puissance4, "Puissance 4"},
        {TypesJeu::Othello, "Othello"}

    };

    int choixJeu;
    bool choixValide;

    do {
        std::cout << "Choisissez un jeu: " << std::endl;
        for (const auto& jeu : nomsDesJeux) {
            std::cout << static_cast<int>(jeu.first) << ". " << jeu.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Votre choix: ";
        std::cin >> choixJeu;

        choixValide = std::cin.good() && nomsDesJeux.find(static_cast<TypesJeu>(choixJeu)) != nomsDesJeux.end();

        if (!choixValide) {
            std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!choixValide);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return static_cast<TypesJeu>(choixJeu);
}

int InterfaceUtilisateur::demanderModeDeJeu() {
    int modeJeu;
    bool choixValide;

    do {
        // To do : enlever tous les cout et cin remplacer par affichageconsole et interfaceUtilisateur(input)

        std::cout << std::endl;
        std::cout << "Choisissez le mode de jeu:\n1. Joueur vs Joueur\n2. Joueur vs Ordinateur\n\nVotre choix: ";
        std::cin >> modeJeu;

        choixValide = std::cin.good() && (modeJeu == 1 || modeJeu == 2);

        if (!choixValide) {
            std::cout << "Choix invalide. Veuillez réessayer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!choixValide);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
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
