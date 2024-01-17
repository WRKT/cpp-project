#ifndef JEUDAMES_H
#define JEUDAMES_H

#include <memory>
#include "coordonnees.h"
#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"

class JeuDames : public IJeu {

public:
    JeuDames(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    void Jouer() override;
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<Position> CoupsPossibles() override;
    void AfficherResultat() const override;

private:
    std::shared_ptr<AGrille> grille;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<AJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;

    Position pionSelectionne;
    std::vector<Position> PionsJouables();
    bool PeutDeplacerEnDiagonale(const Position& depart, const Position& arrivee) const;
    bool PeutCapturer(const Position& position, const Direction& direction) const;
    void DeplacerPiece(const Position& depart, const Position& arrivee);
    void CapturerPiece(const Position& depart, const Position& arrivee);
    void AjouterCapturesPossibles(const Position& position, std::vector<Position>& coupsPossibles) const;
    Jeton GetJetonAdverse() const;
    Jeton DeterminerGagnant() const;
};

#endif // JEUDAMES_H
