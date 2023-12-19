#include "inputconsole.h"
#include <iostream>
#include <limits>
#include <map>
#include <regex>

std::string InputConsole::getString(const std::string &message)
{
    std::string reponse;

    while (true)
    {
        std::cout << message;
        std::cin >> reponse;

        if (std::cin.fail())
        {
            ViderBuffer();
        }
        else
        {
            break;
        }
    }

    return reponse;
}

int InputConsole::getInt(const std::string &message)
{
    int choix;
    std::cout << std::endl;

    while (true)
    {
        std::cout << message;
        std::cin >> choix;

        if (std::cin.fail())
        {
            ViderBuffer();
        }
        else
        {
            break;
        }
    }

    return choix;
}

void InputConsole::ViderBuffer()
{
    std::cout << "Saisie invalide. Veuillez réessayer." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
}

TypesJeu InputConsole::demanderTypeDeJeu()
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

        choixJeu = getInt("Votre choix : ");

        choixValide = nomsDesJeux.find(static_cast<TypesJeu>(choixJeu)) != nomsDesJeux.end();

    } while (!choixValide);

    return static_cast<TypesJeu>(choixJeu);
}

int InputConsole::demanderModeDeJeu()
{
    int modeJeu;
    bool choixValide;
    do
    {
        std::cout << std::endl;
        std::cout << "Choisissez le mode de jeu:" << std::endl;
        std::cout << "1. Joueur vs Joueur" << std::endl;
        std::cout << "2. Joueur vs Ordinateur" << std::endl;
        std::cout << "3. Ordinateur vs Ordinateur" << std::endl;

        modeJeu = getInt("Choix mode de jeu : ");

        choixValide = (modeJeu == 1 || modeJeu == 2 || modeJeu == 3);

    } while (!choixValide);

    return modeJeu;
}

bool InputConsole::demanderRejouer()
{
    std::string choix;
    bool choixValide;
    do
    {
        std::cout << std::endl;
        choix = getString("Retourner au menu principal (o/N) ? ");
        choixValide = (choix == "o" || choix == "O" || choix == "n" || choix == "N");

    } while (!choixValide);

    return choix == "o" || choix == "O";
}

std::string InputConsole::demanderPrenomJoueur(const std::string &prompt)
{
    std::string prenom;
    std::regex regexPrenom("^[A-Za-z]{1,20}$");
    do
    {
        prenom = getString(prompt);

        if (!std::regex_match(prenom, regexPrenom))
        {
            std::cout << "Saisie invalide. Utilisez uniquement des lettres et une longueur entre 1 et 20 caractères." << std::endl;
        }
    } while (!std::regex_match(prenom, regexPrenom));

    return prenom;
}

std::pair<int, int> InputConsole::demanderCoupMorpion(int tailleGrille)
{
    int x, y;
    while (true)
    {
        x = getInt("Entrez la ligne (1 - " + std::to_string(tailleGrille) + ") : ");
        if (x < 1 || x > tailleGrille)
        {
            continue;
        }
        y = getInt("Entrez la colonne (1 - " + std::to_string(tailleGrille) + ") : ");

        if (y < 1 || y > tailleGrille)
        {
            continue;
        }

        return {x - 1, y - 1};
    }
}

std::pair<int, int> InputConsole::demanderCoupOthello(int tailleGrille)
{
    int x, y;

    while (true)
    {
        x = getInt("Entrez la ligne : ");
        y = getInt("Entrez la colonne : ");
        return {x - 1, y - 1};
    }
}

int InputConsole::demanderCoupPuissance4(int nbColonnes)
{
    int colonne;
    bool coupValide = false;

    do
    {
        colonne = getInt("Entrez le numero de la colonne : ");
        return colonne - 1;
    }
}
