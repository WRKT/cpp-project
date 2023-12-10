#include "joueurordinateur.h"
#include <vector>

std::pair<int, int> JoueurOrdinateur::ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

std::pair<int, int> JoueurOrdinateur::ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}

std::pair<int, int> JoueurOrdinateur::ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);
    return CoupsPossible[random];
}
