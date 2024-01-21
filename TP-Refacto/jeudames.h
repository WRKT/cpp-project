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
    void AfficherPionsJouables(const std::vector<Position> &pionsJouables);
    bool EstPionValide(const Position &pionChoisi, const std::vector<Position> &pionsJouables) const;
    void AfficherDeplacements(const std::vector<Position> &coupsPossibles) const;
    bool EstCoupValide(const Position &coupChoisi, const std::vector<Position> &coupsPossibles) const;
    bool PeutDeplacer(const Position& position) const;
    bool PeutCapturer(const Position& position, const Direction& direction) const;
    void DeplacerPiece(const Position& depart, const Position& arrivee);
    bool PeutDeplacerDame(const Position& position) const;
    std::vector<Position> CoupsPossiblesDame(const Position& pion);
    void AjouterCapturesPossibles(const Position& position, std::vector<Position>& coupsPossibles) const;
    void EffectuerCapturesMultiples(const Position &position);
    void VerifierPromotionDame(const Position& position);
    void PromouvoirEnDame(const Position& position);
    bool PeutCapturerDame(const Position& depart, const Direction& direction) const;
    std::vector<Position> CapturesPossiblesDepuisPosition(const Position &position, const Direction &direction, int profondeur) const;
    std::vector<Jeton> GetJetonAdverse() const;
    bool EstJetonAdverse(const Jeton& jeton) const;
    Jeton DeterminerGagnant() const;
    Jeton getPromotion(const Jeton& jeton) const;

};

#endif // JEUDAMES_H
