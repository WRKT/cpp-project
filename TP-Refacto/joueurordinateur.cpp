#include "joueurordinateur.h"

Position JoueurOrdinateur::ChoisirCoordonnees(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);

    return CoupsPossible[random];
}

Position JoueurOrdinateur::ChoisirColonne(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);

    return CoupsPossible[random];
}
