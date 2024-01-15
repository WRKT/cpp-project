#include "joueurhumain.h"
#include "inputconsole.h"
#include <vector>

Position JoueurHumain::ChoisirCoupMorpion(const std::vector<Position> &CoupsPossible)
{
    Position coup;
    coup = InputConsole::demanderCordonnee();

    return coup;
}

Position JoueurHumain::ChoisirCoupPuissance4(const std::vector<Position> &CoupsPossible)
{
    int colonne = InputConsole::demanderColonne();
    for (auto &coup : CoupsPossible)
    {
        if (coup.y == colonne)
        {
            return coup;
        }
    }
    return {-1, -1};
}

Position JoueurHumain::ChoisirCoupOthello(const std::vector<Position> &CoupsPossible)
{
    Position coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}

Position JoueurHumain::ChoisirCoupDames(const std::vector<Position> &CoupsPossible)
{
    Position coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}
