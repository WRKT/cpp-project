#ifndef JEUMORPION_H
#define JEUMORPION_H

#include "IJeu.h"
#include "IGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
#include <memory>

class JeuMorpion : public IJeu {

public:
    JeuMorpion(std::shared_ptr<IGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    void InitialiseJeu() const override;
    std::vector<std::pair<int, int>> CoupsPossibles() override;
    void AfficherResultat() const override;
    void Jouer() override;

private:
    std::shared_ptr<IGrille> grille;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<AJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;
};

#endif // JEUMORPION_H
