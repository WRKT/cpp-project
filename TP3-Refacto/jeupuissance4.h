#ifndef JEUPUISSANCE4_H
#define JEUPUISSANCE4_H

#include "IJeu.h"
#include "IGrille.h"
#include "IJoueur.h"
#include "IAffichage.h"
#include <memory>
#include <string>

class JeuPuissance4 : public IJeu {

public:
    JeuPuissance4(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Jouer() override;
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<std::pair<int, int>> CoupsPossibles() override;
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
