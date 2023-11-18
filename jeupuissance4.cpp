#include "jeupuissance4.h"
#include <iostream>

JeuPuissance4::JeuPuissance4(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuPuissance4::Jouer() {
    //
}

void JeuPuissance4::TourHumain()
{

}

void JeuPuissance4::TourOrdi()
{

}

bool JeuPuissance4::PartieFinie() const {

    return false;
}

bool JeuPuissance4::AGagne() const {

    return false;
}

void JeuPuissance4::PlacerJeton(int ligne, int colonne, Jeton jeton)
{

}

bool JeuPuissance4::colonneValide(int colonne) const {
    return false;
}
