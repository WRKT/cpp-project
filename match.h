#ifndef MATCH_H
#define MATCH_H
#include "puissance4.h"
#include "morpion.h"

class Match
{
public:
    Match();
    void StartJeu();
private:
    void Rejouer();
    int ChoixJeu();
    JeuMorpion morpion;
    JeuPuissance4 puissance4;
};

#endif // MATCH_H
