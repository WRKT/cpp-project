#ifndef IAFFICHAGE_H
#define IAFFICHAGE_H

#include <memory>
#include <string>
#include <vector>
#include "AGrille.h"
#include "coordonnees.h"

class IAffichage
{
public:
    virtual void AfficherGrille(const std::shared_ptr<AGrille>&) = 0;
    virtual void AfficherMessage(const std::string&, const int = 1) const = 0;
    virtual void AfficherErreur(const std::string&) const = 0;
    virtual void AfficherCoupsPossibles(const std::vector<Position>&, const std::string& = "Coups possibles : ") const = 0;
    virtual void MettreAJourGrille(const std::shared_ptr<AGrille>& grille) = 0;

    inline static bool enabled = true;
};


#endif // IAFFICHAGE_H
