#ifndef JEUOTHELLO_H
#define JEUOTHELLO_H
#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include <memory>
#include "IAffichage.h"

class JeuOthello : public IJeu {
public:
    JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Jouer() override;
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<std::pair<int, int>> CoupsPossibles() override;
    void PlacerJeton(int x, int y, Jeton jeton);
    void VoirCoupsPossibles();
    bool VerifiePions() const;
    Jeton GetTypePion() const;
    int ComptePions(Jeton jeton) const;
    bool EstCoupValide(int x, int y, Jeton jeton) const;
    bool EstDirectionValide(int x, int y, int dx, int dy, Jeton jeton) const;

private:
    std::shared_ptr<IGrille> grille;
    std::shared_ptr<IJoueur> joueur1;
    std::shared_ptr<IJoueur> joueur2;
    std::shared_ptr<IJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;

};

#endif // JEUOTHELLO_H
