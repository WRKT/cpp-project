#ifndef JEUPUISSANCE4_H
#define JEUPUISSANCE4_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>

class JeuPuissance4 : public IJeu {
private:
    IGrille& grille;
    std::shared_ptr<IJoueur> joueur1;
    std::shared_ptr<IJoueur> joueur2;
    std::shared_ptr<IJoueur> joueurCourant;

public:
    JeuPuissance4(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2);
    void Jouer() override;
    void TourHumain() override;
    void TourOrdi() override;
    bool AGagne() const override;
    void PlacerJeton(int ligne, int colonne, Jeton jeton) override;
    bool PartieFinie() const override;
    bool colonneValide(int colonne) const;
    IGrille& getGrille() const { return grille; }
};

#endif // JEUPUISSANCE4_H
