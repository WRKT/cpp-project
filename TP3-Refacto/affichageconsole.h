#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H


#include "IAffichage.h"

class AffichageConsole : public IAffichage
{
public:
    void AfficherGrille(const std::shared_ptr<IGrille>) override;
    void AfficherMessage(const std::string, const int = 1) override;
    void AfficherErreur(const std::string) override;
};

#endif // AFFICHAGECONSOLE_H
