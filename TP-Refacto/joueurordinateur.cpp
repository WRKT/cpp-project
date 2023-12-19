#include "joueurordinateur.h"
#include <vector>

std::pair<int, int> JoueurOrdinateur::ChoisirCoupMorpion(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

std::pair<int, int> JoueurOrdinateur::ChoisirCoupPuissance4(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

std::pair<int, int> JoueurOrdinateur::ChoisirCoupOthello(const std::vector<std::pair<int, int>> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}
