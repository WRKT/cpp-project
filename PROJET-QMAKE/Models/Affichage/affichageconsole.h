#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H


#include "IAffichage.h"

class AffichageConsole : public IAffichage
{
public:
    void AfficherGrille(const std::shared_ptr<AGrille>&) const override;
    void AfficherMessage(const std::string&, const int = 1) const override;
    void AfficherErreur(const std::string&) const override;
    void AfficherCoupsPossibles(const std::vector<std::pair<int, int>>&) const override;
};

#endif // AFFICHAGECONSOLE_H
