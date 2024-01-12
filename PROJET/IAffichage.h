#ifndef IAFFICHAGE_H
#define IAFFICHAGE_H

#include <memory>
#include <string>
#include <vector>
#include "AGrille.h"

class IAffichage
{
public:
    virtual void AfficherGrille(const std::shared_ptr<AGrille>&) const = 0;
    virtual void AfficherMessage(const std::string&, const int = 1) const = 0;
    virtual void AfficherErreur(const std::string&) const = 0;
    virtual void AfficherCoupsPossibles(const std::vector<std::pair<int, int>>&) const = 0;

    inline static bool enabled = true;
};


#endif // IAFFICHAGE_H
