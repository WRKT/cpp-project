#include "joueurhumain.h"
#include "inputconsole.h"
#include "IAffichage.h"
#include <vector>

std::pair<int, int> JoueurHumain::ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
}

int JoueurHumain::ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible)
{
    int coup;
    coup = InputConsole::demanderColonne();
}

std::pair<int, int> JoueurHumain::ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
}