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
        AfficherPionsJouables(pionsJouables);

        Position pionChoisi = joueurCourant->ChoisirCoupDames(pionsJouables);
        pionSelectionne = pionChoisi;

        if (EstPionValide(pionChoisi, pionsJouables)) {
            std::vector<Position> coupsPossibles = CoupsPossibles();
            AfficherDeplacements(coupsPossibles);

            Position coupChoisi = joueurCourant->ChoisirCoupDames(coupsPossibles);

            if (EstCoupValide(coupChoisi, coupsPossibles)) {
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
    return (grille->CompteJetons(joueur1->getJeton()) == 0 && grille->CompteJetons(getPromotion(joueur1->getJeton()))== 0 )   || (grille->CompteJetons(joueur2->getJeton()) == 0  && grille->CompteJetons(getPromotion(joueur2->getJeton())) == 0) ;
}

bool JeuDames::PartieFinie() const {
    return AGagne();
}

void JeuDames::AfficherResultat() const {
    int nbJetonJoueur1 = grille->CompteJetons(joueur1->getJeton());
    int nbJetonJoueur2 = grille->CompteJetons(joueur2->getJeton());

    if (nbJetonJoueur1 > nbJetonJoueur2) {
        modeAffichage->AfficherMessage("Le gagnant est " +  joueur1->getInformations() + " !");
    } else if (nbJetonJoueur2 > nbJetonJoueur1) {
        modeAffichage->AfficherMessage("Le gagnant est " +  joueur2->getInformations() + " !");
    } else {
        modeAffichage->AfficherMessage("Match Nul!");
    }
}

void JeuDames::AfficherPionsJouables(const std::vector<Position>& pionsJouables) {
    modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations(), 2);
    modeAffichage->AfficherCoupsPossibles(pionsJouables, "Pions jouables : ");
}

bool JeuDames::EstPionValide(const Position& pionChoisi, const std::vector<Position>& pionsJouables) const {
    return std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end();
}

void JeuDames::AfficherDeplacements(const std::vector<Position>& coupsPossibles) const {
    modeAffichage->AfficherMessage("");
    modeAffichage->AfficherCoupsPossibles(coupsPossibles, "Deplacement possible du pion : ");
}

bool JeuDames::EstCoupValide(const Position& coupChoisi, const std::vector<Position>& coupsPossibles) const {
    return std::find(coupsPossibles.begin(), coupsPossibles.end(), coupChoisi) != coupsPossibles.end();
}

std::vector<Position> JeuDames::CoupsPossibles() {
    std::vector<Position> coupsPossibles;

    Jeton jetonActuel = grille->GetCellule(pionSelectionne.x, pionSelectionne.y);
    if (jetonActuel == Jeton::DameX || jetonActuel == Jeton::DameO) {
        coupsPossibles = CoupsPossiblesDame(pionSelectionne);
    } else {
        int direction = (joueurCourant == joueur1) ? -1 : 1;

        AjouterCapturesPossibles(pionSelectionne, coupsPossibles);

        if (!coupsPossibles.empty()) {
            return coupsPossibles;
        }

        for (int j = -1; j <= 1; j += 2) {
            Position destination{pionSelectionne.x + direction, pionSelectionne.y + j};
            if (grille->EstDansGrille(destination.x, destination.y) && PeutDeplacer(pionSelectionne)) {
                coupsPossibles.push_back(destination);
            }
        }
    }

    return coupsPossibles;
}


std::vector<Position> JeuDames::CoupsPossiblesDame(const Position& pion) {
    std::vector<Position> coupsPossibles;
    const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const auto& direction : directions) {
        Position courant = pion;
        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
        while (grille->EstDansGrille(courant.x, courant.y) && grille->ACaseVide(courant.x, courant.y)) {
            coupsPossibles.push_back(courant);
            courant.x += direction.deltaX;
            courant.y += direction.deltaY;
        }
    }

    return coupsPossibles;
}

