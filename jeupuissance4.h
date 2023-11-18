#ifndef JEUPUISSANCE4_H
#define JEUPUISSANCE4_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"

class JeuPuissance4 : public IJeu {
private:
    IGrille& grille;
    IJoueur& joueur1;
    IJoueur& joueur2;
    char joueurCourantPion;
    bool gameOver;
    bool colonneValide(int colonne) const;

public:
    JeuPuissance4(IGrille& grille, IJoueur& j1, IJoueur& j2);
    void jouer() override;
    bool aGagne(char jeton) const override;
    bool estEgalite() const override;
    IGrille& getGrille() const { return grille; }
};

#endif // JEUPUISSANCE4_H
