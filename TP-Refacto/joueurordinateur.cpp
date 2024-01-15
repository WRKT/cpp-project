#include "joueurordinateur.h"
#include <vector>

Position JoueurOrdinateur::ChoisirCoupMorpion(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

Position JoueurOrdinateur::ChoisirCoupPuissance4(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

Position JoueurOrdinateur::ChoisirCoupOthello(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

Position JoueurOrdinateur::ChoisirCoupDames(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}
