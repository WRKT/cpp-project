#include "jeudames.h"
#include <vector>
#include <algorithm>
#include <set>

void JeuDames::Tour()
{
    while (true)
    {
        std::vector<Position> pionsJouables = PionsJouables();
        if (pionsJouables.empty())
        {
            modeAffichage->AfficherErreur("Pas de jeton jouable");
            return;
        }
        else
        {
            AfficherPionsJouables(pionsJouables);
            Position pionChoisi = joueurCourant->ChoisirCoordonnees(pionsJouables);
            pionSelectionne = pionChoisi;
            if (EstPionValide(pionChoisi, pionsJouables))
            {
                std::vector<Position> coupsPossibles = CoupsPossibles();
                AfficherDeplacements(coupsPossibles);
                Position coupChoisi = joueurCourant->ChoisirCoordonnees(coupsPossibles);
                if (EstCoupValide(coupChoisi, coupsPossibles))
                {
                    DeplacerPiece(pionSelectionne, coupChoisi);
                    modeAffichage->MettreAJourGrille(grille);

                    break;
                }
                else
                {
                    modeAffichage->AfficherErreur("Coup impossible pour le pion choisi");
                }
            }
            else
            {
                modeAffichage->AfficherErreur("Pion choisi n'est pas valide");
            }
        }
    }
}

bool JeuDames::AGagne() const
{
    std::vector<Jeton> liste1 = joueur1->GetListeJeton();
    std::vector<Jeton> liste2 = joueur2->GetListeJeton();
    return (grille->CompteJetons(liste1[0]) == 0 && grille->CompteJetons(liste1[1]) == 0) || (grille->CompteJetons(liste2[0]) == 0 && grille->CompteJetons(liste2[1]) == 0);
}

bool JeuDames::PartieFinie() const
{
    return AGagne();
}

void JeuDames::AfficherResultat() const
{
    std::vector<Jeton> liste1 = joueur1->GetListeJeton();
    std::vector<Jeton> liste2 = joueur2->GetListeJeton();
    int nbJetonJoueur1 = grille->CompteJetons(joueur1->getJeton()) + grille->CompteJetons(liste1[1]);
    int nbJetonJoueur2 = grille->CompteJetons(joueur2->getJeton()) + grille->CompteJetons(liste2[1]);
    if (nbJetonJoueur1 > nbJetonJoueur2)
    {
        modeAffichage->AfficherMessage("Le gagnant est " + joueur1->getInformations() + " !");
    }
    else if (nbJetonJoueur2 > nbJetonJoueur1)
    {
        modeAffichage->AfficherMessage("Le gagnant est " + joueur2->getInformations() + " !");
    }
    else
    {
        modeAffichage->AfficherMessage("Match Nul!");
    }
}

void JeuDames::AfficherPionsJouables(const std::vector<Position> &pionsJouables)
{
    modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations(), 2);
    modeAffichage->AfficherCoupsPossibles(pionsJouables, "Pions jouables : ");
}

bool JeuDames::EstPionValide(const Position &pionChoisi, const std::vector<Position> &pionsJouables) const
{
    return std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end();
}

void JeuDames::AfficherDeplacements(const std::vector<Position> &coupsPossibles) const
{
    modeAffichage->AfficherMessage("");
    modeAffichage->AfficherCoupsPossibles(coupsPossibles, "Deplacement possible du pion : ");
}

bool JeuDames::EstCoupValide(const Position &coupChoisi, const std::vector<Position> &coupsPossibles) const
{
    return std::find(coupsPossibles.begin(), coupsPossibles.end(), coupChoisi) != coupsPossibles.end();
}

std::vector<Position> JeuDames::CoupsPossibles()
{
    std::vector<Position> coupsPossibles;
    int direction = (joueurCourant == joueur1) ? -1 : 1;
    AjouterCapturesPossibles(pionSelectionne, coupsPossibles);
    if (!coupsPossibles.empty())
    {
        return coupsPossibles;
    }
    Jeton jetonActuel = grille->GetCellule(pionSelectionne.x, pionSelectionne.y);
    if (jetonActuel == Jeton::DameX || jetonActuel == Jeton::DameO)
    {
        coupsPossibles = CoupsPossiblesDame(pionSelectionne);
    }
    else
    {
        for (int j = -1; j <= 1; j += 2)
        {
            Position destination{pionSelectionne.x + direction, pionSelectionne.y + j};
            if (PeutDeplacer(pionSelectionne, destination))
            {
                coupsPossibles.push_back(destination);
            }
        }
    }
    return coupsPossibles;
}

