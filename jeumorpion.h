#ifndef JEUMORPION_H
#define JEUMORPION_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>

class JeuMorpion : public IJeu {
private:
    IGrille& grille;
    std::shared_ptr<IJoueur> joueur1;
    std::shared_ptr<IJoueur> joueur2;
    std::shared_ptr<IJoueur> joueurCourant;

public:
    JeuMorpion(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2);
    virtual void TourHumain() override;
    virtual void TourOrdi() override;
    virtual bool AGagne() const override;
    virtual bool PartieFinie() const override;
    void PlacerJeton(int ligne, int colonne, Jeton jeton);
    bool VerifieLignes() const;
    bool VerifieColonnes() const;
    bool VerifieDiagonales() const;
    void Jouer() override;
};

#endif // JEUMORPION_H
