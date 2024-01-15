#ifndef JEUDAMES_H
#define JEUDAMES_H

#include "IJeu.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "IAffichage.h"
#include <memory>
#include <unordered_map>

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
    std::unordered_map<std::shared_ptr<AJoueur>, Position> positionsJoueurs;
    int xPionSelectionne;
    int yPionSelectionne;
    std::vector<Position> PionsJouables();
    bool PeutDeplacerEnDiagonale(int xDepart, int yDepart, int xArrivee, int yArrivee) const;
    void AjouterCapturesPossibles(int x, int y, std::vector<Position>& coupsPossibles) const;
    void DeplacerPiece(int xDepart, int yDepart, int xArrivee, int yArrivee);
    bool EstDeplacementValide(int xDepart, int yDepart, int xArrivee, int yArrivee) const;
    void CapturerPiece(int xDepart, int yDepart, int xArrivee, int yArrivee);
    bool PeutCapturer(int x, int y, int xAdversaire, int yAdversaire) const;
};

#endif // JEUDAMES_H
