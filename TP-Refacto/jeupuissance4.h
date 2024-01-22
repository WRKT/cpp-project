#ifndef JEUPUISSANCE4_H
#define JEUPUISSANCE4_H

#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
#include <memory>

class JeuPuissance4 : public IJeu {

public:
    JeuPuissance4(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage) : IJeu(grille, j1, j2, modeAffichage){};
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<Position> CoupsPossibles() override;
    void AfficherResultat() const override;
    TypesJeu getType() const override { return TypesJeu::Puissance4;}

private:
    const int sequenceGagnante = 4;

};

#endif // JEUPUISSANCE4_H
