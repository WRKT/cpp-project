#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "Models/Interfaces/AJoueur.h"
#include <string>
#include <random>
#include <chrono>

class JoueurOrdinateur : public AJoueur
{

public:
    JoueurOrdinateur(Jeton jeton) : AJoueur("Ordinateur", jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()){};

private:
    std::mt19937 generateur;
    std::vector<std::pair<int, int>> CoupsPossibles;
    std::pair<int, int> ChoisirCoupMorpion(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupPuissance4(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupOthello(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupDames(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
};

#endif // JOUEUR_ORDINATEUR_H
