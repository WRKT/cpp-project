#ifndef JEUOTHELLO_H
#define JEUOTHELLO_H

#include <memory>
#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
#include "coordonnees.h"

class JeuOthello : public IJeu {
public:
    JeuOthello(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage) : IJeu(grille, j1, j2, modeAffichage){
       grille->InitialiserGrilleOthello();
    };
    void Jouer() override;
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<Position> CoupsPossibles() override;
    void AfficherResultat() const override;
    TypesJeu getType() const override { return TypesJeu::Othello;}

private:
    int bloque = 0;
    bool EstCoupValide(const Position& position, const Jeton& jeton) const;
    void RetournerJetons(const Position& position, const Jeton& jeton);
    void RetournerJetonsDansDirection(const Position& position, const Direction& direction, const Jeton& jeton);
    bool PeutRetourner(const Position& position, const Direction& direction, const Jeton& jeton) const;
    Jeton DetermineGagnant() const;
};

#endif // JEUOTHELLO_H