bool JeuDames::PeutCapturerDame(const Position& depart,const Direction& direction) const {
    if (!grille->EstDansGrille(direction.deltaX, direction.deltaY)) {
        return false;
    }

    int dx = (direction.deltaX - depart.x) != 0 ? (direction.deltaX - depart.x) / std::abs(direction.deltaX - depart.x) : 0;
    int dy = (direction.deltaY - depart.y) != 0 ? (direction.deltaY - depart.y) / std::abs(direction.deltaY - depart.y) : 0;

    Position courant = depart;
    courant.x += dx;
    courant.y += dy;
    bool adversaireTrouve = false;

    while (courant.x != direction.deltaX || courant.y != direction.deltaY) {
        Jeton jetonCourant = grille->GetCellule(courant.x, courant.y);
        if (EstJetonAdverse(jetonCourant)) {
            if (adversaireTrouve) {
                return false;
            }
            adversaireTrouve = true;
        } else if (jetonCourant != Jeton::Vide) {
            return false;
        }
        courant.x += dx;
        courant.y += dy;
    }

    return adversaireTrouve && grille->ACaseVide(direction.deltaX, direction.deltaY);
}

std::vector<Position> JeuDames::PionsJouables() {
    std::vector<Position> pionsJouables;
    const std::vector<Direction> toutesDirections = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    bool capturable = false;

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
            Jeton jetonActuel = grille->GetCellule(ligne, colonne);
            if (jetonActuel == joueurCourant->getJeton() ||
                (joueurCourant == joueur1 && jetonActuel == Jeton::DameX) ||
                (joueurCourant == joueur2 && jetonActuel == Jeton::DameO)) {

                Position position{ligne, colonne};
                capturable = false;

                for (const Direction& direction : toutesDirections) {
                    if ((jetonActuel == Jeton::DameX || jetonActuel == Jeton::DameO)
                            ? PeutCapturerDame(position, direction)
                            : PeutCapturer(position, direction)) {
                        pionsJouables.push_back(position);
                        capturable = true;
                        break;
                    }
                }
                if (!capturable) {
                    if ((jetonActuel == Jeton::DameX || jetonActuel == Jeton::DameO)
                            ? PeutDeplacerDame(position)
                            : PeutDeplacer(position)) {
                        pionsJouables.push_back(position);
                    }
                }
            }
        }
    }

    return pionsJouables;
}

bool JeuDames::PeutDeplacer(const Position& position) const {
    int direction = (joueurCourant == joueur1) ? -1 : 1;

    Position destinationGauche = {position.x + direction, position.y - 1};
    if (grille->EstDansGrille(destinationGauche.x, destinationGauche.y) && grille->ACaseVide(destinationGauche.x, destinationGauche.y)) {
        return true;
    }

    Position destinationDroite = {position.x + direction, position.y + 1};
    if (grille->EstDansGrille(destinationDroite.x, destinationDroite.y) && grille->ACaseVide(destinationDroite.x, destinationDroite.y)) {
        return true;
    }

    return false;
}

bool JeuDames::PeutCapturer(const Position& position, const Direction& direction) const {
    Position adversaire = {position.x + direction.deltaX, position.y + direction.deltaY};
    Position destination = {adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

    if (!grille->EstDansGrille(adversaire.x, adversaire.y) || !grille->EstDansGrille(destination.x, destination.y) || !EstJetonAdverse(grille->GetCellule(adversaire.x, adversaire.y))) {
        return false;
    }

    return grille->ACaseVide(destination.x, destination.y);
}

void JeuDames::AjouterCapturesPossibles(const Position& position, std::vector<Position>& coupsPossibles) const {
    const std::vector<Direction> toutesDirections = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const Direction& direction : toutesDirections) {
        std::vector<Position> prisesPossibles = CapturesPossiblesDepuisPosition(position, direction, 1);
        coupsPossibles.insert(coupsPossibles.end(), prisesPossibles.begin(), prisesPossibles.end());
    }
}

