#include "InterfaceUtilisateur.h"
#include "saisieconsole.h"
#include <limits>
#include <map>
#include <regex>

TypesJeu InterfaceUtilisateur::demanderTypeDeJeu()
{
    std::map<TypesJeu, std::string> nomsDesJeux = {
        {TypesJeu::Morpion, "Morpion"},
        {TypesJeu::Puissance4, "Puissance 4"},
        {TypesJeu::Othello, "Othello"}};

    int choixJeu;
    bool choixValide;

    do
    {
        std::cout << std::endl;
        std::cout << "Choisissez un jeu: " << std::endl;

        for (const auto &jeu : nomsDesJeux)
        {
            std::cout << static_cast<int>(jeu.first) << ". " << jeu.second << std::endl;
        }

        choixJeu = SaisieConsole::getInt("Votre choix : ");

        choixValide = nomsDesJeux.find(static_cast<TypesJeu>(choixJeu)) != nomsDesJeux.end();

    } while (!choixValide);

    return static_cast<TypesJeu>(choixJeu);
}

int InterfaceUtilisateur::demanderModeDeJeu()
{

    int modeJeu;
    bool choixValide;

    do
    {
        std::cout << std::endl;
        std::cout << "Choisissez le mode de jeu:\n1. Joueur vs Joueur\n2. Joueur vs Ordinateur\n";

        modeJeu = SaisieConsole::getInt("Choix mode de jeu : ");

        choixValide = (modeJeu == 1 || modeJeu == 2);

    } while (!choixValide);

    return modeJeu;
}

bool InterfaceUtilisateur::demanderRejouer()
{

    char choix;
    bool choixValide;

    do
    {
        std::cout << std::endl;
        std::cout << "Retourner au menu principal? (o/n): ";
        std::cin >> choix;

        choixValide = (choix == 'o' || choix == 'O' || choix == 'n' || choix == 'N');

        if (!choixValide)
        {
            std::cout << "Réponse invalide. Veuillez répondre par 'o' (oui) ou 'n' (non).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!choixValide);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return choix == 'o' || choix == 'O';
}

std::string InterfaceUtilisateur::demanderPrenomJoueur(const std::string &prompt)
{
    std::string prenom;
    std::regex regexPrenom("^[A-Za-z]{1,20}$");
    do
    {
        std::cout << prompt;
        std::cin >> prenom;
        if (!std::regex_match(prenom, regexPrenom))
        {
            std::cout << "Prénom invalide. Utilisez uniquement des lettres et une longueur maximale de 20 caractères." << std::endl;
        }
    } while (!std::regex_match(prenom, regexPrenom));

    return prenom;
}

std::pair<int, int> InterfaceUtilisateur::demanderCoupMorpion(int tailleGrille)
{
    int x, y;
    while (true)
    {
        std::cout << "Entrez la ligne (1 - " << tailleGrille << ") : ";
        if (!(std::cin >> x) || x < 1 || x > tailleGrille)
        {
            std::cout << "Entrée invalide, veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Entrez la colonne (1 - " << tailleGrille << ") : ";
        if (!(std::cin >> y) || y < 1 || y > tailleGrille)
        {
            std::cout << "Entrée invalide, veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        return {x - 1, y - 1};
    }
}

std::pair<int, int> InterfaceUtilisateur::demanderCoupOthello(int tailleGrille)
{
    int x, y;
    while (true)
    {
        std::cout << "Entrez la ligne (1 - " << tailleGrille << ") : ";
        if (!(std::cin >> x) || x < 1 || x > tailleGrille)
        {
            std::cout << "Entrée invalide, veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Entrez la colonne (1 - " << tailleGrille << ") : ";
        if (!(std::cin >> y) || y < 1 || y > tailleGrille)
        {
            std::cout << "Entrée invalide, veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        return {x - 1, y - 1};
    }
}

int InterfaceUtilisateur::demanderCoupPuissance4(int nbColonnes)
{
    int colonne;
    bool coupValide = false;

    while (!coupValide)
    {
        std::cout << "Entrez le numéro de la colonne (1 - " << nbColonnes << ") : ";
        std::cin >> colonne;

        coupValide = (colonne >= 1 && colonne <= nbColonnes);
        if (!coupValide)
        {
            std::cout << "Coup invalide, veuillez réessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return colonne - 1;
}
