#ifndef JEUOTHELLO_H
#define JEUOTHELLO_H
#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>

class JeuOthello : public IJeu {
public:
    JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2);
    void Jouer() override;
    void TourHumain() override;
    void TourOrdi() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    void PlacerJeton(int x, int y, Jeton jeton);
    void VoirCoupPossibles();
    Jeton VerifiePions() const;
    int ComptePions(Jeton jeton) const;


private:
    std::shared_ptr<IGrille> grille;
    std::shared_ptr<IJoueur> joueur1;
    std::shared_ptr<IJoueur> joueur2;
    std::shared_ptr<IJoueur> joueurCourant;
};

#endif // JEUOTHELLO_H
