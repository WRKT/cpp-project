#ifndef JEUMORPION_H
#define JEUMORPION_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"

class JeuMorpion : public IJeu {
private:
    IGrille& grille;
    IJoueur& joueur1;
    IJoueur& joueur2;
    char joueurCourantPion;
    bool gameOver;


public:
    JeuMorpion(IGrille& grille, IJoueur& j1, IJoueur& j2);
    void jouer() override;
    bool aGagne(char jeton) const override;
    bool estEgalite() const override;
};

#endif // JEUMORPION_H
