#include "jeuothello.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuOthello::Jouer()
{

}

void JeuOthello::TourHumain()
{

}

void JeuOthello::TourOrdi()
{

}

bool JeuOthello::AGagne() const
{

}

bool JeuOthello::PartieFinie() const
{

}

void JeuOthello::PlacerJeton(int colonne, Jeton jeton)
{

}

void JeuOthello::voirCoupPossibles()
{

}
