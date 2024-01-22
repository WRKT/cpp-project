#ifndef JEUMORPION_H
#define JEUMORPION_H

#include <memory>
#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"


class JeuMorpion : public IJeu {

public:
    JeuMorpion(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage) : IJeu(grille, j1, j2, modeAffichage){
        modeAffichage->AfficherGrille(grille);
        };
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<Position> CoupsPossibles() override;
    void AfficherResultat() const override;
    TypesJeu getType() const override { return TypesJeu::Morpion;}

private:
    const int sequenceGagnante = 3;
};

#endif // JEUMORPION_H
