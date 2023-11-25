#ifndef JEUPUISSANCE4_H
#define JEUPUISSANCE4_H

#include "IAffichage.h"
#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>

class JeuPuissance4 : public IJeu {

public:
    JeuPuissance4(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Jouer() override;
    void TourHumain() override;
    void TourOrdi() override;
    bool AGagne() const override;
    void PlacerJeton(int colonne, Jeton jeton);
    bool PartieFinie() const override;
    bool VerifieLignes() const;
    bool VerifieDiagonales() const;
    bool VerifieColonnes() const;

private:
    std::shared_ptr<IGrille> grille;
    std::shared_ptr<IJoueur> joueur1;
    std::shared_ptr<IJoueur> joueur2;
    std::shared_ptr<IJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;
};

#endif // JEUPUISSANCE4_H
