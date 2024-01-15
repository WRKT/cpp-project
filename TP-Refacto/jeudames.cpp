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
    // A CLEAN, METHODE TROP LONGUE
    bool coupJouable = false;

    while (!coupJouable) {
        std::vector<Position> pionsJouables = PionsJouables();
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations(),2);

        modeAffichage->AfficherCoupsPossibles(pionsJouables, "Pions jouables : ");

        Position pionChoisi = joueurCourant->ChoisirCoupDames(pionsJouables);
        pionSelectionne = pionChoisi;

        if (std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end()) {
            std::vector<Position> coupsPossibles = CoupsPossibles();

            modeAffichage->AfficherMessage("");
            modeAffichage->AfficherCoupsPossibles(coupsPossibles, "Deplacement possible du pion : ");

            Position coupChoisi = joueurCourant->ChoisirCoupDames(coupsPossibles);

            for (const Position& coups : coupsPossibles)
            {
                if (coups == coupChoisi) {
                    this->DeplacerPiece(pionSelectionne, coupChoisi);
                    coupJouable = true;
                } else {
                    // PETIT BUG ICI : Je rentre toujours dans la condition
                    modeAffichage->AfficherErreur("Coup impossible pour le pion choisi");
                }
            }
        }
        else {
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

                // A CLEAN, METHODE TROP LONGUE
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

bool JeuDames::PeutDeplacerEnDiagonale(const Position& depart, const Position& arrivee) const {
    if (!grille->EstDansGrille(arrivee.x, arrivee.y)) {
        return false;
    }

    int direction = (joueurCourant == joueur1) ? -1 : 1;
    return grille->ACaseVide(arrivee.x, arrivee.y) && (arrivee.x - depart.x) == direction;
}

std::vector<Position> JeuDames::CoupsPossibles() {
    std::vector<Position> coupsPossibles;
    int direction = (joueurCourant == joueur1) ? -1 : 1;

    for (int j = -1; j <= 1; j += 2) {
        Position destination{pionSelectionne.x + direction, pionSelectionne.y + j};
        if (PeutDeplacerEnDiagonale(pionSelectionne, destination)) {
            coupsPossibles.push_back(destination);
        }
    }

    AjouterCapturesPossibles(pionSelectionne, coupsPossibles);

    return coupsPossibles;
}
bool JeuDames::PeutCapturer(const Position& position, const Direction& direction) const {
    Position adversaire{position.x + direction.deltaX, position.y + direction.deltaY};
    Position destination{adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

    if (!grille->EstDansGrille(destination.x, destination.y) ||
        grille->GetCellule(adversaire.x, adversaire.y) != GetJetonAdverse()) {
        return false;
    }

    return grille->ACaseVide(destination.x, destination.y);
}

void JeuDames::DeplacerPiece(const Position& depart, const Position& arrivee) {
    grille->ChangeCellule(arrivee.x, arrivee.y, joueurCourant->getJeton());
    grille->ChangeCellule(depart.x, depart.y, Jeton::Vide);

    if (std::abs(arrivee.x - depart.x) == 2) {
        Position capturePos{(depart.x + arrivee.x) / 2, (depart.y + arrivee.y) / 2};
        grille->ChangeCellule(capturePos.x, capturePos.y, Jeton::Vide);
    }
}

void JeuDames::AjouterCapturesPossibles(const Position& position, std::vector<Position>& coupsPossibles) const {
    std::vector<Direction> directions =  {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (const Direction& dir : directions) {
        if (PeutCapturer(position, dir)) {
            Position destination{position.x + 2 * dir.deltaX, position.y + 2 * dir.deltaY};
            coupsPossibles.push_back(destination);
        }
    }
}

void JeuDames::AfficherResultat() const {
    modeAffichage->AfficherMessage("Match nul!");
}

Jeton JeuDames::GetJetonAdverse() const {
    return (joueurCourant == joueur1) ? joueur2->getJeton() : joueur1->getJeton();
}
