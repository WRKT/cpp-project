#ifndef JEU_H
#define JEU_H
#include "joueur.h"

class Jeu
{
public:
    Jeu();
    virtual void InitialiserJcJ();
    virtual void InitialiserJcO();
    virtual void Jouer();
    virtual void JouerTour() = 0;
    virtual void DemanderRejouer();
    virtual void JoueurContreJoueur() = 0;
    virtual void JoueurContreOrdinateur() = 0;
protected:
    bool gameOver;
    Joueur joueur1;
    Joueur joueur2;
    Joueur* joueurCourant;
    Ordinateur ordinateur;
};

#endif // JEU_H
