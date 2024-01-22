#ifndef JEUDAMES_H
#define JEUDAMES_H

#include <memory>
#include "coordonnees.h"
#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
class JeuDames : public IJeu
{

public:
    JeuDames(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage) : IJeu(grille, j1, j2, modeAffichage)
    {
        grille->InitialiserGrilleDame();
        joueur1->AttribuerListeJeton({Jeton::X, Jeton::DameX});
        joueur2->AttribuerListeJeton({Jeton::O, Jeton::DameO});
    };
    void Tour() override;
    bool AGagne() const override;
    bool PartieFinie() const override;
    std::vector<Position> CoupsPossibles() override;
    void AfficherResultat() const override;
    TypesJeu getType() const override { return TypesJeu::Dames;}
private:
    bool captureEnCours = false;

    Position pionSelectionne;
    std::vector<Position> PionsJouables();
    void AfficherPionsJouables(const std::vector<Position> &pionsJouables);
    bool EstPionValide(const Position &pionChoisi, const std::vector<Position> &pionsJouables) const;
    void AfficherDeplacements(const std::vector<Position> &coupsPossibles) const;
    bool EstCoupValide(const Position &coupChoisi, const std::vector<Position> &coupsPossibles) const;
    bool PeutDeplacer(const Position &depart, const Position &arrivee) const;
    bool PeutCapturer(const Position &position, const Direction &direction) const;
    void DeplacerPiece(const Position &depart, const Position &arrivee);
    void AjouterCapturesPossibles(const Position &position, std::vector<Position> &coupsPossibles) const;
    std::vector<Position> CoupsPossiblesDame(const Position &positionDame);
    bool PeutDeplacerDame(const Position &position) const;
    bool PeutCapturerDame(const Position &depart, const Direction &direction) const;
    void EffectuerCapturesMultiples(const Position &position);
    std::vector<Position> CapturesPossiblesDepuisPosition(const Position &position, const Direction &direction) const;
    std::vector<Jeton> GetJetonAdverse() const;
    Jeton DeterminerGagnant() const;
    std::vector<Position> CalculerPositionsCaptureDame(const Position &positionDame, const Direction &direction) const;
    bool EstJetonAdverse(const Jeton &jeton) const;
    void VerifierPromotionDame(const Position &position);
};

#endif // JEUDAMES_H
