#include "joueurhumain.h"
#include "inputconsole.h"
#include <vector>

std::pair<int, int> JoueurHumain::ChoisirCoupMorpion(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}

std::pair<int, int> JoueurHumain::ChoisirCoupPuissance4(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    int colonne = InputConsole::demanderColonne();
    for (auto &coup : CoupsPossible)
    {
        if (coup.second == colonne)
        {
            return coup;
        }
    }
    return std::make_pair(-1, -1);
}

std::pair<int, int> JoueurHumain::ChoisirCoupOthello(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}
