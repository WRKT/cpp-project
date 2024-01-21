#include "jeuothello.h"
#include <algorithm>
#include <vector>

JeuOthello::JeuOthello(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuOthello::Jouer() {
    grille->InitialiserGrilleOthello();
    modeAffichage->AfficherGrille(grille);
    while (!PartieFinie()) {
        Tour();
        joueurCourant = (joueurCourant == joueur1) ? joueur2 : joueur1;
        modeAffichage->MettreAJourGrille(grille);
    }

    AfficherResultat();
}

void JeuOthello::Tour() {
    std::vector<Position> coupsPossibles = CoupsPossibles();
    bool coupValide = false;

    modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
    modeAffichage->AfficherCoupsPossibles(coupsPossibles);

    if (coupsPossibles.empty()) {
        modeAffichage->AfficherMessage("Aucun coup possible pour " + joueurCourant->getInformations() + ". Passage au joueur suivant.");
        bloque++;
        return;
    }

    while (!coupValide) {
        const Position& coup = joueurCourant->ChoisirCoupOthello(coupsPossibles);

        if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end()) {
            grille->ChangeCellule(coup.x, coup.y, joueurCourant->getJeton());
            RetournerJetons(coup, joueurCourant->getJeton());
            coupValide = true;
            bloque = 0;
        } else {
            modeAffichage->AfficherErreur("Coup impossible.");
        }
    }
}

bool JeuOthello::PartieFinie() const {
    return grille->EstRemplie() || bloque == 2;
}

bool JeuOthello::AGagne() const {
    Jeton gagnant = DetermineGagnant();
    return gagnant == joueur1->getJeton() || gagnant == joueur2->getJeton();
}

void JeuOthello::AfficherResultat() const {
    modeAffichage->AfficherMessage("--> Score : ");
    modeAffichage->AfficherMessage(joueur1->getInformations() + ": " + std::to_string(grille->CompteJetons(joueur1->getJeton())));
    modeAffichage->AfficherMessage(joueur2->getInformations() + ": " + std::to_string(grille->CompteJetons(joueur2->getJeton())));

    if (AGagne()) {
        modeAffichage->AfficherMessage("Le gagnant est " + (DetermineGagnant() == joueur1->getJeton() ? joueur1->getInformations() : joueur2->getInformations()) + " !");
    } else {
        modeAffichage->AfficherMessage("Match Nul!");
    }
}

std::vector<Position> JeuOthello::CoupsPossibles() {
    std::vector<Position> coupsPossibles;

    for (int ligne = 0; ligne < grille->getNbLignes(); ligne++) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); colonne++) {
            Position position{ligne, colonne};
            if (EstCoupValide(position, joueurCourant->getJeton())) {
                coupsPossibles.emplace_back(position);
            }
        }
    }

    return coupsPossibles;
}

void JeuOthello::RetournerJetons(const Position& position, const Jeton& jeton) {
    for (int directionX = -1; directionX <= 1; ++directionX) {
        for (int directionY = -1; directionY <= 1; ++directionY) {
            if (directionX == 0 && directionY == 0)
                continue;

            RetournerJetonsDansDirection(position, {directionX, directionY}, jeton);
        }
    }
}

void JeuOthello::RetournerJetonsDansDirection(const Position& position, const Direction& direction, const Jeton& jeton) {

    Position positionActuel = position;
    positionActuel.x += direction.deltaX;
    positionActuel.y += direction.deltaY;

    if (PeutRetourner(position, direction, jeton)) {
        while (grille->GetCellule(positionActuel.x, positionActuel.y) != jeton) {
            grille->ChangeCellule(positionActuel.x, positionActuel.y, jeton);
            positionActuel.x += direction.deltaX;
            positionActuel.y += direction.deltaY;
        }
    }
}

bool JeuOthello::PeutRetourner(const Position& position, const Direction& direction, const Jeton& jeton) const {
    Position positionActuel = position;
    positionActuel.x += direction.deltaX;
    positionActuel.y += direction.deltaY;

    if (positionActuel.x < 0 || positionActuel.x >= grille->getNbLignes() || positionActuel.y < 0 || positionActuel.y >= grille->getNbColonnes()) {
        return false;
    }

    Jeton jetonAdverse = (jeton == Jeton::X) ? Jeton::O : Jeton::X;

    if (grille->GetCellule(positionActuel.x, positionActuel.y) != jetonAdverse) {
        return false;
    }

    while (positionActuel.x >= 0 && positionActuel.x < grille->getNbLignes() && positionActuel.y >= 0 && positionActuel.y < grille->getNbColonnes()) {
        Jeton jetonActuel = grille->GetCellule(positionActuel.x, positionActuel.y);

        if (jetonActuel == Jeton::Vide) {
            return false;
        } else if (jetonActuel == jeton) {
            return true;
        }

        positionActuel.x += direction.deltaX;
        positionActuel.y += direction.deltaY;
    }

    return false;
}

bool JeuOthello::EstCoupValide(const Position& position, const Jeton& jeton) const {
    if (position.x < 0 || position.x >= grille->getNbLignes() || position.y < 0 || position.y >= grille->getNbColonnes() || grille->GetCellule(position.x, position.y) != Jeton::Vide) {
        return false;
    }

    for (int directionX = -1; directionX <= 1; ++directionX) {
        for (int directionY = -1; directionY <= 1; ++directionY) {
            if (directionX == 0 && directionY == 0) {
                continue;
            }

            if (PeutRetourner(position, {directionX, directionY}, jeton)) {
                return true;
            }
        }
    }

    return false;
}

Jeton JeuOthello::DetermineGagnant() const {
    int countNoir = grille->CompteJetons(Jeton::X);
    int countBlanc = grille->CompteJetons(Jeton::O);

    if (countNoir > countBlanc) {
        return Jeton::X;
    } else if (countBlanc > countNoir) {
        return Jeton::O;
    } else {
        return Jeton::Vide;
    }
}
