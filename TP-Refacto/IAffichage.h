#ifndef IAFFICHAGE_H
#define IAFFICHAGE_H

#include <memory>
#include "AGrille.h"
#include <string>
#include <vector>

class IAffichage
{
public:
    virtual void AfficherGrille(std::shared_ptr<AGrille>) const = 0;
    virtual void AfficherMessage(std::string, const int = 1) const = 0;
    virtual void AfficherErreur(std::string) const = 0;
    virtual void AfficherCoupsPossibles(std::vector<std::pair<int, int>>) const = 0;

    inline static bool enabled = true;
};


#endif // IAFFICHAGE_H
