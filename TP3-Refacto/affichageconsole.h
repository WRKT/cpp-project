#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H


#include "IAffichage.h"

class AffichageConsole : public IAffichage
{
public:
    void AfficherGrille(const std::shared_ptr<IGrille>) const override;
    void AfficherMessage(const std::string, const int = 1) const override;
    void AfficherErreur(const std::string) const override;
};

#endif // AFFICHAGECONSOLE_H