std::vector<Position> JeuDames::CoupsPossiblesDame(const Position &positionDame)
{
    std::vector<Position> coupsPossibles;
    const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const auto &direction : directions)
    {
        Position courant = positionDame;
        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
        while (grille->EstDansGrille(courant.x, courant.y) && PeutDeplacerDame(courant))
        {
            coupsPossibles.push_back(courant);
            courant.x += direction.deltaX;
            courant.y += direction.deltaY;
        }
    }
    return coupsPossibles;
}

bool JeuDames::PeutCapturerDame(const Position &depart, const Direction &direction) const
{
    if (std::abs(direction.deltaX) != std::abs(direction.deltaY))
    {
        return false;
    }

    Position courant = depart;
    courant.x += direction.deltaX;
    courant.y += direction.deltaY;

    while (grille->EstDansGrille(courant.x, courant.y))
    {
        Jeton jetonCourant = grille->GetCellule(courant.x, courant.y);

        if (EstJetonAdverse(jetonCourant))
        {
            courant.x += direction.deltaX;
            courant.y += direction.deltaY;

            if (grille->EstDansGrille(courant.x, courant.y) && grille->ACaseVide(courant.x, courant.y))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (jetonCourant != Jeton::Vide)
        {
            return false;
        }
        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
    }
    return false;
}

std::vector<Position> JeuDames::PionsJouables()
{
    std::vector<Position> pionsJouables = TrouverPionsCapturables();

    if (pionsJouables.empty())
    {
        pionsJouables = TrouverPionsDeplacables();
    }

    return pionsJouables;
}

std::vector<Position> JeuDames::TrouverPionsCapturables()
{
    std::vector<Position> pionsCapturables;
    const std::vector<Direction> toutesDirections = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<Jeton> listeJetonsJoueur = joueurCourant->GetListeJeton();

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne)
    {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne)
        {
            Jeton jetonCourant = grille->GetCellule(ligne, colonne);
            if (std::find(listeJetonsJoueur.begin(), listeJetonsJoueur.end(), jetonCourant) != listeJetonsJoueur.end())
            {
                Position position{ligne, colonne};
                for (const Direction &direction : toutesDirections)
                {
                    bool capture = (jetonCourant == listeJetonsJoueur[0] ? PeutCapturer(position, direction) : PeutCapturerDame(position, direction));
                    if (capture)
                    {
                        pionsCapturables.push_back(position);
                        break;
                    }
                }
            }
        }
    }

    return pionsCapturables;
}

std::vector<Position> JeuDames::TrouverPionsDeplacables()
{
    std::vector<Position> pionsDeplacables;
    const std::vector<Direction> toutesDirections = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<Jeton> listeJetonsJoueur = joueurCourant->GetListeJeton();

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne)
    {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne)
        {
            Jeton jetonCourant = grille->GetCellule(ligne, colonne);
            if (std::find(listeJetonsJoueur.begin(), listeJetonsJoueur.end(), jetonCourant) != listeJetonsJoueur.end())
            {
                Position position{ligne, colonne};
                for (const Direction &direction : toutesDirections)
                {
                    bool deplacement = (jetonCourant == listeJetonsJoueur[0] ? PeutDeplacer(position, {ligne + direction.deltaX, colonne + direction.deltaY}) : PeutDeplacerDame(position));
                    if (deplacement)
                    {
                        pionsDeplacables.push_back(position);
                        break;
                    }
                }
            }
        }
    }

    return pionsDeplacables;
}

bool JeuDames::PeutDeplacerDame(const Position &position) const
{
    const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const auto &direction : directions)
    {
        Position courant = position;
        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
        bool caseVideTrouvee = false;

        while (grille->EstDansGrille(courant.x, courant.y))
        {
            Jeton jetonCourant = grille->GetCellule(courant.x, courant.y);
            if (jetonCourant != Jeton::Vide)
            {
                break;
            }
            caseVideTrouvee = true;

            courant.x += direction.deltaX;
            courant.y += direction.deltaY;
        }
        if (caseVideTrouvee) {
            return true;
        }
    }
    return false;
}

