#ifndef JEUOTHELLO_H
#define JEUOTHELLO_H
#include "IJeu.h"
#include "IGrille.h"
#include "AJoueur.h"
#include <memory>
#include "IAffichage.h"

class JeuOthello : public IJeu {
public:
    JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Jouer() override;
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<std::pair<int, int>> CoupsPossibles() override;

 private:
    std::shared_ptr<IGrille> grille;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<AJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;
    void InitialiseJeu() const;
    bool EstCoupValide(int x, int y, Jeton jeton) const;
    void RetournerJetons(const int x, const int y, Jeton jeton);
    bool PeutRetourner(int x, int y, int directionX, int directionY, Jeton jeton) const;
    Jeton DetermineGagnant() const;
    void AfficherResultat() const;

};

#endif // JEUOTHELLO_H
