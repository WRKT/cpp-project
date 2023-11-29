#include "saisieconsole.h"
#include <sstream>

std::string SaisieConsole::getString (const std::string& message) const
{
    std::string reponse;
    std::cout << std::endl;

    while (true) {

        std:: cout << message;
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

int SaisieConsole::getInt(const std::string& message) const
{
    int choix;
    std::cout << std::endl;

    while (true) {
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


void SaisieConsole::ViderBuffer() const {

    std::cout << "Saisie invalide. Veuillez réessayer." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << std::endl;

}
