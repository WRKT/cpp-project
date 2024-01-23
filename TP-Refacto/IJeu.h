#ifndef IJEU_H
#define IJEU_H

#include <vector>
#include "coordonnees.h"
#include "AGrille.h"
#include "AJoueur.h"
#include "ISauvegarder.h"
#include "IAffichage.h"
#include "TypesJeu.h"
#include <QJsonArray>

class IJeu : public ISauvegarder
{
public:
    IJeu(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage);
    virtual void Jouer();
    virtual void Tour() = 0;
    virtual std::vector<Position> CoupsPossibles() = 0;
    virtual bool AGagne() const = 0;
    virtual bool PartieFinie() const = 0;
    virtual void AfficherResultat() const = 0;
    virtual TypesJeu getType() const = 0;
    virtual void Sauvegarder() const override;
    virtual void Charger(const QJsonArray &grilleData, const QString& nomJoueurCourant )  override;
    virtual ~IJeu() = default;

protected:
    std::shared_ptr<AGrille> grille;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<AJoueur> joueurCourant;
    std::shared_ptr<IAffichage> modeAffichage;
};

#endif // IJEU_H
