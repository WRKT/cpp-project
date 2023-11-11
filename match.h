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
    // Pouvoir avoir une liste de Jeux disponible comme ca pas de changement a l'ajout
};

#endif // MATCH_H
