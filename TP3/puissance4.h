#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include "jeu.h"
#include "grille.h"

class JeuPuissance4 : public Jeu
{
public:
    JeuPuissance4();
    void JoueurContreJoueur();
    void JoueurContreOrdinateur();
private:
    void InitialiserGrille();
    GrillePuissance4 grillePuissance4;
};

#endif // PUISSANCE4_H
