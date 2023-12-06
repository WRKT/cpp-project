#include "joueurhumain.h"
#include "inputconsole.h"
#include <vector>

std::pair<int, int> JoueurHumain::ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}

//std::pair<int, int> JoueurHumain::ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible)
//{
//    int coup;
//    coup = InputConsole::demanderColonne();
//    // renvoyer le coup choisi par le joueur qui est dans coup possible qui a la colonne coup
//    for (auto i : CoupsPossible)
//    {
//        if (i.second == coup)
//        {
//            return i;
//        }
//    }
//}

std::pair<int, int> JoueurHumain::ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::pair<int, int> coup;
    coup = InputConsole::demanderCordonnee();
    return coup;
}
