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
    while (true) {
        std::vector<Position> pionsJouables = PionsJouables();
        AfficherTourEtPions(pionsJouables);

        Position pionChoisi = joueurCourant->ChoisirCoupDames(pionsJouables);
        pionSelectionne = pionChoisi;

        if (EstPionChoisiValide(pionChoisi, pionsJouables)) {
            std::vector<Position> coupsPossibles = CoupsPossibles();
            AfficherCoupsPossibles(coupsPossibles);

            Position coupChoisi = joueurCourant->ChoisirCoupDames(coupsPossibles);

            if (EstCoupChoisiValide(coupChoisi, coupsPossibles)) {
                DeplacerPiece(pionSelectionne, coupChoisi);
                break;
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
    return grille->CompteJetons(joueur1->getJeton()) == 0 || grille->CompteJetons(joueur2->getJeton()) == 0;
}

bool JeuDames::PartieFinie() const {
    return AGagne(); // RAJOUTER ICI, QUAND DEPLACEMENT impossible ?
}

void JeuDames::AfficherResultat() const {
    int nbJetonJoueur1 = grille->CompteJetons(joueur1->getJeton());
    int nbJetonJoueur2 = grille->CompteJetons(joueur2->getJeton());

    if(nbJetonJoueur1 > nbJetonJoueur2)
    {
        modeAffichage->AfficherMessage("Le gagnant est " +  joueur1->getInformations() + " !");
    }
    else if (nbJetonJoueur2 > nbJetonJoueur1)
    {
        modeAffichage->AfficherMessage("Le gagnant est " +  joueur2->getInformations() + " !");
    }
    else
    {
        modeAffichage->AfficherMessage("Match Nul!");
    }
}

void JeuDames::AfficherPionsJouables(const std::vector<Position>& pionsJouables) {
    modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations(), 2);
    modeAffichage->AfficherCoupsPossibles(pionsJouables, "Pions jouables : ");
}

bool JeuDames::EstPionChoisiValide(const Position& pionChoisi, const std::vector<Position>& pionsJouables) const {
    return std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end();
}

void JeuDames::AfficherDeplacementsPions(const std::vector<Position>& coupsPossibles) const {
    modeAffichage->AfficherMessage("");
    modeAffichage->AfficherCoupsPossibles(coupsPossibles, "Deplacement possible du pion : ");
}

bool JeuDames::EstCoupChoisiValide(const Position& coupChoisi, const std::vector<Position>& coupsPossibles) const {
    return std::find(coupsPossibles.begin(), coupsPossibles.end(), coupChoisi) != coupsPossibles.end();
}

std::vector<Position> JeuDames::CoupsPossibles() {
    std::vector<Position> coupsPossibles;
    int direction = (joueurCourant == joueur1) ? -1 : 1;

    AjouterCapturesPossibles(pionSelectionne, coupsPossibles);

    if (!coupsPossibles.empty()) {
        return coupsPossibles;
    }

    for (int j = -1; j <= 1; j += 2) {
        Position destination{pionSelectionne.x + direction, pionSelectionne.y + j};
        if (PeutDeplacerEnDiagonale(pionSelectionne, destination)) {
            coupsPossibles.push_back(destination);
        }
    }

    return coupsPossibles;
}

std::vector<Position> JeuDames::PionsJouables() {
    std::vector<Position> pionsJouables;
    const std::vector<Direction> toutesDirections = {{ -1, -1 }, { -1, 1 }, { 1, -1 },{ 1, 1 }};
    bool capturable = false;

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
            if (grille->GetCellule(ligne, colonne) == joueurCourant->getJeton()) {
                Position position{ligne, colonne};
                for (const Direction& direction : toutesDirections) {
                    if (PeutCapturer(position, direction))
                    {
                        pionsJouables.push_back(position);
                        capturable = true;
                        break;
                    }
                }
            }
        }
    }

    if (!capturable) {
        for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
            for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
                if (grille->GetCellule(ligne, colonne) == joueurCourant->getJeton()) {
                    Position position{ligne, colonne};

                    for (const Direction& direction : toutesDirections) {
                        if (PeutDeplacerEnDiagonale(position, {ligne + direction.deltaX, colonne + direction.deltaY})) {
                            pionsJouables.push_back(position);
                            break;
                        }
                    }
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


bool JeuDames::PeutCapturer(const Position& position, const Direction& direction) const {
    Position adversaire = {position.x + direction.deltaX, position.y + direction.deltaY};
    Position destination = {adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

    if (!grille->EstDansGrille(destination.x, destination.y) ||
        grille->GetCellule(adversaire.x, adversaire.y) != GetJetonAdverse()) {
        return false;
    }

    return grille->ACaseVide(destination.x, destination.y);
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

void JeuDames::DeplacerPiece(const Position& depart, const Position& arrivee) {
    grille->ChangeCellule(arrivee.x, arrivee.y, joueurCourant->getJeton());
    grille->ChangeCellule(depart.x, depart.y, Jeton::Vide);

    if (std::abs(arrivee.x - depart.x) == 2) {
        Position capturePos{(depart.x + arrivee.x) / 2, (depart.y + arrivee.y) / 2};
        grille->ChangeCellule(capturePos.x, capturePos.y, Jeton::Vide);
    }
}

Jeton JeuDames::GetJetonAdverse() const {
    return (joueurCourant == joueur1) ? joueur2->getJeton() : joueur1->getJeton();
}
