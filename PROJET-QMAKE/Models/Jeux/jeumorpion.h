#ifndef JEUMORPION_H
#define JEUMORPION_H

#include <memory>
#include "Models/Interfaces/IJeu.h"
#include "Models/Interfaces/AGrille.h"
#include "Models/Interfaces/AJoueur.h"
#include "Models/Interfaces/IAffichage.h"


class JeuMorpion : public IJeu {

public:
    JeuMorpion(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<std::pair<int, int>> CoupsPossibles() override;
    void AfficherResultat() const override;
    void Jouer() override;

private:
    std::shared_ptr<AGrille> grille;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<AJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;
    const int sequenceGagnante = 3;
};

#endif // JEUMORPION_H
