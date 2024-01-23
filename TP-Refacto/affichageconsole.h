#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H


#include "IAffichage.h"

class AffichageConsole : public IAffichage
{
public:
    void AfficherGrille(const std::shared_ptr<AGrille>&) override;
    void AfficherMessage(const std::string&, const int = 1) const override;
    void AfficherErreur(const std::string&) const override;
    void AfficherCoupsPossibles(const std::vector<Position>&, const std::string& = "Coups possibles : ") const override;
    void MettreAJourGrille(const std::shared_ptr<AGrille>& grille) override ;
};

#endif // AFFICHAGECONSOLE_H
