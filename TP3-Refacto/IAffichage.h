#ifndef IAFFICHAGE_H
#define IAFFICHAGE_H

#include <memory>
#include "IGrille.h"
#include <string>

class IAffichage
{
public:
    virtual void AfficherGrille(std::shared_ptr<IGrille>) = 0;
    virtual void AfficherMessage(std::string, const int = 1) = 0;
    virtual void AfficherErreur(std::string) = 0;

    inline static bool enabled = true;
};


#endif // IAFFICHAGE_H
