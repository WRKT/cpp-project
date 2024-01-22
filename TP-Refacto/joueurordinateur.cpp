#include "joueurordinateur.h"

Position JoueurOrdinateur::ChoisirCoordonnees(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);

    // std::this_thread::sleep_for(std::chrono::seconds(2));

    return CoupsPossible[random];
}

Position JoueurOrdinateur::ChoisirColonne(const std::vector<Position> &CoupsPossible)
{
    std::uniform_int_distribution<int> distribution(0, CoupsPossible.size() - 1);
    int random = distribution(generateur);

    // std::this_thread::sleep_for(std::chrono::seconds(2));

    return CoupsPossible[random];
}
