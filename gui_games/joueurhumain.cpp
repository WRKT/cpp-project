#include "joueurhumain.h"
#include <vector>

Position JoueurHumain::ChoisirCoordonnees(const std::vector<Position> &CoupsPossible)
{
    Position coup;
    coup = input.demanderCoordonnees();
    return coup;
}

Position JoueurHumain::ChoisirColonne(const std::vector<Position> &CoupsPossible)
{
    int colonne = input.demanderColonne();
    for (auto &coup : CoupsPossible)
    {
        if (coup.y == colonne)
        {
            return coup;
        }
    }
    return {-1, -1};
}
