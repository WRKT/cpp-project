#ifndef AFFICHAGECONSOLE_H
#define AFFICHAGECONSOLE_H


#include "IAffichage.h"

class AffichageConsole : IAffichage
{
public:
    AffichageConsole();
    void AfficherGrille(const IGrille&) const;
    void AfficherMessage(const std::string& message) const;
};

#endif // AFFICHAGECONSOLE_H
