#ifndef MORPION_H
#define MORPION_H

#include "jeu.h"
#include "grille.h"

class JeuMorpion : public Jeu
{
public:
    JeuMorpion();
    void JoueurContreJoueur();
    void JoueurContreOrdinateur();
private:
    void InitialiserGrille();
    Grille grilleMorpion;
};

#endif // MORPION_H