void JeuDames::DeplacerPiece(const Position& depart, const Position& arrivee) {
    grille->ChangeCellule(arrivee.x, arrivee.y, grille->GetCellule(depart.x, depart.y));
    grille->ChangeCellule(depart.x, depart.y, Jeton::Vide);

    if (std::abs(arrivee.x - depart.x) == 2) {
        Position capturePos{(depart.x + arrivee.x) / 2, (depart.y + arrivee.y) / 2};
        grille->ChangeCellule(capturePos.x, capturePos.y, Jeton::Vide);
        EffectuerCapturesMultiples(arrivee);
    }
   VerifierPromotionDame(arrivee);
}

bool JeuDames::PeutDeplacerDame(const Position& position) const {
    const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const auto& direction : directions) {
        Position courant = position;
        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
        while (grille->EstDansGrille(courant.x, courant.y) && grille->ACaseVide(courant.x, courant.y)) {
            return true;
            courant.x += direction.deltaX;
            courant.y += direction.deltaY;
        }
    }

    return false;
}
void JeuDames::VerifierPromotionDame(const Position& position) {
    if ((joueurCourant == joueur1 && position.x == 0) || (joueurCourant == joueur2 && position.x == grille->getNbLignes() - 1)) {
        grille->PromouvoirJeton(position);
    }
}

std::vector<Position> JeuDames::CapturesPossiblesDepuisPosition(const Position& position, const Direction& direction, int nbCaptures) const {
    std::vector<Position> prisesPossibles;

    if (nbCaptures <= 0) {
        return prisesPossibles;
    }

    Position adversaire = {position.x + direction.deltaX, position.y + direction.deltaY};
    Position destination = {adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

    if (PeutCapturer(position, direction)) {
        prisesPossibles.push_back(destination);
        std::vector<Position> prisesSupplementaires = CapturesPossiblesDepuisPosition(destination, direction, nbCaptures - 1);
        prisesPossibles.insert(prisesPossibles.end(), prisesSupplementaires.begin(), prisesSupplementaires.end());
    }

    return prisesPossibles;
}

void JeuDames::EffectuerCapturesMultiples(const Position& position) {
    const std::vector<Direction> toutesDirections = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<Position> toutesLesPrises;

    for (const Direction& direction : toutesDirections) {
        std::vector<Position> prisesPossibles = CapturesPossiblesDepuisPosition(position, direction, 1);
        toutesLesPrises.insert(toutesLesPrises.end(), prisesPossibles.begin(), prisesPossibles.end());
    }

    if (!toutesLesPrises.empty()) {
        AfficherDeplacements(toutesLesPrises);

        while (!toutesLesPrises.empty()) {
            Position coupChoisi = joueurCourant->ChoisirCoupDames(toutesLesPrises);
            if (EstCoupValide(coupChoisi, toutesLesPrises)) {
                DeplacerPiece(position, coupChoisi);
                toutesLesPrises = CapturesPossiblesDepuisPosition(coupChoisi, Direction{0, 0}, 1);
                AfficherDeplacements(toutesLesPrises);
            } else {
                modeAffichage->AfficherErreur("Coup impossible pour la position actuelle");
                break;
            }
        }
    }
}

bool JeuDames::EstJetonAdverse(const Jeton& jeton) const {
    auto jetonsAdverses = GetJetonAdverse();
    return std::find(jetonsAdverses.begin(), jetonsAdverses.end(), jeton) != jetonsAdverses.end();
}

std::vector<Jeton> JeuDames::GetJetonAdverse() const {
    if (joueurCourant == joueur1) {
        return {Jeton::O, Jeton::DameO};
    } else {
        return {Jeton::X, Jeton::DameX};
    }
}

Jeton JeuDames::getPromotion(const Jeton& jeton) const {
    return jeton == Jeton::X ? Jeton::DameX : Jeton::DameO;
}