bool JeuDames::PeutDeplacer(const Position &depart, const Position &arrivee) const
{
    if (!grille->EstDansGrille(arrivee.x, arrivee.y))
    {
        return false;
    }
    int direction = (joueurCourant == joueur1) ? -1 : 1;
    return grille->ACaseVide(arrivee.x, arrivee.y) && (arrivee.x - depart.x) == direction;
}

bool JeuDames::PeutCapturer(const Position &position, const Direction &direction) const
{
    Position adversaire = {position.x + direction.deltaX, position.y + direction.deltaY};
    Position destination = {adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

    if (!grille->EstDansGrille(adversaire.x, adversaire.y) || !grille->EstDansGrille(destination.x, destination.y))
    {
        return false;
    }

    Jeton jetonAdversaire = grille->GetCellule(adversaire.x, adversaire.y);
    return EstJetonAdverse(jetonAdversaire) && grille->ACaseVide(destination.x, destination.y);
}

void JeuDames::AjouterCapturesPossibles(const Position &position, std::vector<Position> &coupsPossibles) const
{
    Jeton jetonCourant = grille->GetCellule(position.x, position.y);
    const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    if (jetonCourant == Jeton::DameX || jetonCourant == Jeton::DameO)
    {
        for (const auto &direction : directions)
        {
            if (PeutCapturerDame(position, direction))
            {
                std::vector<Position> positionsCapture = CalculerPositionsCaptureDame(position, direction);
                for (const auto &posCapture : positionsCapture)
                {
                    coupsPossibles.push_back(posCapture);
                }
            }
        }
    }
    else
    {
        for (const auto &direction : directions)
        {
            if (PeutCapturer(position, direction))
            {
                Position positionCapture = {position.x + 2 * direction.deltaX, position.y + 2 * direction.deltaY};
                coupsPossibles.push_back(positionCapture);
            }
        }
    }
}
void JeuDames::DeplacerPiece(const Position &depart, const Position &arrivee)
{
    bool captureEffectuee = false;

    grille->ChangeCellule(arrivee.x, arrivee.y, grille->GetCellule(depart.x, depart.y));
    grille->ChangeCellule(depart.x, depart.y, Jeton::Vide);

    if (std::abs(arrivee.x - depart.x) > 1)
    {
        int stepX = (arrivee.x - depart.x > 0) ? 1 : -1;
        int stepY = (arrivee.y - depart.y > 0) ? 1 : -1;
        Position capturePos = depart;

        while (capturePos.x != arrivee.x && capturePos.y != arrivee.y)
        {
            capturePos.x += stepX;
            capturePos.y += stepY;

            if (EstJetonAdverse(grille->GetCellule(capturePos.x, capturePos.y)))
            {
                grille->ChangeCellule(capturePos.x, capturePos.y, Jeton::Vide);
                captureEffectuee = true;
            }
        }
        if (captureEffectuee)
        {
            EffectuerCapturesMultiples(arrivee);
        }
    }

    VerifierPromotionDame(arrivee);
}

std::vector<Position> JeuDames::CapturesPossiblesDepuisPosition(const Position &position, const Direction &direction, const std::set<Position> &jetonsCaptures) const
{
    std::vector<Position> capturesPossibles;
    Position courant = position;

    // Logique pour la dame
    if (grille->GetCellule(courant.x, courant.y) == Jeton::DameX || grille->GetCellule(courant.x, courant.y) == Jeton::DameO)
    {
        if (PeutCapturerDame(position, direction))
        {
            bool captureEffectuee = false;
            courant.x += direction.deltaX;
            courant.y += direction.deltaY;

            while (grille->EstDansGrille(courant.x, courant.y))
            {
                Jeton jetonCourant = grille->GetCellule(courant.x, courant.y);

                if (jetonCourant != Jeton::Vide && !captureEffectuee)
                {
                    if (EstJetonAdverse(jetonCourant) && jetonsCaptures.find({courant.x, courant.y}) == jetonsCaptures.end())
                    {
                        captureEffectuee = true;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (jetonCourant == Jeton::Vide && captureEffectuee)
                {
                    capturesPossibles.push_back(courant);
                    break;
                }

                courant.x += direction.deltaX;
                courant.y += direction.deltaY;
            }
        }
    }
    else
    {
        Position adversaire = {courant.x + direction.deltaX, courant.y + direction.deltaY};
        Position destination = {adversaire.x + direction.deltaX, adversaire.y + direction.deltaY};

        if (PeutCapturer(courant, direction) && jetonsCaptures.find(adversaire) == jetonsCaptures.end())
        {
            capturesPossibles.push_back(destination);
        }
    }

    return capturesPossibles;
}

void JeuDames::EffectuerCapturesMultiples(const Position &positionInitiale)
{
    std::set<Position> jetonsCaptures;
    Jeton jetonCourant = grille->GetCellule(positionInitiale.x, positionInitiale.y);
    Position positionCourante = positionInitiale;
    bool capturePossible = true;

    while (capturePossible)
    {
        capturePossible = false;
        std::vector<Position> toutesCapturesPossibles;

        const std::vector<Direction> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        for (const auto &direction : directions)
        {
            auto captures = CapturesPossiblesDepuisPosition(positionCourante, direction, jetonsCaptures);
            for (const auto &capture : captures)
            {
                if (jetonsCaptures.find(capture) == jetonsCaptures.end())
                {
                    toutesCapturesPossibles.push_back(capture);
                }
            }
        }

        if (!toutesCapturesPossibles.empty())
        {
            Position captureChoisie;
            bool choixValide = false;
            while (!choixValide)
            {
                captureChoisie = joueurCourant->ChoisirCoordonnees(toutesCapturesPossibles);
                choixValide = std::find(toutesCapturesPossibles.begin(), toutesCapturesPossibles.end(), captureChoisie) != toutesCapturesPossibles.end();
                if (!choixValide)
                {
                    modeAffichage->AfficherErreur("Choix invalide, veuillez réessayer.");
                    modeAffichage->MettreAJourGrille(grille);
                }
            }

            jetonsCaptures.insert(captureChoisie);
            DeplacerPiece(positionCourante, captureChoisie);
            positionCourante = captureChoisie;

            capturePossible = true;
            for (const auto &direction : directions)
            {
                auto nouvellesCaptures = CapturesPossiblesDepuisPosition(positionCourante, direction, jetonsCaptures);
                for (const auto &nouvelleCapture : nouvellesCaptures)
                {
                    if (jetonsCaptures.find(nouvelleCapture) == jetonsCaptures.end())
                    {
                        capturePossible = false;
                        break;
                    }
                }
                if (!capturePossible)
                    break;
            }
        }
    }
}

bool JeuDames::EstJetonAdverse(const Jeton &jeton) const
{
    std::vector<Jeton> jetonsAdverses = GetJetonAdverse();
    return std::find(jetonsAdverses.begin(), jetonsAdverses.end(), jeton) != jetonsAdverses.end();
}

std::vector<Position> JeuDames::CalculerPositionsCaptureDame(const Position &positionDame, const Direction &direction) const
{
    std::vector<Position> positionsCapture;
    Position courant = positionDame;
    bool adversaireTrouve = false;

    courant.x += direction.deltaX;
    courant.y += direction.deltaY;

    while (grille->EstDansGrille(courant.x, courant.y))
    {
        Jeton jetonCourant = grille->GetCellule(courant.x, courant.y);

        if (jetonCourant != Jeton::Vide && !adversaireTrouve)
        {
            if (EstJetonAdverse(jetonCourant))
            {
                adversaireTrouve = true;
            }
            else
            {
                break;
            }
        }
        else if (jetonCourant == Jeton::Vide && adversaireTrouve)
        {
            positionsCapture.push_back(courant);
        }

        courant.x += direction.deltaX;
        courant.y += direction.deltaY;
    }

    return positionsCapture;
}

std::vector<Jeton> JeuDames::GetJetonAdverse() const
{
    if (joueurCourant == joueur1)
    {
        return {Jeton::O, Jeton::DameO};
    }
    else
    {
        return {Jeton::X, Jeton::DameX};
    }
}

void JeuDames::VerifierPromotionDame(const Position &position)
{
    if ((joueurCourant == joueur1 && position.x == 0) || (joueurCourant == joueur2 && position.x == grille->getNbLignes() - 1))
    {
        grille->PromouvoirJeton(position);
    }
}
