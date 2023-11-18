#ifndef JEUMORPION_H
#define JEUMORPION_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include "Jeton.h"

class JeuMorpion : public IJeu {
private:
    IGrille& grille;
    IJoueur& joueur1;
    IJoueur& joueur2;
    char joueurCourantPion;

    bool estFinDuJeu() const;
    bool aGagne(char pion) const;

public:
    JeuMorpion(IGrille& grille, IJoueur& j1, IJoueur& j2);

    void jouer() override;
};

#endif // JEUMORPION_H
