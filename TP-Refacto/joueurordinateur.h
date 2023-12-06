#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "AJoueur.h"
#include <string>
#include "jeton.h"
#include <random>
#include <chrono>

class JoueurOrdinateur : public AJoueur
{

public:
    JoueurOrdinateur(Jeton jeton) : AJoueur("Ordinateur", jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()){};
    bool estHumain() const override { return false; }
    std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible);
    int ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible);
    std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible);

private:
    std::mt19937 generateur;
};

#endif // JOUEUR_ORDINATEUR_H
