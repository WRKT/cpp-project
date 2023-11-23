#ifndef IAFFICHAGE_H
#define IAFFICHAGE_H

#include "IGrille.h"

class IAffichage {
public:
    virtual void AfficherGrille(const IGrille& grille) const = 0;
    virtual void AfficherMessage(const std::string& message) const = 0;
    virtual ~IAffichage() = default;
};

#endif // IAFFICHAGE_H
