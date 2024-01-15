#include "jeudames.h"
#include <vector>
#include <algorithm>

JeuDames::JeuDames(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuDames::Jouer() {
    grille->InitialiserGrilleDame();
    modeAffichage->AfficherGrille(grille);
    while (!PartieFinie()) {
        Tour();
    }
    AfficherResultat();
}

void JeuDames::Tour() {
    bool coupJouable = false;

    while (!coupJouable) {
        auto pionsJouables = PionsJouables();
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations(),2);

        modeAffichage->AfficherCoupsPossibles(pionsJouables, "Pions jouables : ");

        Position pionChoisi = joueurCourant->ChoisirCoupDames(pionsJouables);
        pionSelectionne = pionChoisi;

        if (std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end()) {
            auto coupsPossibles = CoupsPossibles();

            modeAffichage->AfficherMessage("");
            modeAffichage->AfficherCoupsPossibles(coupsPossibles, "Deplacement possible du pion : ");

            Position coupChoisi = joueurCourant->ChoisirCoupDames(coupsPossibles);

            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coupChoisi) != coupsPossibles.end()) {
                DeplacerPiece(pionSelectionne, coupChoisi);
                coupJouable = true;
            } else {
                modeAffichage->AfficherErreur("Coup impossible pour le pion choisi");
            }
        } else {
            modeAffichage->AfficherErreur("Pion choisi n'est pas valide");
        }
    }

    joueurCourant = (joueurCourant == joueur1) ? joueur2 : joueur1;

    modeAffichage->AfficherGrille(grille);
}

bool JeuDames::AGagne() const {
    return false;
}

bool JeuDames::PartieFinie() const {
    return false;
}

std::vector<Position> JeuDames::PionsJouables() {
    std::vector<Position> pionsJouables;

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
            if (grille->GetCellule(ligne, colonne) == joueurCourant->getJeton()) {
                Position position{ligne, colonne};
                if (PeutDeplacerEnDiagonale(position, {ligne - 1, colonne - 1}) ||
                    PeutDeplacerEnDiagonale(position, {ligne - 1, colonne + 1}) ||
                    PeutDeplacerEnDiagonale(position, {ligne + 1, colonne - 1}) ||
                    PeutDeplacerEnDiagonale(position, {ligne + 1, colonne + 1}) ||
                    PeutCapturer(position, {ligne - 1, colonne - 1}) ||
                    PeutCapturer(position, {ligne - 1, colonne + 1}) ||
                    PeutCapturer(position, {ligne + 1, colonne - 1}) ||
                    PeutCapturer(position, {ligne + 1, colonne + 1})) {
                    pionsJouables.push_back(position);
                }
            }
        }
    }
    return pionsJouables;
}

std::vector<Position> JeuDames::CoupsPossibles() {
    std::vector<Position> coupsPossibles;

    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            Position destination{pionSelectionne.x + i, pionSelectionne.y + j};

            if (PeutDeplacerEnDiagonale(pionSelectionne, destination)) {
                coupsPossibles.push_back(destination);
            }

            AjouterCapturesPossibles(pionSelectionne, coupsPossibles);
        }
    }

    return coupsPossibles;
}

bool JeuDames::PeutDeplacerEnDiagonale(const Position& depart, const Position& arrivee) const {
    if (arrivee.x < 0 || arrivee.x >= grille->getNbLignes() || arrivee.y < 0 || arrivee.y >= grille->getNbColonnes()) {
        return false;
    }

    const Jeton jetonAdverse = (joueurCourant == joueur1) ? joueur2->getJeton() : joueur1->getJeton();

    if (grille->ACaseVide(arrivee.x, arrivee.y) &&
        std::abs(arrivee.x - depart.x) == 1 &&
        std::abs(arrivee.y - depart.y) == 1) {
        return true;
    } else if (grille->ACaseVide(arrivee.x, arrivee.y) &&
               std::abs(arrivee.x - depart.x) == 1 &&
               std::abs(arrivee.y - depart.y) == 1 &&
               grille->GetCellule(arrivee.x, arrivee.y) == Jeton::Vide) {
        return true;
    } else if (grille->ACaseVide(arrivee.x, arrivee.y) &&
               grille->GetCellule((depart.x + arrivee.x) / 2, (depart.y + arrivee.y) / 2) == jetonAdverse &&
               std::abs(arrivee.x - depart.x) == 2 &&
               std::abs(arrivee.y - depart.y) == 2) {
        int xCapture = (depart.x + arrivee.x) / 2;
        int yCapture = (depart.y + arrivee.y) / 2;
        return PeutDeplacerEnDiagonale(arrivee, {xCapture, yCapture});
    }

    return false;
}

void JeuDames::AjouterCapturesPossibles(const Position& position, std::vector<Position>& coupsPossibles) const {
    const Jeton jetonCourant = joueurCourant->getJeton();

    if (PeutCapturer(position, {position.x - 1, position.y - 1})) {
        coupsPossibles.push_back({position.x - 2, position.y - 2});
    }
    if (PeutCapturer(position, {position.x - 1, position.y + 1})) {
        coupsPossibles.push_back({position.x - 2, position.y + 2});
    }
    if (PeutCapturer(position, {position.x + 1, position.y - 1})) {
        coupsPossibles.push_back({position.x + 2, position.y - 2});
    }
    if (PeutCapturer(position, {position.x + 1, position.y + 1})) {
        coupsPossibles.push_back({position.x + 2, position.y + 2});
    }
}

void JeuDames::AfficherResultat() const {
    modeAffichage->AfficherMessage("Match nul !");
}

void JeuDames::DeplacerPiece(const Position& depart, const Position& arrivee) {
    grille->ChangeCellule(arrivee.x, arrivee.y, joueurCourant->getJeton());
    grille->ChangeCellule(depart.x, depart.y, Jeton::Vide);
}

bool JeuDames::EstDeplacementValide(const Position& depart, const Position& arrivee) const {
    if (grille->GetCellule(arrivee.x, arrivee.y) != Jeton::Vide) {
        return false;
    }

    int deltaX = std::abs(arrivee.x - depart.x);
    int deltaY = std::abs(arrivee.y - depart.y);
    if (deltaX != 1 || deltaY != 1) {
        return false;
    }

    return true;
}

void JeuDames::CapturerPiece(const Position& depart, const Position& arrivee) {
    if (EstDeplacementValide(depart, arrivee)) {
        grille->ChangeCellule(arrivee.x, arrivee.y, joueurCourant->getJeton());
        int xCapture = (depart.x + arrivee.x) / 2;
        int yCapture = (depart.y + arrivee.y) / 2;
        grille->ChangeCellule(xCapture, yCapture, Jeton::Vide);
        positionsJoueurs[joueurCourant] = arrivee;
    }
}

bool JeuDames::PeutCapturer(const Position& position, const Position& adversaire) const {
    const Jeton jetonCourant = joueurCourant->getJeton();

    return (adversaire.x >= 0 && adversaire.x < grille->getNbLignes() &&
            adversaire.y >= 0 && adversaire.y < grille->getNbColonnes() &&
            grille->ACaseVide(adversaire.x, adversaire.y) &&
            grille->GetCellule(adversaire.x, adversaire.y) != jetonCourant &&
            grille->ACaseVide(position.x - (position.x - adversaire.x) / 2, position.y - (position.y - adversaire.y) / 2) &&
            grille->GetCellule(position.x - (position.x - adversaire.x) / 2, position.y - (position.y - adversaire.y) / 2) == Jeton::Vide);
}
